#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  int average   = 0;
  int arr[8001] = {
      0,
  };
  int  mode      = 10000;
  bool mode_lock = false;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  vector<int> v(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i];
    average += v[i];
    arr[v[i] + 4000]++;
  }

  cout << (int)round((double)average / N) << '\n';

  sort(v.begin(), v.end());

  cout << v[N / 2] << '\n';

  for (int i = 0; i < 8001; i++) {
    if (mode == 10000) {
      mode = i - 4000;
    } else if (arr[mode + 4000] == arr[i] && mode_lock == false) {
      mode_lock = true;
      mode      = i - 4000;
    } else if (arr[mode + 4000] < arr[i]) {
      mode      = i - 4000;
      mode_lock = false;
    }
  }

  cout << mode << '\n';

  cout << abs(v.front() - v.back());

  return 0;
}
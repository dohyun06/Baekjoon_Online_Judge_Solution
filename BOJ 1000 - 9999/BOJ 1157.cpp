#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string S;
  int    al[26] = {
      0,
  };
  int  sum = 0;
  bool nan = false;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;

  for (int i = 0; i < S.length(); i++) {
    if ((int)S[i] >= 97) S[i] = (int)S[i] - 32;
    al[(int)S[i] - 65]++;
  }

  for (int i = 0; i < 26; i++) {
    if (al[sum] < al[i]) {
      sum = i;
      nan = false;
    } else if (al[sum] == al[i] && sum != i)
      nan = true;
  }

  if (nan == true) sum = -2;
  cout << (char)(sum + 65) << '\n';

  return 0;
}
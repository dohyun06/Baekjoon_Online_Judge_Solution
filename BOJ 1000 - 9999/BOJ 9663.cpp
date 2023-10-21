#include <iostream>
#include <cmath>
#include <vector>

int N, ans;
std::vector<int> queen;

bool check(int num) {
  for (int i = 0; i < num; i++)
    if (queen[i] == queen[num] || std::abs(queen[i] - queen[num]) == std::abs(i - num))
      return false;
  
  return true;
}

void NQueen(int re) {
  if (re == N) {
    ans++;
    return;
  }
  for (int i = 0; i < N; i++) {
    queen[re] = i;
    if (check(re)) NQueen(re + 1);
  }
}

int main(void) {
  std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

  std::cin >> N;

  queen.resize(N);

  NQueen(0);

  std::cout << ans;

  return 0;
}
#include <iostream>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int N, size[6], T, P;
  int tsum = 0;

  std::cin >> N;
  for (int i = 0; i < 6; i++) std::cin >> size[i];

  std::cin >> T >> P;

  for (auto i : size) tsum += i / T + (i % T ? 1 : 0);

  std::cout << tsum << '\n' << N / P << ' ' << (N % P);

  return 0;
}

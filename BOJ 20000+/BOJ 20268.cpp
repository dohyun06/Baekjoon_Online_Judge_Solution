#include <iostream>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int T, M, N, temp;

  std::cin >> T;

  for (int i = 0; i < T; i++) {
    std::cin >> M >> N;
    for (int j = 0; j < M + N; j++) std::cin >> temp;
    std::cout << (M * N == 4 ? 7 : 1) << '\n';
  }

  return 0;
}
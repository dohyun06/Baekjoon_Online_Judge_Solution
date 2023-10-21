#include <iostream>
#include <vector>

int main(void) {
  std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

  int N, M, input;

  std::cin >> N >> M;

  std::vector<std::vector<int>> mat(N, std::vector<int>(M));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      std::cin >> mat[i][j];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> input;
      std::cout << mat[i][j] + input << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
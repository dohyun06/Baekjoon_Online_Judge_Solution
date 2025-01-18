#include <iostream>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int         N, M, io = 0, sum = 0;
  std::string S;

  std::cin >> N >> M >> S;

  for (int i = 0; i < M; i++) {
    if (i + 1 < M && S[i] == 'I' && S[i + 1] == 'O') {
      i++;
      io++;
    }
    else
      io = 0;
    if (io >= N && i + 1 < M && S[i + 1] == 'I') sum++;
  }

  std::cout << sum;

  return 0;
}
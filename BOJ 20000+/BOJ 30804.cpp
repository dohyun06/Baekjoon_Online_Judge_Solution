#include <iostream>
#include <vector>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int N, S, pS, fruit[2] = {0, 0}, frIndex[2] = {-1, -1}, res = 0, tmpRes = 0;

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    pS = S;
    std::cin >> S;
    if (fruit[0] != S && fruit[1] != S) {
      res = res > tmpRes ? res : tmpRes;
      if (fruit[0] != pS) {
        fruit[0]   = S;
        tmpRes     = i - frIndex[0];
        frIndex[0] = i;
      }
      else {
        fruit[1]   = S;
        tmpRes     = i - frIndex[1];
        frIndex[1] = i;
      }
    }
    else {
      tmpRes += 1;
      if (fruit[0] == S)
        frIndex[0] = i;
      else
        frIndex[1] = i;
    }
  }
  res = res > tmpRes ? res : tmpRes;

  std::cout << res;

  return 0;
}

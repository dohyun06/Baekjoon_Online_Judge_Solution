#include <cmath>
#include <iostream>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int R, C;

  std::cin >> R >> C;
  std::cout << R * C / 2 << ' ' << R * C - 1;

  return 0;
}
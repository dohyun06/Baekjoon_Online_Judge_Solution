#include <cmath>
#include <iostream>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int    n;
  double A, B;

  std::cin >> n;
  while (n--) {
    std::cin >> A >> B;
    std::cout.precision(1);
    std::cout << std::fixed << (double)std::abs(A - B) << '\n';
  }
  return 0;
}
#include <iostream>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int A, B, C;

  std::cin >> A >> B >> C;

  std::cout << A + B - C << '\n'
            << (B < 10   ? A * 10 + B - C :
                B < 100  ? A * 100 + B - C :
                B < 1000 ? A * 1000 + B - C :
                           A * 10000 + B - C);

  return 0;
}
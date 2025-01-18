#include <iostream>
#include <string>

int main(void) {
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  std::string input;

  for (int i = 0; i < 3; i++) {
    std::cin >> input;
    if (input[0] > '0' && input[0] <= '9') {
      int sum = std::stoi(input) + 3 - i;
      if (sum % 3 && sum % 5)
        std::cout << sum;
      else {
        if (!(sum % 3)) std::cout << "Fizz";
        if (!(sum % 5)) std::cout << "Buzz";
      }
      break;
    }
  }

  return 0;
}

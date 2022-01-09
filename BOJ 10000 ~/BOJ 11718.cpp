#include <iostream>
#include <string>

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    std::string str;

    while (std::getline(std::cin, str)) {
        std::cout << str << '\n';
    }

    return 0;
}
#include <iostream>

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    int max = 0, line = 1, row = 1, input;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cin >> input;

            if(input > max) {
                max = input;
                line = i + 1;
                row = j + 1;
            }
        }
    }

    std::cout << max << '\n' << line << ' ' << row;

    return 0;
}
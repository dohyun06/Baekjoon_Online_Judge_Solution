#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int input, left, coin[6] = { 500,100,50,10,5,1 }, sum = 0;

	std::cin >> input;

	left = 1000 - input;

	for (int i = 0; i < 6; i++) {
		sum += left / coin[i];
		left %= coin[i];
	}

	std::cout << sum;

	return 0;
}
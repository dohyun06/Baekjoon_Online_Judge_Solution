#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, input1, input2, sum = 0;

	std::cin >> N;

	while (N--) {
		std::cin >> input1 >> input2;

		sum += input2 % input1;
	}

	std::cout << sum;

	return 0;
}
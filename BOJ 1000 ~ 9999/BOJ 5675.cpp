#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int A;

	while (std::cin >> A)
		std::cout << (A % 6 ? 'N' : 'Y') << '\n';

	return 0;
}
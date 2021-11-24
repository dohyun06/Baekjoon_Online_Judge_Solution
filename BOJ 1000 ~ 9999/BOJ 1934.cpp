#include <iostream>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int T, A, B;

	std::cin >> T;

	while (T--) {
		std::cin >> A >> B;

		std::cout << A * B / gcd(A, B) << '\n';
	}

	return 0;
}
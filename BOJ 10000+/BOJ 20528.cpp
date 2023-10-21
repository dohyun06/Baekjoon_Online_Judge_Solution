#include <iostream>
#include <vector>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N;

	std::cin >> N;

	std::string S;

	std::cin >> S;

	char c = S[0];

	N--;

	while (N--) {
		std::cin >> S;

		if (S[0] != c) {
			std::cout << 0;

			return 0;
		}
	}

	std::cout << 1;

	return 0;
}
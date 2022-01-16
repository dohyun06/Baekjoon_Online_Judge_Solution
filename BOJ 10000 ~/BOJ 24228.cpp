#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	long long N, R;
	std::cin >> N >> R;
	std::cout << N + 2 * R - 1;

	return 0;
}
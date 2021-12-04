#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int a;

	std::cin >> a;

	while (a--) std::cout << "SciComLove" << '\n';

	return 0;
}
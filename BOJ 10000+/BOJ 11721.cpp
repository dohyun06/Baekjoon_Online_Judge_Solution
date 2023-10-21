#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	std::string s;

	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		std::cout << s[i];
		if (!((i + 1) % 10)) std::cout << '\n';
	}

	return 0;
}
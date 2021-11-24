#include <iostream>
#include <cmath>
#include <map>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, index = 0;
	std::string input;
	std::map<std::string, int> m;

	std::cin >> N;


	for (int i = 0; i < N; i++) {
		std::cin >> input;

		m[input]++;
	}

	for (auto i : m) index = std::max(index, i.second);
	for (auto i : m)
		if (i.second == index) {
			std::cout << i.first; 
			break;
		}

	return 0;
}
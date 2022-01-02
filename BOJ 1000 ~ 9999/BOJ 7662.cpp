#include <iostream>
#include <set>
#include <algorithm>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int T, k, input;
	char c;

	std::cin >> T;

	while (T--) {
		std::multiset<int> ms;

		std::cin >> k;

		while (k--) {
			std::cin >> c >> input;

			if (c == 'I') {
				ms.insert(input);
			}
			else {
				if (input == 1 && !ms.empty()) {
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
				else if (input == -1 && !ms.empty()) {
					ms.erase(ms.begin());
				}
			}
		}

		if (ms.empty()) std::cout << "EMPTY\n";
		else {
			auto iter = ms.end();
			iter--;
			std::cout << *iter << ' ' << *ms.begin() << '\n';
		}
	}

	return 0;
}
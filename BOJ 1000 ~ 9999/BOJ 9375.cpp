#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int T, n, sum;
	std::string s1, s2;

	std::cin >> T;

	while (T--) {
		std::cin >> n;

		sum = 1;
		std::vector<std::string> v;
		std::map<std::string, int> m;

		while (n--) {
			std::cin >> s1 >> s2;
			m[s2]++;
			if (std::find(v.begin(), v.end(), s2) == v.end())
				v.push_back(s2);
		}
		for (int i = 0; i < v.size(); i++) {
			sum *= m[v[i]] + 1;
		}
		std::cout << sum - 1 << '\n';
	}

	return 0;
}
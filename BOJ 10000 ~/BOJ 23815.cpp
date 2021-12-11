#include <iostream>
#include <string>

int calculate(int n, std::string s) {
	if (s[0] == '+')
		return n + std::stoi(s.substr(1, s.length() - 1));
	else if (s[0] == '-')
		return n - std::stoi(s.substr(1, s.length() - 1));
	else if (s[0] == '*')
		return n * std::stoi(s.substr(1, s.length() - 1));
	else if (s[0] == '/')
		return n / std::stoi(s.substr(1, s.length() - 1));
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, p[2] = { 1, 1 }, temp1, temp2,temp3,temp4;
	bool skip = true;
	std::string s1, s2;

	std::cin >> N;

	while (N--) {
		std::cin >> s1 >> s2;

		if ((s1[0] == '-' || s1[0] == '/') && (s2[0] == '-' || s2[0] == '/')) {
			if (skip) {
				temp3 = calculate(p[1], s1), temp4 = calculate(p[1], s2);
				p[1] = p[0] > (temp3 > temp4 ? temp3 : temp4) ? p[0] : temp3 > temp4 ? temp3 : temp4;
			}

			temp1 = calculate(p[0], s1), temp2 = calculate(p[0], s2);
			p[0] = temp1 > temp2 ? temp1 : temp2;
		}
		else {
			temp1 = calculate(p[0], s1), temp2 = calculate(p[0], s2);
			temp3 = calculate(p[1], s1), temp4 = calculate(p[1], s2);
			p[0] = temp1 > temp2 ? temp1 : temp2;
			p[1] = temp3 > temp4 ? temp3 : temp4;
		}

		if (p[1] <= 0) {
			std::cout << "ddong game";
			return 0;
		}

		if (p[0] <= 0) {
			if (skip) {
				p[0] = p[1];
				skip = false;
			}
			else {
				std::cout << "ddong game";
				return 0;
			}
		}
	}

	std::cout << (skip ? p[1] : p[0]);

	return 0;
}
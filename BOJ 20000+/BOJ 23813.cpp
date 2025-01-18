#include <iostream>
#include <cmath>
#include <string>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	long long N, len, sum = 0;
	std::string s;

	std::cin >> s;

	len = s.length();
	N = std::stoi(s);

	for (int i = 0; i < len; i++) {
		sum += N;
		N = N / 10 + (N % 10) * std::pow(10, len - 1);
	}

	std::cout << sum;

	return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool cmp(long long a, long long b) {
	return std::abs(a) < std::abs(b);
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	long long N, sum1 = 0, sum2 = 0, dif = 2147483647;

	std::cin >> N;

	std::vector<long long> v(N);

	for (int i = 0; i < N; i++)
		std::cin >> v[i];

	std::sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N - 1; i++) {
		if (std::abs(v[i] + v[i + 1]) < dif) {
			sum1 = v[i], sum2 = v[i + 1], dif = std::abs(sum1 + sum2);
		}
	}

	if (sum1 < sum2) std::cout << sum1 << ' ' << sum2;
	else std::cout << sum2 << ' ' << sum1;


	return 0;
}
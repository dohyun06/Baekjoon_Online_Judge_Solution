#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	long long n, dp[1001] = { 0,1,3 };

	std::cin >> n;

	for (int i = 3; i <= n; i++) {
		dp[i] = ((dp[i - 2]) % 10007 * 2 + (dp[i - 1] % 10007)) % 10007;
	}

	std::cout << dp[n];

	return 0;
}
#include <iostream>

long long dp[100001][4] = { 0, };

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int T, n;
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	std::cin >> T;

	for (int i = 4; i <= 100000; i++) {
		if (i - 1 >= 0) dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		if (i - 2 >= 0) dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		if (i - 3 >= 0) dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}

	while (T--) {
		std::cin >> n;
		std::cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
	}

	return 0;
}
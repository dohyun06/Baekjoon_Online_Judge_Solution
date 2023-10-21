#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int T, n;

	std::cin >> T;

	while (T--) {
		std::cin >> n;

		std::vector<std::vector<int>> sticker(2, std::vector<int>(n)), dp(2, std::vector<int>(n));

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				std::cin >> sticker[i][j];

		if (n == 1) std::cout << std::max(sticker[0][0], sticker[1][0]) << '\n';
		else {
			dp[0][0] = sticker[0][0];
			dp[1][0] = sticker[1][0];
			dp[0][1] = dp[1][0] + sticker[0][1];
			dp[1][1] = dp[0][0] + sticker[1][1];


			for (int i = 2; i < n; i++) {
				dp[0][i] = std::max(dp[1][i - 2], dp[1][i - 1]) + sticker[0][i];
				dp[1][i] = std::max(dp[0][i - 2], dp[0][i - 1]) + sticker[1][i];
			}

			std::cout << std::max(dp[0][n - 1], dp[1][n - 1]) << '\n';
		}
	}

	return 0;
}
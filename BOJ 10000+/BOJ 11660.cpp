#include <iostream>
#include <vector>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, M, input, x1, x2, y1, y2;

	std::cin >> N >> M;

	std::vector<std::vector<int>> dp(N + 2, std::vector<int>(N + 2));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> input;
			dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] + input - dp[i][j];
		}
	}


	while (M--) {

		std::cin >> x1 >> y1 >> x2 >> y2;

		std::cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
	}

	return 0;
}
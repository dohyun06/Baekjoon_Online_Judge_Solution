#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, K;

	std::cin >> N >> K;

	std::vector<int> weight(N + 1), value(N + 1);
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1));

	for (int i = 1; i <= N; i++)	std::cin >> weight[i] >> value[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (weight[i] <= j)	dp[i][j] = std::max(dp[i][j], value[i] + dp[i - 1][j - weight[i]]);

		}
	}

	std::cout << dp[N][K];

	return 0;
}
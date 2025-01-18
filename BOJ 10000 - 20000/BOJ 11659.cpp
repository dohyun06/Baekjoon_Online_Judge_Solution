#include <iostream>
#include <vector>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, M, input;

	std::cin >> N >> M;

	std::vector<int> dp(N + 1);

	for (int i = 0; i < N; i++) {
		std::cin >> input;

		dp[i + 1] = dp[i] + input;
	}


	while (M--) {
		int i, j;

		std::cin >> i >> j;

		std::cout << dp[j] - dp[i - 1] << '\n';
	}

	return 0;
}
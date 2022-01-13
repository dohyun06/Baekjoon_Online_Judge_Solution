#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N;

	std::cin >> N;

	std::vector<int> A(N), dp(N, 1);

	for (int i = 0; i < N; i++) std::cin >> A[i];

	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (A[i] < A[j] && dp[j] <= dp[i])
				dp[j] = dp[i] + 1;

	std::cout << *std::max_element(dp.begin(), dp.end());

	return 0;
}
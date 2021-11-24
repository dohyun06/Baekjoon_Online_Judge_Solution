#include <iostream>
#include <cmath>
#include <algorithm>

int dp[1000001];

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, arr[4] = { 2, };

	std::cin >> N;

	if (N < 8) {
		std::cout << -1;
		return 0;
	}

	if (N % 2) {
		N -= 5;
		arr[1] = 3;
	}
	else {
		N -= 4;
		arr[1] = 2;
	}

	for (int i = 2; i <= N / 2; i++)
		if (!dp[i])
			for (int j = i * 2; j < N + 1; j += i)
				dp[j] = 1;

	for (int i = 2; i <= N / 2; i++)
		if (!dp[i] && !dp[N - i])
			arr[2] = i, arr[3] = N - i;

	std::sort(arr, arr + 4);

	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << ' ';

	return 0;
}
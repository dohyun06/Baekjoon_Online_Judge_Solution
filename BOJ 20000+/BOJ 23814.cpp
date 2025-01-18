#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	long long D, N, M, K, max;

	std::cin >> D >> N >> M >> K;

	max = (N + M + K) / D;

	if (N / D + M / D + K / D == max) {
		std::cout << K;
		return 0;
	}
	else if (D - N % D < D - M % D) {
		K -= D - (N % D);
		N += D - (N % D);
		if (N / D + M / D + K / D != max) {
			K -= D - (M % D);
			M += D - (M % D);
		}
	}
	else {
		K -= D - (M % D);
		M += D - (M % D);
		if (N / D + M / D + K / D != max) {
			K -= D - (N % D);
			N += D - (N % D);
		}
	}

	std::cout << K;

	return 0;
}
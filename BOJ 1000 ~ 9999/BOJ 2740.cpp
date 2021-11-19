#include <iostream>
#include <vector>

int main(void) {
	int N, M, K;

	std::cin >> N >> M;

	std::vector<std::vector<int>> A(N, std::vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> A[i][j];
		}
	}

	std::cin >> M >> K;

	std::vector<std::vector<int>> B(M, std::vector<int>(K));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			std::cin >> B[i][j];
		}
	}

	int sum;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			sum = 0;

			for (int k = 0; k < M; k++) {
				sum += A[i][k] * B[k][j];
			}
			std::cout << sum << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
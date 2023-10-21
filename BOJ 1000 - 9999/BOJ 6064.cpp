#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int T, M, N, x, y, sum;
	bool flag;

	std::cin >> T;

	while (T--) {
		std::cin >> M >> N >> x >> y;

		flag = true;

		for (int i = x - 1; i < M * N; i += M) {
			if (i % N == y - 1) {
				sum = i + 1;
				flag = false;
				break;
			}
		}

		if (flag) std::cout << "-1\n";
		else std::cout << sum << '\n';
	}


	return 0;
}
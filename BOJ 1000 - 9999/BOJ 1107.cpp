#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

#define INF 10000000

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, M, cnt = 0, sum[3] = { INF, INF, INF };
	bool flag = false;
	std::string sN;

	std::cin >> N >> M;

	sN = std::to_string(N);
	std::vector<int> broken(M);

	for (int i = 0; i < M; i++) std::cin >> broken[i];

	sum[0] = std::abs(N - 100);
	if (!M) sum[1] = sN.length();

	for (int i = 0; i < M; i++)
		if (sN.find((char)(broken[i] + '0')) != std::string::npos) break;
		else if (i == M - 1) sum[1] = sN.length();

	if (sum[1] == INF) {
		for (int i = 1; i <= 1000000; i++) {
			cnt++;

			if (N - i >= 0) {
				sN = std::to_string(N - i);

				for (int j = 0; j < M; j++) {
					if (sN.find((char)(broken[j] + '0')) != std::string::npos) break;
					else if (j == M - 1) {
						sum[2] = sN.length() + cnt;
						flag = true;
						break;
					}
				}
			}
			if (flag) break;

			sN = std::to_string(N + i);

			for (int j = 0; j < M; j++) {
				if (sN.find((char)(broken[j] + '0')) != std::string::npos) break;
				else if (j == M - 1) {
					sum[2] = sN.length() + cnt;
					flag = true;
					break;
				}
			}

			if (flag) break;
		}
	}

	std::cout << *std::min_element(sum, sum + 3);

	return 0;
}
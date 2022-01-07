#include <iostream>
#include <vector>
#include <algorithm>

int tetromino[19][4][2] = {
	{ {0,0}, {0,1}, {1,0}, {1,1} },
	{ {0,0}, {0,1}, {0,2}, {0,3} },
	{ {0,0}, {1,0}, {2,0}, {3,0} },
	{ {0,0}, {0,1}, {0,2}, {1,0} },
	{ {0,2}, {1,0}, {1,1}, {1,2} },
	{ {0,0}, {1,0}, {1,1}, {1,2} },
	{ {0,0}, {0,1}, {0,2}, {1,2} },
	{ {0,0}, {1,0}, {2,0}, {2,1} },
	{ {0,0}, {0,1}, {1,1}, {2,1} },
	{ {0,0}, {0,1}, {1,0}, {2,0} },
	{ {0,1}, {1,1}, {2,0}, {2,1} },
	{ {0,0}, {1,0}, {1,1}, {2,1} },
	{ {0,1}, {1,0}, {1,1}, {2,0} },
	{ {0,1}, {0,2}, {1,0}, {1,1} },
	{ {0,0}, {0,1}, {1,1}, {1,2} },
	{ {0,0}, {0,1}, {0,2}, {1,1} },
	{ {0,1}, {1,0}, {1,1}, {1,2} },
	{ {0,1}, {1,0}, {1,1}, {2,1} },
	{ {0,0}, {1,0}, {1,1}, {2,0} }
};

int main() {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int M, N, sum = 0;
	std::vector<std::vector<int>> v;

	std::cin >> N >> M;

	v.resize(N, std::vector<int>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			std::cin >> v[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				int result = 0;
				for (int l = 0; l < 4; l++) {
					int ax = j + tetromino[k][l][1], ay = i + tetromino[k][l][0];

					if (ax >= 0 && ax < M && ay >= 0 && ay < N) {
						result += v[ay][ax];
					}
				}
				sum = std::max(result, sum);
			}
		}
	}

	std::cout << sum;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, num1, num2, num3, min1[3] = { 0,0,0 }, min2[3], max1[3] = { 0,0,0 }, max2[3];
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> num1 >> num2 >> num3;
		min2[0] = num1 + std::min(min1[0], min1[1]);
		min2[1] = num2 + std::min(min1[0], std::min(min1[1], min1[2]));
		min2[2] = num3 + std::min(min1[1], min1[2]);

		max2[0] = num1 + std::max(max1[0], max1[1]);
		max2[1] = num2 + std::max(max1[0], std::max(max1[1], max1[2]));
		max2[2] = num3 + std::max(max1[1], max1[2]);

		for (int j = 0; j < 3; j++) {
			min1[j] = min2[j];
			max1[j] = max2[j];
		}
	}

	std::cout << std::max(max2[0], std::max(max2[1], max2[2])) << ' ' << std::min(min2[0], std::min(min2[1], min2[2]));

	return 0;
}
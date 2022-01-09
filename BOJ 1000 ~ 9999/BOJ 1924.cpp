#include <iostream>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int x, y, month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, sum = 0;
	std::string day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

	std::cin >> x >> y;

	x--;
	y--;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < month[i]; j++) {
			if (i == x && j == y) std::cout << day[sum];

			sum = (sum + 1) % 7;
		}
	}

	return 0;
}
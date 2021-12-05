#include <iostream>
#include <cmath>
#include <algorithm>

double min(double h, double m, double s) {
	double angle1 = std::abs(h - m), angle2 = std::abs(h - s), angle3 = std::abs(m - s);

	angle1 = angle1 > 180 ? 360 - angle1 : angle1;
	angle2 = angle2 > 180 ? 360 - angle2 : angle2;
	angle3 = angle3 > 180 ? 360 - angle3 : angle3;

	return std::min(std::min(angle1, angle2), angle3);
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed; std::cout.precision(10);

	int T;
	double h, m, s;

	std::cin >> T;

	while (T--) {
		std::cin >> h >> m >> s;

		std::cout << min(h * 30 + m / 2 + s / 120, m * 6 + s / 10, s * 6) << '\n';
	}

	return 0;
}
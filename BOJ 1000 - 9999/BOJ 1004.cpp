#include <iostream>
#include <math.h>
using namespace std;
int main(void) {
	int T, x1, y1, x2, y2, n, cx[50], cy[50], r[50], num = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> cx[j] >> cy[j] >> r[j];
		}
		for (int j = 0; j < n; j++) {
			if (sqrt(pow(x1 - cx[j], 2) + pow(y1 - cy[j], 2)) >= r[j] || sqrt(pow(x2 - cx[j], 2) + pow(y2 - cy[j], 2)) >= r[j]) {
				if (sqrt(pow(x1 - cx[j], 2) + pow(y1 - cy[j], 2)) < r[j])
					num++;
				if (sqrt(pow(x2 - cx[j], 2) + pow(y2 - cy[j], 2)) < r[j])
					num++;
			}
		}
		cout << num << endl;
		num = 0;
	}
	return 0;
}
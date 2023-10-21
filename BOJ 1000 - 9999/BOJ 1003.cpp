#include <iostream>
using namespace std;
int main(void) {
	int T, N, fi[40] = { 0,1, };
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N == 0) cout << "1 0" << endl;
		else {
			for (int j = 1; j < N; j++) {
				fi[j + 1] = fi[j - 1] + fi[j];
			}
			cout << fi[N - 1] << " " << fi[N] << endl;
		}
	}
	return 0;
}
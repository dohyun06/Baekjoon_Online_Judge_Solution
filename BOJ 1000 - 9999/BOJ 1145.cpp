#include <iostream>
#include <vector>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int arr[5],cnt=0;

	for (int i = 0; i < 5; i++) std::cin >> arr[i];

	for (int i = 1;; i++) {
		for (int j = 0; j < 5; j++)
			if (!(i % arr[j])) cnt++;

		if (cnt >= 3) {
			std::cout << i;
			break;
		}

		cnt = 0;
	}

	return 0;
}
#include <iostream>
#include <string>
#include <vector>

void add(std::string a, std::string b) {
	int index = a.length() > b.length() ? a.length() + 1 : b.length() + 1;
	std::vector<int> sum(index, 0); 

	while (a.length() != b.length())
		if (a.length() > b.length())
			b = "0" + b;				
		else
			a = "0" + a;

	for (int i = 0; i < index - 1; i++) {
		if (sum[i] + (a[a.length() - i - 1] - '0') + (b[b.length() - i - 1] - '0') >= 10) {
			sum[i] += (a[a.length() - i - 1] - '0') + (b[b.length() - i - 1] - '0') - 10;
			sum[i + 1]++;
		}
		else
			sum[i] += (int)((a[a.length() - i - 1] - '0') + (b[b.length() - i - 1] - '0'));
	}

	for (int i = sum.size() - 1; i >= 0; i--)
		if (i != sum.size() - 1 || sum[i] != 0)
			std::cout << sum[i];
}

void sub(std::string a, std::string b) {
	int index = a.length() > b.length() ? a.length() : b.length();
	bool lock = false;
	std::vector<int> sum(index, 0);

	while (a.length() != b.length())
		if (a.length() > b.length())
			b = "0" + b;
		else
			a = "0" + a;

	for (int i = 0; i < index; i++) {
		if (sum[i] + (a[a.length() - i - 1] - '0') - (b[b.length() - i - 1] - '0') < 0 && i != index - 1) {
			sum[i] += (a[a.length() - i - 1] - '0') - (b[b.length() - i - 1] - '0') + 10;
			sum[i + 1]--;
		}
		else
			sum[i] += (int)((a[a.length() - i - 1] - '0') - (b[b.length() - i - 1] - '0'));
	}

	for (int i = sum.size() - 1; i >= 0; i--) 
		if (lock || sum[i] != 0) {
			std::cout << sum[i];
			lock = true;
		}
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	std::string A, B;

	std::cin >> A >> B;

	if (A == "0") {
		std::cout << B;
		return 0;
	}
	else if (B == "0") {
		std::cout << A;
		return 0;
	}

	if (A[0] > 48 && B[0] > 48) 
		add(A, B);
	else if (A[0] == '-' && B[0] == '-') { 
		std::cout << '-';
		add(A.erase(0, 1), B.erase(0, 1));
	}
	else {
		if (A[0] == '-') {
			A.erase(0, 1);

			if (A == B) {
				std::cout << 0;
				return 0;
			}

			if (A.length() > B.length()) {
				std::cout << '-';
				sub(A, B);
			}
			else if (A.length() < B.length())
				sub(B, A);
			else {
				for (int i = 0; i < A.length(); i++) {
					if (A[i] - '0' > B[i] - '0') {
						std::cout << '-';
						sub(A, B);
						return 0;
					}
					else if (A[i] - '0' < B[i] - '0')
						break;
				}
				sub(B, A);
			}
		}

		else {
			B.erase(0, 1);

			if (A == B) { 
				std::cout << 0;
				return 0;
			}

			if (A.length() > B.length())
				sub(A, B);
			else if (A.length() < B.length()) {
				std::cout << '-';
				sub(B, A);
			}
			else {
				for (int i = 0; i < A.length(); i++) {
					if (A[i] - '0' > B[i] - '0') {
						sub(A, B);
						return 0;
					}
					else if (A[i] - '0' < B[i] - '0') {
						std::cout << '-';
						break;
					}
				}
				sub(B, A);
			}
		}
	}

	return 0;
}
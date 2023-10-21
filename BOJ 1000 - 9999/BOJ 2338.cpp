#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <complex>
#include <algorithm>

const double PI2 = std::acos(-1) * 2;

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
		if (i != sum.size() - 1 || sum[i] != 0) { 
			std::cout << sum[i];
		}
}

void FFT(std::vector<std::complex<double>>& f, std::complex<double> w) {
	int n = f.size();

	if (n == 1) return;

	std::vector<std::complex<double>> f_even(n / 2), f_odd(n / 2);

	for (int i = 0; i < n; i++) (i % 2 ? f_odd : f_even)[i / 2] = f[i];

	FFT(f_even, w * w);
	FFT(f_odd, w * w);

	std::complex<double> w_p(1, 0);
	
	for (int i = 0; i < n / 2; i++) {
		f[i] = f_even[i] + w_p * f_odd[i];
		f[i + n / 2] = f_even[i] - w_p * f_odd[i];

		w_p *= w;
	}
}

std::vector<std::complex<double>> multiply(std::vector<std::complex<double>> a, std::vector<std::complex<double>> b) {
	int n = 1;

	while (n < a.size() + 1 || n < b.size() + 1) n *= 2;
	n *= 2; 

	a.resize(n); 	
	b.resize(n); 	
	std::vector<std::complex<double>> c(n); 

	std::complex<double> w(std::cos(PI2 / n), std::sin(PI2 / n)); 

	FFT(a, w);
	FFT(b, w);

	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];

	FFT(c, std::complex<double>(1, 0) / w);
	for (int i = 0; i < n; i++) {
		c[i] /= std::complex<double>(n, 0);
		c[i] = std::complex<double>(std::round(c[i].real()), std::round(c[i].imag())); 	
	}

	return c; 
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	std::string SA, SB, A, B;

	std::cin >> SA >> SB;

	A = SA;
	B = SB;

	if (A == "0") {
		std::cout << B;
	}
	else if (B == "0") {
		std::cout << A;
	}

	else if (A[0] > 48 && B[0] > 48)
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
			}

			else if (A.length() > B.length()) { 
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
						break;
					}
					else if (A[i] - '0' < B[i] - '0') {
						sub(B, A);
						break;
          }
				}
			}
		}

		else {
			B.erase(0, 1);

			if (A == B) { 
        std::cout << 0;
			}

			else if (A.length() > B.length())
				sub(A, B);

			else if (A.length() < B.length()) {
				std::cout << '-';
				sub(B, A);
			}

			else {
				for (int i = 0; i < A.length(); i++) {
					if (A[i] - '0' > B[i] - '0') { 
						sub(A, B);
						break;
					}
					else if (A[i] - '0' < B[i] - '0') {
						std::cout << '-';
						sub(B, A);
						break;
					}
				}
			}
		}
	}

	std::cout << '\n';

	A = SA;
	B = SB;

	if (A == B)
		std::cout << 0;
	else if (A == "0") {
		if (B[0] == '-') {
			B.erase(0, 1);
			std::cout << B;
		}
		else
			std::cout << '-' << B;
	}
	else if (B == "0")
		std::cout << A;

	else if (A[0] > 48 && B[0] > 48) {
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
					break;
				}
				else if (A[i] - '0' < B[i] - '0') {
					std::cout << '-';
					sub(B, A);
					break;
				}
			}
		}
	}
	else if (A[0] == '-' && B[0] == '-') {
		A.erase(0, 1);
		B.erase(0, 1);

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
					break;
				}
				else if (A[i] - '0' < B[i] - '0') { 
					sub(B, A);
					break;
				}
			}
		}
	}
	else {
		if (A[0] == '-') {
			A.erase(0, 1);
			std::cout << '-';
			add(A, B);
		}
		else {
			B.erase(0, 1);
			add(A, B);
		}
	}
	std::cout << '\n';

	A = SA;
  B = SB;
  std::vector<int> ans; 	
	std::vector<std::complex<double>> a, b, c;

  if (A == "0" || B == "0") { 		
		std::cout << 0 << '\n'; 
	}
  else if (A[0] == '-' || B[0] == '-') {
    if (A[0] != B[0])	std::cout << '-'; 

		if (A[0] == '-') A.erase(0, 1); 		
		if (B[0] == '-') B.erase(0, 1);
  }

  for (int i = 0; i < A.length(); i++) a.push_back(std::complex<double>(A[i] - '0', 0)); 	
	for (int i = 0; i < B.length(); i++) b.push_back(std::complex<double>(B[i] - '0', 0)); 	
	std::reverse(a.begin(), a.end()); 
	std::reverse(b.begin(), b.end()); 

	c = multiply(a, b); 

  ans.push_back((int)c[0].real() % 10); 	
	ans.push_back((int)c[0].real() / 10); 	
	for (int i = 1; i < c.size(); i++) { 		
		ans.push_back((ans[i] + (int)c[i].real()) / 10); 		
		ans[i] = (ans[i] + (int)c[i].real()) % 10; 	
	}

	for (int i = ans.size() - 1; i >= 0; i--) if (ans[i]) break; else ans.pop_back(); 
	std::reverse(ans.begin(), ans.end()); 

  for (int i = 0; i < ans.size(); i++) { 		
		std::cout << ans[i];
	}

	return 0;
}
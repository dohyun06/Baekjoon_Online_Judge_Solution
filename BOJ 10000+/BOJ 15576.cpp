#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>

const double PI2 = std::acos(-1) * 2;

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

	std::string input1, input2; 	
	std::vector<int> ans; 	
	std::vector<std::complex<double>> a, b, c; 	

	std::cin >> input1 >> input2; 

	if (input1 == "0" || input2 == "0") { 		
		std::cout << 0;
		return 0; 	
	}

	for (int i = 0; i < input1.length(); i++) a.push_back(std::complex<double>(input1[i] - '0', 0)); 	
	for (int i = 0; i < input2.length(); i++) b.push_back(std::complex<double>(input2[i] - '0', 0)); 	
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

	for (int i = 0; i < ans.size(); i++)	
		std::cout << ans[i];

	return 0;
}
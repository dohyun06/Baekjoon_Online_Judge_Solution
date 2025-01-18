#include <iostream>
#include <cmath>
#include <vector>
#include <complex>

#define MOD 100003

const double PI2 = std::acos(-1) * 2;

std::vector<double> A;

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

void IDFT(std::vector<std::complex<double>>& f, std::complex<double> w) {
	int n = f.size();

	if (n == 1) return;

	std::vector<std::complex<double>> f_even(n / 2), f_odd(n / 2);

	for (int i = 0; i < n; i++) (i % 2 ? f_odd : f_even)[i / 2] = f[i];

	FFT(f_even, w * w);
	FFT(f_odd, w * w);

	std::complex<double> w_p(1, 0);
	
	for (int i = 0; i < n / 2; i++) {
		f[i] = std::complex<double>((int)std::round((f_even[i] / std::complex<double>(n, 0) + w_p * f_odd[i] / std::complex<double>(n, 0)).real()) % MOD, 0);
		f[i + n / 2] = std::complex<double>((int)std::round((f_even[i] / std::complex<double>(n, 0) - w_p * f_odd[i] / std::complex<double>(n, 0)).real()) % MOD, 0);
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

	IDFT(c, std::complex<double>(1, 0) / w);

	return c; 
}

std::vector<std::complex<double>> mul(int s, int e) {
	if (s == e - 1) return { 1, A[s] };

	std::vector<std::complex<double>> ans = multiply(mul(s, (s + e) / 2), mul((s + e) / 2, e));
	ans.resize(e - s + 1);
	return ans;
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, Q, K;
	double input;
	std::vector<std::complex<double>> ans;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> input;
		A.push_back(input);
	}

	ans = mul(0, N);

	std::cin >> Q;

	while (Q--) {
		std::cin >> K;
		std::cout << (int)ans[K].real() << '\n';
	}

	return 0;
}
#include <iostream>
#include <algorithm>

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N, alph[26] = { 0, };
	std::string input;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> input;
		alph[input[0] - 'a']++;
	}

	if (*std::max_element(alph, alph + 26) < 5)std::cout << "PREDAJA";
	else
		for (int i = 0; i < 26; i++)
			if (alph[i] >= 5) std::cout << (char)(i + 'a');

	return 0;
}
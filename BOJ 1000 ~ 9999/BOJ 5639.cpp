#include <iostream>
#include <vector>

std::vector<int> node;

void preToPost(int l, int r) {
	int sub = l + 1;
	while (sub <= r && node[sub] < node[l]) sub++;

	if (l + 1 <= sub - 1) preToPost(l + 1, sub - 1);
	if (sub <= r) preToPost(sub, r);

	std::cout << node[l] << '\n';
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int	input;
	
	while (std::cin >> input) node.push_back(input);

	preToPost(0, node.size() - 1);

	return 0;
}
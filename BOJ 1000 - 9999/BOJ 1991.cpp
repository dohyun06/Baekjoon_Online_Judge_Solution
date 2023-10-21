#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> tree;

void preOrder(int root) {
	int left = tree[root].first, right = tree[root].second;
	
	std::cout << (char)(root + 'A');

	if (left > 0) preOrder(left);
	if (right > 0) preOrder(right);
}

void inOrder(int root) {
	int left = tree[root].first, right = tree[root].second;
	
	if (left > 0) inOrder(left);
	
	std::cout << (char)(root + 'A');

	if (right > 0) inOrder(right);
}

void postOrder(int root) {
	int left = tree[root].first, right = tree[root].second;

	if (left > 0) postOrder(left);
	if (right > 0) postOrder(right);

	std::cout << (char)(root + 'A');
}

int main(void) {
	std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

	int N;
	std::cin >> N;

	tree.resize(N);

	for (int i = 0; i < N; i++) {
		char root, left, right;
		std::cin >> root >> left >> right;

		tree[root - 'A'] = { left - 'A',right - 'A' };
	}

	preOrder(0);
	std::cout << '\n';
	inOrder(0);
	std::cout << '\n';
	postOrder(0);

	return 0;
}
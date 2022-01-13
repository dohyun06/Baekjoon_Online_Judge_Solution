#include <iostream>

long long A, B, C;

long long pow(long long A, long long B) {
    if (B == 0) return 1;
    if (B == 1) return A % C;

    long long res = pow(A, B / 2) % C;
    
    return (((res % C) * (res % C)) % C) * (B % 2 ? A % C : 1);
}

int main(void) {
    std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

    std::cin >> A >> B >> C;

    std::cout << pow(A, B) % C;

    return 0;
}
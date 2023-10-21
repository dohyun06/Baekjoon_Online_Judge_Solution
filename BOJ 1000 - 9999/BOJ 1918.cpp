#include <iostream>
#include <string>
#include <vector>
#include <stack>

void trans(std::vector<std::string>& v, int start, int end) {
  for (int i = start; i < end; i++) {
    if (v[i] == "*" || v[i] == "/") {
      v[i - 1] = v[i - 1] + v[i + 1] + v[i];
      v.erase(v.begin() + i, v.begin() + i + 2);
      i--;
      end -= 2;
    }
  }
  for (int i = start; i < end; i++) {
    if (v[i] == "+" || v[i] == "-") {
      v[i - 1] = v[i - 1] + v[i + 1] + v[i];
      v.erase(v.begin() + i, v.begin() + i + 2);
      i--;
      end -= 2;
    }
  }
}

int main(void) {
  std::cout.tie(NULL); std::cin.tie(NULL); std::ios_base::sync_with_stdio(false);

  std::string str, temp;
  std::vector<std::string> vec;
  std::stack<int> st;

  std::cin >> str;

  for (int i = 0; i < str.length(); i++) {
    temp = str[i];
    vec.push_back(temp);
  }

  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == "(") st.push(i);
    else if (vec[i] == ")") {
      vec.erase(vec.begin() + st.top());
      vec.erase(vec.begin() + i - 1);
      trans(vec, st.top(), i - 1);
      i = st.top();
      st.pop();
    }
  }
  trans(vec, 0, vec.size());

  std::cout << vec[0];

  return 0;
}
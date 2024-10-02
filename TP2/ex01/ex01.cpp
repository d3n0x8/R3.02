#include <iostream>
#include <string>

using namespace std;

int sommeR(auto n) {
  if (n == 1)
    return 1;
  else
    return n + sommeR(n - 1);
}

int main() {
  auto i = 5;
  cout << "sommeR de 5: " << sommeR(i) << endl;
  string s = "hello";
  for (auto c : s) {
    cout << c << endl;
  }
}
#include <iostream>

using namespace std;

int sommeR(int n) {
  if (n == 1)
    return 1;
  else
    return n + sommeR(n - 1);
}

int main() { cout << "sommeR de 5: " << sommeR(5) << endl; }
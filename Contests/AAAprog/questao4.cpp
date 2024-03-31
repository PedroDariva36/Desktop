// EXEMPLO STRING DE INPUT : 2 3 7 8 11

#include <iostream>
#include <unordered_map>
#include <vector>

#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  vector<int> v;
  // EXEMPLO STRING DE INPUT : 2 3 7 8 11
  while (cin >> n) {
    v.push_back(n);
  }
  int target = v.back();
  for (int i = 0; i < v.size() - 1; i++) {
    int diff = target - v[i];
    for (int j = 0; j < v.size() - 1; j++) {
      if (v[j] == diff) {
        cout << "SIM\n";
        return 0;
      }
    }
  }
  cout << "NAO\n";
  return 0;
}

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

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int solution();

int main(int argc, char *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  string str;
  cin >> str;
  for (char c : str) {
    // cout << c - ASCII_UPPERCASE_OFFSET;
    if (c - ASCII_UPPERCASE_OFFSET < 26) {
      cout << "SIM" << endl;
      return 0;
    }
  }
  cout << "NAO\n";
  return 0;
}

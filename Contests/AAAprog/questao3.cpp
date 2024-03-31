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
  getline(cin, str);
  if (str.length() == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (str[0] == '\n') {
    cout << 0 << endl;
    return 0;
  }
  int count = 0;
  bool new_word = true;
  for (char c : str) {
    if ((isalpha(c) || isdigit(c))) {
      if (new_word) {
        // cout << "inscresead with " << c << endl;
        count++;
        new_word = false;
      }
    } else {
      // cout << c << " is not alphanum" << endl;
      new_word = true;
    }
  }
  cout << count << endl;
  return 0;
}

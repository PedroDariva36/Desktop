#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    string s, line; 
    set<string> st;

    while (tt--) {
        while ((cin.peek()!='\n') && (cin>>s)){
            st.insert(s);
        }
        for (auto i : st) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

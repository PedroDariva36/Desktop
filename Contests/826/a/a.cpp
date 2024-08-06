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
    while (tt--) {
        string s1, s2;
        cin >> s1 >> s2; 
        
        int c1 = 0, c2= 0;
        for (auto i: s1) if(i == 'X') c1++;
        for (auto i: s2) if(i == 'X') c2++;
        
        if(s1.back() == s2.back()){
            if(c1 == c2) cout << "=";
            else if(s1.back() == 'S'){
                cout << (c1 > c2? '<' : '>');
            }
            else if(s1.back() == 'L'){
                cout << (c1 > c2? '>' : '<');
            }
        }
        else cout << (s1.back() > s2.back()? '<': '>'); 
        cout << endl;


    }
    return 0;
}

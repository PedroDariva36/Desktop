#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    
    vector<char> s;
    char aux = 'a';        


    while (n--) {
        vector<char> c = s;
        s.pb(aux++);
        for (int i = 0; i < c.size(); i++) s.pb(c[i]); 
    }
    if(s.size() >= 1e5){
        for (int i = 0; i < 1e5; i++) {
            cout << s[i];
        } 
        cout << endl;
    }
    else{
        for (auto &i: s) {
            cout << i;
        }
        cout << endl;
    }




    return 0;
}

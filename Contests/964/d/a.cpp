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
        string a;
        string s;
  
        cin >> a;
        cin >> s;


        bool f = 0;
        bool g = 0;
        int pos = 0;
        for (auto &i:s) {
            f = 0;
            int nw = pos;
            for (int j = pos; j < a.size(); j++) {
                if(a[j] == '?'){
                    a[j] = i; 
                    nw = j+1;
                    break;
                } 
                if(a[j] == i){
                    nw = j+1;
                    break;
                }
            }

            if(nw == pos){
                g = 1;
                break;
            }
            pos = nw;
        }
        

        if(g){
            cout << "NO" << endl;
            continue;
        }
        
        for (auto &i: a) {
            if(i == '?') i = 'a';
        }

        cout << "YES" << endl;
        cout << a << endl;

        
         

    }
    return 0;
}

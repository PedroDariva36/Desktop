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
        int n;
        char aux; 
        cin >> n;
        
        map<char,int> m;
        for (int i = 0;i < n; i++) {
            cin >> aux;
            m[aux]++;
        }

        ll sum = 0; 
        for (auto i: m) {
            int k = (i.first - 'A')+1;
            if (k <= i.second) sum++;    
        }
        
        cout << sum << endl;
        
         

    }
    return 0;
}

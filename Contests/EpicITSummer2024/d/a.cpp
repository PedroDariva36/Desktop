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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        pair<ll,ll> m[n+1];
        ll aux; 
        for (int i = 0;i < n; i++) {
            cin >> aux;
            m[aux].first++; 
        }
        int k = 0; 
        for (int i = 0; i <= n; i++) {
            if (m[i].first == 0) continue;
            m[i].second = k++;
        }
 
        /*
        for (auto i: m) {
            cout << i.second << " "; 
        }
        cout << endl; 
        for (auto i: m) {
            cout << i.first << " "; 
        }
        cout << endl;
        */


        ll sum = 0;
        for (int i = 0; i <= n; i++) {
            if (m[i].first == 0) continue;
            sum++;
            int pos = -1;
            ll mx = 1e9;

            for (int j = i+1; j <= n; j++) {
                if(m[j].first == 0) continue;
                
                if(abs(m[i].second - m[j].second) < m[j].first) continue;

                if (m[j].first < mx){
                    pos = j;
                    mx = m[j].first;
                }
            }
//            cout << pos << endl;

            if(pos == -1)
                continue;
            m[pos].first--;
        }
        
        cout << sum << endl;

        
         

    }
    return 0;
}

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
        cin >> n;
        map<ll,ll> m; 
        ll aux;
        for (int i = 0; i <n; i++) {
            cin >> aux;
            m[aux]++;
        } 
        
        ll last = -1;
        ll c = 0;
        ll sum = 0; 
        for (auto i: m) {
            if(abs(last - i.first) > 1){
                sum += c;
                last = i.first;
                c = i.second;
            }
            else {
                if(c > i.second){
                    sum += abs(c-i.second);
                    c = i.second;
                }
                else if(c < i.second){
                    c = i.second;
                }
    
                last = i.first;
            }

        } 
        sum += c;
        cout << sum << endl;
         

    }
    return 0;
}

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
        vector<pair<ll,int>> a(n),b(n),c(n);       
         
        int l = 0;
        for(auto &i: a) {
            cin >> i.first;
            i.second = l++; 
        }

        l = 0;
        for(auto &i: b) {
            cin >> i.first;
            i.second = l++; 
        }
        
        l = 0;
        for(auto &i: c) {
            cin >> i.first;
            i.second = l++; 
        }

        sort(rall(a));
        sort(rall(b));
        sort(rall(c));

        
        ll asw = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if(a[i].second == b[j].second || b[j].second == c[k].second || c[k].second == a[i].second) continue;
                    asw = max(asw, a[i].first + b[j].first + c[k].first);
                }   
            }
        }  

        cout << asw << endl;



    }
    return 0;
}

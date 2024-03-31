#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>a(n);
        for (auto &i : a) cin >> i;
        ll k = 0;
        ll asw = 0;
        for (int i = 1; i < 63; i++) {
            k = 1LL << i;
            set<ll> s; 
            for (auto &j : a) {
                s.insert(j%k);
            }
            if(s.size() == 2){
                asw = k;
                break;
            }
        }
        cout << asw << endl;
    }


    return 0;
}

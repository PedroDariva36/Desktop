#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    long aux;
    cin >> t;
    while (t--) {
        int n;

        cin >> n; 
        unordered_map<ll, ll, custom_hash> a;
        for(int i = 0; i < n; i++){
            cin >> aux;
            a[aux]++;
        }
            
        ll sum = 0; 
        sum += a[1]*a[2];
        for (auto &i : a) {
            if (i.second < 2) continue; 
            sum += (i.second * (i.second-1ll)/2ll);
        }

        cout << sum << endl;

        

    }

    return 0;
}

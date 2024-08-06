#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

bool iz(vector<ll> a){
    bool f = 0;
    for (int i = 0; i < a.size(); i++) {
        if(a[i] != 0) f = 1; 
    }
    return f;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        ll sum = 0; 
        vector<ll> a(n);

        while (iz(a)) {
            map<ll,ll> m;
            for (auto i : a){
                sum += i;
            } 
            

            


        }

         

    }
    return 0;
}

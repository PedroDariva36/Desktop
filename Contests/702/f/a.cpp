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
       
        ll aux;

        map<ll, int> m;
        map<int,int> k;
        

        for (int i = 0; i < n; i++) {
            cin >> aux;
            m[aux]++;
        }
        
        for (auto &i : m) k[i.second]++;
        

        ll mn = n;
        for (auto &i: k) {
            int c = i.first; 
            ll sum = 0; 
            for (auto j : k) {
                if(j.first < c){
                    sum += j.first * j.second;
                }
                if(j.first > c) sum +=(j.first-c)*j.second;
            }
            mn = min(mn,sum);
        }
        cout << mn << endl;

    }
    return 0;
}

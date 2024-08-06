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
        ll n;
        cin >> n;
        vector<char> a(n);
        for(auto &i: a) cin >> i;
        

        ll sum = 0;
        for (int i = 0; i < n-2; i++) {
            if(a[i] == a[i+2])
                sum++;
        }

        cout << n-(sum+1) << endl;
        
         

    }
    return 0;
}

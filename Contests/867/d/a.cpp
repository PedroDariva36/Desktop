#include <algorithm>
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
        
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        
        if(n&1){
            cout << -1 << endl;
            continue;
        }

        vector<int> a, b;
        for (int i = n-1; i > n>>1 ; i--) a.push_back(i);
        for (int i = (n>>1)-1; i > 0 ; i--) b.push_back(i);
        
        reverse(all(b));
        for (int i = 0; i < (n>>1)-1 ;i++) {
            if(i&1) continue;
            swap(a[i],b[i]);
        } 
        reverse(all(b));


        cout << n << " ";
        for(auto i: a) cout << i << " "; 
        cout << (n>>1) << " ";
        for(auto i: b) cout << i << " "; 
        cout << endl;
    }
    return 0;
}

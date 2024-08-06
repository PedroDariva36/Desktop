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
        vector<int> a(n);
        for(auto &i: a) cin >>i;
                    
        sort(all(a));        
        int l = 0;
        int r = n-1;
        ll sum = 0; 
        while (l < r) {
            sum += abs(a[l++] - a[r--]);
        }
        cout << sum << endl;




    }
    return 0;
}

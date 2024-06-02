#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


const long N = 2*1e5;
int n;
long t[2 * N] = {0};
 
void build() {
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i<<1] | t[i<<1|1];
}
 
long query(int l, int r) {
    long res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = (t[l++] | res);
        if (r&1) res = (t[--r] | res);
    }
    return res;
}

bool f(int g,int s){
    long k = query(0, g);
    for (long i = 1; i + g <= s; i++)
        if (query(i,i+g) != k) 
            return false;
    return true;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int s = 0;
        cin >> s;
        n = 1;
        
        while (n <= s) n <<= 1; 
        for (int i = n; i < n+s; i++) cin >> t[i];
        build();
        
        int l = 1;
        int r = s;

        while (l < r) {
            int mid = (l+r)/2;
            if (f(mid,s) == true) 
                r = mid; 
            else 
                l = mid+1; 
        }

        cout << r << endl;
    }

    return 0;
}

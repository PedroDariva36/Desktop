#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long

using namespace std;

int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, mod;
        string s; 
        cin >> n >> mod;
        
        vector<int> a(n);
        vector<int> b;
        map<int, int> m;
        for (int &i: a){
            cin >> i;
            m[i]++;
        }
        cin >> s; 
        ll k;
        stack<int> st;
        int l = 0, r = n-1;
        for (int c = 0; c < s.size(); c++) (s[c] == 'L' ? st.push(a[l++]) : st.push(a[r--])); 
        k = 1;
        while (!st.empty()) {
            k = (k* st.top())%mod;
            st.pop();
            b.push_back(k);
        }
        for (int i = n-1; i >= 0; i--) {
            cout << b[i] << " ";
        } 
        cout << endl;
    }

    return 0;
}

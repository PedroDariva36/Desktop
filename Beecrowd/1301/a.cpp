#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


const int N = 2*1e5;
int n;
long t[2*N];
 
 
void build(){
    for(int i = n-1; i > 0; i--) 
        t[i] = t[i<<1] * t[i<<1|1];
}
 
void modify(int p, long v){
    for(t[p+=n] = v; p > 1; p >>= 1) t[p >> 1] = t[p] * t[p^1]; 
}
 
long query(int l, int r){
   long asw = 1; 
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) asw *= t[l++];
        if (r&1) asw *= t[--r];
   }
    return asw; 
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int s,m;
    while (cin >> s >> m) {
        int a, b;
        char aux;
        
        n = 1;
        while (n < s) n <<= 1;
        for (int i = n; i < n+s;i++) {
            cin >> t[i];
            if (t[i] > 0) t[i] = 1;
            if (t[i] < 0) t[i] = -1;
        }
        build();

        while (m--) {
            cin >> aux;
            cin >> a >> b;
            if (aux == 'C') {
                if (b > 0) b = 1;
                if (b < 0) b = -1;     
                modify(a-1, b);
                continue;
            }
            int k = query(a-1, b);
            if (k > 0) cout << "+";
            else if (k < 0) cout << "-";
            else cout << 0;
        }
        cout << endl;

    }

    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int a[64] = {0};

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--) {
        long x, b;
        cin >> x >> b;
            
        if (x == 1) {
            a[b]++;
            continue;
        }
        bool flag = true;
        long j = 1;
        long c = 0;
        for (int i = 0; i < 64; i++) {
            bool f = j&b;
            if (f > a[i] + c){
                flag = false;
                break;
            }
            c = (a[i] + c - f)>>1;
            j <<= 1;
        } 
    
        cout << (flag? "YES":"NO") << endl;

    }

    return 0;
}

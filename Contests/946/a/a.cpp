#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> m >> n;
        
        ll sum = 0;
        while (n != 0 || m != 0) {
            if (n > 1) {         
                n -= 2;
                sum++;
                
                if (m > 6) m -= 7; 
                else m = 0;
                continue; 
            }
            if (n == 1) {
                n = 0;
                sum++;
                
                if(m > 10) m -= 11;
                else m = 0;
                continue;
            }
        
            if (m > 14) m -= 15;
            else m = 0;
            sum++; 

        }
        
        cout << sum << endl;

    }

    return 0;
}

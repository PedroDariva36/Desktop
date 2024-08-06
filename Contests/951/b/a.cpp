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
        long x,y;
        cin >> x >> y;
        

        int i = 0;
        for (i = 0; i < 32; i++) {
            if ((x&(1LL << i)) == (y&(1LL << i))) continue;
            else break; 
        } 
        cout << (1LL << i) << endl;



    }

    return 0;
}

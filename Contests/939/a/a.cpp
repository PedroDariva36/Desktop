#include <bits/stdc++.h>
#include <vector>
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
        int n,k,q,aux;
        cin >> k >> q;
        vector<int> o(q);
        set<int> s;
        for (int i = 0; i < k; i++) {
            cin >> aux;
            s.insert(aux);
        }
        for (auto &i: o) cin >> i;
            

        
        for (auto m : o) {
            int mn = *s.begin();
            if (m >= mn ) {
                cout << mn-1 << " ";
            }
            else {
                cout << m << " ";
            }
        }
        cout << endl;


    }

    return 0;
}

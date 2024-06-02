#include <bits/stdc++.h>
#include <iterator>
#include <map>
#include <set>
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
        int n;
        ll k;
        ll aux;
        cin >> n >> k;
        map<ll, ll> m;
        vector<long> a;
        for (int i = 0; i < n; i++) {
            cin >> aux;        
            m[aux]++;    
            a.push_back(aux);
        }
        while (m.size() != 0) {
            ll d = 0;
            ll f = 0;
            if (next(m.begin()) != m.end()) {
                f = next(m.begin())->first; 
            }
            else {
                f = m.begin()->first+1;
            }
            d = abs(f - m.begin()->first);
            if (k >= d*m.begin()->second) {
                m[f] += m.begin()->second;
                k -= d * m.begin()->second;
                m.erase(m.begin()->first);
            }
            else {
                break;
            }

        } 
        ll l = m.begin()->first;
        ll sum = n*m.begin()->first; 
        /*

        for (auto &i: a) {
            if (i > l) {
                sum++;
            } 
            else if (i == l) {
                continue; 
            }

            break;
        }
        */
        cout << sum << endl;
        
    }

    return 0;
}

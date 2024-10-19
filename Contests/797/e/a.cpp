#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;
int k;
bool compare(ll a, ll b){
    return a%k > b%k;
}

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n >> k;
    
        ll aux;
        deque<ll> a; 
        for(int i = 0; i < n; i++) {
            cin >> aux;
            a.pb(aux);
        }
        ll sum = 0;
        sort(all(a),compare);
        while (!a.empty()) {
            ll q = a.back(); a.pop_back();
            ll x = a.front();
            ll y = a.back();

            if((q+x)%k <= (q+y)%k){
                a.pop_front();
                sum += (q+x)/k;
            }
            else {
                a.pop_back();
                sum += (q+y)/k;
            }
        }

        cout << sum << endl;



    }
    return 0;
}

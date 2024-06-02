#include <bits/stdc++.h>
#include <map>
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
        int n, aux;
        cin >> n;
        map<int, int> m ;
        for (int i = 0; i < n; i++) {
            cin >> aux; 
            m[aux]++;
        }        
        ll sum = 0; 
        for (auto &i: m) {
            sum += i.second/3; 
        }
        cout << sum << endl;
    }

    return 0;
}

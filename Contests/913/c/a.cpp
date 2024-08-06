#include <bits/stdc++.h>
#include <cstdlib>
#include <queue>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        char aux;
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            m[aux]++;
        }
        
        int mx = 0;
        for (auto i: m) {
            mx = max(mx,i.second);
        }
        
        cout << max(n%2, ((mx*2)-n)) << endl;
        

    }
    return 0;
}

#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    //cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char aux;
        map<char, int> m;
        vector<char> og; 
        for (int i= 0; i < n; i++) {
            cin >> aux;
            og.push_back(aux);
            m[aux]++;
        }
        
        vector<char> a, b;
        for (auto i :m) a.push_back(i.first); 
        
        b = a;
        reverse(all(b));
        

        vector<char> f;
        for (auto &i: og) {
            int k = 0;
            while (b[k] != i) k++; 
            f.push_back(a[k]);
        }
        
        for (auto i: f) {
            cout << i; 
        }
        cout << endl;
    }

    return 0;
}

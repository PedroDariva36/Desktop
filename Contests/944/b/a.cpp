#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <regex>
#include <utility>
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
        string n;
        cin >> n;
        map<char, int> m;
        for (auto i: n) {
            m[i]++; 
        }

        if ((int)m.size() == 1) {
            cout << "NO" << endl;
            continue;
        }
        
        else {
            cout << "YES" << endl;
            
            int s = 0;
            int l = -1 ;
            for (int i = 0; i < n.size(); i++) {
                if (n[i] != n[s]) {
                    l = i;
                    break;
                } 
            }
            swap(n[s],n[l]);
            cout << n << endl;

        }
        


    }

    return 0;
}

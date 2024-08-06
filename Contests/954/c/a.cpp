#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
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
        int n, m;
        string s, s1;
        cin >> n >> m;
        cin >> s;
        vector<int>a(m);
        for (auto &i : a) cin >> i;
        cin >> s1;
        
        set<int> k;
        for (auto i:a) {
            k.insert(i);
        }
        a.clear();
        for (auto i:k) {
           a.pb(i); 
        }


        sort(all(s1));


        for (int i = 0; i < a.size(); i++) {
            s[a[i]-1] = s1[i];
        }
        cout << s << endl;





         

    }
    return 0;
}

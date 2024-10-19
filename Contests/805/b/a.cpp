#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
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
        string s;
        cin >> s;
        
        set<char> a;
        ll sum = 0;
        for(auto &i: s) {
            if(a.count(i) == 0 && a.size() >= 3){
                sum++;
                a.clear();
            }
                a.insert(i);
        }
        
        if(a.size() > 0) sum++; 
        cout << sum << endl;

    }
    return 0;
}

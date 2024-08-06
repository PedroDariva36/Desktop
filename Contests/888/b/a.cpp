#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
        vector<int> p,c;
        priority_queue<int,vector<int>,greater<int>> a, b;
        int aux;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            if(aux % 2 == 0){
                a.push(aux);
                p.pb(0);
            }
            else{
                b.push(aux);
                p.pb(1);
            }
        }    

        for (auto i: p) {
            if(i == 0){
                c.pb(a.top());
                a.pop();
            }
            else{
                c.pb(b.top());
                b.pop();
            }
        } 
        
        cout << (is_sorted(all(c))? "YES":"NO")<< endl;

        
         

    }
    return 0;
}

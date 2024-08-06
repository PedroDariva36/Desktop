#include <bits/stdc++.h>
#include <regex>
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
        int n, x, y;
        cin >> n >> x >> y;
        x--;
        y--;

        vector<int> a(n,1);
        
        int last = -1; 
        for (int i = x+1; i < n;i++) {
            a[i] = last;
            last *= -1;
        }
        last = -1;
        for (int i = y-1; i >= 0;i--) {
            a[i] = last;
            last *= -1;
        }
    
        for(auto i: a){
            cout << i << " ";
        }
        cout << endl;
    } 
    return 0;
}

#include <bits/stdc++.h>
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
        int n, h, m;
        cin >> n >> h >> m;
    
        int a,b;
        vector<pair<int,int>> c(n);


        for(auto &i: c){
            cin >> i.first >> i.second;
        }

        sort(all(c));      


        a = 0; b = 0;
        bool f = -1;
        for (int i = 0; i < n; i++) {
            if(c[i].first < h) continue;
            if(c[i].first == h && c[i].second < m) continue;
            a = c[i].first;
            b = c[i].second;
            break;
        }

        if(a == 0 && b == 0){
            int k = (c[0].first + 24) * 60 +c[0].second - h*60 - m;
            cout << k/60 << " " << k%60 << endl;;
            continue;
        }

        int k = (a * 60 + b - (h)*60 - m);
        cout << k/60 << " " << k%60 << endl;;



         

    }
    return 0;
}

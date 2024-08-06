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
        int n;
        cin >> n;
        string s;
        map<string, set<int>> m; 
        
        for (int i = 0; i <n ; i++) {
            cin >> s;
            m[s].insert(0);
        }
        for (int i = 0; i <n ; i++) {
            cin >> s;
            m[s].insert(1);
        }
         for (int i = 0; i <n ; i++) {
            cin >> s;
            m[s].insert(2);
        }

        vector<int> sum(3,0); 
    

        for(auto &i: m){
            if(i.second.size() == 3) continue;
            if(i.second.size() == 2){
                for (auto &j : i.second) {
                    sum[j]++;
                }
                continue;
            }
            for (auto &j : i.second) sum[j]+= 3;
        }

        for (auto i: sum) {
            cout << i << " ";
        } 
        cout << endl;
    }
    return 0;
}

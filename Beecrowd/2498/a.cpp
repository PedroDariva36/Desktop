#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n, x, aux;
    int q = 1;
    while(cin >> n >> x && n != 0){
        vector<int> memo(x+1);
        for (auto &i : memo) {
            i = 0; 
        } 
        vector<int> wt;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int g, h;
            cin >> g >> h;
            wt.push_back(g);
            v.push_back(h);
        } 

        for (long i = 0; i < n; i++)
            for (long w = x; w >= 0; w--)
                if (w >= wt[i]) 
                    memo[w] = max(memo[w],memo[w-wt[i]] + v[i]);

        cout << "Caso " << q++ << ": " << memo[x] << endl;
    }
    return 0;
}

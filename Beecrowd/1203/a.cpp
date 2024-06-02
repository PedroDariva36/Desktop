#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n,x;
    int a, b;
    while(cin >> n >> x){

        vector<int> wt(n,0);
        for (int i = 0; i < x; i++) {
            cin >> a >> b;
            wt[a-1]++;
            wt[b-1]++;
        }
        
        ll sum = 0;
        for (auto i: wt) sum += i; 

        vector<bool> res(sum+1,false);
        res[0] = true;
        for (int i = 0; i < n; i++) {
            for (int w = x; w >= 0; w--) {
                if(res[w]) res[w+wt[i]] = true; 
            } 
        }


        cout << (res[x]? "S":"N") << endl;
    }
    return 0;
}

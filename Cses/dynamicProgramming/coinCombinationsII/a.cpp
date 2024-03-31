#include <bits/stdc++.h>
#define ll long long 
#define mx 10123456


using namespace std;


const unsigned ll Mod =1e9+7;

vector<int> coins;
ll res[mx];
 
 
int main (int argc, char *argv[]){
 
    int n,x,aux;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        coins.push_back(aux);
    }

    sort(coins.rbegin(),coins.rend());
    for (int i = 1; i <= x; i++) res[i] = 0;
    
    res[0] = 1;
    for (auto &c : coins) {        
        for (int i = 1; i <= x; i++) {
            if (i-c >= 0) {
                res[i] += res[i-c];
                res[i] = res[i] % Mod;
            }
        }
    }

    cout << res[x] << endl;
   
    return 0;
}

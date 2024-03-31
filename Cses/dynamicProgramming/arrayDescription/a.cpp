#include <bits/stdc++.h>
#include <vector>
#define N 1000012 // 10^5
#define M 112
#define ll long long
#define ull unsigned ll

using namespace std;

ll memo[N][M];
vector<int> a;
int dx[] = {-1,0,1};
const ll mod = 1e9+7;


int n, m, aux;
int main (int argc, char *argv[]){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            memo[i][j] = 0;

    
    for (int i = 0; i < n; i++) {
        cin >> aux;
        a.push_back(aux);
    }
    
    if(a[n-1] == 0){
        for(int i = 0; i < m; i++)
            memo[n-1][i] = 1;
    }
    else memo[n-1][a[n-1]-1] = 1;
    

    for (int i = n-2; i >= 0; i--) {
        if(a[i] == 0){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 3; k++){
                    if (j+dx[k] > m || j+dx[k] < 0)continue;
                    memo[i][j] += memo[i+1][j+dx[k]];
                }
                memo[i][j] %= mod;
            }
        }
        else{
            for(int k = 0; k < 3; k++){
                if (a[i]-1+dx[k] > m || a[i]-1+dx[k] < 0) continue;
                memo[i][a[i]-1] = (memo[i][a[i]-1] + memo[i+1][a[i]-1+dx[k]]); 
            }
            memo[i][a[i]-1] %= mod;
        }
    }
    /*
    cout << endl;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++)
            cout << memo[i][j] << " ";
        cout << endl;
    }
    */
    ull sum = 0;    
    for(int i = 0; i < m; i++){
        sum = (sum + memo[0][i]) % mod;
    }
    cout << sum << endl; 

    return 0;
}

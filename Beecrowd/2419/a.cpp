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
    int n,m;
    cin >> n >> m;

    char a[n][m]; 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    ll asw = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') continue;
            int k = 0;

            if(i > 0 && a[i-1][j] == '#') k++;
            if(i < n-1 && a[i+1][j] == '#') k++;
            if(j > 0 && a[i][j-1] == '#') k++;
            if(j < m-1 && a[i][j+1] == '#') k++;
            if(k != 4) asw++;
        } 
    }
    cout << asw << endl;



    return 0;
}

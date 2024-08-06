#include <bits/stdc++.h>
#include <cmath>
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
        char a[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }
        
        char aux = '.';
        for (int i = 0; i < 3; i++) {
            if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != '.') {
                aux = a[i][0];
            }
        } 
        for (int i = 0; i < 3; i++) {
            if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != '.') {
                aux = a[0][i];
            }
        } 

        if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != '.'){
            aux = a[0][0];
        }  

        if(a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != '.'){
            aux = a[1][1];
        }
    
        if(aux == '.'){
            cout << "DRAW" << endl;
        }
        else{
            cout << aux << endl;
        }


    }
    return 0;
}

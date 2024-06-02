#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int x, y, z;
    cin >> x >> y >> z;

    if (x*x != y*y + z*z) {
         cout << "Nao eh retangulo!" << endl;
         return 0;
    }
    
    double aux = (double)z/2;
    aux = 3*aux*aux;
    aux /= 2;
     
    cout << "AREA = " << (ll)aux + ((z*y) >> 1) << endl;


    return 0;
}

#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

char a[4] = {'N','L','S','O'};

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n,m = 4,k;
    char aux;

    while (cin >> n && n != 0) {
        k = 0; 
        for (int i = 0; i < n; i++) {
            cin >> aux; 
            k = (aux == 'E'? (k-1 + m)%m : (k+1 + m)%m); 
        }
             
        cout << a[k]<< endl; 



        
         

    }
    return 0;
}

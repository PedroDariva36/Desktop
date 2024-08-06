#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);

        int n;
        cin >> n;
        
        ll aux;
        int a[2] = {0,0}; 
        for ( int i = 0; i < n; i++) {
            cin >> aux;
            a[aux%2]++;
        }

        if(a[0] > a[1]){
            cout << a[1] << endl;
            return 0;
        } 
        cout << a[0] << endl;

         



         

    return 0;
}

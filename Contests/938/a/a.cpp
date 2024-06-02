#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n,a,b ;
        cin >> n >> a >> b;
        
        int k = (n/2 * b) + (n%2)*a;


        cout << min(k, n*a) << endl;





    }

    return 0;
}

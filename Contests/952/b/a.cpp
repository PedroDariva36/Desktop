#include <bits/stdc++.h>
#include <regex>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        

        int pos = 1;
        int mx = 0;
        for (int i = 2; i <= n; i++) {
             int sum = 0; 
            for (int j = 1; j*i <= n; j++ ) {
                sum += j*i;
            }
        
            if(sum > mx){
                pos = i;
                mx = sum;
            }    

        }
        
        cout << pos << endl;

    }

    return 0;
}

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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
    
        for (int i = n-1; i >= k+1; i--) {
            cout << i+1 << " ";
        } 
        for (int i = 0; i < k+1; i++) {
            cout << i+1 << " ";
        }  
        cout << endl;


         

    }
    return 0;
}

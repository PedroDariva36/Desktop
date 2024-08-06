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
        char aux;
        cin >> n >> k;
        int a[26] = {0};
        for(int i = 0; i < n; i++) {
            cin >> aux;
            a[aux-'a'] = !a[aux-'a'];
        }
        
        ll sum = 0; 
        for (auto i: a) {
            sum += i; 
        }
        
        if(sum-k > 1)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;

         

    }
    return 0;
}

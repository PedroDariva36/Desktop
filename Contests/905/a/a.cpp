#include <bits/stdc++.h>
#include <vector>
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
        char aux;
        vector<int> a;
        for (int i = 0;i < 4; i++) {
            cin >> aux;
            a.pb(aux-'0');
        }
        ll sum = 0; 
        int d = 1;
        for (auto &i : a) {
            if(i == 0) i = 10; 
            sum += abs(d-i);
            sum ++;
            d = i;
        }        

        cout << sum << endl;
        
         

    }
    return 0;
}

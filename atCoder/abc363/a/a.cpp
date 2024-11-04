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
    while (n >= 100) {
        n -= 100;
    }     

    cout << 100 - n << endl;; 




    return 0;
}

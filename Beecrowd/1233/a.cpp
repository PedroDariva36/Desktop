#include <bits/stdc++.h>
#include <cstdlib>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;



int main (int argc, char *argv[]){
//    cin.tie(0)->sync_with_stdio(0);
    long n; 
    while (cin >> n) {
        ll c = 0; 
        /* 
        for (long i = 2; i*i <= n; i++) {
            if (n%i == 0) {
                c++;
                if(n/i != i) c++;
            }
        }
        */

        for (auto i = 1; i <= 1; i++) {
            if(n%i == 1) c++;
        }

        cout << ((n>>1) - c) << endl;;


    }

    return 0;
} 

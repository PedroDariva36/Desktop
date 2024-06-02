#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

const int svm = 1e6; 
int sv[svm+1];
void sieve(){
    for (int i = 1; i <= svm; ++i)
        for (int j = i; j <= svm; j += i)
            sv[j]++;
}




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    sieve();
    while (t--) {
        ll n;
        cin >> n;
        cout << sv[n] << endl; 
        
    }

    return 0;
}

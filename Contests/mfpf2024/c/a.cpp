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
    int a,b;
    cin >> a >> b;
    ll asw = 0; 
    for (int i = 1; i <= a; i++) {
        if(a%i == 0 && a/i == (b/i+1)){
            asw = i;
            break;
        }
    }
    cout << asw << endl;



    return 0;
}

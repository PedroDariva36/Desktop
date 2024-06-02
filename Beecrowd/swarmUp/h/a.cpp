#include <bits/stdc++.h>
#include <cstdlib>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


const int N = 1e6;
int n;
pair<ll,ll> t[2*N];
int v;

ll sum = 0;
void build(){

    for(int i = n-1; i > 0; i--){
        ll a = t[i<<1].first;
        ll b = t[i<<1|1].first;
        ll first = t[n].first;
        
        v = __builtin_popcount(i<<1);
        if(v == 1 && a > b){
            t[i].first = a;
            t[i].second = t[i << 1].second + t[i<<1|1].first;;
            continue;
        }
        else {
            t[i].first = min(t[i<<1].first, t[i<<1|1].first);
            t[i].second = abs(b-a)*abs(b-a) + t[i<<1].second + t[i<<1|1].second;
            continue;
        }

       if(a > first && b > first){
            t[i].first = min(t[i<<1].first, t[i<<1|1].first);
            t[i].second = abs(b-a)*abs(b-a) + t[i<<1].second + t[i<<1|1].second;
            continue;
       }
       t[i] = max(t[i<<1],t[i<<1|1]);
       t[i].second = 0;

        


    } 
}
int main (int argc, char *argv[]){
    int r;
    cin >> r;
    n = 1 << r;

    for (int i = 0; i < n; i++){ 
        cin >> t[i+n].first;
        t[i+n].second = 0;
    }

    build(); 
    cout << t[1].second << endl;

    return 0;        


}



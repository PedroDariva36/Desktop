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
        int n;
        ll k;
        cin >> n >> k;

        ll aux;
        ll asw = 0;
        map<ll,ll> m;
        for(int i = 0; i < n; i++){
            cin >> aux;
            m[aux%k]++; 
        }

        if(k == 4){
            if(m[0] >= 1) asw = 0; 
            else if(m[3] >= 1) asw = 1;
            else{ 
                int l = 4;
                for(int i = 2; i >= 1; i--){
                    if(m[i] > 0){
                        l-=i;
                        asw++;
                    }
                }
            }
        } 
        else{
            for(int i = k; i >= 1; i--){
                if(m[(i)%k] >= 1){
                    asw = ((k - i) % k); 
                    break;
                }
            }
        } 
        cout << asw << endl;;

    }
    return 0;
}

#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define f first
#define s second
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        pii b; 
        cin >> n;
        vector<pii> a(n);
        cin >> b.first >> b.second;
        for (auto &i : a) cin >> i.first >> i.second;
    
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }


        int pos = 0;
        double k, d = hypot((b.f - a[0].f), (b.s - a[0].s));  
        for (int i = 1; i < n; i++) {
            k = hypot((b.f - a[i].f), (b.s - a[i].s)); 
            if(k < d){
                d = k; 
                pos = i; 
            }
        }
        
        cout << pos+1 << endl;


     


        

         

    }
    return 0;
}

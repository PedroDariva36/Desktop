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
        int n;
        cin >> n;
        
        vector<pair<int,int>> ta,tb,tc;


        vector<ll> a(n), b(n), c(n), pfa, pfb,pfc;
        for (auto &i : a) cin >> i; 
        for (auto &i : b) cin >> i; 
        ll t = 0; 
        for (auto &i : c){
            cin >> i; 
            t+=i;
        }
        ll sum = 0; 
        for (int i = 0; i < n; i++) {
            sum += a[i];
            pfa.pb(sum);
        } 
        
        sum = 0; 
        for (int i = 0; i < n; i++) {
            sum += b[i];
            pfb.pb(sum);
        } 
        
        sum = 0; 
        for (int i = 0; i < n; i++) {
            sum += c[i];
            pfc.pb(sum);
        } 
        

        
        sum = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if((pfa[j] - pfa[i] + a[i]) >= t/3){
                    ta.pb({i,j});
                    break;
                }
            }  
        }

        sum = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if((pfb[j] - pfb[i] + b[i]) >= t/3){
                    tb.pb({i,j});
                    break;
                }
            }  
        }

        
        sum = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if((pfc[j] - pfc[i] + c[i]) >= t/3){
                    tc.pb({i,j});
                    break;
                }
            }  
        }
        
        for (int i = 0; i < ta.size(); i++) {
            for (int j = 0; j < tb.size(); j++) {
                if()
                for (int k = 0; k < tc.size(); k++) {
                                   


                } 
            } 
        }         
                


    }
    return 0;
}

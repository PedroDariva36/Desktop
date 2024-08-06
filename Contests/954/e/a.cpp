#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        map<ll,int> cl;
        map<ll,vector<ll>> m; 
        vector<ll> a; 
        
        ll k,aux;

        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> aux;
            cl[aux]++; 
        }   
        for (auto i: cl) 
        if(i.second % 2 == 1)
            m[i.first%k].pb(i.first/k);

        ll sum = 0;
        ll c = 0;
        for (auto j: m) {
            a = j.second;
            sort(all(a));
            
            if(a.size() % 2 == 1) {
                c++;
                if(a.size() == 1) continue;
                vector<ll> pref, suf; 

                aux = 0;
                for (int i = 0; i < (int)a.size()-1; i+=2){
                    pref.push_back(abs(a[i]-a[i+1])+aux);
                    aux = pref.back();
                }

                aux = 0; 
                reverse(all(a));
                for (int i = 0; i < (int)a.size()-1; i+=2) {
                    suf.push_back(abs(a[i]-a[i+1])+aux);
                    aux = suf.back();
                }
                reverse(all(suf));

                aux = min(pref.back(), suf.front());
                for (int i = 0; i < (int)pref.size()-1; i++) {
                    aux = min(aux,pref[i] + suf[i+1]); 
                }
                sum += aux;
            }
            else{
                for (int i = 0; i < a.size(); i+=2)
                    sum += abs(a[i] - a[i+1]);
            }
        }  

        cout << (c == n%2? sum:-1) << endl;


    }

    return 0;
}

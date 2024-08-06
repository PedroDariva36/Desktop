#include <bits/stdc++.h>
#include <unistd.h>
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
            

        vector<ll> a(n);
        for(auto & i: a) cin >> i;

    
        sort(all(a));
        a.erase(unique(all(a)),a.end());
    
        if(a.size() == 1){
            cout << "YES" << endl;
            continue;
        }
        bool f = 1;
        ll last = a[0];
        for (int i = 1; i < a.size(); i++) {
            if(last%5 == 0){
                if(a[i]%5 == 0){
                    a[i] += a[i]%10;
                    last +=  last % 10;;
                    if(a[i] == last) continue; 
                    else {
                        f = 0;
                        break;
                    }
                }
                else{
                    f = 0;
                    break;
                }
            }   
            else if(a[i]%5 == 0) {
                f = 0; 
                break;
            } 
            else{
                if(a[i]%2 == 1) a[i] += a[i]%10; 
                if(last%2 == 1) last += last%10; 
            
                while (a[i]%10 != last%10) {
                    a[i] += a[i]%10;
                } 
                
                if((a[i]/10)%2 != (last/10)%2){
                    f = 0;
                    break;
                }
            }
        } 

        
        cout << (f?"YES":"NO") << endl;




         

    }
    return 0;
}

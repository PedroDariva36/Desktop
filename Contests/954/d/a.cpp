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
        char aux;
        cin >> n;
        vector<int> a;
        for (int i = 0;i < n; i++) {
            cin >> aux;
            a.pb(aux-'0');
        }
        
        if(n == 2){
            cout << a[0]*10 + a[1]; 
            cout << endl;
            continue;
        }


        int mn = 999*20; 

        for(int i = 1; i < n; i++){
            vector<int> b; 
            
            int k = 0; 
            while (k < i ) {
                b.pb(a[k]);
                k++; 
            }
            b.back() = (b.back()*10)+a[i];
    

            k = i+1;
            while (k < n) {
                b.pb(a[k]);
                k++;
            }

            bool fz = false;
            int sum = 0; 

            for (auto j: b) {
                if(j == 0){
                    fz = true;
                    break;
                } 
                int v = 0; 
                for (int i= 0;i<b.size(); i++) {
                    if(b[i] == 1)v++; 
                }
                if(v == b.size()){
                    sum = 1;
                    break;
                }
                


                if(j == 1) continue;
                sum += j;
            } 
            if(fz){
                mn = 0;
                break;
            }
            if(sum == 0) continue;
            mn = min(mn, sum);

            

                        
        }
        cout << mn << endl;

    }
    return 0;
}

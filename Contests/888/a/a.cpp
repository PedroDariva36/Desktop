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
        int n, m, k ,h;
        cin >> n >> m >> k >> h;
    

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        } 
    
        ll sum = 0; 
        for (int i = 0; i < n; i++) {
            if((a[i] - h)%k == 0){
                if(abs(a[i] - h)/k > m-1) continue;
                if(abs(a[i] - h)/k == 0) continue;
                sum++; 
            }
        }
        
        cout << sum << endl;



        
         

    }
    return 0;
}

#include <bits/stdc++.h>
#include <bitset>
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
        vector<int> a(31); 
        
        cin >> n;
        for (int i = 0; i < 31; i++) {
            if(1 & (n >> i)){
                if(a[i]){
                    a[i+1] = 1;
                    a[i] = 0;
                }
                else if(i > 0){
                    if(a[i-1] == 1){
                        a[i-1] = -1;
                        a[i+1] = 1;
                    }
                    else a[i] = 1;
                }
                else if(i == 0) a[i] = 1;
            }        
        } 


        cout << a.size() << endl;
        for (auto i : a) {
            cout << i << " ";
        }
        cout << endl; 
         

    }
    return 0;
}

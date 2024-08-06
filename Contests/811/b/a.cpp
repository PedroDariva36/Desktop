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
    
        vector<int> a(n);
        map<int,int> m;

        for(auto &i: a){
            cin >> i;
            m[i]++;
        }        
    
        

        ll last = 0; 
        for (int i = 0; i < n; i++) {
            if(m[a[i]] > 1){
                last = i+1;
            } 
            m[a[i]]--;
        }

        cout << last << endl;


    }
    return 0;
}

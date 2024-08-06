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
        int n, k;
        cin >> k >> n;
        
        vector<int> a = {1, 2, 4, 7, 11, 16, 22, 29, 37};  
        set<int> s; 
        for(int i = 0; i < a.size(); i++){
            if(a[i] > n) break;
            if(s.size() == k) break;
            s.insert(a[i]);
        }
        

        for (int i = n; i>= 1; i--) {
            if((int)s.size() < k) s.insert(i);
        }
        
        for(auto &i: s){
            cout << i << " "; 
        }
        cout << endl;

    }
    return 0;
}

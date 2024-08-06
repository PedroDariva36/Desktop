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
        int n, m;
        cin >> n >> m;
        set<int> s; 
        int aux;
        for(int i = 0; i < n; i++){
            cin >> aux;
            s.insert(aux); 
        }
        {
            int i = 1; 
            while (m > 0) {
                if(s.count(i)) {
                    i++;
                    continue;
                }
                s.insert(i); 
                m -= i++;
            } 
        }
        
        if(*s.rbegin() != s.size() || m != 0){
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
         

    }
    return 0;
}

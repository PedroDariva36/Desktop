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
        
        vector<int> a(n),b;
        for (auto &i : a) 
            cin >> i;
        int pos = -1;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if(a[i] >= last){
                last = a[i];
                continue;
            }
            else{
                pos = i; 
                break;
            }
        }

        if(pos == -1){
            if(is_sorted(all(a)))
                cout << "Yes" << endl;
            else 
                cout << "No" << endl;
            continue; 
        }
        for (int i = pos; i < n; i++) b.pb(a[i]);
        for (int i = 0; i < pos; i++) b.pb(a[i]);
        
        if(is_sorted(all(b)))
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;





    }
    return 0;
}

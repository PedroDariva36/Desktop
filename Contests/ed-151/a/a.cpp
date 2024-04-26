#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        

        if (x != 1) {
            cout << "YES" << endl;
            cout << n << endl;
            for(int i = 0; i < n; i++)
                cout << 1 << " ";
            cout << endl;
            continue;
        }
        
        set<int> a;
        for (int i = 2; i <= k; i++) {
            if (i != x) a.insert(i); 
        }
            
        if (a.size() == 0) {
            cout << "NO" << endl;
            continue;
        }


        if (a.size() == 1) {
            int l = *(a.begin()); 
            if (n%l == 0) {
                cout << "YES" << endl;
                cout << n/l << endl;
                for (int i = 0; i < n/l; i++) {
                    cout << l << " "; 
                } 
                cout << endl;
            } 

            else cout << "NO" << endl;
            continue;

        } 
        
        vector<int> b;
        while (n > 0) {
            if (n%2 == 1) {
                n-=3;
                b.push_back(3);
            } 
            else {
                n-=2;
                b.push_back(2);
            }
        }
            
        cout << "YES" << endl;
        cout << b.size() << endl;
        for (auto i : b) {
            cout << i << " "; 
        }
        cout << endl;



   }

    return 0;
}

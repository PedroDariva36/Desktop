#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <vector>
#define pii pair<int,int>
#define f first
#define s second


using namespace std;
int n, x, y, z;
int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        vector<int> a;
        while (n--) {
            cin >> x >> y;
            for (int i = x; i <= y; i++) a.push_back(i);
        }
        cin >> z;
        sort(a.begin(),a.end());
        //for (auto &i : a) cout << i << " ";
        //cout << endl;
        
    
        auto it = find(a.begin(),a.end(), z);
        if (it == a.end()){
            cout << z << " not found"<< endl;
            continue;
        }
        int i;
        for (i = it - a.begin(); i < a.size(); i++) {
            if (a[i] != z) break;
        }
        x = (it - a.begin());
      
        cout << z << " found from " << x << " to " << i-1 << endl;


    }
    return 0;
}

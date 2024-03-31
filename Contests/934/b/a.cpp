#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        set<int> s;
        vector<int> a(2*n);
        for (auto &i : a) {
            cin >> i; 
            s.insert(i);
        }
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[a[i]]++;
        }
        
        int d = 0;
        set<int> l;
        vector<int> b,c,fb,fc; 
        for (auto &i : m){
            if(i.second > 1){
                l.insert(i.first);
            } 
            else {
                c.push_back(i.first);
                b.push_back(i.first);
            }
            s.erase(i.first);

        }
        
       if(s.size() != n){
            for (auto i : s) {
                fb.push_back(i);
                fb.push_back(i);
            }
            for (auto i : l) {
                fc.push_back(i);
                fc.push_back(i);
            }
        }
        
       for (int i : b) {
            fb.push_back(i); 
       }
        
        for (int i : c) {
            fc.push_back(i); 
       }

        for (int i = 0; i < 2*k; i++) {
            cout << fc[i] << " "; 
        }
        cout << endl;
        
        for (int i = 0; i < 2*k; i++) {
            cout << fb[i] << " "; 
        }

       cout << endl;
         

    }

    return 0;
}

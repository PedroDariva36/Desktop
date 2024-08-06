#include <algorithm>
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
        string a;
        cin >> a;

        map<char, vector<int>> m;

        char first = a[0];
        char last = a.back();    
        for (int i = 0; i < a.size(); i++)  
            m[a[i]].push_back(i);
       

        vector<int> path; 
        int op = (first > last? -1 : 1);
        for (char i = first; i != last + op ; i += op) {
            for (auto j: m[i]) path.pb(j);
        }
         

        cout << abs(first-last) << " " << path.size() << endl;
        for (auto i: path) cout << i+1 << " ";
        cout << endl;



        



         

         

    }
    return 0;
}

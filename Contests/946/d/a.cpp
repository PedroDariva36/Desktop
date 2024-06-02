#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        char aux;
        cin >> n;
        vector<char> a;
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            cin >> aux; 
            a.push_back(aux);
            m[aux]++; 
        }
        int f = false;
         
        if (a.size() == 2 && m.size() == 2) f = true;             
        int k = min(m['N'], m['S']);
        int l = min(m['W'], m['E']);
        

        //if (m['N'] + m['S'] > 3) f = true;
        //if (m['W'] + m['E'] > 3) f = true;
        

        m['N'] -= k;
        m['S'] -= k;
        m['W'] -= l; 
        m['E'] -= l; 
        
        if (f || m['N']%2 == 1 || m['S']%2 == 1 || m['W']%2 == 1 || m['E']%2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        
        for (auto &i: a) {
            


        } 

        



    }

    return 0;
}

#include <bits/stdc++.h>
#include <bitset>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;
    
map<char, int> m;
const ll N = 1e6;
const ll B = (1ll << 51) -1;

ll a[4][N] = {0};

int main (int argc, char *argv[]){
    m['A'] = 0;
    m['C'] = 1;
    m['G'] = 2;
    m['T'] = 3;

    cin.tie(0)->sync_with_stdio(0);
    int n, p; 
    cin >> n >> p;
    char aux;
    string s; 

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aux;
            a[m[aux]][j] |= 1ll << i;
        } 
    } 
    cin >> s;
    

    ll old = B;
    ll next;
    ll current;
    vector<char> b;
    for (int i = 0; i < n; i++) {
        next = a[m[s[i]]][i];  
        if (old == 0) {
            if (next == 0) {
                cout << s[i] << " -1" << endl;
                continue; 
            }

            old = next;
            b.pb(s[i]);
            continue;
        }


        current = (old&next);
        if (current == 0) {
            for (auto c: b) cout << c ;
            b.clear();
            for (int j = 0; j < 50; j++) {
                if (old&(1ll << j)) {
                    cout << " " << j+1 << endl;
                    break;
                } 
            }
            i--;
            old = 0;
            continue;
        }
        old = current;
        b.pb(s[i]);

    }

    if (b.size() > 0) {
        for (auto c: b) cout << c ;
        for (int j = 0; j < 50; j++) {
            if (old&(1ll << j)) {
                cout << " " << (1ll << j) << endl;
                break;
            } 
        } 
    }   



    /*    
    cout << endl; 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            bing = a[i][j];
            cout << bing << " ";
        }
        cout << endl;
    } 
    */



    return 0;
}

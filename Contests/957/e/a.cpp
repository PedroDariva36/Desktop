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
        int n;
        cin >> n;
        
        vector<int> b; 
        ll aux = n;
        while (aux != 0) {
            b.pb(aux%10);
            aux /= 10;
        }
        reverse(all(b));



        vector<pair<int,int>> c;
        for (int i = 1; i <= 10000; i++)  {
            for (int j = i-1; j >= i - 5; j--) {
                if (i - j <= 0)continue;
                aux = n*i - j;
                

                vector<int> a;
                while (aux != 0) {
                    a.pb(aux%10);
                    aux /= 10;
                }
            
                reverse(all(a));
                /*
                for (auto i: a) {
                    cout << i << " ";
                }
                cout << i << endl;
                */

                bool f = 1; 
                for (int k = 0; k < a.size(); k += b.size()) {
                    for (int l = 0; l < b.size(); l++) {
                        if(i + l >= a.size()) break; 
                        if(a[i+l] != b[l]){
                            f = 0;
                            break;
                        }  
                    } 
                    if(f) c.pb({i, j});
                }
            }
        } 
        for (auto i: c) {
            cout << i.first << " " << i.second << endl;
        }

    }
    return 0;
}

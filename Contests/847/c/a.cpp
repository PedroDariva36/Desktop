#include <bits/stdc++.h>
#include <deque>
#include <map>
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
        vector<deque<int>> a(n,deque<int>()); 
        
        int aux = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                cin >> aux;
                a[i].pb(aux);
            }
        }

        vector<int> c;
        
        map<int, int> b;

        for (int j = 0; j < n; j++){ 
            for (int i = 0; i < n; i++){ 
                if(!a[i].empty()) b[a[i].front()]++;
            }
            
            int pos = b.begin()->first;
            int mx = b.begin()->second;
            for (auto i: b) {
                if(i.second >= mx){
                    mx = i.second;
                    pos = i.first;
                }
            }
            c.pb(pos);
            b[pos] = 0;
            

            for (int i = 0; i < n; i++) 
                if(!a[i].empty() && a[i].front() == pos) a[i].pop_front();
        }


        for (auto i: c) {
            cout << i <<  " ";
        }
        cout << endl;

            

     


         

    }
    return 0;
}

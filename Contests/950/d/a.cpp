#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back



using namespace std;

int search(vector<ll> &b){
    for (int i = 1; i < b.size(); i++) {
        if(b[i] < b[i-1]){
            return b[i-1];

        }
    } 
    return -1;
}

int main (int argc, char *argv[]){
    //cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n-1);

        for (auto &i : a) 
            cin >> i;

        for (int i = 0; i < n-1; i++) 
            b[i] = gcd(a[i],a[i+1]);

        for (auto &i : b) 
            cout << i << " ";
        cout << endl; 

        int pos = search(b);
        if(pos == -1){
            cout << "YES" << endl;
            continue;
        }

        bool f = 0;
        for (int i = -1; i < 2; i++) {
            if(pos+i < 0 || pos+i >= a.size()) 
                continue;

            cout << i+pos << endl;

            vector<ll> c, d;
            for (int j = 0; j < (int)a.size(); j++) {
                if(j == pos + i) continue;
                c.pb(a[j]);
            }  

            for (int j = 0; j < (int)c.size()-1; j++) 
                d.pb(gcd(c[j],c[j+1]));
            
            
            for (auto &i : d) 
                cout << i << " ";
            cout << endl;
            

            if(search(d) == -1) f = 1;
        } 

        cout << (f? "YES": "NO") << endl; 






    } 


    return 0;
}

#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    
    set<char> c, v;

    v.insert('a');
    c.insert('b');     
    c.insert('c');     
    c.insert('d');     
    v.insert('e');


    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s,final;
        cin >> n >> s; 


        for (int i = 0; i < (int)s.size(); i++) {
            if( i < ((int)s.size() -1) && c.count(s[i]) && v.count(s[i+1])){
                final.pb(s[i]);
                final.pb(s[i+1]);
                final.pb('.'); 
                i+=1;
            }
            else {
                if(final.size() > 0) final.pop_back();
                final.pb(s[i]);
                final.pb('.');
                continue;
            } 
        } 
        final.pop_back();
        cout << final << endl;
         

    }
    return 0;
}

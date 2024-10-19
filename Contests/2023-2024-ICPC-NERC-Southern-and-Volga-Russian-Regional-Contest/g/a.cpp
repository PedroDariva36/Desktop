#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <unordered_map>
#include <unordered_set>
#include <vector>
template<typename T, typename comp_function = std::less<T>> using indexed_set = class __gnu_pbds::tree<T, __gnu_pbds::null_type, comp_function, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


bool solve(string s){
    ll a = 0, b = 0;
    for(int i = 0; i < s.size(); i++){
        if(i >= (s.size()/2)){
            a+= s[i]-'0';
        }
        else b+= s[i]-'0';
    }
    return a == b;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
     
    map<ll,map<ll,ll>> g;
    vector<string> a; 
    string s;
    
    
    for(int i = 0; i < n; i++){
        cin >> s;
        ll sum = 0;
        for(auto &c: s){
            sum += (c-'0');
        }
        g[s.size()][sum]++;
        a.pb(s);
    } 


    ll sum = 0;
    for(int i = 0; i < n; i++){
        string s = a[i];
        for(int j = 1; j <= s.size(); j++){
            if(j%2 != s.size()%2) continue;
            //cout << s.size() << " " << j << endl;
            
            ll k = (s.size()+j)/2; 
            ll l = 0;
            ll r = 0;
            for(int c = 0; c < s.size(); c++){
               if(c < k) 
                    l += s[c] - '0'; 
               else 
                    r += s[c] - '0';
            }
            //cout << r << " " << l << endl;
            sum += g[j][l-r];

            if(s.size() != j){
                reverse(all(s)); 
                l = 0;
                r = 0;
                for(int c = 0; c < s.size(); c++){
                    if(c < k) 
                        l += s[c] - '0'; 
                    else 
                        r += s[c] - '0';
                }
                //cout << r << " " << l  << endl;
                sum += g[j][l-r];
                reverse(all(s));
            }
        }
    } 
    cout << sum << endl;



    return 0;
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}};
template<typename T, typename comp_function = std::less<T>> using indexed_set = class __gnu_pbds::tree<T, __gnu_pbds::null_type, comp_function, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename K, typename V> using hash_map = std::unordered_map<K, V, custom_hash>;
template<typename T> using hash_set = std::unordered_set<T, custom_hash>;
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> m(n,0);
        priority_queue<int, vector<int>, greater<int>> p2, p1;


        int c2 = 0;
        int c1 = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 2) {
                p2.push(i);
                c2++;
            }
            if(a[i] == 1) {
                p1.push(i); 
                c1++; 
            }
        } 
        vector<pair<int,int>> asw;
            
        for(int i = n-1; i >= 0; i--){
            if(c2 > 0){
                if(a[i] == 2){
                    c2--; 
                    m[i] = 1;
                    continue;
                } 
    
                if(a[i] == 1){
                    while (m[p2.top()]) p2.pop();                    
                    int n2 = p2.top(); p2.pop(); 
                    swap(a[n2], a[i]);  
                    asw.pb({n2+1, i+1}); 
                    p1.push(n2); 
                    c2--; 
                    m[i] = 1;
                    continue;
                }
                if(a[i] == 0){
                    while (m[p1.top()]) p1.pop();                    
                    int n1 = p1.top(); p1.pop(); 
                    swap(a[n1], a[i]);  
                    asw.pb({n1+1, i+1}); 
                    p1.push(i); 
                    i++;
                    continue;
                }
            }
            else if(c1 > 0){
                if(a[i] == 1){
                    c1--; 
                    m[i] = 1;
                    continue;
                } 
                else{
                    while (m[p1.top()]) p1.pop();                    
                    int n1 = p1.top(); p1.pop(); 
                    swap(a[n1], a[i]);  
                    asw.pb({n1+1, i+1}); 
                    p1.push(i); 
                    i++;
                    continue;
                }
            }
            else break;
        }   

        cout << asw.size() << endl;
        for(auto &i: asw){
            cout << i.first << " " << i.second << endl;;
        }    



    

    }

    return 0;
}

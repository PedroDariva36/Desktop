#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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



int main() {
    int n;	
    cin >> n;
	vector<array<int,3>> a(n);
    vector<int> b(n);


    for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		a[i][2] = i;  	
    }
	sort(a.begin(), a.end());

	int c = 0, last = 0;

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;  
	
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            last++;
            q.push({a[i][1], last});
            b[a[i][2]] = last;
        } 
        else {
            auto aux = q.top();
			if (aux.first < a[i][0]) {
				q.pop();
				q.push({a[i][1], aux.second});
			    b[a[i][2]] = aux.second;
			}

			else {
				last++;
				q.push({a[i][1], last});
				b[a[i][2]] = last;
			}
		}
        c = max(c,(int)q.size());

	}
     c = max(c,(int)q.size()); 


	cout << c << endl;
    for(auto &i: b) cout << i << " ";
    cout << endl;
    
}

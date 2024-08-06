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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
    
        vector<ll> a(n),b(n),pos,neg;
        for (auto &i :a) cin >> i;
        for (auto &i :b) cin >> i;

        priority_queue<ll,vector<ll>,greater<ll>> q;

        multiset<ll> s;

        ll k;
        for (int i = 0; i < n; i++) {
            k = b[i] - a[i];
            if(k >= 0)
                q.push(k); 
            else 
                s.insert(k);
        } 
        ll sum = 0; 


        while (!q.empty()) {
            if(s.empty() && q.size() > 1){
                q.pop();
                q.pop();
                sum++;
                continue;
            }
            if(s.empty() && q.size() <= 1) break;


            auto l = s.upper_bound(-q.top());
            if(l != s.end()){ 
                if(q.top() + *l > 0){
                    sum++;
                    q.pop();
                    s.erase(l);
                } 
            }
            if(l == s.end()){
                if(q.size() <= 1) break; 
                else {
                    q.pop();
                    q.pop();
                    sum++;
                }
            }

        }

        cout << sum << endl;;

         

    }
    return 0;
}

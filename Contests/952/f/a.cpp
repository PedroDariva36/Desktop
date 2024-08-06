#include <bits/stdc++.h>
#include <queue>
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
        long n,h;
        cin >> h >> n;
            
        vector<ll> a(n),c(n);

        for (auto &i: a) {
            cin >> i; 
        }
        for (auto &i: c) {
            cin >> i; 
        }

        priority_queue<pair<ll,int>> q;
        ll turn = 0;
        while (h > 0) {
            if (q.empty()) {
                ll sum = 0;
                for (auto i: a) {
                    sum += i;
                }

                h -= sum;
                turn++; 
                for (int i = 0; i < n; i++) {
                    q.push({-(c[i]+turn), i});
                }
                
                continue;
            } 

            turn = max(turn, abs(q.top().first));

            int pos = q.top().second;  q.pop();
            h -= a[pos];            
            q.push({-(turn + c[pos]),pos});

        }
        cout << turn << endl;

    }

    return 0;
}

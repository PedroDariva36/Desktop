#include <bits/stdc++.h>
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
        int n;
        cin >> n;
        vector<long> a(n);
        map<long, priority_queue<long>> m;

        for (auto &i : a) {
            cin >> i;
            m[i>>2].push(-i);
        } 
        
        for (auto &i: a) {
            cout <<  -m[i>>2].top() << " ";
            m[i>>2].pop();
        }
        cout << endl;



    }

    return 0;
}

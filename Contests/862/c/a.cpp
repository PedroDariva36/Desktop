#include <bits/stdc++.h>
#include <map>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;



void solve(int n, map<int, int> &m){
    for (int i = 2; i*i <= n; i++) {
        while (n%i == 0) {
            n /= i;   
            m[i]++;
        }
    }
    if(n!=1) m[n]++;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int,int> m;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : a) {
            solve(i,m); 
        }
        ll sum = 0;
        ll rest = 0; 
        for (auto &i : m) {
            sum += i.second/2;
            i.second = i.second % 2;
            rest += i.second; 
        }

        sum += rest/3;

        cout << sum << endl;
    }

    return 0;
}

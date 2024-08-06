#include <bits/stdc++.h>
#include <iterator>
#include <queue>
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
        ll sum = 0;
        ll aux = 0;
        priority_queue<ll> q; 
        for (int i = 0; i < n; i++) {
            cin >> aux;            
            if(aux == 0){
                if(!q.empty()){
                    sum += q.top();
                    q.pop();
                }
            }
            else q.push(aux);
        }
        cout << sum << endl; 


    }
    return 0;
}

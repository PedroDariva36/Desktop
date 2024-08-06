#include <bits/stdc++.h>
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
        int a, b, c;
        cin >> a >> b >> c;
        
        priority_queue<int> q;
        q.push(-a);
        q.push(-b);
        q.push(-c);
        
        int k = 5;
        while (k--) {
            int aux = -q.top(); q.pop();
            aux++;
            q.push(-aux);
        }
        
        ll d = 1;
        while (!q.empty()) { 
            d *= -q.top();
            q.pop();
        }

            
        cout << d << endl; 


         

    }
    return 0;
}

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
    int n; 
    int a ,b ,c;
    while (cin >> n) {
    
        queue<pair<int,int>> q;
        while (n--) {
            cin >> a >> b >> c; 
            q.push({
                ((a*60 + b)*60),
                (c*60)
            });
        }

        ll sum = 0;
        ll k = 0; 
        q.pop();
        while (!q.empty()) {
            tie(a,b) = q.front(); 
            //a = -a;
            //b = -b;
            
            if(k == 0){
                q.pop();
                k = (a/1800 + 2)*1800;
                continue;
            }

            if(k > a+b){
                q.pop();
                sum++;
                continue;
            }
            else if(k >= a) q.pop(); 

            k+= 1800;
        }

        cout << sum << endl;
    }
    return 0;
}

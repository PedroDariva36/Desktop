#include <bits/stdc++.h>
#include <vector>
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
        vector<char> a(n);
        
        for(auto &i: a){
            cin >> i;
        }
        ll sum = 0;
        priority_queue<int> q; 
        for (int i = 0; i < n; i++) {
            if(a[i] == 'R'){
                sum += (n-1 - i);
                if(i > (n-1 - i)){
                    q.push(i - (n-1 - i));
                }
            }
            else {
                sum += i;
                if(i < (n-1 - i)){
                    q.push((n-1 - i) - i);
                }
            }
        }

         
        while (n--) {
            if(!q.empty()){
                sum += q.top();
                q.pop();
            } 
            cout << sum << " ";
        }
        cout << endl;


        



    }
    return 0;
}

#include <algorithm>
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
        vector<pair<int,int>> a(n); 
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        } 
        sort(all(a));
    
        vector<ll> prefix(n);
        vector<ll> asw(n,0);
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i].first;
            prefix[i] = sum;
        }
            
        asw[a[n-1].second] = n-1;
        for(int i = n-2; i >= 0; i--){
            sum = prefix[i];
            if(sum >= a[i+1].first){
                asw[a[i].second] = asw[a[i+1].second];
            }
            else asw[a[i].second] = i;
        }
    
        
        for(int i = 0; i < n; i++){
            cout << asw[i] << " ";
        }
        cout << endl;


    }

    return 0;
}

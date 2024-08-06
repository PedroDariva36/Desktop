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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
        
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;
    int last = 0;
    ll sum = 0;
    for (int i = n-1; i >= 0; i--) {
        
        a[i] = (a[i] + last + 10)%10;
        if(a[i] == b[i]) continue; 
        
        int k = 0;
        while ((a[i] + k + 10)%10 != b[i]) k++;        
        int l = (10 - k)%10; 
       
    
        if(k > l) {
            last -= l;
            sum += l;
        }
        else  {
            last += k;
            sum += k;
        }
    }

    cout << sum << endl;         
         

    return 0;
}

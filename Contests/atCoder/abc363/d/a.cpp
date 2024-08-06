#include <algorithm>
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
    //cin.tie(0)->sync_with_stdio(0);
    
    ull n;
    cin >> n;

    vector<ull> a;
    a.push_back(10);
    a.pb(9);
    { 
        int i = 2;
        while (a.back() < n) {
            a.pb(9*a[i-2]);
            cout << a.back() << endl;
            i++;
        }
        a.pop_back();
    }   
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl; 
    }
   
    string s;
    int i = a.size()-1;
    
    n-= a[i];
    while (i >= 0) {
        if(a[i] > n){
            ll aux = a[i]/n;
            cout << aux;
            n -= a[i]*aux;

        }
        else{
            cout << n/a[i]; 
            n/=a[i];
            i-=2;
        }
    } 
    /* 
    cout << s;
    reverse(all(s));
    cout << s << endl;
    */
    return 0;
}

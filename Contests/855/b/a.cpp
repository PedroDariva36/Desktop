#include <bits/stdc++.h>
#include <cctype>
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
        ll n, k;
        cin >> n >> k;
        
        vector<char> a(n);
        for(auto &i: a) cin >> i;    

        map<char,int> up, lo; 
        for (auto i:a) {
            if('A' <= i && i <= 'Z')up[i]++;
            else lo[i]++;
        }
        ll sum = 0;
        ll ksum = 0;
        for (char i = 'A'; i <= 'Z'; i++) {
            sum += min(up[i], lo[tolower(i)]); 
            ksum += abs(up[i] - lo[tolower(i)])/2;
        } 
        
        

        cout << sum  +  min(k,ksum)<< endl;
         


         

    }
    return 0;
}

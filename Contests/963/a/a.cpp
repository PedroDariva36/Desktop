#include <bits/stdc++.h>
#include <ios>
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
        string s;
        cin >> n;
        cin >> s; 
        
        map<char,int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        ll sum = 0;
        for (auto i: m) {
            if(i.first == '?') continue;
        
            if(i.second > n){
                sum+= n; 
            }
            else sum += i.second;

        } 

        
 
        cout << sum << endl;



         

    }
    return 0;
}

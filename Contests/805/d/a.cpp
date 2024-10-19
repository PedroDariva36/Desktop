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
        string s, k;
        int p;
        cin >> s >> p;
        k = s;
        sort(rall(k));

        map<char,int> m;

        ll sum = 0; 
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] -'a' + 1;
        }
       
       
        for (int i = 0; i < k.size(); i++) {
            if(p < sum){
                m[k[i]]++; 
                sum -= (k[i]-'a')+1; 
            }
            else break;
        }

        for (auto i: s) {
            if(m[i] >= 1){
                m[i]--;
                continue;
            }
            cout << i;
        } 
        cout << endl;
    


    }
    return 0;
}

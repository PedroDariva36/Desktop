#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


int solve(char a, char b, bool d){
    int cw = 0;
    int acw = 0;
    if (!d) {
        if (b > a) {
            cw = b-a;
            acw = 26 - cw;
        }
        else {
            acw = (a-b + 26)%26;
            cw = 26 - acw;
        }
    }
    else {
        if (b > a) {
            acw = b-a;
            cw = 26 - acw; 
        }
        else {
            cw = (a-b + 26)%26;
            acw = 26 - cw;
        } 
    }
    return cw;
    return (d? acw : cw);
}


int k[4];
int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
   
    
    string s; 
    while (cin >> s) {
        if (s[0] == '*') break;
        vector<int> a(s.size());
        vector<int> b(s.size());
            
        k[0] = solve('a', s[0],0);
        k[1] = solve('a', s[0], 1);
        int l = 0; 

        if (k[0] < k[1]) l = 1;
        a[0] = k[l];
        b[0] = l; 
        

        for (int i = 1; i < s.size(); i++) {
            a[i] = min(
                        solve(s[i-1], s[i],0)
                        solve(s[i-1], s[i], 1)
                    min(
                        solve('a', s[i],0),
                        solve('a', s[i], 1)
                    )
            );          
        }
        




        for (auto i: a) {
            cout << i << " "; 
        }
        cout << endl;


        ll sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += a[i]; 
        }

        

        //cout << endl;
        cout << sum << endl;

    }

    return 0;
}

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


vector<int> s(1e6+1,0);
int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n, aux;
    cin >> n;
    
    
    vector<int> a(n);
    for (auto &i: a) {
        cin >> i;
        s[i]++;
    }
    
    int x = *max_element(all(a));
    for (int i = x; i > 0; i--) {
        int c = 0;
        for(int j = i; j <= x; j += i) c += s[j];
    
        if (c > 1) {
            cout << i << endl;
            break;
        }

    }
     

      
    return 0;
}

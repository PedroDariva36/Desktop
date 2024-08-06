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
        vector<char> a(n),b(n); 
        for (auto &i : a) {
            cin >> i;
            if(i == 'G') i = 'B';
        }

        for (auto &i : b) {
            cin >> i;
            if(i == 'G') i = 'B';
        }
        
        bool f = 1; 
        for(int i = 0; i <n; i++){
            if(a[i] != b[i]) f = 0;        
        }
        cout << (f?"YES":"NO") << endl;
    



    }
    return 0;
}

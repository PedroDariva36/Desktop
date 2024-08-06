#include <bits/stdc++.h>
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
    
        int p1 = 0, p2 = 0, p3 = 0; 
        vector<int> a(n);
        for(auto &i: a) cin >> i; 
    
        for (int i = 0; i < n; i++) {
            if(a[i] != i+1 && a[i] != n-i)
                p3++;
            else if(a[i] != i+1) 
                p1++;
            else if(a[i] != n-i)
                p2++;
        }
        



        if(p1 + p3 <= p2){
            cout << "First" << endl;
        }
        else if(p2 + p3 < p1)
            cout << "Second" << endl;
        else 
            cout << "Tie" << endl;





    }
    return 0;
}

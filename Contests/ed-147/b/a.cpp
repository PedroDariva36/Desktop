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
        vector<int> a(n),b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;        
        
       
        int first = -1;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if(a[i] != b[i]){
                if(first == -1) first = i;
                last = i;
            }
        }
        
        for(int i = first-1; i >= 0; i--){
            if (b[i] <= b[first]) first = i;
            else break;
        }
        for(int i = last; i < n; i++){
            if (b[last] <= b[i]) last = i;
            else break;
        }

        cout << first+1 << " " << last+1 << endl;     

        

        



        
         

    }
    return 0;
}

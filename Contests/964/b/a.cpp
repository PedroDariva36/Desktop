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
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        ll sum = 0; 
    

        for (int i = 0;i < 2; i++) {
            int c1 = 0, c2 = 0; 
    
            if(a1 > b1) c1++;
            if(a1 < b1) c2++;
            if(a2 > b2) c1++;
            if(a2 < b2) c2++;
            swap(b1,b2);
            if(c1 > c2) sum++;
        }
    
        swap(a1,a2); 
        for (int i = 0;i < 2; i++) {
            int c1 = 0, c2 = 0; 
    
            if(a1 > b1) c1++;
            if(a1 < b1) c2++;
            if(a2 > b2) c1++;
            if(a2 < b2) c2++;
            swap(b1,b2);
            if(c1 > c2) sum++;
        }


    
        cout << sum << endl;

    }
    return 0;
}

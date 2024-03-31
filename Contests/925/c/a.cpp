#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;


int main (int argc, char *argv[]){
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long>a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int lp = 0, rp = n-1;
        long lv = a[0], rv = a[n-1];
        int lq = 0, rq = 0;
        
        while (lp <= rp) {
            if(a[lp] == a[lp+1]){
                lp++;
                lq++;
                continue;
            }
            if(a[rp] == a[rp-1]){
                rp--;
                rq++;
                continue;
            }
            break;
        }
        
        if(lv == rv){
            if((n-(lq+rq)-2) < 0)
                cout << 0 << endl;
            else cout << n-(lq+rq)-2 << endl;
        }
        else {
            if(lq >= rq){
                cout << n-lq-1 << endl;
            }
            else {
                cout << n-rq-1 << endl;
            }
        }


            




    }


    return 0;
}

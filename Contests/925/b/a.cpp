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
        long k;
        ll sum = 0,total = 0;

        vector<long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum +=a[i];
        }
        k = sum/n;
        

        bool f = true;
        for (auto &i : a) {
            if(i >= k) total += i - k;
            else {
                if(total < k - i) {
                    f = false;
                    break;
                }
                total -= k-i;
            }
        }
        
        if(f){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
         

        
        

        

    }


    return 0;
}

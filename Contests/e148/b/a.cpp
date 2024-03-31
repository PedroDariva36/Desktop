#include <algorithm>
#include <bits/stdc++.h>
#include <vector>


using namespace std;


int main (int argc, char *argv[]){
    
    int t;
    cin >> t;
    while (t--) {
        vector<long> a;
        long n, k, aux;

        cin >> n >> k;
        
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back(aux);
        }
        
        sort(a.begin(),a.end());
        
        cout << endl;
        for (auto i : a) {
            cout << i << " ";
        }
        cout << endl;

        long start = 0;
        long end = a.size();
        long l = k;

        
        while (k--){
            if (a[start]+a[start+1] <= a[end]) end--;
            else start += 2;
        }
        long long sum = 0;
        for (int i = start; i < end; i++) sum += a[i];
        
        start = 0;
        end = a.size();
        while (l--){
            if (a[start]+a[start+1] > a[end]) end--;
            else start += 2;
        }
        long long sum2 = 0;
        for (int i = start; i < end; i++) sum2 += a[i];
        




        cout << max(sum,sum2) << endl;
    }

    return 0;
}

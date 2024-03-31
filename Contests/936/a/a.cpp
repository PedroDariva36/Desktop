#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long aux;
        cin >> n;
        vector<long> a;
        for (int i = 0; i < n; i++) {
            cin >> aux; 
            a.push_back(aux); 
        }
        sort(a.begin(), a.end());
        ll sum = 0;
        int med = n/2;
        if (n %2 == 0) {
            med = n/2-1;
        }
        for (int i = med; i < n; i++) {
            if (a[i] != a[med]) {
                break;
            }
            sum++;
        } 
        cout << sum << endl;
    }

    return 0;
}

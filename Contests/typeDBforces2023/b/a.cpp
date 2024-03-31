#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        long n; 
        cin >> n;

        map<long, long> m;
        for (long x = 2; x*x <= n; x++) {
            while (n%x == 0) {
                m[x]++;
                n /= x;
            }
        }
        if (n > 1) m[n]++;        
        
        ll sum = 0;
        ll l;
        long mn;

        while (m.size() > 0) {
            mn = 1e8;
            l = 1;
            vector<int> a;
            for (auto &i: m){ 
                mn = min(mn, i.second);
                l *= i.first;
                a.push_back(i.first);
            }
            for (auto &i: a) {
                if (m[i] - mn == 0) 
                    m.erase(i);
                else
                m[i] -= mn;
            }
            sum += l * mn;
        }
        cout << sum << endl;

    }


    return 0;
}

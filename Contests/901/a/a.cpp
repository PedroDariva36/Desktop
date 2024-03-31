#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;



int main (int argc, char *argv[])
{
    int t;
    cin >> t;
    while (t--) {
        long a, b ,n;
        cin >> a >> b >> n;
        vector<long> c(n);
        for (auto &i : c) {
            cin >> i; 
        }
        ll sum = b;
        for (auto i : c) {
            sum += min(a-1 , i);
        }
        cout << sum << endl;


    }
    return 0;
}

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
        ll k;
        cin >> n >> k;
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            a.push_back(i);
        }        
            

        for (int i = 0; i < n-1; i++) {
            swap(a[i],a[i+1]);
            ll sum =0;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
                sum += abs(a[i] - (i+1));
            }
            cout << " = " << sum << endl;

        }
        for (int i = 0; i < n-1; i++) {
            swap(a[i],a[i+1]);
            ll sum =0;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
                sum += abs(a[i] - (i+1));
            }
            cout << " = " << sum << endl;

        }
        for (int i = 0; i < n-1; i++) {
            swap(a[i],a[i+1]);
            ll sum =0;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
                sum += abs(a[i] - (i+1));
            }
            cout << " = " << sum << endl;

        }



    }
    return 0;
}

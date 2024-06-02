#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

int m1[105];
int m2[105];



using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        
        cin >> b >> a;

        int n = a.size();
        ll sum = 0;
        ll r1 = 0;
        ll r2 = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) m1[j] = a[i] * b[j];
            
            swap(a[i],b[i]);

            for (int j = 0; j < n; j++) m2[j] = a[i] * b[j];
    
                
            r1 = 0;
            r2 = 0;

            for (int k = 0; k < n; k++){
                if(m2[k] == m1[k])continue; 
                if (m2[k] > m1[k]) r2 += k;
                else r1 += k;
            }
            if (r2 > r1) continue;
            swap(a[i],b[i]);
        }
        cout << b << endl;
        cout << a << endl;

    }

    return 0;
}

#include <bits/stdc++.h>
#include <iomanip>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pii pair<int,int>


using namespace std;

double calcDist(pii a, pii b, pii c){
    double k = (b.second - a.second)*c.first - (b.first - a.first)*c.second + b.first * a.second - b.second*a.first;
    return k/sqrt((b.second - a.second) * (b.second - a.second) + (b.first - a.first)*(b.first - a.first));
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n && n != 0) {
        
        vector<pii> a(n);
        for (auto &i : a) cin >> i.first >> i.second;
        
        double mn = 1e6;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                
                double pos = 0, neg = 0;
                for (auto k : a) {
                    double aux = calcDist(a[i], a[j], k);
                    (aux != 0 && aux > 0? pos += aux: neg += aux);
                }
                mn = min(mn, abs(pos+neg));

            }
        }

        cout << fixed << setprecision(3) << mn << endl;

    }

    return 0;
}

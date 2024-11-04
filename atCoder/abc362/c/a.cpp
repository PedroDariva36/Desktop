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
    int n;
    cin >> n;
    vector<pair<ll,ll>> a(n); 
    vector<ll> b(n); 

    for (auto &i: a) {
        cin >> i.first >> i.second;
    }

    ll sum = 0; 
    for (int i = 0; i < n; i++) {
        if(a[i].second <= 0){
            sum += a[i].second; 
            b[i] = a[i].second; 
            continue;
        }
        if(a[i].first >= 0){
            sum += a[i].first;
            b[i] = a[i].first; 
            continue;
        }
        b[i] = 0; 
    } 
    
    for (int i = 0; i < n; i++) {
        if(sum == 0) break;
        if(sum < 0){
            ll aux = a[i].second - b[i];
            if(abs(aux) > 0){
                if(abs(sum) < aux ){
                    b[i] += abs(sum);
                    sum = 0;
                    continue;
                }
                b[i] += aux;
                sum += aux; 
            }
        }
        if (sum > 0){
            ll aux = a[i].first - b[i];
            if(abs(aux) > 0){
                if(abs(sum) < abs(aux)){
                    b[i] -= sum;
                    sum = 0;
                    continue;
                }
                b[i] += aux;
                sum += aux; 
            }
        }
    } 


    if(sum == 0){
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
        return 0;
    }

    cout << "No" << endl;

        return 0;
    }

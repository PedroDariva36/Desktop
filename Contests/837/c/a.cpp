#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

const long N = 1e5;
vector<bool> sv(N+1, 1); 
vector<int> primes;

void sieve(){
    for(int i = 2; i *i <= N; i++){
        if(sv[i]) for(int j = i*i; j <= N; j+=i)
            sv[j] = 0;
    }
    
    for(int i = 2; i <= N; i++) if(sv[i]) primes.pb(i); 
}



void factor(int x, map<int,int> &m){
    for(int i = 0; i < primes.size() && primes[i] * primes[i] <= x; i++){
        if(x%primes[i] == 0){ 
            while (x%primes[i] == 0) {
                x/=primes[i];
            }
            m[primes[i]]++;
        }
    }
    if(x != 1) m[x]++;
}



int main (int argc, char *argv[]){
    sieve(); 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        bool f = 0;
        cin >> n;
        
        map<int,int> m;
        for(int i = 0,aux; i < n; i++){
            cin >> aux,factor(aux,m); 
        }
        
        for(auto &i: m) if(i.second > 1) f = 1;



        cout << (f? "YES" : "NO") << endl;
    }

    return 0;
}

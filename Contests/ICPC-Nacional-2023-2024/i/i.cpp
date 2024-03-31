#include<bits/stdc++.h>
#define ll long long

using namespace std;
  
const ll M = 1e9+7;

ll vet['z'+1];
ll qnt[112345];
 
map<char, ll> ma;
string s;
ll n, a, b, final, aux, ans;

int main(int argc, char const *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> n;
    
    a = n % M;
    b = (n-1) % M;
    final = (a * b) / 2;
    final %= M;
 
    memset(qnt, 0, sizeof(qnt));
    memset(vet, 0, sizeof(vet));

    for (int i = s.size()-1; i >= 0 ; i--){
        ma[s[i]]++;
        vet[s[i]]++;
        for (int c = 'a'; c < s[i]; c++)
            qnt[i] += vet[c];
    }
    
    aux = 0;
    ans = 0;
    for (int i = 0; i < s.size(); i++){
        for (auto c : ma) 
            if (c.first < s[i])
                aux += c.second;
        
        ans += qnt[i] % M;
    }
    final = ((aux % M) * final) % M;
    ans = (ans * a) % M;
    ans += final;
    ans %= M;
 
    cout << ans << endl;
    return 0;
}


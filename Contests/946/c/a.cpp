#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


ll solve(unordered_map<pair<int,int>, map<int,int>,custom_hash> &m){
    ll sum = 0;

    for (auto &i : m) {
        if(i.second.size() < 2) continue;

        vector<int> aux; 
        for (auto &j:i.second) aux.push_back(j.second); 
         
        for (int k = 0; k < aux.size()-1; k++) {
            for (int l = k+1; l < aux.size(); l++) {
                sum+= (ll)aux[k]*aux[l];     
            } 
        }
    }

    return sum;
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i: a)
            cin >> i; 

        unordered_map<pair<int,int>, map<int,int>,custom_hash>  m1,m2,m3;
        
        for (int i= 0; i < n-2;i++) {
            m1[{a[i],a[i+1]}][a[i+2]]++;
            m2[{a[i],a[i+2]}][a[i+1]]++;
            m3[{a[i+1],a[i+2]}][a[i]]++;
        }
        /*
        for (auto &i : m1) {
            for (auto j: i.second) {
                cout << i.first.first << " " << i.first.second << " ";  
                cout << j.first << " " << j.second << endl;; 
          
            } 
        }
        cout << endl; 
        for (auto &i : m2) {
            for (auto j: i.second) {
                cout << i.first.first << " " << i.first.second << " ";  
                cout << j.first << " " << j.second << endl;; 
            } 
        }
        
        cout << endl; 
        for (auto &i : m3) {
            for (auto j: i.second) {
                cout << i.first.first << " " << i.first.second << " ";  
                cout << j.first << " " << j.second << endl;; 
            } 
        }
        */
        ll sum = 0;
        sum += solve(m1);
        sum += solve(m2);
        sum += solve(m3);
        cout << sum << endl;
    }

    return 0;
}

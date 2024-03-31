#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long
#define dl double long

using namespace std;



int main (int argc, char *argv[]){
    int t, n, aux;
    cin >> t;    

    while (t--) {
        cin >> n;
        
        map<int, int> s;
        for (int i = 0; i< n; i++) {
            cin >> aux;
            s[aux]++;
        }
        
        ll asw = 0;
        ll sum = 0;
        ll c;

        for(auto i: s){
            c = i.second;
            if (c >= 3) asw += c * (c-1) * (c-2) / 6;
            if (c >= 2) asw += c * (c-1) * sum / 2;
            sum += i.second;
        }
        
        cout << asw << endl;
            
    }


    return 0;
}

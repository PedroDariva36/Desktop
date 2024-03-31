#include <bits/stdc++.h>
#include <map>

#define ll long long

using namespace std;

map<int, int> m;


ll combinatorics( int n, int k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


int main (int argc, char *argv[]){
    int n, aux;
    cin >> n;
    
    while (n--) {
        cin >> aux;
        m[aux]++;
    }
    
    
    int pos = -1;
    int s = 3;
    for(auto i : m){
        if (i.second >= s) {
            pos = i.first;
            break;
        }
        s -= i.second;
    }
    
    cout << combinatorics(m[pos],s) << endl;





    return 0;
}





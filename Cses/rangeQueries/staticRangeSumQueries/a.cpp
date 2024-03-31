#include <bits/stdc++.h>
#include <vector>
#define pii pair<int,int>

using namespace std;


int main (int argc, char *argv[]){
    int n, m;  
    cin >> n >> m;
    long aux;
    vector<long> a;
    vector<long> prefix;

    a.push_back(0);
    prefix.push_back(0);
    

    long sum;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        a.push_back(aux);
        
        sum += aux;
        prefix.push_back(sum);
    }
    
    while (m--) {
        int x,y;
        cin >> x >> y;
        
        cout << a[x] + abs(prefix[x] - prefix[y]) << endl;
    }


    return 0;
}

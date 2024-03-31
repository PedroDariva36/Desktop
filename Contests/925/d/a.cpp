#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long


using namespace std;


int main (int argc, char *argv[]){
    
    int t;
    cin >> t;
    while (t--) {
        long n,x,y,aux;
        
        cin >> n >> x >> y;
        
        vector<long> a(n);
        for (auto &i: a) {
            cin >> i; 
        }
        
        map<long,map<long,long>> m;
        ll sum = 0;
        for (auto &i: a){
            sum += m[(x - i%x)%x][i%y];
            m[i%x][i%y]++; 
        }


        cout << sum << endl;

    }


    return 0;
}

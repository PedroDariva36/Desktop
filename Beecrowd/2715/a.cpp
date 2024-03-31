#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

int main (int argc, char *argv[]){
    
    int n,aux;
    while (cin >> n && n != EOF) {
        
        vector<int> a;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
             cin >> aux;
             a.push_back(aux);
             sum += aux;
        }
        
        long long m = sum;
        long long local = 0;
        for (int i = 0; i < n; i++) {
            local += a[i];
            if(abs(sum - 2*local) > m) break;
            m = sum - 2*local; 
        }
        cout << abs(m) << endl;


    }


    return 0;
}

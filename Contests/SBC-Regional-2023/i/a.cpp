#include <bits/stdc++.h>
#include <vector>

using namespace std;


long long countOddSum(vector<int> &a, int n){
    long long temp[2] = {1, 0};
    long long val = 0;
 
    for (int i = 0; i < n; i++) {
        val = (val + a[i]) % 2;
        temp[val]++;
    }

    return temp[0] * temp[1];
}
 


int main (int argc, char *argv[]){
    
    int n, aux;
    cin >> n;
    vector<int> a;
    while (n--) {
        cin >> aux;
        a.push_back(aux);
    }

    cout << countOddSum(a, a.size());
    


    return 0;
}

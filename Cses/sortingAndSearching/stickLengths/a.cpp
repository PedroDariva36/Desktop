#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

using namespace std;


int main (int argc, char *argv[]){
    long n, aux,fm ,sm;
    cin >> n;
    vector<long> a;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        a.push_back(aux);
    }

    sort(a.begin(),a.end());

    fm = n/2;
    sm = n/2-1;

    unsigned long long sum = 0;
    unsigned long long altSum = 0;
    
    for (auto &i: a){
        sum += abs(i - a[fm]);
        altSum += abs(i - a[sm]);
    }
    sum = min(sum,altSum);

    cout << sum << endl;
    return 0;
}

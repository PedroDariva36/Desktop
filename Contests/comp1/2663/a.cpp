#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]){
    
    int n , k, aux;
    map<int, int> a;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        a[-aux]++;
    }

    int count = 0;
    for (auto i : a) {
        count += i.second;
        if (count >= k) {
            break;
        }
    }
    cout << count << endl;
    





    return 0;
}



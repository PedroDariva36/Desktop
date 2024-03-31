#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define ull unsigned long long
#define mod 1000000007
using namespace std;

float basic[100];
float fac(int x){
    if (x == 0) return 1;
    if (basic[x] == 0) basic[x] = (fac(x-1) * x);
    return basic[x];
}

int main (int argc, char *argv[]){
    
    string n;
    while (cin >> n) {
        cout << n.size() << endl;

        map<char, int> m;
        for (auto &i : n) m[i]++; 
        
        float c = fac(n.size());
        for (auto &i : m) c = c/fac(i.second);

        cout << fmod(c,mod) << endl;
    }

    return 0;
}

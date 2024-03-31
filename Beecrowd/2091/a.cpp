#include <bits/stdc++.h>
#define ll long long

using namespace std;


int n;
ll aux, asw;

int main (int argc, char *argv[]){
    
    while (cin >> n && n != 0) {
        map<ll,int> m;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            m[aux]++;
        }
        for (auto i : m) {
            if (i.second % 2 != 0) {
                cout << i.first << endl;
                break;
            }
        }
    }


    return 0;
}

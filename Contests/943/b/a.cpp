#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string a, b;
        char aux;
        cin >> n >> m;
        
        cin >> a >> b;

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                i++;
                j++;
                k++;
                continue; 
            } 
            j++;
        }


        cout << k << endl;


        


    }

    return 0;
}

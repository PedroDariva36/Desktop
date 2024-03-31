#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> a,b;
int main (int argc, char *argv[]){
    int n, aux;
    cin >> n;

    for (int i = 0 ; i < n; i++) {
        cin >> aux;
        a.push_back(aux);
    }
    
    for (int i = 0 ; i < n; i++) {
        cin >> aux;
        b.push_back(aux);
    }

    for (int i = 0 ; i < n; i++)
        cout << a[i] + b[i] << " ";
    cout << endl;

    return 0;
}

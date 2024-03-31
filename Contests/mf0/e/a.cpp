#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main (int argc, char *argv[]){
    vector<int> p, e;
    long long aux;
    int n, m; 
    cin >> n;
    m = n;
    while (m--) {
        cin >> aux;
        p.push_back(aux);
    }
    while(n--){
        cin >> aux;
        e.push_back(aux);
    }
    sort(p.begin(), p.end());
    sort(e.begin(), e.end());
        
    int midle = p.size()/2;
    if (n % 2 != 0) midle++;

    cout << p[midle] + e[0] << " " << p[midle] - e[0];
    int d1, d2;
    d1 = p[midle] - p[midle-1];
    d2 = p[midle+1] - p[midle];
    
    if (d1 > d2) {
        cout << p[midle-1] + e[2] << " " << p[midle-1] - e[2] <<" " ;
        cout << p[midle+1] + e[1] << " " << p[midle+1] - e[1] <<" " ;
    }
    else {
        cout << p[midle-1] + e[1] << " " << p[midle-1] - e[1]<< " ";
        cout << p[midle+1] + e[2] << " " << p[midle+1] - e[2] << " " ;
    }

    //cout << p[p.size()/2+1] + e[0] << " " << p[p.size()/2+1] - e[0];



    return 0;
}


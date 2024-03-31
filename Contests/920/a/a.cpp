#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define pii pair<int,int>

using namespace std;

int main (int argc, char *argv[]){
    
    int t; 
    cin >> t;

    while (t--) {
        
        vector<pii> a;
        for (int i = 0; i < 4; i++) {
            pii aux;
            cin >> aux.first >> aux.second;
            a.push_back(aux);
        }
        int asw = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = i+1; j < 4; j++) {
                if (a[i].first == a[j].first) {
                    int k = abs(a[i].second - a[j].second);
                    asw = k*k;
                }
            }
        }
        cout << asw << endl;
        

    }


    return 0;
}

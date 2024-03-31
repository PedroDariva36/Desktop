#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        int n; 
        char aux;
        cin >> n;
        vector<int> a(n);

        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                cin >> aux;
                a[i] += (aux == '1');
            }
        }
        
        int last = 0;
        
        for (int i = 0 ; i < n; i++) {
            if(a[i]){
                if(last == 0) last = a[i];
                else{
                    if(last == a[i]) cout << "SQUARE";
                    else cout << "TRIANGLE";
                    break;
                }
            }
        }
        
        cout << endl;
        
    }
}

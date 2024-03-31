#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a = 0, b = 0;
        char aux;
        for (int i = 0; i < 5;i++) {
            cin >> aux;
            
            if(aux == 'A') a++;
            else b++;

        }

        if (a > b) cout << "A";
        else cout << "B";
        cout << endl;
    }


    return 0;
}

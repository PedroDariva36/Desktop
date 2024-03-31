#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
    int t, a, b, c; 
    char x;
    cin >> t; 

    while (t--) {
        a = 0;
        b = 0;
        c = 0;

        for (int i = 0; i < 9; i++) {
            cin >> x;
            if(x == 'A') a++;
            if(x == 'B') b++;
            if(x == 'C') c++;
        }
        
        if (a == 2) cout << "A" << endl;
        if (b == 2) cout << "B" << endl;
        if (c == 2) cout << "C" << endl;

    }


    return 0;
}

#include <bits/stdc++.h>
#include <vector>


using namespace std;

int t, n;
long long aux;
int main (int argc, char *argv[]){
    
    cin >> t;
    while (t--) {
        cin >> n;
        int even = 0;
        int odd = 0;
        bool one = false;

        for (int i = 0; i < n; i++) {
            cin >> aux; 
            if (aux % 2 == 0) even++;
            else {
                if (aux == 1) one = true;
                odd++;
            }
        }
        
//        cout << odd << " " << even << " " << one << endl;
        if (one || (even > odd && odd == 0) || (odd > even && even == 0)) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO"<< endl;
    }


    return 0;
}

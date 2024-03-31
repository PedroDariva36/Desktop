#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            for (int l = 0; l < 2; l++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < 2; k++){
                        if ((j + i)%2 == 0) {
                            cout << "#";
                        }
                        else {
                            cout << ".";
                        }
                    }

                }
                cout << endl;
            } 
        }

    }

    return 0;
}

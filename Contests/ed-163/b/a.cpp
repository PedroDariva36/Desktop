#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;



int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        int n;
        int aux;
        cin >> n;
        
        vector<int> a;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back(aux);
        }    


        bool f = true;
        bool r = false;
        int i = 0;
        while (i < a.size()) {
            if (r) r = 0;
            if (a[i] > a[i+1]) {
                int u = a[i] % 10;
                int d = a[i] / 10;
                
                if(a[i] < 10){
                    f = false;
                    break;
                }


                if(i < a.size()-1 && u > a[i+1]){
                    f = false;
                    break;
                }
                
                if (i > 0 && d < a[i-1] ) {
                    if(a[i-1] < 10){
                        f = false;
                        break;
                    }
                    r = true;
                }
                a[i] = d;
                a.insert(a.begin()+i,u);
            
                if (r) {
                    i = 0;
                    continue;
                }
            } 
            i++;
        }

    
        for (auto i : a) {
            cout << i << " ";
        }
        cout << endl;

        cout << (f? "YES": "NO") << endl;
    }
    return 0;
}

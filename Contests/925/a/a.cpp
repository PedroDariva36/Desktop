#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;


int main (int argc, char *argv[]){
    
    int t;
    cin >> t;

    while (t--) {
        int n,k;
        char aux;
        cin >> n;
        
        k = n/26;
        if(k == 3){
            cout << "zzz" << endl;
            continue;
        }
        
        if (n < 28) {
            n -= 2;
            aux = 'a'+(n-1);
            cout << "aa" << aux << endl;
            continue;
        }
        
        if(n < 53){
          n-=27;
          aux = 'a' + (n-1);
          cout << "a" << aux << "z"<< endl;
          continue;
        }
        
        if(n < 78){
            n-= 52;
            aux = 'a'+ (n-1);
            cout << aux << "zz" << endl;
        }
    }

    return 0;
}

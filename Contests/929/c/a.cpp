#include <bits/stdc++.h>
#define ll long long


using namespace std;


bool isPrime(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, l;
        cin >> a >> b  >> l;
        
        if (l % a != 0 && l % b == 1) {
            cout << 1 << endl;
            continue;
        }
        int ac = ceil(log2(l)/log2(a));
        int bc = ceil(log2(l)/log2(b));
        
        if(a == b){
            bc = 0;
        }
    

        set<int> s;
        long aux;
        for (int i = 0; i <= ac; i++) {
            for (int j = 0; j <= bc ; j++) {
                aux = pow(a,i) * pow(b,j);    
                if (aux <= l && l % aux == 0) {
                    s.insert(l/aux);
                }
            }
        }


        cout << s.size() << endl;;

    }

    return 0;
}

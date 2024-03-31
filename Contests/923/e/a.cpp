#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int asw[n+1];
        int l = 1, r = n;
        for(int i = 0; i < k; i++){
            for(int j = i; j < n; j += k){
                if(i%2 == 0)
                    asw[j] = l++;
                else 
                    asw[j] = r--;
            }
        }

        for(int i = 0 ; i < n; i++){
            cout << asw[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

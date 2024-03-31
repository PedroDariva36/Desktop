#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin >> a >> b >> c;
        
        if (a < b && b < c)
            cout << "STAIR" << endl;
        else if(a < b && b > c)
            cout << "PEAK" << endl;
        else 
            cout << "NONE" << endl;
        



    }

    return 0;
}

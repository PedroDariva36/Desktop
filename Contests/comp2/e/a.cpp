#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second


using namespace std;

int main (int argc, char *argv[]){
    
    int x,y,z;

    cin >> x >> y >> z;

        
    int f1 = y*2 + z*4;
    int f2 = x*2 + z*2;
    int f3 = y*2 + x*4;

    cout << min(f1,min(f2,f3)) << endl;




    return 0;
}

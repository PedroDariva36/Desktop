#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;


vector<int> a(log10(2*1e5)+1);


 int solve(int n){

    if (n<10)
      return n*(n+1)/2;

    int d = log10(n);
    int *a = new int[d+1];
    a[0] = 0, a[1] = 45;
    for (int i=2; i<=d; i++)
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));
 

    int p = ceil(pow(10, d));
    int msd = n/p;
    return msd*a[d] + (msd*(msd-1)/2)*p +  
           msd*(1+n%p) + solve(n%p);
}       



int main (int argc, char *argv[]){
    a[0] = 0, a[1] = 45;
    for (int i=2; i<=log10(2*1e5); i++)
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));

    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;

    }


    return 0;
}

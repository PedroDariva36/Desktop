#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <ios>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);

        double s;
        cin >> s;
        double r = sqrt(s/(4-3.14));
        cout << r << endl;
        cout << std::fixed<<std::setprecision(2) << (r*r)*3.14 << endl;



    return 0;
}

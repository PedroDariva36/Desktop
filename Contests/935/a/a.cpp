#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll a,b,c;
        cin >> a >> b >> c;
        
        ll sum = 0;
        if (b%3 == 0){
            sum += b/3;
            sum += c/3;

            if (c%3 > 0) sum++;


        } else if (c >= 3-(b%3)){
            c -= (3-(b%3));
            b += 3-(b%3);
        
            sum += b/3;
            sum += c/3;
            if (c%3 > 0) {
                sum++;
            }
        }
        else{
            cout << -1 << endl;
            continue;
        }
        sum+=a;
        
        cout << sum << endl;

    }

    return 0;
}

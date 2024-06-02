#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    //cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        ll sum = 0;
        bool flag = false;
        int k = s.size()-1;
        while (k >= 0) {
            //cout << k << s << endl;
            if (s[k] == '1') {
                k--;
                continue;
            } 
            int size = 0;
            int i = k-1;
            for (; i >= 0; i--) {
                if (s[i] == '1') {
                    int j = i;
                    while(j >= 0 && s[j] == '1') {
                        size++;
                        s[j] = '0';
                        j--;
                    }
                    cout << k <<  " " << i << endl;
                    cout << k-i << endl;
                    cout << size << endl;
                    sum += abs(((k-i)) * (size+1));
                    k -= size;
                }
            }
            if (size == 0) {
                break;
            }
        }
        cout << sum << endl;
    }

    return 0;
}

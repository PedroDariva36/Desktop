#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    long n, w, aux;
    long counter = 0;
    deque<long> a;
    cin >> n >> w;

    while (n--) {
        cin >> aux;
        a.push_front(aux); 
    }
    sort(a.begin(),a.end());


    while (a.size() > 1) {
        if (a[0] + a[a.size()-1] > w) 
            a.pop_back();

        else {
            a.pop_front();
            a.pop_back();
        }
        counter++;
    }
    counter += a.size();
    cout << counter << endl;

    return 0;
}

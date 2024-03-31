#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <unordered_set>
#include <vector>
#define N 2000001

using namespace std;
int n, aux;
int a[N];





int main (int argc, char *argv[]){
    
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    

    for(int i = 1; i <= n; i++){
        cin >> aux;
        a[aux] = i;
    }
    
    int sum = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < last) sum++;
        last = a[i];
    }
    
    cout << sum+1 << endl;



    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
int main (){
    int a = 1;
    cin >> n;
    int i = 2;
    while (i > 1) {

        i*2 > n ? (i*2)%n == 0 ? i = n-1: i = ((i*2) %n) -1 : i = i * 2;
        a++;
 //       cout << i<< endl;
    }


    cout << a << endl;



    return 0;
}

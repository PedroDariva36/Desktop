#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll  long long
using namespace std;

const ll N = 32001;
array<int,N> primes;
char sv[N] = {1};
int n,k = 0;

void sieve(){
    memset(sv, 1, sizeof(sv)); 
    for (int i = 3; i * i < N; i += 2)
        if (sv[i])
            for (int j = i * i; j < N; j += i + i)
                sv[j] = false;

    primes[k++] = 2;
    for (int i = 3; i < N; i += 2)
        if (sv[i]) primes[k++] = i; 
}
 
int main (int argc, char *argv[]){
    sieve(); 
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    while(scanf("%d",&n) && n != 0){
        int m = n;
        for (int i = 0; i < k && primes[i] * primes[i] <= n; i++){
            const int g = primes[i]; 
            if (n % g == 0) {
                while (n % g == 0) n /= g;
                m /= g;
                m *= g - 1;
            }
        }
        if (n != 1) {
            m /= n;
            m *= n - 1;
        }
        printf("%d\n", m);
    }

    return 0;
}

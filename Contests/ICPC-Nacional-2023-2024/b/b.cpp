#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << "\n"
#define MAX 3001


typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;



int vet[MAX];

int main(int argc, char const *argv[]){
    
    int n;
    cin >> n;

    for (int i = 0; i < 3*n; i++) cin >> vet[i];
    
    sort(vet, vet+(n*3));

    long long ans1 = 0, ans2 = 0,  ans3 = 0;

    for (int i = 0; i < (n*3); i += 3){
        ans1 += vet[i];
        ans2 += vet[i+1];
        ans3 += vet[i+2];
    }
    if (ans1 != ans2) cout << "Y\n";
    else{
        
        reverse(vet, vet+(n*3));
        ans1 = 0, ans2 = 0,  ans3 = 0;
        
        for (int i = 0; i < (n*3); i += 3){
            ans1 += vet[i];
            ans2 += vet[i+1];
            ans3  += vet[i+2];
        }

        if (ans1 != ans2) cout << "Y\n";
        else cout << "N\n";
    }
    

    return 0;
}

#include <bits/stdc++.h>
#include <ctime>
#include <vector>


using namespace std;

int main (int argc, char *argv[]){
    
    vector<int> days;
    long long n; 
    long m;
    double med = 0;
    int aux;
    
    cin >> n >> m;
        double sum = 0;
        for (int i = 0 ; i < 30; i++) {
            cin >> aux;
            days.push_back(aux);
            sum+=aux;
        }
        long long j = 0;
        int i = 0;
        while (n < m) {
            med = ceil(sum/30);
            sum -= days[i]; 
            sum += med; 
            days[i] = med;
            n += med;
            i++;
            i= i % 30;
            j++;
            //cout << med << endl;
        }
        cout << j << endl; 
    return 0;
}

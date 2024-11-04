#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <vector>
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}};
template<typename T, typename comp_function = std::less<T>> using indexed_set = class __gnu_pbds::tree<T, __gnu_pbds::null_type, comp_function, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename K, typename V> using hash_map = std::unordered_map<K, V, custom_hash>;
template<typename T> using hash_set = std::unordered_set<T, custom_hash>;
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

const int N = 101;
int n;
ll a[N][N][N];
ll pre[N][N][N];

void prefixSum3d()
{
    pre[0][0][0] = a[0][0][0];

    for (int i = 1; i < n; i++) pre[i][0][0] = pre[i - 1][0][0] + a[i][0][0];
    for (int i = 1; i < n; i++) pre[0][i][0] = pre[0][i - 1][0] + a[0][i][0];
    for (int i = 1; i < n; i++) pre[0][0][i] = pre[0][0][i - 1] + a[0][0][i];

    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            pre[k][i][0] = a[k][i][0] + pre[k - 1][i][0] + pre[k][i - 1][0] - pre[k - 1][i - 1][0];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            pre[0][i][j] = a[0][i][j] + pre[0][i - 1][j] + pre[0][i][j - 1] - pre[0][i - 1][j - 1];
        }
    }
    for (int j = 1; j < n; j++) {
        for (int k = 1; k < n; k++) {
            pre[k][0][j] = a[k][0][j] + pre[k - 1][0][j] + pre[k][0][j - 1] - pre[k - 1][0][j - 1];
        }
    }

    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                pre[k][i][j] = a[k][i][j]
                             + pre[k - 1][i][j]
                             + pre[k][i - 1][j]
                             + pre[k][i][j - 1]
                             - pre[k - 1][i - 1][j]
                             - pre[k][i - 1][j - 1]
                             - pre[k - 1][i][j - 1]
                             + pre[k - 1][i - 1][j - 1];
            }
        }
    }
}

ll query(int lx, int rx, int ly, int ry, int lz, int rz) {
    ll result = pre[rx][ry][rz];

    if (lx > 0) result -= pre[lx - 1][ry][rz];
    if (ly > 0) result -= pre[rx][ly - 1][rz];
    if (lz > 0) result -= pre[rx][ry][lz - 1];

    if (lx > 0 && ly > 0) result += pre[lx - 1][ly - 1][rz];
    if (lx > 0 && lz > 0) result += pre[lx - 1][ry][lz - 1];
    if (ly > 0 && lz > 0) result += pre[rx][ly - 1][lz - 1];

    if (lx > 0 && ly > 0 && lz > 0) result -= pre[lx - 1][ly - 1][lz - 1];

    return result;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                cin >> a[i][j][k];

    prefixSum3d();
    
    cin >> q;
    while (q--){
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        cout << query(lx-1, rx-1, ly-1, ry-1, lz-1, rz-1) << endl;
    }


    return 0;
}

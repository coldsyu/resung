#include <bits/stdc++.h>
using namespace std;
void solve() {
    double n, m, a;
    cin >> n >> m >> a;
    long long p = ceil(n / a), q = ceil(m / a);
    cout << p * q;
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

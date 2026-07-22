#include <bits/stdc++.h>
using namespace std;
void h(string s) {
    int n = s.size();
    int nums[2] {};
    for (int i = 1, j = 0; i < n; i++) {
        if (s[i] == 'C') {
            j++;
            continue;
        }
        nums[j] *= 10;
        nums[j] += s[i] - '0';
    }
    // for (int x : nums) {
    //     cout << x << " ";
    // }
    vector<int> r;
    int p = 0;
    while (pow(26, p + 1) <= nums[1]) p++;
    for (; p >= 0; p--) {
#define N pow(26, p)
        // if (nums[1] < N) continue;
        int k = nums[1] / N;
        r.push_back(k);
        nums[1] -= k * N;
    }
    int m = r.size();
    int g = 50;
    while (g--) {
        for (int i = m - 1; i >= 0; i--) {
            if (i - 1 >= 0 and r[i] <= 0) {
                r[i] += 26;
                r[i - 1]--;
                // goto X;
            }
        }
    }
    for (int x : r) {
        // cout << x << " ";
        if (1 <= x and x <= 26) {
            cout << char(x + 'A' - 1);
        }
    }
    cout << nums[0] << "\n";
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i + 1 < n; i++) {
        if ('0' <= s[i] and s[i] <= '9' && s[i + 1] == 'C') {
            h(s);
            return;
        }
    }
    int j = 0;
    while ('A' <= s[j] and s[j] <= 'Z') j++;
    int num1 = stoi(s.substr(j));
    s = s.substr(0, j);
    int num2 = 0;
    for (int i = s.size() - 1, p = 0; i >= 0; i--) {
        num2 += (s[i] - 'A' + 1) * pow(26, p++);
    }
    printf("R%dC%d\n", num1, num2);
}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

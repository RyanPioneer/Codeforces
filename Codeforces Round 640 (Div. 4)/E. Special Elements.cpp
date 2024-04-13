/**
 * Source: is.gd/9y6uQu
 * Date: 2024/4/13
 * Time:
 * Space:
 * Skill: Notice the constraint that 1 <= ai <= n
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;


void solve() {
    int n, res = 0;
    cin >> n;
    vector<int> a(n), cnt(n + 1, 0), isSpecial(n + 1, 0);
    for (auto &i: a) {
        cin >> i;
        cnt[i]++;
    }
    for (int left = 0; left < n; ++left) {
        int total = a[left];
        for (int right = left + 1; right < n; ++right) {
            total += a[right];
            if (total > n) break;
            if (cnt[total] >= 1) {
                isSpecial[total] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) res += isSpecial[i] * cnt[i];
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin>>t; t--;) {
        solve();
    }
}
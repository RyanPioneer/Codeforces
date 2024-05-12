/**
 * Source: ibit.ly/FTYNE
 * Date: 2024/5/12
 * Time:
 * Space:
 * Skill:
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


using namespace std;
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;


const int MX = 2e5+5;
int presum[MX] = {0};
vector<int> nums[MX];
map<int, int> num2idx;


void solve() {
    int n, q, l, r, cnt = 0;
    cin >> n >> q;
    num2idx.clear();
    num2idx[0] = 0;
    nums[0].clear();
    nums[0].push_back(0);
    for (int i = 1, j; i <= n; i++) {
        cin >> j;
        presum[i] = presum[i - 1] ^ j;
        if (num2idx.find(presum[i]) == end(num2idx)) {
            num2idx[presum[i]] = ++cnt;
            nums[cnt].clear();
        }
        nums[num2idx[presum[i]]].push_back(i);
    }
    while (q--) {
        cin >> l >> r;
        if (presum[r] == presum[l - 1]) {
            cout << "YES" << endl;
            continue;
        }
        auto it = upper_bound(begin(nums[num2idx[presum[r]]]), end(nums[num2idx[presum[r]]]), l - 1);
        if (it == end(nums[num2idx[presum[r]]]) || *it >= r) {
            cout << "NO" << endl;
            continue;
        }
        auto it2 = upper_bound(begin(nums[num2idx[presum[l - 1]]]), end(nums[num2idx[presum[l - 1]]]), *it);
        if (it2 == end(nums[num2idx[presum[l - 1]]]) || *it2 >= r) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t; t--) {
        solve();
    }
}
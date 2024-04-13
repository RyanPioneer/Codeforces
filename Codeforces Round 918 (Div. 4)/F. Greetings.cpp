/**
 * Source: is.gd/MMbSff
 * Date: 2024/4/6
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


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;


class BIT{
public:
    vector<int> arr;
    int n;

    BIT(int n) {
        this->n = n;
        arr = vector<int>(n, 0);
    }

    int querySum(int idx) {
        int total = 0;
        while (idx > 0) {
            total += arr[idx];
            idx -= idx & -idx;
        }
        return total;
    }

    void update(int idx, int num) {
        while (idx < n) {
            arr[idx] += num;
            idx += idx & -idx;
        }
    }
};


void solve() {
    ll res = 0;
    int n;
    cin >> n;
    BIT *tree = new BIT(2 * n + 1);
    vector<vector<int>> nums(n);
    vector<int> arr;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        nums[i].push_back(a);
        nums[i].push_back(b);
        arr.push_back(a), arr.push_back(b);
    }

    sort(begin(arr), end(arr));
    unordered_map<int, int> num2idx;
    for (int i = 0; i < arr.size(); i++) {
        num2idx[arr[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) tree->update(num2idx[nums[i][1]], 1);

    sort(begin(nums), end(nums));
    for (int i = 0; i < n; i++) {
        tree->update(num2idx[nums[i][1]], -1);
        res += tree->querySum(num2idx[nums[i][1]]);
    }
    cout << res << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}
/**
 * Source: https://rb.gy/ecru3
 * Date: 2023/9/16
 * Skill:
 * Runtime: 156 ms
 * Memory Usage: 0 MB
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

string solve() {
    int n, k, total = 0;
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> k;
        total += k;
    }
    if (total % 2)
        return "NO";
    else
        return "YES";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << solve() << endl;
}
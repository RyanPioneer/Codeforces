/**
 * Source: https://rb.gy/psvl3
 * Date: 2023/9/16
 * Skill:
 * Runtime: 217 ms
 * Memory Usage: 0 MB
 * Time complexity: O(1)
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
    int a, b, c;
    cin >> a >> b >> c;
    return a + c % 2 > b ? "First" : "Second";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << solve() << endl;
}
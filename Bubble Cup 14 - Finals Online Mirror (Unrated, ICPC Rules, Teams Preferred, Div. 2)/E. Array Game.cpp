/**
 * Source: t.ly/bdtbK
 * Date: 2024/5/4
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


const int MX = 2e5+1;

void solve() {
    int n;
    cin >> n;
    int arr[MX];
    for (int i=0; i < n; i++) cin >> arr[i];
    int num1 = 1, num2 = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1]) break;
        num1++;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] <= arr[i + 1]) break;
        num2++;
    }
    if (num1 % 2 == 1 || num2 % 2 == 1) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t = 1; t; t--) {
        solve();
    }
}
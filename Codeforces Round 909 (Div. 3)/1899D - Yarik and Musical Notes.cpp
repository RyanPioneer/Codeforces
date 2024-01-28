/**
 * Source: jpeg.ly/sEUxl
 * Date: 2023/11/18
 * Skill:
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
#include <bitset>
#include <functional>
#include <list>
#include <cmath>
#include <math.h>


using namespace std;


#define ll long long


int main() {
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> nums;
        for (int j = 0; j < n; j++) {
            cin >> m;
            nums.push_back(m);
        }
        sort(begin(nums), end(nums));
        int right = 0;
        ll res = 0;
        for (int j = 0; j < n; j++) {
            while (right < n && (nums[right] == nums[j] || (nums[j] == 1 && nums[right] == 2))) right++;
            res += right - j - 1;
        }
        cout << res << endl;
    }
}
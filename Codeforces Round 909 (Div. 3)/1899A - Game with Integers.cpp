/**
 * Source: jpeg.ly/vatee
 * Date: 2023/11/17
 * Skill:
 *
 */


#include <iostream>


using namespace std;


int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n % 3 == 0) cout << "Second" << endl;
        else cout << "First" << endl;
    }
}
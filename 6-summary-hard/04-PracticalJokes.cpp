/* https://training.olinfo.it/#/task/ois_prankster/statement */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p = 0; cin >> n;
    int freq[3]{0};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[(x - p + 3) % 3]++;
        p = x;
    }
    int ans = min(freq[1], freq[2]);
    int rem = max(freq[1], freq[2]) - ans;
    ans += (rem / 3) * 2 + rem % 3;
    cout << ans << endl;
}

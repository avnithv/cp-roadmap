/* https://training.olinfo.it/#/task/ois_brackets/statement */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vt vector
#define endl "\n"

void solve() {
	int n, k; cin >> n >> k;
	int arr[n];
	for (int &i : arr) cin >> i;

	vt<int> st;
	st.pb(-1);
	for (int i : arr) {
		if (st.back() == i) st.pop_back();
		else st.pb(i);
	}
	cout << (st.size() == 1 ? 1 : 0) << endl;
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}

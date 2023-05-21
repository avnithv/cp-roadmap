/* https://atcoder.jp/contests/abc216/tasks/abc216_d */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vt vector
#define endl "\n"
#define mp make_pair

typedef pair<int, int> pii;

int main() {
	int n, m; cin >> n >> m;
	int state[m];
	memset(state, 0, sizeof(state));

	vt<int> vis[n], arr[m];
	vt<int> sm;
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a; a--;
			arr[i].pb(a);
			if (j == 0) {
				vis[a].pb(i);
				if (vis[a].size() == 2) {
					sm.pb(a);
				}
			}
		}
	}

	while (!sm.empty()) {
		int p = sm.back(); sm.pop_back();
		int i = vis[p][0], j = vis[p][1];
		state[i]++; state[j]++;
		if (state[i] < arr[i].size()) {
			int a = arr[i][state[i]];
			vis[a].pb(i);
			if (vis[a].size() == 2) {
				sm.pb(a);
			}
		}

		if (state[j] < arr[j].size()) {
			int a = arr[j][state[j]];
			vis[a].pb(j);
			if (vis[a].size() == 2) {
				sm.pb(a);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (state[i] != arr[i].size()) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}

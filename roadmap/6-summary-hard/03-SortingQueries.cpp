/* https://atcoder.jp/contests/abc217/tasks/abc217_e */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vt vector
#define endl "\n"
#define mp make_pair

typedef pair<int, int> pii;

int main() {
	int q; cin >> q;

	vt<vt<int>> ads;
	vt<int> pr;

	vt<int> ad;
	int p = 0;
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			ad.pb(x);
		} else if (t == 2) {
			p++;
		} else {
			ads.pb(ad);
			pr.pb(p);
			ad = vt<int>();
			p = 0;
		}
	}
	ads.pb(ad);
	pr.pb(p);

	multiset<int> queue;
	for (int i = 0; i < ads.size(); i++) {
		int s = 0;
		while (pr[i]--) {
			if (!queue.empty()) {
				int x = *queue.begin();
				queue.erase(queue.find(x));
				cout << x << endl;
			} else {
				cout << ads[i][s] << endl;
				s++;
			}
		}

		for (int j = s; j < ads[i].size(); j++) {
			queue.insert(ads[i][j]);
		}
	}
}

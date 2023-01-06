#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> namu;

long long binary(long long l, long long r) {
	long long med = (l + r) / 2;
	if (l > r || !med) return med;
	long long ret = 0;
	for (int i = 0; i < n; i++)
		if (namu[i] >= med)
			ret += namu[i] - med;
	if (ret < m) return binary(l, med - 1);
	return binary(med + 1, r);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	namu.resize(n);
	for (int i = 0; i < n; i++) cin >> namu[i];
	sort(namu.begin(), namu.end());
	cout << binary(0, namu[n - 1]) << endl;
	return 0;
}
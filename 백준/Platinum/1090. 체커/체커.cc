#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll x[50], y[50];
vector<pair<ll, ll>> v;

ll solve(int N, pair<ll, ll> cur);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++)cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v.push_back({ x[i],y[j] });
	for (int i = 0; i < n; i++) {
		ll ans = (ll)1e9;
		for (int j = 0; j < v.size(); j++)
			ans = min(ans, solve(i, v[j]));
		cout << ans << " ";
	}
	return 0;
}
ll solve(int N,pair<ll, ll> cur)
{
	vector<ll> t;
	for (int i = 0; i < n; i++) 
		t.push_back(abs(x[i] - cur.first) + abs(y[i] - cur.second));	
	sort(t.begin(), t.end());
	ll ret = 0;
	for (int i = 0; i < N+1; i++)
		ret += t[i];
	return ret;
}
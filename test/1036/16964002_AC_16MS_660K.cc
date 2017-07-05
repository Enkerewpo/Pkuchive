#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 100 + 10;
int n, T, k, dp[maxn];
class gang {
public:
	int t, p, s;
	gang(int _t = 0, int _p = 0, int _s = 0) : t(_t), p(_p), s(_s) {}
	~gang() {}
}g[maxn];
bool cmp(const gang& a, const gang& b) {
	return a.t < b.t;
}
int main() {
	scanf("%d%d%d", &n, &k, &T);
	for (int i = 1; i <= n; i++) scanf("%d", &g[i].t);
	for (int i = 1; i <= n; i++) scanf("%d", &g[i].p);
	for (int i = 1; i <= n; i++) scanf("%d", &g[i].s);
	sort(g + 1, g + n + 1, cmp);
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j] != -1 && abs(g[i].s - g[j].s) <= g[i].t - g[j].t) {
				dp[i] = max(dp[i], dp[j] + g[i].p);
				ans = max(ans, dp[i]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
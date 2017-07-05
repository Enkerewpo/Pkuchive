#include <cstring>
#include <cstdio>
typedef long long ll;
const int maxn = 26;
ll dp[maxn][maxn][2];
int ans[maxn], n, T;
ll k;
void initial(int len) {
	memset(dp, 0, sizeof dp);
	dp[1][1][0] = dp[1][1][1] = 1;
	for (int j = 2; j <= len; j++) {
		for (int i = 1; i <= j; i++) {
			for (int k = i; k < j; k++) dp[i][j][0] += dp[k][j - 1][1];
			for (int k = 1; k < i; k++) dp[i][j][1] += dp[k][j - 1][0];
		}
	}
}
void solve(int n, ll k) {
	int cur, N = n, f, len = 2;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (sum + dp[i][n][0] + dp[i][n][1] >= k) {
			cur = i;
			k -= sum;
			ans[1] = i;
			break;
		}
		sum += dp[i][n][1] + dp[i][n][0];
	}
	n--;
	bool vis[maxn];
	memset(vis, 0, sizeof vis);
	if (dp[cur][n][1] >= k) f = 1;
	else { 
		k -= dp[cur][n][1];
		f = 0;
	}
	while (n > 0) {
		if (!f) {
			for (int i = cur; i <= n; i++) {
				if (dp[i][n][1] >= k) {
					cur = i;
					ans[len++] = cur;
					break;
				}
				k -= dp[i][n][1];
			}
		}
		else {
			for (int i = 1; i < cur; i++) {
				if (dp[i][n][0] >= k) {
					cur = i;
					ans[len++] = cur;
					break;
				}
				k -= dp[i][n][0];
			}
		}
		n--;
		f = 1 - f;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!vis[j]) {
				ans[i]--;
				if (!ans[i]) {
					printf("%d%c", j, (i == N ? '\n' : ' '));
					vis[j] = 1;
					break;
				}
			}
		}
	}
}
int main() {
	initial(20);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &k);
		solve(n, k);
	}
	return 0;
}
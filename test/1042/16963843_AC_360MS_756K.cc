/*Kvar_ispw17*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, h, t[30], d[30], f[30][400];
int dp[30][400];
int main() {
	while (scanf("%d", &n) && n) {
		scanf("%d", &h);
		memset(f, 0, sizeof f);
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= n; i++) scanf("%d", &f[i][1]);
		for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
		for (int i = 2; i <= n; i++) scanf("%d", &t[i]);
		h *= 12, t[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 2; j <= h; j++) {
				if (f[i][j - 1] <= d[i]) break;
				f[i][j] = f[i][j - 1] - d[i];
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= h; j++) {
				if (dp[i - 1][j] != -1) {
					int sum = 0;
					for (int k = 0; k <= h; k++) {
						if (t[i] + k + j > h) break;
						dp[i][t[i] + k + j] = max(dp[i][j + t[i] + k], dp[i - 1][j] + sum);
						if (f[i][k + 1] > 0) sum += f[i][k + 1];
					}
				}
			}
		}
		int mk = 1, MAX = 0;
		for (int i = 1; i <= n; i++) {
			if (dp[i][h] > MAX) {
				MAX = dp[i][h];
				mk = i;
			}
		}
		int NMAX = MAX;
		for (int i = mk; i >= 2; i--) {
			int sum = 0, k;
			for (k = 0; k <= h; k++) {
				if (MAX == sum + dp[i - 1][h - k - t[i]]) {
					f[i][0] = k;
					break;
				}
				sum += f[i][k + 1];
			}
			h = h - t[i] - k;
			MAX -= sum;
		}
		f[1][0] = h;
		for (int i = 1; i < n; i++) {
			printf("%d, ", f[i][0] * 5);
		}
		printf("%d\n", f[n][0] * 5);
		printf("Number of fish expected: %d\n\n", NMAX);
	}
	return 0;
}
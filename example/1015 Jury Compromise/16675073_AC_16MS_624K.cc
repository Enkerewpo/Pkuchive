#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
int f[30][1000];
int path[30][1000], p[300], d[300], answer[300];
int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
int main() {
	int i, j, k, t1, t2, n, m, nMinP_D, _case = 0;
	while(1) {
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0) break;
		_case++;
		for(int i = 1; i <= n; i++) scanf("%d %d", &p[i], &d[i]);
		memset(f, -1, sizeof f);
		memset(path, 0, sizeof path);
		nMinP_D = m * 20;
		f[0][nMinP_D] = 0;
		for(j = 0; j < m; j++) {
		    for(k = 0; k <= nMinP_D * 2; k++) {
		        if(f[j][k] >= 0) {
			    for(i = 1; i <= n; i++){
			        if(f[j][k] + p[i] + d[i] > f[j + 1][k + p[i] - d[i]]) {
				    t1 = j, t2 = k;
				    while(t1 && path[t1][t2] != i) {
				         t2 -= p[path[t1][t2]] - d[path[t1][t2]];
					 t1--;
				    }
				    if(t1 == 0){
					    f[j + 1][k + p[i] - d[i]] = f[j][k] + p[i] + d[i];
					    path[j + 1][k + p[i] - d[i]] = i;
				    }
				}
			    }
			}
		    }
		}
		i = nMinP_D;
		j = 0;
		while(f[m][i + j] < 0 && f[m][i - j] < 0) j++;
		if(f[m][i + j] > f[m][i - j]) k = i + j;
		else k = i - j;
		printf("Jury #%d\n",_case);
       		printf("Best jury has value %d for prosecution and value %d for defence:\n",
				(k - nMinP_D + f[m][k]) / 2,(f[m][k] - k + nMinP_D) / 2);
        	for(i = 1; i <= m; i++) {
            		answer[i] = path[m - i + 1][k]; 
            		k -= p[answer[i]] - d[answer[i]];
        	}
        	qsort(answer+1, m, sizeof(int), cmp);
        	for(i = 1; i <= m; i++)  
          		printf(" %d", answer[i]);
        	printf("\n\n");     
    	}  
    return 0;   
}   	
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 50;
int left[maxn], right[maxn], mark[maxn];
enum state{eq, neq};
class flag {
public:
	bool f1,f2;
}flag[maxn];
class balance {
public:
	int l[maxn], r[maxn], len;
	state st;
}_k[maxn];
bool cmp(balance A, balance B) {
	return A.st < B.st;
}
void _swap(int* a, int* b) {
	int* e;
	e = a;
	a = b;
	b = e;
}
int n, k;
int main() {
#ifdef local
	freopen("1029.in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	int cnt = 0;
      	for(int q = 1; q <= k; q++) {
		int l;
		scanf("%d", &l);
		_k[q].len = l;
		for(int i = 1; i <= l; i++) scanf("%d", &_k[q].l[i]);
		for(int i = 1; i <= l; i++) scanf("%d", &_k[q].r[i]);
		char d;
		cin >> d;
		if(d == '=') {cnt++; _k[q].st = eq;}
		else {_k[q].st = neq; _swap(_k[q].l, _k[q].r);}
	}
	sort(_k + 1, _k + k + 1, cmp);
	for(int q = 1; q <= cnt; q++) {
		for(int i = 1; i <= _k[q].len; i++) flag[_k[q].l[i]].f1 = flag[_k[q].l[i]].f2 = true;
		for(int i = 1; i <= _k[q].len; i++) flag[_k[q].r[i]].f1 = flag[_k[q].r[i]].f2 = true;	
	}
	for(int q = cnt + 1; q <= k; q++) {
		for(int i = 1; i <= _k[q].len; i++) flag[_k[q].l[i]].f1 = true;
	       	for(int i = 1; i <= _k[q].len; i++) flag[_k[q].r[i]].f2 = true;
	}
	int acnt = 0, ans;
	for(int i = 1; i <= n; i++) {
		if(flag[i].f1 && flag[i].f2) continue;
		else {
			acnt++;
			ans = i;
		}
	}
	if(acnt == 1) printf("%d", ans);
	else printf("0");
	return 0;
}	

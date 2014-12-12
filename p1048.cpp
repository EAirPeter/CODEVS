#include <cstdio>

using namespace std;

int N, D[101], E[101];
int F[101][101];

inline int update(int &x, const int y) {
	if (y < x)
		x = y;
	return x;
}

int dfs(const int l, const int r) {
	if (l == r)
		return 0;
	if (F[l][r])
		return F[l][r];
	F[l][r] = 0x7fffffff;
	for (int i = l; i < r; ++i)
		update(F[l][r], dfs(l, i) + dfs(i + 1, r) + E[r] - E[l - 1]);
	return F[l][r];
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &D[i]);
		E[i] = E[i - 1] + D[i];
	}
	printf("%d\n", dfs(1, N));
	return 0;
}


#include <cstdio>

using namespace std;

int N, X;
int D[201];
int F[200][200];

inline int update(int &x, const int y) {
	if (y > x)
		x = y;
	return x;
}

int dfs(const int l, const int r) {
	if (l == r)
		return 0;
	if (F[l][r])
		return F[l][r];
	for (int i = l; i < r; ++i)
		update(F[l][r], dfs(l, i) + dfs(i + 1, r) + D[l] * D[i + 1] * D[r + 1]);
	return F[l][r];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &D[i]);
		D[i + N] = D[i];
	}
	D[N << 1] = D[0];
	for (int i = 0; i < N; ++i)
		update(X, dfs(i, i + N - 1));
	printf("%d\n", X), fflush(stdout);
	return 0;
}


#include <cstdio>

using namespace std;

inline int min(const int a, const int b) {
	return a < b ? a : b;
}

inline int &update(int &x, const int y) {
	if (y > x)
		x = y;
	return x;
}

int N, M, K;
int D[50][50];
int F[100][50][50];

int main() {
	scanf("%d%d", &N, &M);
	K = M + N - 2;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &D[i][j]);
#define updatec(x) update(F[k][i][j], x);
	for (int k = 1; k < K; ++k) {
		int n = min(N, k + 1);
		int m = min(M, k + 1);
		for (int i = 0; i < n; ++i)
			if (k - i < m)
				for (int j = 0; j < n; ++j)
					if (k - j < m && i != j) {
						if (i && j)
							updatec(F[k - 1][i - 1][j - 1]);
						if (i)
							updatec(F[k - 1][i - 1][j]);
						if (j)
							updatec(F[k - 1][i][j - 1]);
						updatec(F[k - 1][i][j]);
						F[k][i][j] += D[i][k - i] + D[j][k - j];
					}
	}
	F[K][N - 1][N - 1] = F[K - 1][N - 2][N - 2];
	update(F[K][N - 1][N - 1], F[K - 1][N - 1][N - 2]);
	update(F[K][N - 1][N - 1], F[K - 1][N - 2][N - 1]);
	printf("%d\n", F[K][N - 1][N - 1]), fflush(stdout);
	return 0;
}


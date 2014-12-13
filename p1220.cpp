#include <cstdio>
#include <cstring>

using namespace std;

int N, X = 0x80000000;
int F[101][101];

inline int update(int &x, const int y) {
	if (y > x)
		x = y;
	return x;
}

int main() {
	memset(F[1], 0x80, sizeof(int) * 100 * 101);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j) {
			int t;
			scanf("%d", &t);
			F[i][j] += t;
			update(F[i + 1][j], F[i][j]);
			update(F[i + 1][j + 1], F[i][j]);
		}
	for (int i = 0; i < N; ++i)
		update(X, F[N][i]);
	printf("%d\n", X), fflush(stdout);
	return 0;
}


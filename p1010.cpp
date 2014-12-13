#include <cstdio>

using namespace std;

int N, M;
bool D[16][16];
int F[16][16];

inline void deny(const int x, const int y) {
	if (x < 0 || x > N)
		return;
	if (y < 0 || y > M)
		return;
	D[x][y] = true;
}

void preproc(const int x, const int y) {
	static int dx[9] = {0, -1, -1, 1, 1, -2, -2, 2, 2};
	static int dy[9] = {0, -2, 2, -2, 2, -1, 1, -1, 1};
	for (int i = 0; i < 9; ++i)
		deny(x + dx[i], y + dy[i]);
}

int main() {
	scanf("%d%d", &N, &M);
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
		preproc(a, b);
	F[0][0] = 1;
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= M; ++j)
			if (D[i][j])
				F[i][j] = 0;
			else {
				if (i)
					F[i][j] += F[i - 1][j];
				if (j)
					F[i][j] += F[i][j - 1];
			}
	printf("%d\n", F[N][M]), fflush(stdout);
	return 0;
}


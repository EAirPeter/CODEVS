#include <cstdio>

using namespace std;

const int dx[4] = {1, 1, 2, 2};
const int dy[4] = {-2, 2, -1, 1};

int N, M;
int x1, y1, x2, y2;
long long F[51][51];

inline void proc(const long long x, const long long y, const long long z) {
	if (x < 1 || x > N)
		return;
	if (y < 1 || y > M)
		return;
	F[x][y] += z;
}

int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);
	F[x1][y1] = 1;
	for (int i = x1; i < x2; ++i)
		for (int j = 1; j <= M; ++j)
			for (int k = 0; k < 4; ++k)
				proc(i + dx[k], j + dy[k], F[i][j]);
	printf("%lld\n", F[x2][y2]), fflush(stdout);
	return 0;
}


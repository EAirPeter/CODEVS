#include <cstdio>

using namespace std;

int N, M;
int D[350];
int F[41][41][41][41];
int M1, M2, M3, M4;

inline void update(int &x, const int y) {
	if (y > x)
		x = y;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d", &D[i]);
	for (int i = 0; i < M; ++i) {
		int t;
		scanf("%d", &t);
		switch (t) {
		case 1:
			++M1;
			break;
		case 2:
			++M2;
			break;
		case 3:
			++M3;
			break;
		case 4:
			++M4;
			break;
		}
	}
#define FC F[i1][i2][i3][i4]
#define F1 F[i1 - 1][i2][i3][i4]
#define F2 F[i1][i2 - 1][i3][i4]
#define F3 F[i1][i2][i3 - 1][i4]
#define F4 F[i1][i2][i3][i4 - 1]
	for (int i1 = 0; i1 <= M1; ++i1)
		for (int i2 = 0; i2 <= M2; ++i2)
			for (int i3 = 0; i3 <= M3; ++i3)
				for (int i4 = 0; i4 <= M4; ++i4) {
					if (i1)
						update(FC, F1);
					if (i2)
						update(FC, F2);
					if (i3)
						update(FC, F3);
					if (i4)
						update(FC, F4);
					FC += D[i1 * 1 + i2 * 2 + i3 * 3 + i4 * 4];
				}
	printf("%d\n", F[M1][M2][M3][M4]), fflush(stdout);
	return 0;
}


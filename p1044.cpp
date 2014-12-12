#include <cstdio>

using namespace std;

int N;
int D[21];
int F1[21], F2[21];
int X1, X2;

inline int update(int &x, const int y) {
	if (y > x)
		x = y;
	return x;
}

int main() {
	while(scanf("%d", &D[N++]) == 1);
	--N;
	X1 = X2 = 1;
	for (int i = 0; i < N; ++i) {
		F1[i] = F2[i] = 1;
		for (int j = 0; j < i; ++j)
			if (D[j] >= D[i])
				update(X1, update(F1[i], F1[j] + 1));
			else
				update(X2, update(F2[i], F2[j] + 1));
	}
	printf("%d\n%d\n", X1, X2), fflush(stdout);
	return 0;
}


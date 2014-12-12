#include <algorithm>
#include <cstdio>

using namespace std;

class seg {
public:
	int a, b, c;
} D[1000];

bool operator <(const seg &a, const seg &b) {
	if (a.b != b.b)
		return a.b < b.b;
	if (a.a != b.a)
		return a.a < b.a;
	return a.c > b.c;
}

int N, F[1000001], Y = 1;

inline int update(int & x, const int y) {
	if (y > x)
		x = y;
	return x;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d%d", &D[i].a, &D[i].b, &D[i].c);
	sort(D, D + N);
	for (int i = 0; i < N; ++i) {
		while (Y <= D[i].b) {
			F[Y] = F[Y - 1];
			++Y;
		}
		update(F[D[i].b], F[D[i].a] + D[i].c);
	}
	printf("%d\n", F[D[N - 1].b]), fflush(stdout);
	return 0;
}


#include <algorithm>
#include <cstdio>

using namespace std;

int N, F[5000];

int main() {
	int c = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int t;
		scanf("%d", &t);
		if (c > 0 ? t > F[c - 1] : true)
			F[c++] = t;
		else
			*lower_bound(F, F + c, t) = t;
	}
	printf("%d\n", c), fflush(stdout);
	return 0;
}


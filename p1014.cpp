#include <cstdio>

using namespace std;

int M, N, X;
bool F[20001] = {true};

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; ++i) {
		int t;
		scanf("%d", &t);
		for (int j = M - t; j > -1; --j)
			if ((F[j + t] |= F[j]) && j + t > X)
				X = j + t;
	}
	printf("%d\n", M - X), fflush(stdout);
	return 0;
}


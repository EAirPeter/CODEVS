#include <cstdio>
#include <cstring>

using namespace std;

#define NOCHECK

class hint {
	friend bool operator <(const hint &a, const hint &b);
public:
	hint(const int x) {
		d[0] = x;
		z = 1;
		wrap();
	}

	hint() {
		z = 0;
	}

	inline bool defined() {
		wrap();
		return z;
	}

	inline void wrap() {
		while (z > 0 && !d[z - 1])
			--z;
	}
	inline static bool longer(const hint &a, const hint &b) {
		return a.z > b.z;
	}
	static NOCHECK hint plus(const hint &a, const hint &b) {
		int t = 0;
		hint res;
		for (int i = 0; i < b.z; ++i) {
			res.d[i] = a.d[i] + b.d[i] + t;
			if (res.d[i] < MDN)
				t = 0;
			else {
				res.d[i] -= MDN;
				t = 1;
			}
		}
		for (int i = b.z; i < a.z; ++i) {
			res.d[i] = a.d[i] + t;
			if (res.d[i] < MDN)
				t = 0;
			else {
				res.d[i] -= MDN;
				t = 1;
			}
		}
		res.z = a.z;
		if (t)
			res.d[res.z++] = t;
		res.wrap();
		return res;
	}
	void print() {
		wrap();
		if (!z)
			return (void) putchar('0');
		printf("%d", d[z - 1]);
		for (int i = z - 2; i > -1; --i)
			printf("%08d", d[i]);
	}
private:
	int z;
	int d[8];
	static const int MDN;
};

const int hint::MDN = 100000000;

bool operator <(const hint &a, const hint &b) {
	if (a.z != b.z)
		return a.z < b.z;
	for (register int i = a.z - 1; i > -1; --i)
		if (a.d[i] != b.d[i])
			return a.d[i] < b.d[i];
	return false;
}

hint operator +(const hint &a, const hint &b) {
	if (hint::longer(a, b))
		return hint::plus(a, b);
	else
		return hint::plus(b, a);
}

inline hint update(hint &x, const hint &y) {
	if (x < y)
		x = y;
	return x;
}

int N, M;
int D[80];
hint X, F[80][80];

hint dfs(const int l, const int r) {
	if (l == r)
		return hint(D[l]);
	if (F[l][r].defined())
		return F[l][r];
	F[l][r] = dfs(l + 1, r) + dfs(l + 1, r) + hint(D[l]);
	return update(F[l][r], dfs(l, r - 1) + dfs(l, r - 1) + hint(D[r]));
}

int main() {
	scanf("%d%d", &N, &M);
	while (N--) {
		for (int i = 0; i < M; ++i)
			scanf("%d", &D[i]);
		memset(F, 0, sizeof(F));
		X = X + dfs(0, M - 1) + dfs(0, M - 1);
	}
	X.print(), putchar('\n'), fflush(stdout);
	return 0;
}


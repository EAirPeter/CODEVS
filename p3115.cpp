#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define NOCHECK

class hint {
	friend bool operator <(const hint &a, const hint &b);
public:
	void NOCHECK trans(char *s) {
		z = 0;
		int i;
		char t;
		for (i = (int) strlen(s); i > 8; i -= 8) {
			t = s[i];
			s[i] = '\0';
			d[z++] = atoi(&s[i - 8]);
			s[i] = t;
		}
		t = s[i];
		s[i] = '\0';
		d[z++] = atoi(s);
		s[i] = t;
	}
	inline void wrap() {
		while (z > 0 && !d[z - 1])
			--z;
	}
	static NOCHECK hint minus(const hint &a, const hint &b) {
		int t = 0;
		hint res;
		for (int i = 0; i < b.z; ++i) {
			if (a.d[i] < b.d[i] + t) {
				res.d[i] = MDN + a.d[i] - b.d[i] - t;
				t = 1;
			}
			else {
				res.d[i] = a.d[i] - b.d[i] - t;
				t = 0;
			}
		}
		for (int i = b.z; i < a.z; ++i)
			if (a.d[i] < t) {
				res.d[i] = MDN + a.d[i] - t;
				t = 1;
			}
			else {
				res.d[i] = a.d[i] - t;
				t = 0;
			}
		res.z = a.z;
		res.wrap();
		return res;
	}
	void print() {
		if (!z)
			return (void) putchar('0');
		printf("%d", d[z - 1]);
		for (int i = z - 2; i > -1; --i)
			printf("%08d", d[i]);
	}
private:
	int z;
	int d[500];
	static const int MDN;
};

const int hint::MDN = 100000000;

bool operator <(const hint &a, const hint &b) {
	if (a.z != b.z)
		return a.z < b.z;
	return memcmp(a.d, b.d, a.z * sizeof(int)) < 0;
}

int main() {
	hint a, b;
	char S[1024];
	scanf("%s", S);
	a.trans(S);
	scanf("%s", S);
	b.trans(S);
	if (a < b)
		putchar('-'), hint::minus(b, a).print();
	else
		hint::minus(a, b).print();
	fflush(stdout);
	return 0;
}


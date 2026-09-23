#include <stdio.h>

int main()
{
	int t = 0, n = 0, e1 = 0, o1 = 0, num = 0;
	scanf("%d", &t);

	int results[101] = { 0 };

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);

		scanf("%d", &e1);
		scanf("%d", &o1);

		int pE = e1 & 1;
		int pO = o1 & 1;

		int ok = 1;
		for (int j = 2; j < n; j++) {
			scanf("%d", &num);

			int want = (j % 2 == 0) ? pE : pO;
			if ((num & 1) != want) {
				ok = 0;
			}
		}
		results[i] = ok;
	}

	for (int i = 0; i < t; i++) {
		printf(results[i] ? "YES\n" : "NO\n");
	}
}

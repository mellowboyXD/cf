#include <stdio.h>

int main(void)
{
        int n = 0;
        scanf("%d", &n);

        int count = 0;
        while (n > 0) {
                int p, t, v;
                scanf("%d %d %d", &p, &t, &v);

                if ((p + v + t) >= 2)
                        count++;
                n--;
        }

        printf("%d\n", count);
        return 0;
}

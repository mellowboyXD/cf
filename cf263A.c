#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int i, j;
        for (int k = 0; k < 5; k++) {
                char buf[11] = {0};
                fgets(buf, sizeof(buf), stdin);
                int j0, j1, j2, j3, j4;
                sscanf(buf, "%d %d %d %d %d\n", &j0, &j1, &j2, &j3, &j4);

                if (j0 == 1) {
                        j = 0;
                        i = k;
                } else if (j1 == 1) {
                        j = 1;
                        i = k;
                } else if (j2 == 1) {
                        j = 2;
                        i = k;
                } else if (j3 == 1) {
                        j = 3;
                        i = k;
                } else if (j4 == 1) {
                        j = 4;
                        i = k;
                }
        }

        int moves = abs(i - 2) + abs(j - 2);
        printf("%d\n", moves);
        return 0;
}

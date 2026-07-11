#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
        int n, k;
        scanf("%d %d\n", &n, &k);

        if (k > n || k < 1 || n < 1) {
                fprintf(stderr, "Invalid input\n");
                return 1;
        }

        char buf[1024];
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
                fprintf(stderr, "Error reading input\n");
                return 1;
        }

        int *scores =  malloc(n * sizeof(*scores));
        if (!scores) {
                perror("Could not malloc\n");
                return 1;
        }

        char *tok = strtok(buf, " ");
        for (int i = 0; i < n; i++) {
                if (tok == NULL) {
                        fprintf(stderr, "Invalid input\n");
                        return 1;
                }

                int score = atoi(tok);
                scores[i] = score;
                tok = strtok(NULL, " ");
        }

        int count = 0;
        int target = scores[k - 1];
        for (int i = 0; i < n && scores[i] >= target; i++) {
                if (scores[i] > 0 && scores[i] >= target)
                        count++;
        }

        printf("%d\n", count);

        free(scores);
        return 0;
}

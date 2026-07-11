#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
        char buf[102];
        int n;

        fgets(buf, sizeof(buf), stdin);
        n = strlen(buf);

        if (buf[n - 1] == '\n')
                buf[--n] = '\0';

        int count = 0;
        bool seen[26] = {0};
        for (int i = 0; i < n; i++) {
                int idx = buf[i] - 'a';

                if (!seen[idx]) {
                        count++;
                        seen[idx] = true;
                }
        }

        if (count % 2 == 0)
                printf("CHAT WITH HER!\n");
        else
                printf("IGNORE HIM!\n");

        return 0;
}

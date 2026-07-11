#include <ctype.h>
#include <stdio.h>
#include <strings.h>

int main(void)
{
        char str1[102] = {0};
        char str2[102] = {0};

        fgets(str1, sizeof(str1), stdin);
        fgets(str2, sizeof(str2), stdin);
        int n = strlen(str1);

        for (int i = 0; i < n; i++) {
                if (str1[i] == '\n' || str2[i] == '\n')
                        continue;

                char c1 = tolower(str1[i]);
                char c2 = tolower(str2[i]);

                if (c1 < c2) {
                        printf("-1\n");
                        return 0;
                } else if (c1 > c2) {
                        printf("1\n"); 
                        return 0;
                }
        }

        printf("0\n");

        return 0;
}

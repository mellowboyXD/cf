#include <stdio.h>

int main(void)
{
        int nlines = 0;
        scanf("%d\n", &nlines);

        int x = 0;
        while (nlines > 0) {
                char buf[5] = {0};
                fgets(buf, sizeof(buf), stdin);
                if (buf[1] == '+')
                        x++;
                else if (buf[1] == '-')
                        x--;
                nlines--;
        }

        printf("%d\n", x);
        return 0;
}

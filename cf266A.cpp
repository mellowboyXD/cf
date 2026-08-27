#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n = 0;
        string input;

        scanf("%d\n", &n); // scanf consumes the newline character
        getline(cin, input);

        int take = 0;
        for (int i = 0; i < input.length() - 1; i++) {
                if (input[i] == input[i + 1])
                        take++;
        }

        cout << take << "\n";
}

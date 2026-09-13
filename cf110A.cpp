#include <bits/stdc++.h>

using namespace std;

int main()
{
        long long n, c;
        cin >> n;

        for (c = 0; n > 0; n /= 10) {
                int d = n % 10;
                if (d == 4 || d == 7)
                        c++;
        }

        if (c == 4 || c == 7)
                cout << "YES\n";
        else
                cout << "NO\n";
}

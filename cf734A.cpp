#include <bits/stdc++.h>

using namespace std;

int main()
{
        long n = 0, a = 0, d = 0;
        string g;
        cin >> n >> g;

        for (long i = 0; i < n; i++) {
                if (g[i] == 'A') {
                        a++;
                } else {
                        d++;
                }
        }

        if (a > d) {
                cout << "Anton\n";
        } else if (d > a) {
                cout << "Danik\n";
        } else {
                cout << "Friendship\n";
        }
}

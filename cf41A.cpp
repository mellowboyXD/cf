#include <bits/stdc++.h>

using namespace std;

int main()
{
        string l, t;
        cin >> l >> t;

        reverse(l.begin(), l.end());
        if (l == t)
                cout << "YES\n";
        else 
                cout << "NO\n";

        return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() 
{
        int k, n, b;
        cin >> k >> n >> b;

        int cost = (b * (k + k*b) ) / 2;
        cout << max(cost - n, 0) << "\n";
}

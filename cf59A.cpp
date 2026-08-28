#include <bits/stdc++.h>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	// count upper
	int uc = 0;
        for (unsigned char c: input) {
                if (isupper(c))
                        uc++;
        }

        if (uc > input.length() - uc) {
                for (auto &c: input) {
                        c = toupper(static_cast<unsigned char>(c));
                }
        } else {
                for (auto &c : input) {
                        c = tolower(static_cast<unsigned char>(c));
                }
        }

        cout << input << "\n";
}

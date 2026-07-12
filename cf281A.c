#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	// word will not exceed 10^3 in length
	// take newline & terminating character into account
	char buffer[1002] = { 0 };

	char *word = fgets(buffer, sizeof(buffer), stdin);
	assert(word && "could not read input.");

	// remove trailing newline
	int n = strlen(word);
	if (word[n - 1] == '\n')
		word[--n] = '\0';

	word[0] = toupper(word[0]);
	printf("%s\n", word);
	return 0;
}

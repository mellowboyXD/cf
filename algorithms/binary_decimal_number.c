/**
 * Given n, find the multiple of x, m, such that n * m = x and x is made up of
 * only 0s and 1s. 
 *
 * n > 0
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum error_t {E_USAGE = 1, E_NEED_MORE_RAM, E_UNREACHABLE, E_CALC, E_OOB};

#define ERR_CALC_RESULT ((struct result_t){ 0, 0, E_CALC })
#define ERR_OOB_RESULT ((struct result_t){ 0, 0, E_OOB })

struct result_t {
	uint64_t x;
	uint64_t m;

	enum error_t _error;
};

struct node_t {
	uint64_t rem;
	int digit;
	int parent;
};

struct result_t find_binary_decimal_multiple(uint64_t n)
{
	struct node_t *q = malloc(n * sizeof(*q));
	if (!q) {
		return (struct result_t){ 0, 0, E_NEED_MORE_RAM };
	}

	bool *visited = calloc(n, sizeof(*visited));
	if (!visited) {
		free(q);
		return (struct result_t){ 0, 0, E_NEED_MORE_RAM };
	}

	int read = 0, write = 0;

	struct node_t root = { .rem = 1 % n, .digit = 1, .parent = -1 };
	q[write++] = root;
	visited[1 % n] = true;
	while (read < write) {
		struct node_t curr = q[read++];
		if (curr.rem == 0) {
			// found our r
			// reconstruct x
			read--;
			uint64_t x = 0;
			uint64_t place = 1;
			while (read >= 0) {
				struct node_t c = q[read];

				if (c.digit) {
					if (place > UINT64_MAX - x) {
						// would overflow: x + place
                                                free(q);
                                                free(visited);
						return ERR_CALC_RESULT;
					}

					x += place;
				}

				// go to parent
				read = c.parent;

				if (read >= 0) {
					if (place > UINT64_MAX / 10) {
						// would overflow: 10 * place
                                                free(q);
                                                free(visited);
						return ERR_CALC_RESULT;
					}

					place *= 10;
				}
			}

			free(q);
			free(visited);
			return (struct result_t){ x, x / n, 0 };
		}

		// append 0
		uint64_t r0 = (10 * curr.rem) % n;
		if (!visited[r0]) {
                        if (write >= n) {
                                free(q);
                                free(visited);
                                return ERR_OOB_RESULT;
                        }

			struct node_t node = { .rem = r0,
					       .digit = 0,
					       .parent = read - 1 };
			q[write++] = node;
			visited[r0] = true;
		}

		// append 1
		uint64_t r1 = (10 * curr.rem + 1) % n;
		if (!visited[r1]) {
                        if (write >= n) {
                                free(q);
                                free(visited);
                                return ERR_OOB_RESULT;
                        }

			struct node_t node = { .rem = r1,
					       .digit = 1,
					       .parent = read - 1 };
			q[write++] = node;
			visited[r1] = true;
		}
	}

	// unreacheable
	free(q);
	free(visited);
	return (struct result_t){ 0, 0, E_UNREACHABLE };
}

int main(int argc, char *argv[argc + 1])
{
	int64_t n;
	if (argc < 2) {
		if (scanf("%ld", &n) != 1) {
			fprintf(stderr, "[Usage]: bindec 7\n");
			fprintf(stderr, "n must be a valid integer.\n");
			return E_USAGE;
		}
	} else {
		char *end = NULL;
		n = strtol(argv[1], &end, 10);
		if (end && *end != '\0') {
			fprintf(stderr, "[Usage]: bindec 7\n");
			fprintf(stderr,
				"n must be a valid positive integer only.\n");
			return E_USAGE;
		}
	}

	if (n <= 0) {
		fprintf(stderr, "[Usage]: bindec 7\n");
		fprintf(stderr,
			"n must be a positive integer greater than 0.\n");
		return E_USAGE;
	}

	struct result_t result = find_binary_decimal_multiple(n);
	if (result._error != 0) {
                switch (result._error) {
                        case E_NEED_MORE_RAM:
		                fprintf(stderr, "Could not allocate. Not enough memory space.\n");
                                break;
                        case E_UNREACHABLE:
                                fprintf(stderr, "A supposedly unreacheable block of code was reached.\n");
                                break;
                        case E_CALC:
                                fprintf(stderr, "An overflow occurred during calculation.\n");
                                break;
                        case E_OOB:
                                fprintf(stderr, "An out-of-bounds error occured during calculation.\n");
                                break;
                        default:
                                fprintf(stderr, "An unknown error occured during calculation.\n");

                }

		return result._error;
	}

	printf("= %ld x %lu = %lu\n", n, result.m, result.x);
	return 0;
}

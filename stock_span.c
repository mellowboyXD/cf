/*
 * Given an array arr[] of daily stock prices, the stock span for i-th day is 
 * the count of consecutive days up to and including day i, such that each of 
 * those days had a stock price less than or equal to the price on day i.
 *
 * https://www.geeksforgeeks.org/dsa/the-stock-span-problem/
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 256

typedef struct {
        int __stack[STACK_SIZE]; /* stack container */
        int p;  /* stack pointer points to the next available pos */
} stack_t;

int s_peek(stack_t stack);
int s_pop(stack_t *stack);
void s_push(stack_t *stack, int value);

int *stock_span(int *arr, int n, int *retsize)
{
        stack_t stack = {0};

        int *spans = calloc(n, sizeof(int));
        if (!spans) {
                perror("Could not calloc\n");
                return NULL;
        }

        /*for (int i = 0; i < n; i++) {
                int curr = arr[i];
                int c = 1; // set to 1 since it is equal to itself
                for (int j = 0; j < i; j++) {
                        if(arr[j] < curr)
                                c++;
                }
                spans[i] = c;
        }*/

        /* 
         * The idea is to use a stack directly to find the index of the first
         * previous greater element for every day. Once we get the index, we can
         * compute the span as follows:
         *      `spans[i] = current_index - index_of_prev_greater_element` 
         */
        for (int i = 0; i < n; i++) {
                while (stack.p > 0 && arr[s_peek(stack)] <= arr[i])
                        s_pop(&stack);

                /* if stack is empty, all elements to the left are smaller */
                if (stack.p == 0)
                        spans[i] = i + 1;
                else
                        spans[i] = i - s_peek(stack);

                s_push(&stack, i);
        }

        *retsize = n;
        return spans;
}

int main(void)
{
        int stocks[] = {100, 80, 60, 120};
        int retsize = 0;
        int *spans = stock_span(stocks, 4, &retsize);

        for (int i = 0; i < retsize; i++) {
                printf("%d ", spans[i]);
        }
        printf("\n");

        free(spans);
        return 0;
}

int s_peek(stack_t stack)
{
        assert(stack.p > 0);
        return stack.__stack[stack.p - 1];
}

void s_push(stack_t *stack, int value)
{
        if (stack->p >= STACK_SIZE)
                return;

        stack->__stack[stack->p++] = value;
}

int s_pop(stack_t *stack)
{
        assert(stack->p > 0);
        return stack->__stack[--stack->p];
}

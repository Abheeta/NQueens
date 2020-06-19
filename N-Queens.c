#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<time.h>

int sols = 0; //contains the number of solutions

//This is a recursive function that adds one queen onto the board in each step and declares the board as a result once
//all queens have been added.
void nQueens (int n, int q, int cb[]) {
    int i, column, flag, n_placeholder;
    int x = (n+1)/2;
    if(n == q) {
        for (i = 1; i <= n; i++) 
            printf("%d  ", cb[i]);
        printf("\n");
        sols++;

        if (cb[1] <= n/2) {
            for (i = 1; i <= n; i++) 
                printf("%d  ", (n-cb[i]+1));
            printf("\n");
            sols++;
        }
    }

    else {
        n_placeholder = (q == 0) ? x : n;
        for (column = 1; column <= n_placeholder; column++) {
            flag = 1;

            for (i = 1; i <= q; i++)
            {
                if ((column == cb[i]) || ((int)fabs(q+1-i) == (int)fabs(column-cb[i])))
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1)
            {
                cb[q+1] = column;
                nQueens(n, q+1, cb);
            }
        }
    }
}

void main() {
    int n, q = 0, *cb;
    clock_t start, end;
    double time_used;

    printf("Enter input size: ");
    scanf("%d", &n);
    cb = (int *) malloc ((n+1) * sizeof(int));

    for (q = n; q > 0; q--)
        cb[q] = 0;

    printf("Output:\n");
    start = clock();
    nQueens (n, q, cb);
    end = clock();

    time_used = ((double)(end - start))/CLOCKS_PER_SEC; 
    printf("Time taken = %lf\n", time_used);
    printf("Number of solutions = %d", sols);
}
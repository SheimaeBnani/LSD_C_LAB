#include <stdlib.h>
#include <stdio.h>
#define N 10

double *DecomLU(double A[N][N], double B[N], int n)
{
        double *X;
        X = malloc(sizeof(double) * n);
        double L[N][N],Y[N];
        int i,j,k;
        double s;
        for( k = 0 ; k < n - 1 ; k++)
        {
                for(i = k + 1 ; i < n ; i++)
                {
                        L[i][k] = A[i][k] / A[k][k];
                        for(j = k + 1; j < n; j++)
                                A[i][j] = A[i][j] - L[i][k] * A[k][j];
                }
        }
        Y[0] = B[0];
        for(i = 1 ; i < n ; i++)
        {
                s = 0;
                for(j = 0 ; j < i ; j++)
                        s += L[i][j] * Y[j];
                Y[i] = B[i] - s;
        }
        X[n - 1] = Y[n - 1] / A[n - 1][n - 1];
        for(i = n - 2 ; i >= 0 ; i--)
        {
                s = 0;
                for(j = i + 1 ; j <= n - 1 ; j++)
                        s += A[i][j] * X[j];
                X[i] = (Y[i] - s) / A[i][i];
        }
        return (X);
}


int main()
{
 	 double   A[N][N], B[N];
 	 double   *X;
 	 int i,j,n;

	  printf("Enter the size of the matrix: ");
 	  scanf("%d", &n);

  /* Filling the matrix A */
 	 printf("Filling the matrix A\n");
 	 for(i = 0; i < n; i++)
 	 {
   		 for(j = 0; j < n; j++)
   	 	{
     			 printf("A[%d][%d] = ", i, j);
     			 scanf("%lf", &A[i][j]);
    	 	}
  	 }

  /* Filling the vector B*/
 	 printf("Filling the matrix B\n");
 	 for (i = 0; i < n; i++)
 	 {
   		 printf("B[%d] = ", i);
   		 scanf("%lf", &B[i]);
 	 }

  /* The calculation of the result */
	 X = DecomLU(A,B,n);

  /* Printing the results */
        printf("\nThe solution is : ");
        for (i = 0; i < n; i++)
                 printf("%lf\n", X[i]);

}


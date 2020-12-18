#include <stdio.h>
#include <stdlib.h>
#define N 10


double *Descente(double A[N][N], double B[N], int n)
{
 	  double *X;
	  X = malloc(sizeof(double) * n);
	  int i,j,k;
          double s;
	  X[0]=B[0]/A[0][0];
          for(i = 1; i < n; i++)
          {
                s=0;
                for(j = 0; j < i; j++)
                        s += A[i][j]* X[j];
                X[i] = (B[i]-s) / A[i][i];

          }

           return (X);
}


int main()
{
  	double  A[N][N], B[N];
  	double  *X;
  	int   i,j,n;

  	printf("Enter the size of the matrix: ");
  	scanf("%d", &n);

  /* Filling the matrix A */
  	printf("Filling the matrix A\n");
  	for( i = 0; i < n; i++)
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
  	X = Descente(A, B, n);
  
  /* Printing the results */
  	printf("\nThe solution is : ");
        for (i = 0; i < n; i++)
                 printf("%lf\n", X[i]);

}

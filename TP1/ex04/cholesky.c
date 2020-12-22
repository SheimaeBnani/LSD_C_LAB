#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define N 10

int main()
{
	int i, j, k, n;
        printf("Enter the size of the matrix: ");
        scanf("%d", &n);
        double C[N][N], A[N][N], B[N], S1, S2;
        double T[N][N], s;
	double *X;
        X = malloc(sizeof(double) * n);
        double *Y;
        Y = malloc(sizeof(double) * n);
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        printf("A[%d][%d]= ", i, j);
                        scanf("%lf", &A[i][j]);
                }
        }
        for(i=0;i<n;i++)
        {
                printf("B[%d]= ", i);
                scanf("%lf", &B[i]);
        }
        C[0][0]=sqrt(A[0][0]);
        for(i=1;i<n;i++)
                C[i][0]=A[i][0]/C[0][0];
        for(j=1;j<n;j++)
        {
                for(i=0;i<j - 1;i++)
                        C[i][j]=0;
                S1 = 0.0;
                for(k=0;k<j;k++)
                        S1+=pow(C[j][k], 2);
                C[j][j]=sqrt(A[j][j]-S1);
                for(i=j + 1;i<n;i++)
                {
                        S2 = 0.0;
                        for(k=0;k<j;k++)
                                S2+=C[i][k]*C[j][k];
                        C[i][j]=(1.0/C[j][j])*(A[i][j]-S2);
                }
        }
        printf("\n");
	printf("C= ");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                        printf("%lf\t", C[i][j]);
                 printf("\n");
        }
	printf("T= \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			T[i][j] = C[j][i];
			printf("%lf\t", T[i][j]);
		}
		printf("\n");
	}
	  Y[0] = B[0]/C[0][0];
        for(i = 1; i < n; i++)
        {
                s=0;
                for(j = 0; j < i; j++)
                        s += C[i][j]* Y[j];
                Y[i] = (B[i]-s) / C[i][i];

        }
        printf("\nY= ");
        for (i = 0; i < n; i++)
                 printf("%lf\n", Y[i]);
        X[n-1] = Y[n-1] / T[n-1][n-1];
        for(i = n-2; i >= 0; i--)
        {
                s = 0;
                for(j = i+1; j < n; j++)
                        s = s + T[i][j] * X[j];
                X[i] = (Y[i] - s) / T[i][i];
        }
        printf("\nX=  ");
        for (i = 0; i < n; i++)
                 printf("%lf\n", X[i]);

	return (0);
}


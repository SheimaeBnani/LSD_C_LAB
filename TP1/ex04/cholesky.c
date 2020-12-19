#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
	int i, j, k, n;
        printf("Enter the size of the matrix: ");
        scanf("%d", &n);
        double C[N][N], A[N][N], B[N], S1, S2;
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
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                        printf("%lf\t", C[i][j]);
                 printf("\n");
        }

  	return (0);
}
/*double Determinant(double C[N][N], int n);
{
                double s = 1, det = 0, D[N][N];
                int i,j,m,k,c;
                if(n == 1)
                {
                        return (C[0][0]);
                }
                else
                {
               		 det = 0;
               		 for(c=0;c<n;c++)
                	{
                       		 m = 0;
                       		 k = 0;
                       		 for(i=0;i<n;i++)
                        	{
                                	for(j=0;j<n;j++)
                                	{	
                                       		 D[i][j] = 0;
                                        	if(i!=0 && j!=c)
                                        	{
                                               		 D[m][k] = C[i][j];
                                               		 if(k<n-2)
                                                       		 k++;
                                               		 else
                                               		 {
                                                       		 k = 0;
                                                       		 m++;
                                                	}
                                        	}
                               		 }
                        	}
			det = det + s * (C[0][c] * determinant(D, n-1);
			s = -1 * s;
			}
		}
		return (det);
 }


*/

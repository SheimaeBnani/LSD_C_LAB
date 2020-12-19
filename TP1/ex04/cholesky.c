#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define N 10

int main()
{
	int i, j, k, n;
        printf("Enter the size of the matrix: ");
        scanf("%d", &n);
        double C[N][N], A[N][N], B[N], X[N], S1, S2;
        double T[N][N], IN[N][N], IT[N][N], Y[N], ratio, s;
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
	for(i=1;i<=n;i++)
	{
		 for(j=1;j<=n;j++)
	         {
			 if(i==j)
		          {
				   C[i][j+n] = 1;
			  }
			 else
			 {
				   C[i][j+n] = 0;
			 }
		 }
	 }
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n;j++)
		{
			 if(i!=j)
			 {
				 ratio = C[j][i]/C[i][i];
				 for(k=1;k<=2*n;k++)
				 {
					  C[j][k] = C[j][k] - ratio*C[i][k];
				  }
			 }
		 }
	 }
	for(i=1;i<=n;i++)
	 {
		 for(j=n+1;j<=2*n;j++)
		 {
			   	IN[i][j] = C[i][j]/C[i][i];
		 }
	 }
	 /* The inverse of C */
	 printf("\nThe inverse of C is:\n");
	 for(i=1;i<=n;i++)
	 {
		  for(j=n+1;j<=2*n;j++)
		  {
			  printf("%lf\t",C[i][j]);
		  }
		  printf("\n");
	 }
	/*The inverse of T */
         for(i=0;i<n;i++)
         {
                  for(j=0;j<n;j++)
                  {
                           if(i==j)
                           {
                                T[i][j+n] = 1;
                           }
                           else
                           {
                                T[i][j+n] = 0;
                           }
                  }
         }
         for(i=0;i<n;i++)
        {
                  for(j=0;j<n;j++)
                  {
                           if(i!=j)
                           {
                                    ratio= T[j][i]/T[i][i];
                                    for(k=0;k<2*n;k++)
                                    {
                                        T[j][k] = T[j][k] - ratio*T[i][k];
                                    }
                           }
                  }
         }
         for(i=0;i<n;i++)
        {
                  for(j=n;j<2*n;j++)
                  {
                        IT[i][j] = T[i][j]/T[i][i];
                  }
         }
         printf("\nThe inverse T is:\n");
         for(i=0;i<n;i++)
         {
                  for(j=n;j<2*n;j++)
                  {
                        printf("%lf\t",T[i][j]);
                  }
                  printf("\n");
         }
         /*Resulotion of the system*/
         printf("Y=I*B:\n");
         Y[0]=B[0]*IN[0][0];
 
         for(i=1;i<n;i++)
         {
              s=0;
              for(j=0;j<i;j++)
                         s+=C[i][j]*Y[j];
              Y[i]=(B[i]-s)*IN[i][i];
         }
         for(i=0;i<n;i++)
                  printf("%lf\t", Y[i]);
         printf("\n");
         Y[0]=B[0]/C[0][0];
         for(i=1;i<n;i++)
         {
                s=0;
                for(j=0;j<i;j++)
                {
                      s+=C[i][j]*Y[j];
                }
                Y[i]=(B[i]-s)/C[i][i];
         }
         for(i=0;i<n;i++)
         {
               printf("Y[%d]=%lf\t", i, Y[i]);
         }
         X[n-1]=Y[n-1]/T[n-1][n-1];
	for(int i=n-2;i>=0;i--)
	{
		s=0;
		for(j=i;j<n;j++)
			s=s+T[i][j]*X[j];
		X[i]=(Y[i]-s)/T[i][i];
	}
         for(i=0;i<n;i++)
         {
               printf("X[%d]=%lf\t", i, X[i]);
         }

		 return(0);
}


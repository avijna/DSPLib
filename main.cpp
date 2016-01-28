#include <stdio.h>
#include "UnitTest++.h"

//#include "koolplot.h"
//#include <QtGui>

using namespace std;
int fact(int);
int fibonacci(int);
int printsquare(int );

int main()
{

    int i, j;
    for(i=0; i<=10; i++) {
        printf("%d     %d \n", i, i*i);
    }

    for(i=0; i<10; i++) {
        for(j=0; j<i; j++)
            printf("*");

        printf ("\n");
    }
    printf("factorial of 5 is %d", fact(5));
    fibonacci(20);
    printsquare(20);
	 return UnitTest::RunAllTests();

}

int fact(int x) {

    if (x == 1)
        return 1;
    else
        return (x * fact(x -1) );
}

int fibonacci(int x) {
    int i, a=0, b=1, c;
        printf("fibonacci sequence of %d is ", x);
        printf ("%d ", a);
        printf ("%d ", b);
    for (i=0; i<=x; i++) {
        c = a+b;
        printf ("%d ", c);
        a=b;
        b=c;
    }
}


int printsquare(int n)
{
	int i, j;
	printf("\n");
	for(i = 0; i < n; i = i + 1)
		{
		for(j = 0; j < n; j = j + 1)
            if (i>0 && j>0 && i<n-1 && j<n-1) {
                printf(" ");
            }
            else
                printf("*");
		printf("\n");
		}
	return 0;
}

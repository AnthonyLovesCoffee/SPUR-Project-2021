#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_OF_BITS 53
#define ARRAY_SIZE 10

double laplaceDeriv(double b, double m){
    double y;
    double res;
    double h;
    double deriv;
    y = (rand()*1.0/(RAND_MAX + 1.0));
    h = ldexp((rand()*1.0)/(RAND_MAX+1.0),NUM_OF_BITS);
    if (y >= 0.5){
        deriv = -b / y;
        res = (-b * log(2.0*b*y) + m) + (h * deriv);
    }
    else {
        deriv = b / (1-y);
        res = (b * -log(2.0 - 2.0 * y) + m) + (h * deriv);
    }
    return res;
}

int main()
{
double doubleArr[ARRAY_SIZE];
int intArr[ARRAY_SIZE];
int i,j,p,found;
double x,y;

// We have see no numbers yet, so set array to zeros.
for (i = 0; i < ARRAY_SIZE; i++) {
	intArr[i] = 0;
}

// Look at 10 random number
for (i = 0; i < ARRAY_SIZE; i++){
   //x = laplaceDeriv(6.3, 2.0);
   x = log(1.0/3.14159265358979323846 + ldexp(i*1.0, -54));

   //output the array's elements
   printf("doubleArr:\n");
   for (j = 0; j < ARRAY_SIZE; j++){
       printf("%f %d\n", doubleArr[j], intArr[j]);
   }

   found = 0;
   for (p = 0;p < ARRAY_SIZE && found == 0; p++){
       if (doubleArr[p] == x && intArr[p] >= 1){
           intArr[p] += 1;
           found +=1;
        } else if (intArr[p] == 0) {
           doubleArr[p] = x;
           intArr[p] = 1;
           found += 1;
        }
    }
}
//output the array's elements
printf("Final doubleArr:\n");
  double difference = 0;
  for (j=0; j<ARRAY_SIZE; j++){
    if (intArr[j] == 0){
     printf("%0.50e %d\n", doubleArr[j], intArr[j]);
    }
     if (j<ARRAY_SIZE-1 && intArr[j+1] != 0) {
       for (x = nextafter(doubleArr[j],doubleArr[j+1]); x != doubleArr[j+1]; x = nextafter(x,doubleArr[j+1])){
           printf("%0.50e %d\n", x, 0);
       }
     }
}
return 0;
}


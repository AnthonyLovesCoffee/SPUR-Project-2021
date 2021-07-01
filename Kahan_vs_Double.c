#include <stdio.h>
#include <stdlib.h>

/* function declarations
@param: takes integer "num", the number you would like to sum up to from 1

@returns: the sum of all the numbers from 1 to "num" (Up) OR "num" to 1 (Down)
*/

void mainF(int num);
double doubleSummationUp(int num);
double doubleSummationDown(int num);
double kahanSummationUp(int num);
double kahanSummationDown(int num);
double telescopingMethod(int num);

int main()
{
    int num;
    printf("Please enter number");
    scanf("%d", &num);
    if (num <= 0){
        printf("Error");
        exit(1);
    }
    else{
        mainF(num);
    }
    return 0;
}

double doubleSummationUp(int num){
    double res = 0.0; // local var to hold result

    for (int i=1; i<=num; i++){
        res += ((1.0/(i+1)) - (1.0/(i+2)));
    }

    return res;
}

double doubleSummationDown(int num){
    double res = 0.0;
    int i = num;

    for (i; i>=1;i--){
        res += ((1.0/(i+1)) - (1.0/(i+2)));
    }

    return res;
}

double kahanSummationUp(int num){
    double res = 0.0; // local var to hold result
    double error = 0.0; // local var to hold error
    double newRes, y, term; // temp vars

    for(int i=1; i<=num; i++){
        term = ((1.0/(i+1.0)) - (1.0/(i+2.0)));
        y = term - error;
        newRes = res + y;

        /*
        the error is always 0 when newRes is evaluated from the above expression,
        whenever there is a loss however, the higher-order y is subtracted from the error,
        this cancels out the y and leaves the lower-order error
        */

        error = (newRes - res) - y;
        res = newRes;
    }
    return res;
}

double kahanSummationDown(int num){
    int i = num;
    double res = 0.0; // local var to hold result
    double error = 0.0; // local var to hold error
    double newRes, y, term; // temp vars

    for(i; i>=1; i--){
        term = ((1.0/(i+1.0)) - (1.0/(i+2.0)));
        y = term - error;
        newRes = res + y;

        error = (newRes - res) - y;
        res = newRes;
    }
    return res;
}

double telescopingMethod(int num){
    double res = 0.0;
    double term = (1.0/(num+2.0));
    res = 0.5 - term;
    return res;
}

void mainF(int num){

    double doubleUp;
    doubleUp = doubleSummationUp(num);
    printf("Sum up to 100,000 using doubles = %f\n", doubleUp);

    double doubleDown;
    doubleDown = doubleSummationDown(num);
    printf("Sum down from 100,000 using doubles = %f\n", doubleDown);

    double kahanUp;
    kahanUp = kahanSummationUp(num);
    printf("Sum up to 100,000 using Kahan = %g\n", kahanUp);

    double kahanDown;
    kahanDown = kahanSummationDown(num);
    printf("Sum down from 100,000 using Kahan = %g\n", kahanDown);

    double differenceDoubleKahanUp = doubleUp - kahanUp;
    printf("Difference counting upwards = %g\n", differenceDoubleKahanUp);

    double differenceDoubleKahanDown = doubleDown - kahanDown;
    printf("Difference counting downwards = %g\n", differenceDoubleKahanDown);

    printf("Telescoping Method = %g\n", telescopingMethod(num));

    printf("Telescoping vs doubleUp = %g\n", (telescopingMethod(num) - doubleUp));
    printf("Telescoping vs kahanUp = %g\n", (telescopingMethod(num) - kahanUp));
    printf("Telescoping vs doubleDown = %g\n", (telescopingMethod(num) - doubleDown));
    printf("Telescoping vs kahanDown = %g\n", (telescopingMethod(num) - kahanDown));
}

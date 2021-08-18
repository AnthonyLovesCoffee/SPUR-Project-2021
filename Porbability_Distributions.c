#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double expoDistribution(double lambda){
    double y;
    y = (rand()*1.0)/(RAND_MAX + 1.0);
    return -log(1- y) / lambda;
}

double findAvg(double sum, int n){
    return sum/n;
}

double weibullDistribution(double lambda, double k){
    double y;
    double res;
    y = (rand()*1.0)/(RAND_MAX + 1.0);
    res = pow(-log(1-y), 1.0/k) * lambda;
    return res;
}

double paretoDistribution(double xm, double alpha){
    double y;
    double res;
    y = (rand()*1.0/(RAND_MAX + 1.0));
    res = xm / pow((1-y), 1.0/alpha) ;
    return res;
}

double paretoAvg(double xm, double alpha){
    return alpha * xm / (alpha-1);
}

int main()
{
    int sample = 1000;
    int i;
    double res = 0.0;
    double randNum;
    for (i=0; i<sample; i++)
    {
        randNum = paretoDistribution(6.3, 2.0);
        res += randNum;
        printf("%f\t", randNum);
    }
    printf("\nThe mean of the pareto numbers: %f\n", paretoAvg(6.3, 2.0));
    printf("\nThe sample mean: %f\n", findAvg(res, sample));
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[],int n,double b[]){
    double sum=0, sum2=0, times=1, sumh=0, max=-999, min=999;
    for(int i=0 ; i<n ; i++){
        sum += a[i];
    }
    b[0] = sum/n;
    for(int i=0; i<n ; i++){
        sum2 += pow(a[i] - (sum/(double)n),2);
    }
    b[1] = sqrt(sum2/(double)n);
    for(int i=0 ; i<n ; i++){
        times *= a[i];
    }
    b[2] = pow(times,1/(double)n);
    for(int i=0 ; i<n ; i++){
        sumh += 1/a[i];
    }
    b[3] = (double)n/sumh;
    for(int i=0 ; i<n ; i++){
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    b[4] = max;
    b[5] = min;
}
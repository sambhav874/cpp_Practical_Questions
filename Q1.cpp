//Program to compute the sum of the first n terms of the following series:
//S=1-1/(2*2)+1/(3/3)-...1/(n*n)

#include<iostream>
#include <math.h> //maths header file is required to use the pow function i.e used to specify the powers raised to the numbers.
using namespace std;

//double type if used because the function is defined with the double data type because of the minute calculations performed.
double SumTilln(int n){
    
    double sum=0.0;
    
    for(int i=1;i<=n;i++){

        double tempSum=pow(-1,i+1)*(1.0/pow(i,i));
        sum+=tempSum;

        
// the loop is starting from 1 because if it will start from 0 it will would automatically result in wrong calculation.

//The tempSum here defines the equations in form of pow function which actually denotes that -1 carries the power of i+1 multiplied to 1/i to the power of i.

//In every iteration the loop will increment the calue of i and tempSum into the sum.
        
    }

    cout<<"The sum is "<<sum<<endl;
    return 0;
}


int main(int argc,char* argv[]){
    double n;

     if (argc > 1) {
        n = atoi(argv[1]);
    }
    else {
        cout << "Enter the value of n: ";
        cin >> n;
    }
    return
    SumTilln(n);
    cout<<endl;
    cout<<endl;

}
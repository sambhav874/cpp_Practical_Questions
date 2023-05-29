#include<iostream>
using namespace std;

//Write a program to calculate GCD of two numbers.
int gcd(int a , int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);

}

int main(){
    int num1,num2;

    cout<<"\nEnter number 1 : ";
    cin>>num1;

    cout<<"\nEnter number 2 : ";
    cin>>num2;


    int resultingNum= gcd(num1,num2);

    cout<<"The greatest common divisor of "<<num1<<" and "<<num2<<" is "<<resultingNum<<"."<<endl;
}
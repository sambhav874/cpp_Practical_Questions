//Write a program to search a given element in a set of N numbers.

#include<iostream>
#include <set>
using namespace std;

void findNum(set<int> val,int b){

    int index=0;
    for (auto v:val){
        index++;
        //auto keyword in C++ will analyze the variable's data type when used with variables. The compiler decides the data type for a variable by looking at its initialization.
        if(b==v){ 
            cout<<"Element is present at "<<index<<" index."<<endl;
            //checking if the target number is equal to iterating element.
        }
        else{
            cout<<endl;
        }
    }
}
int main(){
    

    int a;
    cout<<"Enter the total number of elements to add in the set.";
    cin>>a;
// to create a set of a user defined size.
    set<int> val;
    for(int i=0;i<a;i++){
        int num;
        cin>>num;
        val.insert(num);
        //adding the user defined elements into the set.
    }
    int b;
    cout<<"Enter the element you need to find. ";
    cin>>b;
// b here is the target element that is to be searched.
    findNum(val,b);
    
    
    
    
}
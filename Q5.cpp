#include <iostream>
using namespace std;
void mergeTwoArrays(int arr1[],int arr2[],int arr3[],int n1 ,int n2){

int i=0,j=0,k=0;

    while(i<n1){
        arr3[k++]=arr1[i++];
    }
// traverse the array until the resulting array have all the elements of the input array.
    while(j < n2){
      arr3[k++] = arr2[j++];
    }
// traverse the array until the resulting array have all the elements of the input array.

sort(arr3, arr3+n1+n2);
//sorting the resulting array by specifying the array and the index till which we have to sort the values.
}


   

int main(){

    int range,range1;

    cout<<"Enter the total number of elements in array 1.";
    cin>>range;
    cout<<endl;
    int arr1[range];

    for(int i=0;i<range;i++){
        cin>>arr1[i];
    }
// getting a user defined input for the array1 that is going to be added in the resulting array.
    cout<<endl;
    cout<<"[";

    for(int i=0;i<range;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"]";

    cout<<endl;
    cout<<endl;


    cout<<"Enter the total number of elements in array 2.";
    cin>>range1;
    cout<<endl;
    int arr2[range1];
    for(int i=0;i<range1;i++){
        cin>>arr2[i];
    }
// getting a user defined input for the array2 that is going to be added in the resulting array.
    cout<<"[";

    for(int i=0;i<range;i++){
        cout<<arr1[i]<<" ";
    }

    cout<<"]";

    cout<<endl;
    cout<<endl;

int n1=sizeof(arr1)/sizeof(arr1[0]);
int n2=sizeof(arr2)/sizeof(arr2[0]);
//obtaining the size of the arrays to create a resulting array of the same size.

cout<<endl;
cout<<endl;

int arr3[n1+n2];

mergeTwoArrays(arr1,arr2,arr3,n1,n2);
//calling the function.

cout<<"[";
for(int j=0;j<n1+n2;j++){
    cout<<arr3[j]<<" ";
}
cout<<"]";
//printing the resulting array.
   
}
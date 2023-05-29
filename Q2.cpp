//Program to remove the duplicate value in an array


#include <iostream>
using namespace std;


void createArray(int n,int array[]){
            
    for (int i=0;i<n;i++){
        cin>>array[i];
    }
    
    
};
void returnArray(int n, int array[]){
            
    for (int j=0;j<n;j++){
        cout<<array[j]<<"  ";
    }
};

void deleteDuplicates(int n, int array[]){
    for(int i=0;i<n;i++){
        for (int j=i+1;j<n;){
            if (array[i]==array[j])
            {
                for(int k=j;k<n;k++){
                    array[k]=array[k+1];
                    
                }
                n--;
                
            }
            else{
                j++;
            }
        }
    }
}

int main(){
    int n;
    int ar_1[n];
    cout<<"Enter the total number of elements to be present in the array."<<endl;
    cin>>n;
    createArray(n,ar_1);
    returnArray(n,ar_1);
    cout<<endl;
    cout<<endl;
    cout<<"After the deletion of duplicate elements the array looks like: "<<endl;
    deleteDuplicates(n,ar_1);
    returnArray(n,ar_1);


}
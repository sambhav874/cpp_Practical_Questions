#include <iostream>
using namespace std;
#include <string>
#include <cctype>

void add_1(string text){
    int count;
    count=0;  
                
    for(int i=0;i<text.length();i++){
    
                cout<<text[i]<<"--"<<count++<<endl;
               
    }
}
void concatenate(string str1, string str2){
    
    cout<<str1<<str2;
}

void compare(string str1,string str2){
    int str3;
    str3=str1.compare(str2);
    if(str3<0){
        cout<<str1<<" is smaller than "<<str2<<endl;
    }
    else if(str3>0){
        cout<<str1<<" is greater than "<<str2<<endl;
    }
    else{
        cout<<"Both are equal."<<endl;
    }
}

void length(string str){
    int count=0;
    char *ptr;

    ptr=&str[0];
   while(*ptr){
    count++;
    ptr++;
    }
    cout<<"The length of the string is "<<count<<endl;
//* operator is used to refer to a pointer.
//& operator is used to initialize a pointer.
}

void toUpperCase(string str){
    
  // Loop through each character in the string
  for (int i = 0; i < str.length(); i++) {
    // If the character is lowercase, convert it to uppercase
    if (islower(str[i])) {
      str[i] = toupper(str[i]);
    }
  }
  
  // Print the modified string
  cout << str << endl;

}

void reverse(string str){

    for(int i=str.length();i>=0;i--){
        cout<<str[i];
    }

}

void addAtAddress(int position,string str,string mainStr){


    mainStr.insert(position,str);
    cout<<mainStr;
    


}
    
    


void menu(){
    int input;
    string str;
    string str1;
    string str2;
    string mainStr;
    int position;
    cout<<"\n\n\t\tEnter the function you want to perform.\t\t\n\n"
    <<"1--- To know the address of each character in string\t\t\n\n"
    <<"2--- Concatenate two strings.\t\t\n\n"
    <<"3--- Compare two strings.\t\t\n\n"
    <<"4--- To calculate length of the string.\t\t\n\n"
    <<"5--- To convert all lowercase characters to uppercase.\t\t\n\n"
    <<"6--- To reverse the string.\t\t\n\n"
    <<"7--- Insert a string in another string at a user specified position.\t\t\n\n"
;
    cin>>input;
    switch (input)
    {
    case 1:
        cout<<"Enter a string."<<endl;
        cin>>str;
        add_1(str);
        cout<<endl;
        break;
    
    case 2:
        cout<<"Enter string 1."<<endl;
        cin>>str1;
        cout<<"Enter string 2."<<endl;
        cin>>str2;
        concatenate(str1,str2);
        cout<<endl;
        break;
    

    case 3:
        cout<<"Enter string 1."<<endl;
        cin>>str1;
        cout<<"Enter string 2."<<endl;
        cin>>str2;
        compare(str1,str2);
        cout<<endl;
        break;
    

    case 4:
        cout<<"Enter a string ."<<endl;
        cin>>str;
        cout<<endl;
        length(str);
        cout<<endl;
        break;
    

    case 5:
        cout<<"Enter a string ."<<endl;
        cin>>str;
        cout<<endl;
        cout<<"The string looks like ";
        toUpperCase(str);
        cout<<endl;
        break;

    case 6:
        cout<<"Enter a string ."<<endl;
        cin>>str;
        cout<<endl;
        cout<<"The string looks like ";
        reverse(str);
        cout<<endl;
        break;
    

    case 7:
        cout<<"Enter string in which you want to add ."<<endl;
        cin>>mainStr;
        cout<<endl;
        cout<<"Enter string you want to add ."<<endl;
        cin>>str;
        cout<<endl;
        cout<<"Enter the position where you want to add ."<<endl;
        cin>>position;
        cout<<endl;
        cout<<"The string looks like ";
        addAtAddress(position,str,mainStr);
        cout<<endl;
        break;
    

    default:
        cout<<"Invalid input.";
        break;
    }
    
}



int main(){
    menu();
    
}
#include<iostream>
using namespace std;

void count_char(int a,string str){

	int count=0;
	for(int i=0;i<str.length();i++){
	//Now we can access all the letters now we have to compare all the letters
		for(int j=0;j<str.length();j++){
			if(str[i]==str[j]){
				count+=1;
			}
		}
		//if i==0 means its the first letter so we wont check it and print it
		if(i==0){
		    cout<<"\nThe number of occurence of '"<<str[i]<<"' is: "<<count;
		    count=0;
	    } 
	    else{
	    	bool c=true; //let us consider that word had occured only once
	    	//if it occur again then we will change it ot false

	    	//loop for checking the repetition
	    	for(int j=i-1;j>=0;j--){  //here we will go in reverse direction from i to 0
	    		if(str[i]==str[j]){ 
	                c=false;   //if condition is true means letter is repeated so c changed to false
	    			break;    //if it already occured once then we no need to check it again
				}
				else{
					continue; //means continuation of checking
				}
			}
			if(c){  //here if c is true means it occured only once if it false the there is repetetion
			    cout<<"\nThe number of occurence of '"<<str[i]<<"' is:"<<count;

			    //count=0 to start counting again for next letter
			    //value of d and y are wrong because if c is false count wont be 0 so we need to move it
			}
		}
		count=0;
		//after moving count out of else the result is as per desired
	}
}
int main(int argc,char* argv[]){

	cout<<"\n\t\tThis a program that prints a table indicating "<<"\n\t the number of occurrences of each alphabet in the text entered as command line arguments\n" <<"-------------------------------------------------------------------------------------------------------\n";

	//argc count the words in command line cout<<argc;
	//first word is the name of our file
 
	//by now we can only pass each word at a time through argv[]

	//so we will create a string and concatinate all the word one by one
	string str;
	cout<<"\nYour String is:"<<str;
    cin>>str;
	count_char(argc,str);
	cout<<"\n------------------------------------------------------------------\n";
	return 0;
}
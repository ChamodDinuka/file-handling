#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;
class subject{
	private:
		
	public:
		string subname;
		int num;
		int regnum[100];
		int marks[100];
		int swap;
		int change;
		char grade;
};
const int MAXSUBJECTS=10;
const int MAXSTUDENT=100;
subject x[10];
int i=0,j=0,k,n,MAX;
void Display_sub();
void Display_stu();
//void sub_sum();
//void save();
int main(){
 	ifstream get("sujdata.txt");
 		string subname;
		int num;
		int regnum[3];
		int marks[3];
 	while(get>>x[i].subname>>x[i].num){
 			
 			j=0;
 	  	while(j<x[i].num){
 	  		get>>x[i].regnum[j]>>x[i].marks[j];
 	  		j++;
		   }
 		i++;
	 }MAX=i;
	for(k=0;k<MAX;k++){
	
    for(j=0;j<x[k].num;j++)
    {
    	for(i=0;i<x[k].num-1;i++){
    		if(x[k].regnum[i]>x[k].regnum[i+1]){
    			x[k].swap=x[k].regnum[i];
    			x[k].regnum[i]=x[k].regnum[i+1];
    			x[k].regnum[i+1]=x[k].swap;
    			x[k].change=x[k].marks[i];
    			x[k].marks[i]=x[k].marks[i+1];
    			x[k].marks[i+1]=x[k].change;
			}
    		
		}
    	
   	}} 
	   
	   while(n!=5){
	   	cout<<"press 1 to Display subject \n";
	   	cout<<"press 2 to Display student \n";
	   	cout<<"press 3 to Display subject summary \n";
	   	cout<<"press 4 to save summaries \n";
	   	cout<<"press 5 to Exit program \n";
	    	cin>>n;
	    	switch(n){
	    		case 1:
	    			Display_sub();
	    			break;
	    		case 2:
	    			Display_stu();
	    			break;
	    		case 3:
	    		//	sub_sum();
	    			break;
	    		case 4:
	    		//	save();
	    			break;
	    		case 5:
				    exit(EXIT_FAILURE);	
				default:
				    cout<<"\nplease insert correct number!\n\n";    
				    system("pause");
					
			}
	   
	   }
}
void Display_sub(){
	string name;
	cout<<"enter subject code"<<endl;
	cin>>name;
	i=0;
	while(x[i].subname!=name){
		i=i+1;
		if(i==MAX){
		
    	cout<<"\nERROR :subject code is not found \n";
    	break;}
	}
	for(j=0;j<x[i].num;j++){
		cout<<x[i].regnum[j]<<" "<<x[i].marks[j]<<" ";
		if(x[i].marks[j]<30){
			cout<<"F\n";
		}else if(x[i].marks[j]>=30 && x[i].marks[j]<40){
			cout<<"D\n";
		}else if(x[i].marks[j]>=40 && x[i].marks[j]<55){
			cout<<"C\n";
		}else if(x[i].marks[j]>=55 && x[i].marks[j]<70){
			cout<<"B\n";
		}else{
			cout<<"A\n";
		}
	}system("pause");
}
void Display_stu(){
	int sn;
	int count=0,compair=0;
	cout<<"Enter the student number\n";
	cin>>sn;
	for(i=0;i<MAX;i++){
		compair=x[i].num+compair;
		for(j=0;j<x[i].num;j++){
			if(sn==x[i].regnum[j]){
				cout<<x[i].subname<<" "<<x[i].marks[j]<<" ";
				if(x[i].marks[j]<30){
				cout<<"F\n";
				}else if(x[i].marks[j]>=30 && x[i].marks[j]<40){
				cout<<"D\n";
				}else if(x[i].marks[j]>=40 && x[i].marks[j]<55){
				cout<<"C\n";
				}else if(x[i].marks[j]>=55 && x[i].marks[j]<70){
				cout<<"B\n";
				}else{
				cout<<"A\n";
				}break;
			
			}else{
				count++;
		    }
			}
		
	}
if(count==compair){
	cout<<"\nIndex not found\n";
}
 system("pause");
}

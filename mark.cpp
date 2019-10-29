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
void sub_sum(){
	int ave=0,numA=0,numB=0,numC=0,numD=0,numF=0,i=0;
	string name;
	float SD,var=0;
	cout<<"enter subject code"<<endl;
	cin>>name;
	while(x[i].subname!=name){
		i=i+1;
			if(i==MAX){
		
    	cout<<"\nERROR :subject code is not found \n";
    	break;}
	}
	if(i!=MAX){
	
	for(j=0;j<x[i].num;j++){
		ave=ave+(x[i].marks[j]/x[i].num);
	}for(j=0;j<x[i].num;j++){
		if(x[i].marks[j]<30){
			numF++;
		}else if(x[i].marks[j]>=30 && x[i].marks[j]<40){
			numD++;
		}else if(x[i].marks[j]>=40 && x[i].marks[j]<55){
			numC++;
		}else if(x[i].marks[j]>=55 && x[i].marks[j]<70){
			numB++;
		}else{
			numA++;
		}
}
    for(j=0;j<x[i].num;j++){
    	var=((float)x[i].marks[j]-ave)*((float)x[i].marks[j]-ave)/x[i].num+var;
	} SD=sqrt(var);
	cout<<"\nAvearge = "<<ave<<endl;
	cout<<"Standed deviation = "<<SD<<endl;
	cout<<"Number of A's : "<<numA<<"\nNumber of B's : "<<numB<<"\nNumber of C's : "<<numC<<endl;
	cout<<"Number of D's : "<<numD<<"\nNumber of A's : "<<numF<<endl<<endl;
	
}else{
	system("pause");
}
}
void save(){
	ofstream out("summdata.txt");
    
	float a,b,c,d,f;
	for(i=0;i<MAX;i++){
	float numA=0,numB=0,numC=0,numD=0,numF=0;
	for(j=0;j<x[i].num;j++){
		if(x[i].marks[j]<30){
			numF++;
		}else if(x[i].marks[j]>=30 && x[i].marks[j]<40){
			numD++;
		}else if(x[i].marks[j]>=40 && x[i].marks[j]<55){
			numC++;
		}else if(x[i].marks[j]>=55 && x[i].marks[j]<70){
			numB++;
		}else{
			numA++;
		}
    }a=(numA/x[i].num)*100.0;
     a=((float)((int)(a*10)))/10;
     b=(numB/x[i].num)*100.0;
     b=((float)((int)(b*10)))/10;
     c=(numC/x[i].num)*100.0;
     c=((float)((int)(c*10)))/10;
     d=(numD/x[i].num)*100;
     d=((float)((int)(d*10)))/10;
     f=(numF/x[i].num)*100;
     f=((float)((int)(f*10)))/10;
     out<<x[i].subname<<" "<<x[i].num<<" A "<<a<<"% B "<<b<<"% C "<<c<<"% D "<<d<<"% F "<<f<<"%"<<endl;
}
 out.close();
 cout<<"\nsummaries of the all subject have been stored in 'summdata.txt'\n\n";
system("pause");
}

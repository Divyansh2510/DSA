//These program finds the GCD 

#include<iostream>
using namespace std;

int GCD(int a,int b){
	while(a>0 && b>0){
	if(a>b){
		 a = a%b;
	}
	else{
		b = b%a;
	}
  }
  if (a==0) return b;
  return a;
	
}

int main(){
	int a  = 0;
	int b = 28;
	cout<<GCD(a,b);
	return 0;
}

#include<iostream>
using namespace std;
void toh(int n,char s,char h,char d);
int main()
{
	int n;
	cout<<"enter the default disk"<<endl;
	cin>>n;
	toh(n,'s','h','d');
	return 0;
	}
void toh(int n,char s,char h,char d){
	if(n==1)
	{
		cout<<"Moved disk "<<n<<" from "<<s<<" to "<<d<<endl;
	}
	else{
		toh(n-1,s,d,h);
		cout<<"Moved disk "<<n<<" from "<<s<<" to "<<d<<endl;
		toh(n-1,h,s,d);
	}
}

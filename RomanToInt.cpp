//Here in these code we taken a Roman no. as input and then converted it into an Integer.

#include<iostream>
#include<string>
#include<unordered_map> 
using namespace std;

int romanToInt(string s){
unordered_map<char,int> items = {{'I',1},{'V',5},{'X',10},{'L',50},
                                {'C',100},{'D',500},{'M',1000}};
 int n= s.size();
 int total =0 ;
for(int i=0;i<n;i++){
	if(i+1<n && items[s[i]]<items[s[i+1]]){
		total -= items[s[i]];
	}
	else{
		total += items[s[i]];
	}
  }
   return total;
}

int main(){
	 cout<<romanToInt("DV");
	 return 0;
}
        

#include<iostream>
using namespace std;

int getSum(int a, int b) {
        int c=0;
        while(b!=0){
            c=a&b;
            a=a^b;
            b=c<<1;
        }
        return a;
    }
    
int main(){
	cout<<getSum(1,2);
	return 0;
}

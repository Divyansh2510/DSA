 #include<iostream>
 using namespace std;
 
  int findComplement(int num) {
        int mask = 0;
        int temp = num;

        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return num ^ mask;
    }

int main(){
	cout<<findComplement(5);
	return 0;
}

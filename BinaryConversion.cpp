// Here we  are given a Binary string and we can use FLIP and DELETE operations on it to convert a string with
// 0's only . Atlast we want to return the minimum operation required for the conversion.

#include <iostream>
using namespace std;

int Delete(string Binary, int size, int CountOp);

int Flip(string Binary, int size, int CountOp) {
    for (int i = 0; i < size; i++) {
        Binary[i] = (Binary[i] == '0') ? '1' : '0';
    }
    CountOp++;
    return Delete(Binary, size, CountOp);
}

int Delete(string Binary, int size, int CountOp) {
    for (int i = 0; i < size;) {
        if (Binary[i] == '0') {
            i++;
        } else {
            CountOp++;
            i++;
        }
    }
    return CountOp;
}

int invertBinary(string Binary) {
    int size = Binary.length();
    int CountOp = 0;
    int Count_0 = 0;
    int Count_1 = 0;

    for (int i = 0; i < size; i++) {
        if (Binary[i] == '0') {
            Count_0++;
        } else {
            Count_1++;
        }
    }

    if (Count_1 > Count_0) {
        return Flip(Binary, size, CountOp);
    } else if(Count_1<Count_0) {
        return Delete(Binary, size, CountOp);
    }else if(Count_1==0 && Count_0==1){
    	return 0;
	}else{
		return 1;
	}
}

int main() {
    cout << invertBinary("1");
    return 0;
}


//Delete columns of to make string sorted 
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int count = 0;

        for (int col = 0; col < cols; col++) {
            for (int row = 0; row < rows - 1; row++) {
                if (strs[row][col] > strs[row + 1][col]) {
                    count++;      // column is not sorted
                    break;        // move to next column
                }
            }
        }

        return count;
    }
    
int main(){
	vector<string> str = {"cba","daf","ghi"};
	cout<<minDeletionSize(str);
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;

vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            string s = to_string(num);

            for (char ch : s) {
                ans.push_back(ch - '0');
            }
        }

        return ans;
    }
    
int main(){
	vector<int> n = {12,11};
	vector<int> a = separateDigits(n);
	for(int n : a){
		cout<<n;
	}
	return 0;
}

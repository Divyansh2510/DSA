#include<iostream>
#include<vector>
using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;

        while(i < n1 && j < n2) {

            if(nums1[i] < nums2[j]) {
                i++;
            }
            else if(nums2[j] < nums1[i]) {
                j++;
            }
            else {
                return nums1[i];
            }
        }

        return -1;
    }
    
int main(){
	vector<int> n = {1,2,3};
	vector<int> m = {2,3,4};
	cout<<getCommon(n,m);
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int maxDistance(vector<int>& colors) {
        int n = colors.size();

        for (int j = n - 1; j >= 0; j--) {
            if (colors[0] != colors[j]) {
                return j;
            }
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                return n - 1 - i;
            }
        }

        return 0;
    }
    
int main(){
	vector<int> a = {1,1,1,6,1,1};
	cout<<maxDistance(a);
	return 0;
}

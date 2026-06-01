#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long currMass = mass;   // use long long to avoid overflow

        for (int asteroid : asteroids) {
            if (currMass < asteroid)
                return false;

            currMass += asteroid;
        }

        return true;
    }
    
int main(){
	vector<int> a = {3,9,19,5,21};
	int mass=10;
	cout<<asteroidsDestroyed(mass, a);
	return 0;
}

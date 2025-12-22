//Gas Station problem Solution . 

#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas =0 , totCost =0;

        for( int val : gas){
            totGas+= val;
        }

        for( int val : cost){
            totCost+=val;
        }

        if(totGas<totCost){
            return -1;
        }
        
        int start=0 , currGas = 0;
        for(int i=0;i<gas.size();i++){
        currGas+= (gas[i]-cost[i]);
        if (currGas<0){
            start=i+1;
            currGas=0;
        }
      }
      return start;
    }
    

int main(){
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};
	cout<<canCompleteCircuit( gas,  cost);
	return 0;
}

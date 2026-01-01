//We are given a string with jewels and other string with stones , we have to return no. of stones that can be jewels .

#include<iostream>
#include<unordered_set>
using namespace std;

 int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        for(char a : jewels){
            s.insert(a);
        }
        int count=0;
        for(char b : stones){
            if(s.count(b)){
                count++;
            }
        }
        return count;
    }
    
    
    int main(){
    	cout<<numJewelsInStones("aAA", "aAAbbbb");
    	return 0;
	}

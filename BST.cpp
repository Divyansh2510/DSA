//These is Binary Search Tree code

#include<vector>
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
	Node(int value){
		data =value;
		right=left=NULL;
	}
};

Node* insert(Node* root,int val){
	if(root==NULL){
		return new Node(val);
	}
	
	if(val<root->data){
		root->left = insert(root->left,val);
	}
	
	if(val>root->data){
		root->right = insert(root->right,val);
	}
	
	return root;
}


void inorder(Node* root){
	if(root==NULL){
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
}

bool Search(Node* root, int target){
	if(root==NULL){
		return false;
	}
	
	if(root->data==target){
		return true;
	}
	
	if(target<root->data){
		Search(root->left,target);
	}else{
		Search(root->right,target);
	}
	
}
Node* BuildBST(vector<int> arr){
	Node* root = NULL;
	for(int val : arr){
		root = insert(root,val);
	}
	return root;
}

int main(){
	vector<int> values = {3,2,1,5,6,4};
	Node* root = BuildBST(values);
//	inorder(root);
//	cout<<endl;
    cout<<Search(root,8);
	return 0;
}

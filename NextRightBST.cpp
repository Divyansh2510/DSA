#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL || root->left == NULL) {
            return root;
        }

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        Node* prev = NULL;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                if (q.empty()) {
                    break;
                }
                q.push(NULL);
                prev = NULL;  // Reset prev for new level
            } 
            else {
                if (prev != NULL) {
                    prev->next = curr;
                }

                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);

                prev = curr;
            }
        }
        return root;
    }
};

// Function to print level order using next pointers
void printLevels(Node* root) {
    while (root != NULL) {
        Node* curr = root;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "# ";  // End of level
        root = root->left;
    }
}

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4  5  6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    root = sol.connect(root);

    cout << "Level order using next pointers: ";
    printLevels(root);

    return 0;
}


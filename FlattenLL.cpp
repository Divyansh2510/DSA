//Here these is the code to flatten a multilevel linked list. 

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {

                Node* next = curr->next;

                // Flatten the child list
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // Go to the end of flattened child list
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // Connect back to next part
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};

// Function to print flattened list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Helper function to create a simple multilevel list
// Example list created:
// 1 - 2 - 3 - 4
//         |
//         7 - 8
//             |
//             11 - 12
Node* createSampleList() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    n7->next = n8; n8->prev = n7;

    Node* n11 = new Node(11);
    Node* n12 = new Node(12);
    n11->next = n12; n12->prev = n11;

    // Link child levels
    n3->child = n7;
    n8->child = n11;

    return n1;
}

// MAIN FUNCTION
int main() {
    Node* head = createSampleList();

    cout << "Before Flattening: (only level 1 displayed)" << endl;
    printList(head);

    Solution sol;
    head = sol.flatten(head);

    cout << "\nFlattened List:" << endl;
    printList(head);

    return 0;
}


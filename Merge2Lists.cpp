//Here we will be merging Two sorted linked lists into a  single sorted linked list.

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

// Merge Two Sorted Linked Lists (Recursive)
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    if (head1 == NULL || head2 == NULL) {
        return head1 == NULL ? head2 : head1;
    }

    if (head1->val <= head2->val) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

// Insert node at the end of the list
void insertNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print Linked List
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    // Sorted List 1
    insertNode(head1, 1);
    insertNode(head1, 3);
    insertNode(head1, 5);

    // Sorted List 2
    insertNode(head2, 2);
    insertNode(head2, 4);
    insertNode(head2, 6);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    // Merge Two Sorted Linked Lists
    ListNode* mergedHead = mergeTwoLists(head1, head2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}


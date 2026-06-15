#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == nullptr) return nullptr;

        int count = 0;
        ListNode* temp1 = head;

        while(temp1){
            temp1 = temp1->next;
            count++;
        }

        int mid = count / 2;

        count = 1;
        ListNode* temp2 = head->next;
        ListNode* prev = head;

        while(count != mid){
            temp2 = temp2->next;
            prev = prev->next;
            count++;
        }

        prev->next = temp2->next;
        delete temp2;

        return head;
    }
};


void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main(){

    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before deletion: ";
    printList(head);

    Solution obj;

    head = obj.deleteMiddle(head);

    cout << "After deletion: ";
    printList(head);

    return 0;
}

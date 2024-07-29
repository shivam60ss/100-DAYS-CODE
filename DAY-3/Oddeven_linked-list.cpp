#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

class LinkedList {
public:
    ListNode* head;
    LinkedList() : head(nullptr) {}

    void addNode(int val) {
        ListNode* newNode = new ListNode(val);
        if(!head) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        ListNode* temp = head;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    Solution solution;
    cout << "Original List: ";
    list.printList();

    ListNode* result = solution.oddEvenList(list.head);
    cout << "Odd-Even List: ";
    list.printList();

    return 0;
}
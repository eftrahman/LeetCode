#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next && current->next->next) {
            ListNode* first = current->next;
            ListNode* second = current->next->next;

            first->next = second->next;
            second->next = first;
            current->next = second;

            current = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper functions to create and print linked lists for testing purposes
ListNode* createList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Test case
    ListNode* head = createList({1, 2, 3, 4});
    ListNode* result = solution.swapPairs(head);
    printList(result); // Expected output: 2 1 4 3

    return 0;
}

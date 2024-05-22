#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify code
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Loop through both lists until both are null and there is no carry left
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the values from the nodes, or 0 if the node is null
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum of the values and the carry
            int sum = val1 + val2 + carry;

            // Update the carry for the next addition
            carry = sum / 10;

            // Create a new node with the digit value of sum and attach it to the result list
            current->next = new ListNode(sum % 10);

            // Move to the next nodes in the lists and the result list
            current = current->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // The result list starts from the next of dummy node
        ListNode* result = dummyHead->next;
        delete dummyHead;  // Free the dummy node
        return result;
    }
};

int main() {
    // Create first number: 342 represented as 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second number: 465 represented as 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}

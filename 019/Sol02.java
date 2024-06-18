class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first.next;
        }

        // Move both pointers until first reaches the end
        while (first != null) {
            first = first.next;
            second = second.next;
        }

        // Remove the nth node from the end
        second.next = second.next.next;

        return dummy.next;
    }

    // Helper functions to create and print linked lists for testing purposes
    public static ListNode createList(int[] values) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        for (int val : values) {
            current.next = new ListNode(val);
            current = current.next;
        }
        return dummy.next;
    }

    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        ListNode head1 = createList(new int[]{1, 2, 3, 4, 5});
        int n1 = 2;
        ListNode result1 = solution.removeNthFromEnd(head1, n1);
        printList(result1); // Expected output: 1 2 3 5

        // Test case 2
        ListNode head2 = createList(new int[]{1});
        int n2 = 1;
        ListNode result2 = solution.removeNthFromEnd(head2, n2);
        printList(result2); // Expected output: (empty list)

        // Test case 3
        ListNode head3 = createList(new int[]{1, 2});
        int n3 = 1;
        ListNode result3 = solution.removeNthFromEnd(head3, n3);
        printList(result3); // Expected output: 1
    }
}

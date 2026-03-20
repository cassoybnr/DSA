Reverse Nodes in k-Group
by CodeChum Admin

Given a linked list, reverse the nodes of a linked list k at a time and return its modified head. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end should remain as is.

Example:
Input: 1->2->3->4->5
k = 3
Output: 3->2->1->4->5


Sample Output 1

Enter the size of the linked list: 5
Enter k: 3
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Enter element 5: 5
Original List: 1 -> 2 -> 3 -> 4 -> 5 ->
Modified List: 3 -> 2 -> 1 -> 4 -> 5 ->
Sample Output 2

Enter the size of the linked list: 7
Enter k: 5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Enter element 5: 5
Enter element 6: 6
Enter element 7: 7
Original List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 ->
Modified List: 5 -> 4 -> 3 -> 2 -> 1 -> 6 -> 7 ->
Sample Output 3

Enter the size of the linked list: 3
Enter k: 1
Enter element 1: 2
Enter element 2: 3
Enter element 3: 4
Original List: 2 -> 3 -> 4 ->
Modified List: 2 -> 3 -> 4 ->
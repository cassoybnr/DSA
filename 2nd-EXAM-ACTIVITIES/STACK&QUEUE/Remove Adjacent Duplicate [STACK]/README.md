Remove Adjacent Duplicate [STACK]
by Edrian Guanzon


This program removes adjacent duplicate
characters from a string. The stack is used to
process characters one by one, ensuring that
whenever two consecutive identical characters are
encountered, they are removed immediately.
Function Descriptions:

1. peek() = returns the top element of the stack
without removing it. It is used to check the
most recently inserted character in the stack
before deciding whether to push a new
character or remove a duplicate.

2. removeDuplicates() > processes the input
string character by character and removes all
adjacent duplicate characters using a stack.


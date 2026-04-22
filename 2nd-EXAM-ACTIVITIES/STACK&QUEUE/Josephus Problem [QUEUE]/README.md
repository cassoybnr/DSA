Josephus Problem [QUEUE]
by Edrian Guanzon


The Josephus Problem is a classical problem based on a circular elimination process. In this problem, a group
of n people is arranged in a circle. Starting from a fixed position, every k-th person is eliminated from the
circle repeatedly until only one person remains. The goal is to determine the position of the last surviving
person.
Function Description:
1. rotate() - moves the front element of the circular queue to the rear. It simulates a single step of circular
traversal in the Josephus problem.
2. josephus() > solves the Josephus problem using a circular queue by simulating the elimination
process.
o All n people are inserted into the circular queue.
o The queue is rotated k—1 times using the rotate() function.
o The k-th person (front element) is removed from the queue.
o Steps 2-3 are repeated until only one element remains.
Steps:





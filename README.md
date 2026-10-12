# Stacks-Queues-and-Deques
Completed Assignment for CS210-11 Class. This contains implementations of stacks, queues, and deques through the use of arrays and linked lists.

## Explanation
Every operation within these 6 implementations has space complexity O(1). This is because the only things ever created within these operations are the values that we want to push/queue.

Every operation involving linked lists (excluding print) has time complexity O(1). Because the operations we are required to make only ever deal with data at the head or tail of a linked list, there is no need to traverse through a list to find a value. The stack and queue implementations are both singly-linked, with the queue implementation having a pointer to the tail for easy access. The deque implementation is a doubly-linked list.

Most of the operations from the array-based implementations are O(1) for similar reasons. The following operations are O(n):
- dequeue() from QueueArray
- push_front() from DequeArray
- pop_front() from DequeArray
- print() from all 6 implementations.

In the case of print(), it iterates throughout all of the lists in order to print each value. For the other 3 operations, they either insert or remove the first element of the array. Because there may already be existing values in the rest of the array, we must shift all of these values accordingly. That being said, these three operations could become O(1) if we created a massive array and inserted values from the middle of the array. However, we would need to allocate too much memory for this to be reasonable.

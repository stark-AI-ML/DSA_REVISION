# Reverse Linked List II (LeetCode 92)

## Problem

Reverse a linked list from position `left` to position `right` (inclusive).

Example:

```text
Input:
1 -> 2 -> 3 -> 4 -> 5
left = 2
right = 4

Output:
1 -> 4 -> 3 -> 2 -> 5
```

---

# My Initial Approach (Vector Based)

## Thought Process

My first idea was:

1. Find the node before the reversal starts (`prevLeftNode`).
2. Store every node from `left` to `right` inside a vector.
3. Reverse the pointers using the vector.
4. Connect the reversed portion back to the original list.

### Visualization

Before:

```text
1 -> 2 -> 3 -> 4 -> 5

prevLeftNode
     |
     v
1 -> 2 -> 3 -> 4 -> 5
```

Store:

```text
Vector

[2, 3, 4]
```

Reconnect:

```text
1 -> 4 -> 3 -> 2 -> 5
```

---

## Complexity

Time Complexity

```text
O(N)
```

Space Complexity

```text
O(K)

K = right - left + 1
```

because the nodes are stored in a vector.

---

## Mistakes I Made

### 1. Treated `left` and `right` as values

I assumed

```cpp
if(node->val == left)
```

which is incorrect.

The problem is based on **1-indexed positions**, not node values.

---

### 2. Infinite loop

Forgot to move the pointer.

```cpp
tail = tail->next;
```

---

### 3. Pointer reconnection mistakes

While reconnecting the reversed nodes, I accidentally:

* overwrote pointers
* accessed invalid indices
* didn't handle edge cases correctly

---

## Improvement

Instead of checking

```cpp
node->val == left
```

maintain a position counter.

```cpp
int pos = 1;
```

Now collect nodes between

```text
left <= pos <= right
```

instead of matching values.

This makes the vector approach correct.

---

# Optimal Approach (In-place Reversal)

Instead of storing nodes, reverse the links directly.

Steps:

1. Create a dummy node.
2. Move to the node just before `left`.
3. Keep `curr` fixed.
4. Repeatedly remove the next node and insert it immediately after `prev`.

Visualization:

Initial

```text
1 -> 2 -> 3 -> 4 -> 5

prev
 |
1

curr
 |
2
```

Iteration 1

Move `3` after `1`

```text
1 -> 3 -> 2 -> 4 -> 5
```

Iteration 2

Move `4` after `1`

```text
1 -> 4 -> 3 -> 2 -> 5
```

Done.

---

## Complexity

Time Complexity

```text
O(N)
```

Space Complexity

```text
O(1)
```

No extra data structure is required.

---

# Comparison

| My Vector Approach                     | Optimal In-place Approach |
| -------------------------------------- | ------------------------- |
| Easy to understand                     | Slightly harder           |
| Uses extra memory                      | Constant memory           |
| O(N) Time                              | O(N) Time                 |
| O(K) Space                             | O(1) Space                |
| Good for learning pointer reconnection | Preferred in interviews   |

---

# What I Learned

* Read the problem carefully. `left` and `right` represent **positions**, not values.
* A vector can simplify pointer manipulation and is a good first approach while revising linked lists.
* Once the logic is clear, the same idea can be implemented without extra memory using in-place pointer manipulation.
* Most linked list mistakes come from pointer updates and edge cases rather than the overall algorithm.

---

# Personal Note

While revising linked lists after a long break, it's okay to first solve problems using extra space to build confidence. The important progression is:

1. Solve the problem correctly.
2. Analyze the time and space complexity.
3. Optimize the space if possible.

Correctness comes first; optimization comes next.

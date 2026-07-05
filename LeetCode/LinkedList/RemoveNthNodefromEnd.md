# Remove Nth Node From End of List

## My Solution (Vector Based)

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        vector<ListNode*> nodes;

        ListNode* curr = dummy;

        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        ListNode* prev = nodes[nodes.size() - n - 1];
        ListNode* del = prev->next;

        prev->next = del->next;

        delete del;

        return dummy->next;
    }
};
```

### Complexity

* **Time:** `O(N)`
* **Space:** `O(N)`

---

## Optimal Solution (Two Pointers) 

### Quite clever solution though i am impressed my solution seems completely noob 

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; i++)
            fast = fast->next;

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;

        delete del;

        return dummy.next;
    }
};
```

### Complexity

* **Time:** `O(N)`
* **Space:** `O(1)`

---

# Difference

| My Solution                                    | Optimal Solution                                                     |
| ---------------------------------------------- | -------------------------------------------------------------------- |
| Stores every node in a `vector`.               | Uses two pointers (`fast` and `slow`).                               |
| Finds the previous node using vector indexing. | Finds the previous node by maintaining a fixed gap of `n + 1` nodes. |
| Easier to understand.                          | More memory efficient.                                               |
| **Time:** `O(N)`                               | **Time:** `O(N)`                                                     |
| **Space:** `O(N)`                              | **Space:** `O(1)`                                                    |

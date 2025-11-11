#include <iostream>

class Node
{
public:
    int data;
    Node *next; // creating a pointer for the node object it self  // See it is a pointer to the object not the class(bluePrint) like Node node1; ->  Node node3;

    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
};

int main()
{

    // All values are going to be null now but the thing is we have to assingn it to next node until it's last node so......
    Node node1(1);

    std ::cout << node1.data << "  " << node1.next << std ::endl;

    Node node2(3);
    std ::cout << node2.data << "   " << node2.next << std ::endl;

    Node node3(4);
    std ::cout << node3.data << "   " << node3.next << std ::endl;
    // o/p

    // 1  0
    // 3   0
    // 4   0

    // Now we are assigning the pointer next to the refrence address of next node ...
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    std ::cout << node1.data << "  " << node1.next << std ::endl;
    std ::cout << node2.data << "   " << node2.next << std ::endl;

    // both belows are the same you know,   -> it combines dereferencing and member access in one step.
    //  When you have a pointer to an object, -> allows you to access the object's members directly

    std ::cout << node2.next->data << std::endl;
    // so when ever you have an pointer to an object you can directly access it with ->, as it derefrence and acess the member

    std ::cout << (*node2.next).data;
    // while you can go by your old one like by dereferencing and then acessing the data (see first you need to complete the derefencing)
    // then go for member so () this is imp
}

/*

How node2.next->data Works:

node2.next is a pointer to node3.

-> dereferences node2.next and accesses the data member of the object it points to.

Therefore, node2.next->data is equivalent to (*node2.next).data, but more concise and readable.

 */

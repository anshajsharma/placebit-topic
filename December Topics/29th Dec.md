# Reverse a Linked List
**QLink:** https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
```c++
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *prev = NULL, *curr = head;
        while(curr){
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
};
```

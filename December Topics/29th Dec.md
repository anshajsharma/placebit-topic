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
# Rotate a Linked List
**QLink:** https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

```c++
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        int n = 0;
        Node* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        k = k%n;
        if(k==0 || n==0) return head;
        Node *last = head;
        while(last->next){
            last = last->next;
        }
        
        int loopCount = k-1;
        
        Node* newLast = NULL;
        Node* newHead = NULL;
        
        temp = head;
        while(loopCount--){
            temp = temp->next;
        }
        
        newLast = temp;
        newHead = newLast->next;
        
        newLast->next = NULL;
        last->next = head;
        
        return newHead;
    }
};
```

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
# Merge two sorted linked lists
**QLink:** https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

```c++
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(!head1) return head2;
    if(!head2) return head1;
    Node *ans,*currPointer = new Node(0) ,*temp;
    ans = currPointer;
    while(head1 && head2){
        if(head1->data > head2->data){
            temp = head2;
            head2 = head2->next;
            currPointer->next = temp;
            currPointer = temp;
            temp -> next = NULL;
        }else{
            temp = head1;
            head1 = head1->next;
            currPointer->next = temp;
            currPointer = temp;
            temp -> next = NULL; 
        }
    }
    if(head1) currPointer->next = head1;
    if(head2) currPointer->next = head2;
    return ans->next;
    
}  
```

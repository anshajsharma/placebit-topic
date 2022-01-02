# Nth node from end of linked list 
```c++
int c = 0;
int ans=0;
void clone(Node *head, int &n)
{
      c++;
       if(head->next)  clone(head->next,n);
       if(n>c) {ans = -1; return;}
        n--;
       if(n<0) return;
        if(n == 0 ) ans = head->data;
}
int getNthFromLast(Node *head, int n)
{
       // Your code here
       // newbie approach
        //   int siz = 0;
        //   Node* temp = head;
        //   while(temp){
        //       temp=temp->next;
        //       siz++;
        //   }
        //   int loopC = siz - n;
        //   if(loopC<0) return -1;
        //   temp = head;
        //   while(loopC--){
        //         temp=temp->next;
        //   }
        //   return temp->data;
        clone(head,n);
      return ans;
        
}
```

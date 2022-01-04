# Implemented Stack using Linked List
```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
  int data;
  node *next;
  node(){
    data = 0;
    next = NULL;
  }
  node(int data,node* nxt){
    this->data = data; 
    next = nxt;
  }
};

class mystack {
private:
  node *top;
  int len;
public:
  mystack(){
    top = NULL;
    len = 0;
  }
  bool isEmpty(){
    return len == 0;
  }

  int size(){
    return len;
  }

  int peek(){
    if(top) return top->data;
    else return -1;
  }

  void push(int d)
  {
    node *newNode = new node(d,top);
    if(!newNode){
      cout<<"Stack Overflow!\n";
      return;
    }
    top = newNode;
    len++;
  }

  void pop()
  {
    if(!top){
      cout<<"Stack is already empty!\n";
      return;
    }
    node *temp = top;
    top = top->next;
    len--;
    delete temp;
  }

  void print(){
    node *temp = top;
    while(temp){
      cout<<temp->data<<" ";
      temp = temp->next;
    } 
    cout<<endl;
  }

};

void solve()
{
  
  mystack st;
  // cout<<5;
  st.push(5);
  st.pop();
  st.pop();
  st.print();
  st.push(6);
  st.push(8);
  st.pop();
  st.push(1);

  st.print();

  cout<<st.peek()<<endl;
  cout<<st.size()<<endl;

}
```
# Implemented Queue using Linked List

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
  int data;
  node *next;
  node(){
    data = 0;
    next = NULL;
  }
  node(int data,node* nxt){
    this->data = data; 
    next = nxt;
  }
};

class myqueue {
private:
  node *front,*rear;
  int len;
public:
  myqueue(){
    front = NULL;
    rear = NULL;
    len = 0;
  }
  bool isEmpty(){
    return len == 0;
  }

  int size(){
    return len;
  }

  int frontVal(){
    if(front) return front->data;
    else return -1;
  }

  void push(int d)
  {
    node *newNode = new node(d,NULL);
    if(!newNode){
      cout<<"Max size limit reached!\n";
      return;
    }
    if(rear) rear->next = newNode;
    else front = newNode;
    rear = newNode;
    len++;
  }

  void pop()
  {
    if(!front){
      cout<<"Queue is already empty!\n";
      return;
    }
    node *temp = front;
    front = front->next;
    if(front == NULL) rear = NULL;
    len--;
    delete temp;
  }

  void print(){
    node *temp = front;
    while(temp){
      cout<<temp->data<<" ";
      temp = temp->next;
    } 
    cout<<endl;
  }

};

void solve()
{
  
  myqueue q;
  // cout<<5;
  q.push(5);
  q.pop();
  q.pop();
  q.print();
  q.push(6);
  q.push(8);
  q.pop();
  q.push(1);

  q.print();

  cout<<q.frontVal()<<endl;
  cout<<q.size()<<endl;

}
```
# Deque

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void showdq(deque <int> g)
{
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
void solve()
{
  
  deque<int> dq;

  dq.push_back(5);
  dq.push_front(1);
  dq.push_back(6);
  dq.push_front(8);
  showdq(dq);
  dq.pop_front();
  showdq(dq);
  dq.pop_back();
  showdq(dq);

}
```

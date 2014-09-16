#include<iostream>
using namespace std;

template <class t>
class node
{
public:
  t d;
  node *next;
  node(t el, node *ne=0)
  {
    d=el;
    next=ne;
  }
};

template <class t>
class list
{
  node<t> *head,*tail;
public:
  list()
  {
    head=tail=0;
  }

  void h(t el)
  {
    head=new node(el,head);
    if(tail==0)
      tail=head;
  }
    
  void ta(t el)
  {
    if(tail!=0)
    {
      tail->next=new node(el);
      tail=tail->next;
    }
  }
  
  void print()
  {
    node *p=head;
    while(p!=0)
    {
      cout<<p->d;
      p=p->next;
    }
  }
 
  void delh()
  {
    if(head==tail)
    {
      delete head;
      head=tail=0;
    }
    else
    {
      node *p=head;
      head=head->next;
      delete p;
    }
  }
  
  void delt()
  {
    node *p=head;
    for(p=head;p->next!=0;p=p->next);
      delete p->next;
      tail=p;
      tail->next=0;
  }
  
  void search(t el)
  {
    node *p=head;
    while(p!=0)
    {
      if(p->d==el)
        cout<<el;
        p=p->next;
    }
  }
};

int main()
{
  list<int> a;
  int no,c;
  char ans;
  cout<<"Menu\n";
  cout<<"1. Add at head\n";
  cout<<"2. Add at tail\n";
  cout<<"3. Delete at head\n";
  cout<<"4. Delete at tail\n";
  cout<<"5.print\n";
  do
  {
    cout<<"enter choice\n";
    cin>>c;
    switch(c)
    {
      case 1: cout<<"Enter no: ";
              cin>>no;
              a.h(no);
              break;
             
      case 2: cout<<"enter no: ";
              cin>>no;
              a.ta(no);
              break;
      
      case 3: a.delh();
              break;

      case 4: a.delt();
              break;
            
      case 5: a.print();
              break;
            
      default:cout<<"Wrong input\n";
    }
    cout<<"do you want to continue? ";
    cin>>ans;
  }while(ans!='n');
    
  return 0;
}

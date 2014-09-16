#include<iostream>
using namespace std;

class node
{
public:
  int d;
  node *r;
  node *l;

  node(int el)
  {
    d=el;
  }
};

class list
{
public:
  node *root;
  list()
  {
    root=0;
  }

  void insert(int el)
  {
    node *p=root;
    node *prev=0;
    while(p!=0)
    {
      prev=p;
      if(p->d<el)
        p=p->l;
      else
        p=p->r;
    }
    if(root==0)
      root=new node(el);
    else
      if(prev->d>el)
        prev->r=new node(el);
      else
        prev->l=new node(el);
    }

    node* search(int el)
    {
      node *p=root;
      while(p!=0)
      {
        if(p->d==el)
          return p;
        else if(p->d<el)
          p=p->r;
        else 
          p=p->l;
      }
      return 0;
    }

    void del(node *&p)
    {
      node *temp=p;
      node *prev=0;
      if(p->l==0)
        p=p->r;
      else if(p->r==0)
        p=p->l;
      else
        if((p->l!=0)&&(p->r!=0))
        {
          temp=p->l;
          prev=p;
          while(temp->r!=0)
          {
            prev=temp;
            temp=temp->r;
          }
          p->d=temp->d;
          if(prev=p)
            prev->l=temp->l;
          else
            prev->r=temp->l;
        }
      delete temp;
    }

    void print(node *p)
    { 
      if(p!=0)
      {
        print(p->l);
        cout<<p->d;
        print(p->r);
      }
    }
};

int main()
{
  class list a;
  int c,no;
  char ans;

  cout<<"menu\n";
  cout<<"1.to insert values\n";
  cout<<"2. to search for values\n";
  cout<<"3. to delete values\n";
  cout<<"4. to print in sorted order\n";

  do
  {
    cout<<"enter choice\n";
    cin>>c;
    switch(c)
    {
      case 1: cout<<"Enter no: ";
              cin>>no;
              a.insert(no);
              break;
            
      case 2: cout<<"enter element to search: ";
              cin>>no;
              a.search(no);
              break;

      case 3: a.del(a.root);
              break;

      case 4: a.print(a.root);
              cout<<endl;
              break;

      default:cout<<"wrong input\n";
    }

    cout<<"do you want to continue\n";
    cin>>ans;

    }while(ans=='y');
  return 0;
}

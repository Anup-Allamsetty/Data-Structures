#include<iostream>
using namespace std;
int flag=0;
class node
{
public:
  int d;
  node *l;
  node *r;
  int c;
  node(int el)
  {
    d=el;
    l=r=0;
    c=0;
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
  void ins(int el,node *&p) 
  {
    if((p==0)&&(flag==0))
    {
      root=new node(el);
      flag=1;
    }
    else if((p==0)&&(flag=1))
    {
      p=new node(el);
    }
    else
      if(el<p->d)
      {
        ins(el,p->l);
        if((ht(p->l)-ht(p->r))==2)
          if(el<p->l->d)
            sll(p);
          else
            dll(p);
      }
      else
      {
        ins(el,p->r);
        if((ht(p->r)-ht(p->l))==2)
          if(p->r->d<el)
            srl(p);
          else
            drl(p);
      }
    p->c=max(ht(p->l),ht(p->r))+1;
  }


  void sll(node *&k2)
  {
    node *k1=k2->l;
    k2->l=k1->r;
    k1->r=k2;
    k2->c=max(ht(k2->l),ht(k2->r))+1;
    k1->c=max(ht(k2),ht(k1->l))+1;
    k2=k1;
  }

  int ht(node *p)
  {
    if(p==NULL)
      return -1;
    else
      if((p->r==0)&&(p->l==0))
        return 0;
      else if(p->r!=0)
        return (p->r->c+1);
      else
        return (p->l->c+1);
  }
  
  void srl(node *&k1)
  {
    node *k2=k1->r;
    k1->r=k2->l;
    k2->l=k1;
    k2->c=max(ht(k2->r),ht(k1))+1;
    k1->c=max(ht(k1->r),ht(k1->l))+1;
    k1=k2;
  }

  void dll(node *&k3)
  {
    srl(k3->l);
    sll(k3);
  }
  
  void drl(node *&k1)
  {
    sll(k1->r);
    srl(k1);
  }
  
  int max(int m,int n)
  {
    if(m>n)
      return m;
    else
      return n;
  }

  int search(int el, node *p)
  {
    if(p!=0)
    {
      if(el==p->d)
        return 1;
      else if(el>p->d)
        search(el,p->r);
      else
        search(el,p->l);
    }
  }

  void print(node *p)
  {
    if(p!=0)
    {
      cout<<" "<<p->d<<" "<<p->c<<" ";
      print(p->l);
      print(p->r);
    }
  }
};

int main()
{
  int c,no;
  char ans;
  list a;
  cout<<"Menu\n";
  cout<<"1. To insert\n";
  cout<<"2. To search\n";
  cout<<"3. To print\n";
  do
  {
    cout<<"Enter choice\n";
    cin>>c;
    switch(c)
    {
      case 1: cout<<"enter no: ";
              cin>>no;
              a.ins(no,a.root);
              break;

      case 2: cout<<"enter no to be searched: ";
              cin>>no;
              no=a.search(no,a.root);
              if(no==1)
                cout<<"Found\n";
              else
                cout<<"Not found\n";
                break;
            
      case 3: a.print(a.root);
              break;
      default: cout<<"Wrong input\n";
    }
    
    cout<<"do you want to continue?\n";
    cin>>ans;
  }while(ans!='n');
  return 0;
}

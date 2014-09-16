#include<iostream>

using namespace std;

class a
{
  int c;
  int *ar;
  int t;
public:
  a(int cap)
  {
    int i;
    c=cap;
    ar=new int[c];
    t=-1;
  }
  
  int sz()
  {
    return (t+1);
  }

  int full()
  {
    if(sz()==c)
      return 1;
    else 
      return 0;

  }

  void insert(int el)
  {
    int i;
    if(full())
      cout<<"overflow\n";
    else
    {
      i=sz()+1;
      while(ar[i/2]>el)
      {
        ar[i]=ar[i/2];
        i=i/2;
      }
      ar[i]=el;
    }
    t++;
  }

  void print()
  {
    int i;
    for(i=1;i<=sz();i++)
    {
      cout<<ar[i];
      cout<<endl;
    }
  }

  void dele()
  {
    int i,c;
    int min=ar[1];
    int m=sz();
    int last=ar[m--];

    for(i=1;(2*i)<=sz();i=c)
    {
      c=2*i;
      if(ar[c+1]<ar[c])
        c++;
      if(last>ar[c])
        ar[i]=ar[c];
      else
        break;
    }

    ar[i]=last;
    t--;
  }
};

int main()
{
  a b(10);
  int no,c;
  char ans;
  cout<<"Menu\n";
  cout<<"1. To insert\n";
  cout<<"2. to delete\n";
  cout<<"3. print\n";
  
  do
  {
    cout<<"enter choice: ";
    cin>>c;
    switch(c)
    {
      case 1: cout<<"enter no: ";
              cin>>no;
              b.insert(no);
              break;

      case 2: b.dele();
              break;

      case 3: b.print();
              break;

      default:cout<<"Wrong input\n";
    }
    cout<<"do you want to continue?: ";
    cin>>ans;
  }while(ans!='n');

  return 0;
}

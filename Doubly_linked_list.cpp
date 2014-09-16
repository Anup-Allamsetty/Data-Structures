#include<iostream>
using namespace std;

template <class t>
class node
{
public:
    t d;
    node *temp;
    node *next;
    node *prev;
    node(t el, node *n, node *p)
    {
        d=el;
        next=n;
        prev=p;
    }
};

template <class t>
class d
{
    node<t> *head, *tail;
    public:
    d()
    {
        head=tail=0;
    }
    void h(t el)
    {
        if(head!=0)
        {
            head=new node<t>(el,head,0);
            head->next->prev=head;
        }
        else
            head=tail=new node<t>(el,0,0);
    }
    void ta(t el)
    {
        if(tail!=0)
        {
            tail=new node<t>(el,0,tail);
            tail->prev->next=tail;
        }
        else
            tail=head=new node<t>(el,0,0);
    }
    void print()
    {
        node<t> *p=head;
        while(p!=0)
        {
            cout<<p->d;
            p=p->next;
        }
    }void dh()
    {
        node<t> *temp=head;
        head=head->next;
        delete temp;
        head->prev=0;
    }
    void dt()
    {
        node<t> *temp=tail;
        tail=tail->prev;
        delete temp;
        tail->next=0;
    }
    void search(t el)
    {
        node<t> temp=head;
        while(temp!=0)
        {
            if(temp->d==el)
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                temp->next=head;
                head->prev=temp;
                head=temp;
            }
            temp=temp->next;
        }
    }
};

int main()
{
    d<int>a;
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
            case 1:cout<<"Enter no: ";
                    cin>>no;
                    a.h(no);
                    break;
            case 2:cout<<"enter no: ";
                    cin>>no;
                    a.t(no);
                    break;
            case 3:a.dh();
                    break;
            case 4:a.dt();
                    break;
            case 5:a.print();
                    break;
            default: cout<<"Wrong input\n";
        }
        cout<<"do you want to continue? ";
        cin>>ans;
    }while(ans!='n');
    return 0;
}

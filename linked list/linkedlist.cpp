#include <iostream>
using namespace std;
template <typename T>
class linkedlist
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& val, Node* nxt) : data(val), next(nxt) {}

    }*head, * second, * t;
public:
    void creation(int A[], int n)
    {
        Node* last, * third;
        head = new Node(A[0], NULL);
        head->data = A[0];
        head->next = NULL;
        last = head;
        for (int i = 1; i < n; i++)
        {
            third = new Node(A[i], NULL);
            third->data = A[i];
            third->next = NULL;
            last->next = third;
            last = third;
        }
        /* Node* t1, * t2;             // to make a loop in alinked list
         t1 = head->next->next;
         t2 = head->next->next->next->next;
         t2->next = t1;*/

    }
    void creation2(int B[], int n)
    {
        Node* last, * third;
        second = new Node(B[0], NULL);
        //head->data = B[0];
        //head->next = NULL;
        last = second;
        for (int i = 1; i < n; i++)
        {
            third = new Node(B[i], NULL);
            //third->data = A[i];
            //third->next = NULL;
            last->next = third;
            last = third;
        }

    }
    void CreatCiruclelinkedlist(int A[], int n)
    {
        Node* last, * third;
        head = new Node(A[0], NULL);
        head->data = A[0];
        head->next = head;
        last = head;
        for (int i = 1; i < n; i++)
        {
            third = new Node(A[i], NULL);
            third->data = A[i];
            third->next = last->next;
            last->next = third;
            last = third;
        }
    }

    void display()
    {
        Node* p = head;  //t;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }

    }
    void Redisplay()                //using Recrution
    {
        Node* p = head;
        if (p != NULL)
        {
            cout << p->data << " ";
            Redisplay(p->next);
        }
    }
    void REdisplay()                  //using Recrution
    {
        Node* p = head;
        if (p != NULL)
        {
            REdisplay(p->next);
            cout << p->data << " ";
        }
    }
    int count()
    {
        Node* p = head;
        int c = 0;
        while (p)
        {
            c++;
            p = p->next;
        }
        return c;
    }
    int length()
    {

        Node* p = head;
        int l = 0;
        do
        {

            l++;
            p = p->next;
        } while (p != head);

        return l;

    }
    int Rcount()                 //using Recrution
    {
        Node* p = head;
        if (p == 0)
            return 0;
        else
        {
            return Rcount(p->next) + 1;
        }
    }
    int sum()
    {
        Node* p = head;
        int s = 0;
        while (p != NULL)
        {
            s += p->data;
            p = p->next;
        }
        return s;
    }
    int Rsum()                           //using Recrution
    {
        Node* p = head;
        if (p != 0)
        {
            return Rsum(p->next) + p->data;
        }
        else
            return 0;
    }
    void inserfront(const T& value)
    {
        Node* t;
        t = new Node(value, NULL);
        t->next = head;
        head = t;
    }
    void Insert(T index, T x)
    {
        Node* p = head;
        Node* t;
        t = new Node(x, NULL);
        t->data = x;
        if (head = NULL)
        {
            head = t;
        }
        if (index < 0)
            return;

        if (index == 0)
        {
            t->next = head;
            head = t;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
                p = p->next;
            t->next = p->next;
            p->next = t;

        }
    }
    void insertback(const T& value)
    {
        Node* t;
        t = new Node(value, NULL);
        Node* p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
        t->next = NULL;
    }
    void Delete(T index)
    {
        Node* t;
        Node* p = head;
        if (index < 1)
        {
            return;
        }
        if (index == 1)
        {
            t = head;
            head = head->next;
            delete t;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                t = p;
                p = p->next;
            }
            t->next = p->next;
            delete p;
        }


    }
    void Deletefront()
    {
        Node* t = head;
        head = head->next;
        delete t;
    }
    void Deleteback()
    {
        Node* t;
        Node* p = head;
        while (p->next != NULL)
        {
            t = p;
            p = p->next;
        }
        t->next = NULL;
        delete p;
    }
    void Reverce()
    {

        Node* t = head;
        T* A, i = 0;
        A = new T[3];
        while (t != NULL)
        {
            A[i] = t->data;
            t = t->next;
            i++;
        }
        t = head;
        i--;
        while (t != 0)
        {
            t->data = A[i];
            t = t->next;
            i--;
        }

    }
    T max()
    {
        Node* p = head;
        T x = INT_MIN;
        while (p)
        {
            if (p->data > x)
            {
                x = p->data;
                p = p->next;
            }
        }
        return x;
    }
    T Rmax(Node* p1)              //using Recursion
    {
        Node* p = head;
        T x = 0;
        if (p == 0)
            return INT_MIN;
        x = Rmax(p->next);
        if (x > p->data)
            return x;
        else
            return p->data;
    }
    void Lisearch(T value)
    {
        bool f = 0;
        Node* p = head;
        while (p != NULL)
        {
            if (value == p->data)
                f = 1;

            p = p->next;

        }
        if (f)
            cout << "it's founded" << endl;
        else
            cout << "it's not founded" << endl;

    }
    /* void RLisearch(T value, Node* f)                    //un completed
     {
         Node* p = head;
         bool f = 0;
         if (value == p->data)
             f = 1;
         else
             RLisearch(0, p->next);
         if (f)
             cout << "it's founded";
         else
             cout << "it's not founded";
     }*/
    void improvelisearch(T value)
    {
        bool f = 0;
        Node* p = head;
        Node* t = NULL;
        while (p != NULL)
        {
            if (value == p->data)
            {
                t->next = p->next;
                p->next = head;
                head = p;
                f = 1;
            }
            t = p;
            p = p->next;

        }
        if (f)
        {
            cout << "it's founded" << endl;
        }
        else
            cout << "it's not founded" << endl;

    }
    void SortInsert(T value)
    {
        Node* p = head, * q = NULL;
        Node* t;
        t = new Node(value, NULL);
        if (head == NULL)
        {
            head = t;
        }
        else
        {
            while (p && p->data < value)   //p here mean != NULL so it can insert at the end
            {
                q = p;
                p = p->next;
            }
            if (p == head)
            {
                t->next = head;
                head = t;
            }
            else
            {
                t->next = q->next;
                q->next = t;
            }
        }

    }
    int ISsorted()
    {
        Node* p = head;
        int x = INT_MIN;
        while (p != NULL)
        {
            if (p->data < x)
                return 0;
            else
            {
                x = p->data;
                p = p->next;
            }
        }
        return 1;
    }
    void RemoveDuplicate()
    {
        Node* p = head;
        Node* t = p->next;
        while (t != NULL)
        {
            if (p->data != t->data)
            {
                p = t;
                t = t->next;
            }
            else
            {
                p = t->next;
                delete t;
                t = p->next;
            }


        }
    }
    void RverseWithPointers()
    {
        Node* p = head;
        Node* t = NULL, * q = NULL;
        while (p != NULL)
        {
            q = t;
            t = p;
            p = p->next;
            t->next = q;
        }
        head = t;
    }
    void RverseWithPointersUsingRecusion()                          //un completed using Recrusion
    {
        Node* p = head;
        Node* t = NULL;
        if (p)
        {
            t = p;
            p = p->next;
            RverseWithPointersUsingRecusion();
            p->next = t;
        }
        else
            head = t;
    }
    void Contact2linkedlist()
    {
        Node* p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = second;
        second = NULL;
    }
    void Merg2SortedLiknedlist()
    {
        Node* l = NULL;
        if (head->data < second->data)
        {
            t = l = head;
            head = head->next;
            t->next = NULL;
        }
        else
        {
            t = l = second;
            second = second->next;
            t->next = NULL;

        }
        while (head && second)
        {

            if (head->data < second->data)
            {
                l->next = head;
                l = head;
                head = head->next;
                l->next = NULL;

            }
            else
            {

                l->next = second;
                l = second;
                second = second->next;
                l->next = NULL;
            }

        }
        if (head)
        {
            l->next = head;

        }
        if (second)
        {
            l->next = second;
        }


    }
    bool IsLoop()
    {
        Node* p, * t;
        p = t = head;

        do
        {
            p = p->next;
            t = t->next;
            t = t != NULL ? t->next : NULL;


        } while (p && t && p != t);
        return p == t ? true : false;
    }
    void DisplayCircullinkedlist()
    {
        Node* p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
    }
    bool InsertCirculLinkedlist(int position, int x)
    {
        Node* p = head;
        if (position<0 || position>length())
            return 0;
        if (position == 0)
        {
            t = new Node(x, NULL);
            t->data = x;
            if (head == NULL)
            {
                head = t;
                head->next = head;
            }
            else
            {

                while (p->next != head)
                {
                    p = p->next;
                }
                t->next = head;
                p->next = t;
                head = t;

            }
        }
        else
        {
            for (int i = 0; i < position - 1; i++)
            {
                p = p->next;
            }
            t = new Node(x, NULL);
            t->data = x;
            t->next = p->next;
            p->next = t;
        }


    }
    bool DeleteCiruclLinkedlist(int index)
    {
        Node* t, * p;
        if (index<1 || index>length())
            return 0;
        if (index == 1)
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            if (p == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                p->next = head->next;
                delete head;
                head = p->next;

            }
        }
        else
        {
            p = head;
            for (int i = 0; i < index - 2; i++)
            {
                p = p->next;
            }
            t = p->next;
            p->next = t->next;
            delete t;
        }

    }
    void FindMiddleLinkedlist()
    {
        Node* p = head, * t = head;
        while (t)
        {
            t = t->next;
            if (t)
                t = t->next;
            if (t)
                p = p->next;
        }
        cout << "the middle of the linkedlist is " << p->data;
    }


};

int main()
{
    int A[] = { 1,3,5,4,6 };
    // int B[] = { 2,4,8 };
    linkedlist <int>l;
    l.creation(A, 5);
    //l.CreatCiruclelinkedlist(A,5);
   // l.creation2(B, 3);

    //n1.Redisplay();
    //n1.REdisplay();
    //cout<<n1.count();
    //cout << n1.Rcount();
    //cout << n1.sum();
    //cout << n1.Rsum();
   // l.inserfront(5);
  // l.insertback(6);
    //l.Insert(0,15);
    //l.Delete(2);
    //l.Deletefront();
    //l.Deleteback();
    //l.Reverce();
    //cout<<l.max();
  //  cout << l.Rmax(head);
   // l.Lisearch(3);
    //l.RLisearch(15,NULL);                     //un completed
   // l.improvelisearch(3);
    //l.SortInsert(15);
    /*cout << l.ISsorted() << endl;
    if (l.ISsorted())
        cout << "the linked list is sorted";
    else
        cout << "the linked list isn't sorted";*/
        //l.RemoveDuplicate();                              //un completed
        // l.RverseWithPointers();
         //l.RverseWithPointersUsingRecusion();
        // l.Contact2linkedlist();
    //l.Merg2SortedLiknedlist();
   /* l.IsLoop();
    if (l.IsLoop())
    {
        cout << "the linked list conatin a loop";
    }
    else
        cout << "the linked list is linear";*/
        //cout<< l.length();
       // l.InsertCirculLinkedlist(8, 9);
        //cout << endl;
        // l.DeleteCiruclLinkedlist();
         //l.DisplayCircullinkedlist();
    l.FindMiddleLinkedlist();
    //l.display();
}

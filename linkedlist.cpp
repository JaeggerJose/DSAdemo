#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


struct Node {
    int e, coe;
    Node* link;
};

int count(Node* head) {
    Node* n = head;
    int num = 0;
    while(n!=0) {
        num++;   
        n = n->link;
    }
    return num;
}

Node* insert_val(Node* start, int coe, int e) {
    Node* tmp;
    Node* n = new Node(); //allocate memory for new node and insert value into it.
    n->coe = coe;
    n->e = e;
    n->link = NULL; //give the new Node's link to NULL,and detect if the linked list is NULL or not.
    if(start == NULL)
        return n;
    else {
        tmp = start;
        while(tmp->link!=NULL)
            tmp = tmp->link;
        n->link = tmp->link;
        tmp->link = n;
    }
    return start;
}

Node* swap(struct Node* ptr1, struct Node* ptr2)
{
    Node* tmp = ptr2->link;
    ptr2->link = ptr1;
    ptr1->link = tmp;
    return ptr2;
}

int bubblesort(struct Node** head, int count)
{
    struct Node** h;
    int i, j, swapped;
  
    for (i = 0; i <  count; i++)
    {
        h = head;
        swapped = 0;
        for (j = 0; j < count-i-1; j++) 
        {
            Node* p1 = *h;
            Node* p2 = p1->link;
            if (p1->e < p2->e)
            {
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->link;
        }
        if (swapped == 0)
            break;
    }
    return 0;
}


void displayPolynomial(Node* head){
   if(head==NULL) {
       cout << "No poly" << endl;
   } else {
       Node* tmp = head;
       while(tmp!=NULL) {
           cout << tmp->coe<<"x^"<<tmp->e;
           tmp=tmp->link;
           (tmp!=NULL&&tmp->coe!=0) ? cout<<"+": cout<<"\n";
       }
   }
   cout << endl;
}

void polymult(Node* list1, Node* list2) {
    Node* list3 = NULL;
    Node* tmp1 = list1;
    Node* tmp2 = list2;
    while(tmp1!=NULL) {
        while (tmp2!=NULL) {
            list3 = insert_val(list3,tmp1->coe*tmp2->coe,tmp1->e+tmp2->e);
            tmp2 = tmp2->link;
        }
        tmp1 = tmp1->link;
        tmp2 = list2;
    }
    Node* ptr = list3;
    Node* tmp = NULL;
    int size_list3 = count(list3);
    //bubblesort(&list3, size_list3);
    while(ptr->link!=NULL) {
        if(ptr->e==ptr->link->e) {
            ptr->coe = ptr->coe + ptr->link->coe;
            tmp = ptr->link;
            ptr->link = ptr->link->link;
            free(tmp);
        } else {
            ptr = ptr->link;
        }
    }
    displayPolynomial(list3);
}

int main()
{
    srand(time(NULL));
    Node *list1 = NULL;
    Node *list2 = NULL;
    int fir_time, sec_time;
    cout << "Please enter how many terms you need to input in the first list!" << endl;
    cin >> fir_time;
    if(fir_time<100) {
        cout << "And then, please enter each the coefficient and expotent in the first term" << endl;
        for(int i=0;i<fir_time;i++) {
            int ex, coe;
            cout << "the " << i << " term's coefficient and expotent: ";
            cin >> coe >> ex;
            list1=insert_val(list1,coe,ex);
        }
    } else {
        for(int i=fir_time;i>0;i--) {
            int x = rand()%(i+1);
            x == 0 ? x = 1 : 1;
            list1=insert_val(list1,x,i);
        }
    }
    int size_list1 = count(list1);
    //bubblesort(&list1, size_list1);
    displayPolynomial(list1);
    cout << "Please enter how many terms you need to input in the second list!" << endl;
    cin >> sec_time;
    if(sec_time<100) {
        cout << "And then, please enter each the coefficient and expotent in the second term" << endl;
        for(int i=0;i<sec_time;i++) {
            int ex, coe;
            cout << "the " << i << " term's coefficient and expotent: ";
            cin >> coe >> ex;
            list2=insert_val(list2 ,coe,ex);
        }
    } else {
        for(int i=sec_time;i>0;i--) {
            int x = rand()%(i+1);
            x == 0 ? x = 1 : 1;
            list2=insert_val(list2,x,i);
        }
    }
    int size_list2 = count(list2);
    //bubblesort(&list2, size_list2);
    displayPolynomial(list2);
    polymult(list1, list2);
    return 0;
}

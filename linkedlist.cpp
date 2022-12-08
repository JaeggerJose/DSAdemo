#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Node of polynominal in Linked list
struct Node {
    int e, coe;
    Node* link;
};
//count how the size of Llinked list
int count(Node* head) {
    Node* n = head;
    int num = 0;
    while(n!=0) {
        num++;
        n = n->link;
    }
    return num;
}
//instert a node in non_dense_mode
Node* insert_val(Node* start, int coe, int e) {
    Node* tmp;
    Node* n = new Node(); //allocate memory for new node and insert value into it.
    n->coe = coe;
    n->e = e;
    n->link = NULL; //give the new Node's link to NULL,and detect if the linked list is NULL or not.
    if(start == NULL || e > start->e) {
        n->link = start;
        start = n;
    }else {
        tmp = start;
        while(tmp->link!=NULL&& tmp->link->e >= e)
            tmp = tmp->link;
        n->link = tmp->link;
        tmp->link = n;
    }
    return start;
}
//insert a node in dense mode
Node* dense_insert(Node* start, int coe, int e) {
    Node* tmp;
    Node* n = new Node(); //allocate memory for new node and insert value into it.
    n->coe = coe;
    n->e = e;
    n->link = NULL; //give the new Node's link to NULL,and detect if the linked list is NULL or not.
    if(start == NULL)
        return n;
    tmp = start;
    while(tmp->link!=NULL)
        tmp = tmp->link;
    n->link = tmp->link;
    tmp->link = n;
    return start;

}
//remove the repeated terms
void removeDuplicates(Node* start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->link!= NULL) {
        ptr2 = ptr1;

        while (ptr2->link != NULL) {
            if (ptr1->e == ptr2->link->e) {
                ptr1->coe = ptr1->coe + ptr2->link->coe;
                dup = ptr2->link;
                ptr2->link=ptr2->link->link;

                delete (dup);
            }
            else
                ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
}
//swappeing 2 Nodes
Node* swap(struct Node* ptr1, struct Node* ptr2) {
    Node* tmp = ptr2->link;
    ptr2->link = ptr1;
    ptr1->link = tmp;
    return ptr2;
}
// Bubble sort for swaping node according to the exp of each node
int bubblesort(struct Node** head, int count) {
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

void displayPolynomial(Node* head) {
   if(head==NULL) {
       cout << "No poly" << endl;
   } else {
       Node* tmp = head;
       while(tmp!=NULL) {
           cout <<tmp->coe<<"x^"<<tmp->e;
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

    double START,END;
    START = clock();

    while(tmp1!=NULL) {
        while (tmp2!=NULL) {
            list3 = insert_val(list3,tmp1->coe*tmp2->coe,tmp1->e+tmp2->e);
            tmp2 = tmp2->link;
        }
        tmp1 = tmp1->link;
        tmp2 = list2;
    }
    removeDuplicates(list3);
    int size_list3 = count(list3);
    bubblesort(&list3, size_list3);
    END = clock();
    displayPolynomial(list3);
    cout << "Time waste is: " << (END - START) / CLOCKS_PER_SEC <<" second(s)"<< endl;
}

void dense_polymult(Node* list1, Node* list2) {
    Node* tmp1 = list1;
    Node* tmp2 = list2;
    Node* tmp3 = NULL;
    Node* tmp5 = NULL;
    double START,END;

    START = clock(); //start counting time
    //We use the tracing method to trace every term when it mutiply,
    //thus the time complexity will be m*n(tmp1's size * tmp2's size)
    while(tmp1!=NULL) {
        while(tmp2!=NULL) {
            while(tmp3!=NULL&&(tmp3->e!=tmp1->e+tmp2->e))
            tmp3 = tmp3->link;
            if((tmp3==NULL)||(tmp3->e!=tmp1->e+tmp2->e)) {
                tmp5 = dense_insert(tmp5, tmp1->coe*tmp2->coe, tmp1->e+tmp2->e);
            } else if(tmp3->e==tmp1->e+tmp2->e) {
                tmp3->coe += tmp1->coe*tmp2->coe;
            }
            tmp2 = tmp2->link;
            tmp3 = tmp5;
        }
        tmp1 = tmp1->link;
        tmp2 = list2;
    }
    END = clock();// end counting time

    displayPolynomial(tmp5);
    cout << "Time waste is: " << (END - START) / CLOCKS_PER_SEC <<" second(s)"<< endl;
}

int main() {
    srand(time(NULL));
    Node *list1 = NULL;
    Node *list2 = NULL;
    int fir_time, sec_time;

    //inupt the first poly
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
        for(int j=3*fir_time;j>0;j--){
            int epn;
            int coef = (rand()%100)+1;
            int c=rand()%2;
            if(c){
                epn=j;
                list1=insert_val(list1,coef,epn);
            }
        }
    }

    // refrom the first poly
    int size_list1 = count(list1);
    bubblesort(&list1, size_list1);
    removeDuplicates(list1);

    //input the second poly
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
        for(int j=3*sec_time;j>0;j--){
            int epn;
            int coef = (rand()%100)+1;
            int c=rand()%2;
            if(c){
                epn=j;
                list2=insert_val(list2,coef,epn);
            }
        }
    }
    //reform the second poly
    int size_list2 = count(list2);
    bubblesort(&list2, size_list2);
    removeDuplicates(list2);
    //according the size of 2 poly to swap, if bigger will be first.
    if(size_list2>size_list1){
        Node* tmp=list1;
        list1 = list2;
        list2 = tmp;
        int tmp_num = size_list1;
        size_list1 = size_list2;
        size_list2 = tmp_num;
    }
    //print out 2 polys
    displayPolynomial(list1);
    displayPolynomial(list2);

    //determine if 2 poly dense or not
    Node* arg1 = list1;
    cout << arg1->e;
    Node* arg2 = list2;
    bool dense = true;
    while(arg1!=NULL) {
        if(arg1->link!=NULL) {
            if(arg1->e==(arg1->link->e)+1) {
                cout << arg1->e << arg1->link->e+1;
                dense = true;
            }
            else
                dense = false;
        }
        arg1 = arg1->link;
    }
    if(dense) {
        while(arg2!=NULL) {
            if(arg2->link!=NULL) {
                if(arg2->e==(arg2->link->e)+1)
                    dense = true;
                else
                    dense = false;
            }
            arg2 = arg2->link;
        }
    }
    cout << "\nDense:"<< dense << endl;
    //according to the dense or not to using different function for polynominal mutiply
    !dense ? polymult(list1, list2):dense_polymult(list1, list2);
    return 0;
}

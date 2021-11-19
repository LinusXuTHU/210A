#include<iostream>
using namespace std;
typedef struct list {
    int number;
    int s;
    struct list* next;
}linklist;
linklist* creat_in(int n) {
    linklist* head = nullptr, * p, * q=NULL;
    for (int i = 0; i < n; i++) {
        p = (linklist*)malloc(sizeof(linklist));
        cin >> p->number;
        if (head == nullptr) {
            head = p;
            q = p;
        }
        else {
            q->next = p;
            q = p;
        }
    }
    if (q != nullptr) q->next = nullptr;
    return head;
}
linklist* listcpy(linklist* head1) {
    linklist* p = head1, * q,* head2 = nullptr,* r = nullptr;
    while (p != nullptr) {
        q = (linklist*)malloc(sizeof(linklist));
        if (head2 == nullptr) {
            head2 = q;
            q->number = p->number;
            r = q;
        }
        else {
            r->next = q;
            q->number = p->number;
            r = q;
        }
        p = p->next;    
    }
    return head2;
}
linklist* creat_change(int n) {
    linklist* head = nullptr, * p, * q = NULL;
    for (int i = 0; i < n; i++) {
        p = (linklist*)malloc(sizeof(linklist));
        cin >> p->number >> p->s;
        if (head == nullptr) {
            head = p;
            q = p;
        }
        else {
            q->next = p;
            q = p;
        }
    }
    if (q != nullptr) q->next = nullptr;
    return head;
}
linklist* changelist(linklist* in, linklist* change)
{
    linklist* p1, * p2,* p3,* q = nullptr;
    p2 = change;
    while (p2 != nullptr)
    {
        p1 = in;
        q = in;
        while (p1 != nullptr)
        {
            if ( p2->s == 0){
                if(p1->number == p2->number){
                    if (p1 == in)
                    {
                        in = p1->next;
                    }
                    else
                    {
                        q->next = p1->next;
                    }
                    break;
                }
                else
                {
                    q = p1;
                    p1 = p1->next;
                }
            }
            else if (p2->s == 1) {
                if (p1 == in && p2->number < p1->number) {
                    p3 = (linklist*)malloc(sizeof(linklist));
                    p3->number = p2->number;
                    p3->next = p1;
                    in = p3;
                }
                else if (p1 != nullptr && q->number < p2->number && p1->number > p2->number) {
                    p3 = (linklist*)malloc(sizeof(linklist));
                    p3->number = p2->number;
                    q->next = p3;
                    p3->next = p1;
                }
                else if(p2->number > p1->number &&p1->next == nullptr)
                {
                    p3 = (linklist*)malloc(sizeof(linklist));
                    p3->next = nullptr;
                    p1->next = p3;
                    p3->number = p2->number;
                }
                q = p1;
                p1 = p1->next;
            }
        }
        p2 = p2->next;
    }
    return in;
}
void print(linklist* head_out) {
    linklist* p = head_out;
    while (p != nullptr) {
        if (p->number != 0)
            cout << p->number << endl;
        p = p->next;
    }
}
int main() {
    int m, n;
    linklist* in;
    linklist* change;
    cin >> m;
    in = creat_in(m);
    cin >> n;
    change = creat_change(n);
    in = changelist(in, change);
    print(in);
    return 0;
}

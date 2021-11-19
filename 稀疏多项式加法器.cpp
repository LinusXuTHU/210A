#include<iostream>
using namespace std;
typedef struct list {
    int c;
    int e;
    struct list* next;
}linklist;
int amount = 0, p1_used = 0, p2_used = 0, zero = 0;
linklist* creat(int n) {
    linklist* head = nullptr, * p, * q=NULL;
    for (int i = 0; i < n; i++) {
        p = (linklist*)malloc(sizeof(linklist));
        cin >> p->c >> p->e;
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
linklist* addition(linklist* head1, linklist* head2)
{
    linklist* p1, * p2, * q = nullptr, * r = nullptr;
    linklist* head_out = NULL;
    p1 = head1;
    p2 = head2;
    while (true) {
        if (p1->e == p2->e)
        {
            q = (linklist*)malloc(sizeof(linklist));
            q->c = p1->c + p2->c;
            q->e = p1->e;
            if (p1_used == 0 && p2_used == 0) {
                head_out = q;
                r = q;
            }
            else {
                r->next = q;
                r = q;
            }
            p1 = p1->next;
            p2 = p2->next;
            amount++;
            p1_used++;
            p2_used++;
        }
        else if (p1->e > p2->e)
        {
            q = (linklist*)malloc(sizeof(linklist));
            q->c = p2->c;
            q->e = p2->e;
            if (p1_used == 0 && p2_used == 0) {
                head_out = q;
                r = q;
            }
            else {
                r->next = q;
                r = q;
            }
            p2 = p2->next;
            amount++;
            p2_used++;
        }
        else
        {
            q = (linklist*)malloc(sizeof(linklist));
            q->c = p1->c;
            q->e = p1->e;
            if (p1_used == 0 && p2_used == 0) {
                head_out = q;
                r = q;
            }
            else {
                r->next = q;
                r = q;
            }
            p1 = p1->next;
            amount++;
            p1_used++;
        }
        if (p1 == nullptr && p2 == nullptr)
        {
            if (r != nullptr) r->next = nullptr;
            break;
        }
        else if (p1 == nullptr)
        {
            q->next = p2;
            r = q;
            break;
        }
        else if(p2 == nullptr)
        {
            q->next = p1;
            break;
        }
    }
    return head_out;
}
void print(linklist* head_out) {
    linklist* p = head_out;
    while (p != nullptr) {
        if (p->c != 0)
            cout << p->c << " " << p->e << endl;
        p = p->next;
    }
}
void count_zero(linklist* head_out) {
    linklist* p = head_out;
    while (p != nullptr) {
        if (p->c == 0)
            zero++;
        p = p->next;
    }
}
int main() {
    int m,n;
    linklist* head1;
    linklist* head2;
    linklist* head_out = NULL;
    cin >> m;
    head1 = creat(m);
    cin >> n;
    head2 = creat(n);
    head_out = addition(head1, head2);
    count_zero(head_out);
    cout << amount + m + n - p1_used - p2_used - zero<< endl;
    print(head_out);
    return 0;
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// single linked list node
// or "list_entry_t" in the slide
typedef struct __Node{
    int value;
    struct __Node* next;
} Node;

// naive linked-list
typedef struct __List{
    Node* head;
} List;

// write in different perspective, exceptions go away!
void remove_list_node(List* list, Node* target){

    // the "indirect" pointer point to the *address* we update
    Node **indirect = &list->head;

    // use this indirect pointer to access linked list
    while(*indirect != target)
        indirect = &(*indirect)->next;

    *indirect = target->next;
}

void append(int value, Node **head){
    Node **indirect = head;

    // add new node
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value, newNode->next = NULL;

    // traverse
    while(*indirect)
        indirect = &(*indirect)->next;

    // insert
    *indirect = newNode;
}

void traversal_ll(List* list){
    Node* current = list->head;
    while(current){
        printf("%d --> ", current->value);
        current = current->next;
    }
    printf("\n");
}

// when compile, add -g option to debug in gdb, because you sucks
int main(void){
    
    Node a, b, c;
    a.value = 1;
    b.value = 2;
    c.value = 3;

    Node *aa = &a;
    Node *bb = &b;
    Node *cc = &c;

    List ll;
    ll.head = NULL;
    // aa->next = bb;
    // bb->next = cc;
    // cc->next = NULL;

    List *ll_p = &ll;

    append(4, &ll_p->head);
    traversal_ll(ll_p);

    return 0;
}
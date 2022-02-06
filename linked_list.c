#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

void display(struct node *start);
struct node *create();
struct node *add(struct node *start, int data);
struct node *append(struct node *start, int data);
struct node *add_after(struct node *start, int data, int pos);
struct node *add_before(struct node *start, int data, int pos);
struct node *add_at_pos(struct node *start, int data, int pos);
struct node *delete(struct node *start, int pos);
struct node *reverse(struct node *start);
int count(struct node *start);
int search(struct node *start, int data);

int main() {
    int choice, data, pos;
    struct node *start;
    printf("1.Create Linked List\n2.Display\n");
    printf("3.Add At Beginning\n4.Add At End\n5.Add After\n6.Add Before\n");
    printf("6.Add at Position\n8.Delete\n9.Reverse\n10.Count\n11.Search\n12.Exit\n");
    do {
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = create();
                printf("Linked List Created Successfully\n");
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("Enter Data: ");
                scanf("%d", &data);
                start = add(start, data);
                break;
            case 4:
                printf("Enter Data: ");
                scanf("%d", &data);
                start = append(start, data);
                break;
            case 5:
                printf("Enter Data: ");
                scanf("%d", &data);
                printf("Enter Position: ");
                scanf("%d", &pos);
                start = add_after(start, data, pos);
                break;
            case 6:
                printf("Enter Data: ");
                scanf("%d", &data);
                printf("Enter Position: ");
                scanf("%d", &pos);
                start = add_before(start, data, pos);
                break;
            case 7:
                printf("Enter Data: ");
                scanf("%d", &data);
                printf("Enter Position: ");
                scanf("%d", &pos);
                start = add_at_pos(start, data, pos);
                break;
            case 8:
                printf("Enter Position: ");
                scanf("%d", &pos);
                start = delete(start, pos);
                break;
            case 9:
                start = reverse(start);
                printf("Reversal Success!\n");
                break;
            case 10:
                data = count(start);
                printf("Length of Linked List is %d\n", data);
                break;
            case 11:
                printf("Enter Data To Search: ");
                scanf("%d", &data);
                pos = search(start, data);
                if(pos != -1) printf("Position of %d is %d\n", data, pos);
                break;
            case 12:
                exit(0);
            default:
                printf("Wrong Choice\n");
        }


    } while (choice != 12);
}

struct node *create() {
    struct node *start = NULL;
    int size, i, j;
    printf("Enter Size: ");
    scanf("%d", &size);
    printf("Enter Elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &j);
        start = append(start, j);
    }
    return start;
}

struct node *append(struct node *start, int data) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct node *p = start;
    if (start == NULL) {
        temp->data = data;
        temp->next = NULL;
        start = temp;
        return start;
    }
    temp->data = data;
    temp->next = NULL;
    while (p->next != NULL) p = p->next;
    p->next = temp;
    return start;
}

void display(struct node *start) {
    struct node *p = start;
    if (start == NULL) {
        printf("Linked List is Empty\n");
        return;
    }
    while (p != NULL) {
        printf("%d ---> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct node *add(struct node *start, int data) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = start;
    start = temp;
    return start;
}

struct node *add_after(struct node *start, int data, int pos) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct node *p = start;
    int cnt = 0;
    if (pos == 0) {
        start = add(start, data);
        return start;
    }
    while (p->next != NULL) {
        if (cnt == pos) {
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            return start;
        }
        p = p->next;
        cnt++;
    }
    printf("Wrong Position Given!\n");
    return start;
}

struct node *add_before(struct node *start, int data, int pos) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct node *p = start;
    int cnt = 0;
    if (pos == 0){
        start = add(start, data);
        return start;
    }
    while (p->next != NULL) {
        if (cnt == pos - 1) {
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            return start;
        }
        cnt++;
        p = p->next;
    }
    printf("Wrong Position Given!\n");
    return start;
}
struct node *add_at_pos(struct node *start, int data, int pos){
    struct node *p = start;
    int cnt = 0;
    if(pos == 0){
        start->data = data;
        return start;
    }
    while(p->next != NULL){
        if (cnt == pos){
            p->data = data;
            return start;
        }
        p = p->next;
        cnt++;
    }
    printf("Wrong Position Given\n");
    return start;
}
struct node *delete(struct node *start, int pos){
    struct node *p = start;
    int cnt = 0;
    if (pos == 0){
        start = start->next;
        return start;
    }
    pos--;
    while (p->next != NULL){
        if(cnt == pos){
            p->next = p->next->next;
            return start;
        }
        p = p->next;
        cnt++;
    }
    printf("Wrong Position Given!\n");
    return start;
}
struct node *reverse(struct node *start){
    struct node *p, *prev, *next;
    prev = NULL;
    p = start;
    while(p != NULL){
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    start = prev;
    return start;
}
int count(struct node *start){
    struct node *p = start;
    int cnt = 0;
    while(p != NULL){
        cnt += 1;
        p = p->next;
    }
    return cnt;
}
int search(struct node *start, int data){
    struct node *p = start;
    int cnt = 0;
    while(p != NULL){
        if (p->data == data) return cnt;
        p = p->next;
        cnt += 1;
    }
    printf("Data Not in List!\n");
    return -1;
}

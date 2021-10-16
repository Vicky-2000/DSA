#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}* node;

node head = NULL;

node create(){
    node temp = (node)malloc(sizeof(struct node));
    if (temp == NULL)
        printf("\nOut of Memory Space");
    else{
    printf("\nEnter the data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    return temp;
    }
}

void display(){
    if (head == NULL)
        printf("\nList is empty");
    else{
        node ptr = head;
        printf("\nThe elements are : ");
        while (ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
}

void insert_begin(){
    node temp = create();
    if (head == NULL)
        head = temp;
    else{
        temp->link = head;
        head = temp;
    }
}

void insert_end(){
    node temp = create();
    if (head == NULL)
        head = temp;
    else{
        node ptr = head;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = temp;
    }
}

void insert_pos(){
    int i, count;
    node ptr, temp = create();
    printf("\nEnter the position for new node to be inserted : ");
    scanf("%d", &count);
    if (count == 0){
        temp->link = head;
        head = temp;
    }
    else{
        for (i = 0, ptr = head; i < count-1  ; i++){
            if (ptr == NULL){
                printf("\nPosition not found");
                return;
            }
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

void delete_begin(){
    node ptr = head;
    if (ptr == NULL)
        printf("\nList is Empty");
    else{
        printf("\nDeleted element is : %d", ptr->data);
        head = head->link;
        free(ptr);
    }
}

void delete_end(){
    node temp, ptr = head;
    if (head == NULL)
        printf("\nList is Empty");
    else if (head->link == NULL){
        printf("\nDeleted element is : %d", ptr->data);
        head = NULL;
        free(ptr);
    }
    else{
        while (ptr->link != NULL){
            temp = ptr;
            ptr = ptr->link;
        }
        printf("\nThe deleted element is : %d", ptr->data);
        temp->link = NULL;
        free(ptr);
    }
}

void delete_pos(){
    int i, pos;
    node temp, ptr = head;
    if (head == NULL)
        printf("\nList is Empty");
    else{
        printf("\nEnter the position of the node to be deleted : ");
        scanf("%d", &pos);
        if (pos == 0){
            printf("Deleted element is : %d", ptr->data);
            head = head->link;
            free(ptr);
        }
        else{
            for (i = 0; i < pos; i++){
                temp = ptr;
                ptr = ptr->link;
                if (ptr == NULL){
                    printf("\nPosition not Found");
                    return;
                }
            }
            printf("Deleted element is : %d", ptr->data);
            temp->link = ptr->link;
            free(ptr);
        }
    }
}

void main(){
    int ch;
    printf("\n\t\t\tMENU\n\n1.Display\n2.Insert at the beginning\n3.Insert at the end\n4.Insert at specified position\n5.Delete from beginning\n6.Delete from the end\n7.Delete from specified position\n0.Exit\n--------------------------------------");
    while (1){
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch){
        case 1: display();
            break;
        case 2: insert_begin();
            break;
        case 3: insert_end();
            break;
        case 4: insert_pos();
            break;
        case 5: delete_begin();
            break;
        case 6: delete_end();
            break;
        case 7: delete_pos();
            break;
        case 0: exit(0);
        default:
            printf("\nWrong Choice");
        }
    }
}
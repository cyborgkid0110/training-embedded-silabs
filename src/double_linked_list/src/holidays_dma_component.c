#include "holidays_dma_component.h"
#include <stddef.h>

/* initialize double linked list */

Holidays* setInitial(Holidays* head, char* day, char* desc) {
    Holidays* temp = malloc(sizeof(Holidays));
    if (temp == NULL) {
        printf("insufficient memory.\n");
        return NULL;
    }
    temp->prev = NULL;
    strcpy(temp->day, day);
    strcpy(temp->desc, desc);
    temp->next = NULL;
    head = temp;
    return head;
}

/* insert node at begin of linked list*/
Holidays* insertBeg(Holidays* head, char* day, char* desc) {
    if (head == NULL) {
        head = setInitial(head, day, desc);
        return head;
    }
    Holidays* temp = setInitial(temp, day, desc);
    head->prev = temp;
    temp->next = head;
    head = temp;
    return head;
}

/* insert node at last of linked list */
Holidays* pushBack(Holidays* head, char* day, char* desc) {
    if (head == NULL) {
        head = setInitial(head, day, desc);
        return head;
    }

    Holidays* pos = head;
    while (pos->next != NULL)
        pos = pos->next;
    Holidays* temp = setInitial(temp, day, desc);
    pos->next = temp;
    temp->prev = pos;
    return head;
}

/* delelte linked list, start from node */
Holidays* deleteAllData(Holidays* head) {
    Holidays* current = head;
    while (current != NULL) {
        Holidays* next = current->next;
        free(current);
        current = next;
    }
    printf("Data removed.\n");
    return NULL;
}

/* delete first node of linked list */
Holidays* deleteFirst(Holidays* head) {
    if (head != NULL) {
        Holidays* temp = head->next;
        free(head);
        temp->prev = NULL;
        head = temp;
    }
    printf("First data removed.\n");
    return head;
}

/* delete last node of linked list */
Holidays* deleteLast(Holidays* head) {
    if (head != NULL) {
        Holidays* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
    }
    printf("Last data removed.\n");
    return head;
}

/* print all data of linked list */
void printAll(Holidays* head) {
    if (head != NULL) {
        printf("Holiday list: \n");
        Holidays* temp = head;
        while(temp->next != NULL) {
            printf("%s %s\n", temp->day, temp->desc);
            temp = temp->next;
        }
    }
    else
        printf("No data to print.\n");
}

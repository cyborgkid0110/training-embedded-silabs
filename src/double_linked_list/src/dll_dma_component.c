#include "dll_dma_component.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* initialize double linked list */

void init(DoubleLinkedList** head, uint32_t number) {
    if (*head != NULL) {
        SECOND_INIT_WARN_LOG();
        return;
    }

    DoubleLinkedList* temp = malloc(sizeof(DoubleLinkedList));
    if (temp == NULL) {
        INSUFFICIENT_MEMORY_LOG();
        return;
    }
    temp->prev = NULL;
    temp->number = number;
    temp->next = NULL;
    *head = temp;
}

/* insert node at begin of linked list*/
void insertNode(DoubleLinkedList** head, uint32_t number, uint16_t index) {
    if (*head == NULL) {
        init(head, 0);
        INIT_SUCCESS_LOG();
        return;
    }
    uint16_t dll_size = getSize(head);
    if (index > dll_size) {
        INDEX_OUT_OF_RANGE_LOG();
        return;
    }

    /* move to node at index idx */
    DoubleLinkedList* pos = *head;
    for (uint16_t idx = 0; idx < index; idx++) {
        if (pos->next == NULL) break;
        pos = pos->next;
    }

    /* append new node on the left */
    DoubleLinkedList* newNode = NULL;
    init(&newNode, number);

    /* append new node on the right if reached last node */
    if (index == dll_size) {
        newNode->prev = pos;
        pos->next = newNode;
    }
    else {
        newNode->next = pos;
        if (pos->prev != NULL) {
            newNode->prev = pos->prev;
            pos->prev->next = newNode;
        }
        pos->prev = newNode;

        /* change head node if new node is append at index 0 */
        if (index == 0) {
            *head = newNode;
        }
    }
}

/* delete linked list, start from node */
void deleteAllData(DoubleLinkedList** head) {
    DoubleLinkedList* current = *head;
    while (current != NULL) {
        DoubleLinkedList* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("Double linked list removed.\n");
}

/* delete node of linked list */
void deleteNode(DoubleLinkedList** head, uint16_t index) {
    if (*head == NULL) {
        EMPTY_LIST_LOG();
        return;
    }
    uint16_t dll_size = getSize(head);
    if (index >= dll_size) {
        INDEX_OUT_OF_RANGE_LOG();
        return;
    }

    /* move to node at index idx */
    DoubleLinkedList* current = *head;
    for (uint16_t idx = 0; idx < index; idx++) {
        current = current->next;
    }

    if (current->prev == NULL) {
        if (current->next == NULL)
            *head = NULL;
        else {
            current->next->prev = NULL;
        }
    }
    else {
        if (current->next == NULL) {
            current->prev->next = NULL;
        }
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
    }
    free(current);
    printf("Node at index %d removed.\n", index);
}

/* print all data of linked list */
void printAll(DoubleLinkedList** head) {
    if (*head == NULL) {
        EMPTY_LIST_LOG();
    }
    else {
        printf("Linked list: \n");
        DoubleLinkedList* temp = *head;
        do {
            printf("%lu ", temp->number);
            temp = temp->next;
        }
        while(temp != NULL);
        printf("\n");
    }
}

uint16_t getSize(DoubleLinkedList** head) {
  uint16_t count = 0;
  if (*head != NULL) {
      DoubleLinkedList* temp = *head;
      do {
          count++;
          temp = temp->next;
      }
      while (temp != NULL);
  }
  return count;
}

void modifyNode(DoubleLinkedList** head, uint32_t new_num, uint16_t index) {
  if (*head == NULL) {
      EMPTY_LIST_LOG();
  }
  else {
      uint16_t dll_size = getSize(head);
      if (index >= dll_size) {
          INDEX_OUT_OF_RANGE_LOG();
      }
      else {
          /* move to node at index idx */
          DoubleLinkedList* current = *head;
          for (uint16_t idx = 0; idx < index; idx++) {
              current = current->next;
          }
          current->number = new_num;
          printf("Modified node at index %d\n", index);
      }
  }
}

void searchNumber(DoubleLinkedList** head, uint32_t number) {
  if (*head == NULL) {
      EMPTY_LIST_LOG();
  }
  else {
      uint8_t found = 0;
      uint16_t index = 0;
      /* move to node at index idx */
      DoubleLinkedList* current = *head;
      printf("Target: %lu\n", number);
      printf("Found at index: ");
      while (current != NULL) {
          if (current->number == number) {
              printf("[%u] ", index);
              found = 1;
          }
          index++;
          current = current->next;
      }
      if (found == 0) {
          printf("None. ");
          SEARCH_FAILED_LOG();
      }
      printf("\n");
  }
}

void searchIndex(DoubleLinkedList** head, uint16_t index) {
  if (*head == NULL) {
      EMPTY_LIST_LOG();
  }
  else {
      uint16_t dll_size = getSize(head);
      if (index >= dll_size) {
          INDEX_OUT_OF_RANGE_LOG();
      }
      else {
          /* move to node at index idx */
          DoubleLinkedList* current = *head;
          for (uint16_t idx = 0; idx < index; idx++) {
              current = current->next;
          }
          printf("Find number at index %u: %lu\n", index, current->number);
      }
  }
}

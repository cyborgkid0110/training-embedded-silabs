#ifndef DoubleLinkedList_DMA_COMPONENT
#define DoubleLinkedList_DMA_COMPONENT

#include <stdint.h>

#define INIT_SUCCESS_LOG()        printf("Node initialized successfully.\n")
#define SECOND_INIT_WARN_LOG()    printf("Linked list was already initialized.\n")
#define INSUFFICIENT_MEMORY_LOG() printf("Initialize failed due to insufficient memory.\n")
#define EMPTY_LIST_LOG()          printf("Failed due to empty list.\n")
#define INDEX_OUT_OF_RANGE_LOG()  printf("Failed due to index out of range.\n")
#define SEARCH_FAILED_LOG()       printf("Search failed.\n")

typedef struct double_linked_list DoubleLinkedList;

struct double_linked_list {
  DoubleLinkedList* prev;
  uint32_t number;
  DoubleLinkedList* next;
};

void init(DoubleLinkedList** head, uint32_t number);
void insertNode(DoubleLinkedList** head, uint32_t number, uint16_t index);
void deleteNode(DoubleLinkedList** head, uint16_t index);
void deleteAllData(DoubleLinkedList** head);
void modifyNode(DoubleLinkedList** head, uint32_t new_num, uint16_t index);
void searchNumber(DoubleLinkedList** head, uint32_t number);
void searchIndex(DoubleLinkedList** head, uint16_t index);
uint16_t getSize(DoubleLinkedList** head);
void printAll(DoubleLinkedList** head);

#endif // DoubleLinkedList_DMA_COMPONENT

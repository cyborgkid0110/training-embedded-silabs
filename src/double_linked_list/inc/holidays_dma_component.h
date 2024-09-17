#ifndef HOLIDAYS_DMA_COMPONENT
#define HOLIDAYS_DMA_COMPONENT

typedef struct holiday_node Holidays;

struct holiday_node {
  Holidays* prev;
  char day[6];
  char desc[100];
  Holidays* next;
};

Holidays* setInitial(Holidays* head, char* day, char* desc);
Holidays* insertBeg(Holidays* head, char* day, char* desc);
Holidays* pushBack(Holidays* head, char* day, char* desc);
Holidays* deleteAllData(Holidays* head);
Holidays* deleteFirst(Holidays* head);
Holidays* deleteLast(Holidays* head);
void printAll(Holidays* head);

#endif // HOLIDAYS_DMA_COMPONENT

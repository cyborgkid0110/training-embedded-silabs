#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "dll_component.h"

#ifndef MAX_ARGS
#define MAX_ARGS 3
#endif

#ifndef BUFSIZE
#define BUFSIZE    80
#endif

static char cmd_buffer[BUFSIZE];
DoubleLinkedList* head = NULL;

int getElementFromArg(char* arg) {
  int temp = atoi(arg);
  return temp;
}

void parse_command_line() {
  char *args[MAX_ARGS] = {NULL, NULL, NULL};
  char *token = strtok(cmd_buffer, " ");
  uint8_t index = 0;

  while (token != NULL && index < MAX_ARGS) {
      args[index] = token; // Save the token
      token = strtok(NULL, " ");
      index++;
  }

  if (!strcmp(args[0], "init")) {
      init(&head, 0);
  }
  else if (!strcmp(args[0], "insert")) {
      if (args[1] && args[2]) {
          insertNode(&head, getElementFromArg(args[1]), getElementFromArg(args[2]));
      }
      else {
          printf("Wrong command format");
      }
  }
  else if (!strcmp(args[0], "delete")) {
      if (args[1]) {
          deleteNode(&head, getElementFromArg(args[1]));
      }
      else {
          printf("Wrong command format");
      }
  }
  else if (!strcmp(args[0], "find")) {
      if (!strcmp(args[1], "number") && args[2]) {
          searchNumber(&head, getElementFromArg(args[2]));
      }
      else if (!strcmp(args[1], "index") && args[2]) {
          searchIndex(&head, getElementFromArg(args[2]));
      }
      else {
          printf("Wrong command format");
      }
  }
  else if (!strcmp(args[0], "print")) {
      printAll(&head);
  }
  else if (!strcmp(args[0], "modify")) {
      if (args[1] && args[2]) {
          modifyNode(&head, getElementFromArg(args[1]), getElementFromArg(args[2]));
      }
  }
  else {
      printf("\nInput command > ");
  }

}

void double_linked_list_init(void) {
  printf("\n\n----------------------------------------\n");
  printf("Usage: '[command] [option1] [option2]'\n");
  printf("Type 'init' to create new linked list\n");
  printf("Type 'print' to print the list\n");
  printf("Type 'insert [num] [index]' to insert number\n");
  printf("Type 'modify [new_num] [index]' to modify number\n");
  printf("Type 'delete [index]' to clear element\n");;
  printf("Type 'find number/index [num]' to find number\n\n");
}

void double_linked_list_action(void) {
  int8_t c = 0;
  static uint8_t index = 0;
  static uint8_t print_welcome = 1;

  if (print_welcome) {
    printf("Input command > ");
    print_welcome = 0;
  }

  c = getchar();
  if (c > 0) {
   if (c == '\r' || c == '\n') {
     cmd_buffer[index] = '\0';
     parse_command_line();
     index = 0;
   }
   else {
     if (index < BUFSIZE - 1) {
       cmd_buffer[index] = c;
       index++;
     }
     /* Local echo */
     putchar(c);
   }
  }
}


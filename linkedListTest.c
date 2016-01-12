#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
  LinkedList list;
  list.head = NULL;
  list.tail = NULL;
  list.length = 0;
  return list;
}

int add_to_list(LinkedList* list,void* number){
  Element *e = (Element *)malloc(sizeof(Element));
  e->value = (int *)number;
  e->next = NULL;
  if(list->length == 0){
    list->tail = list->head = e;
  } else {
    list->tail->next = e;
    list->tail = e;
  }
  list->length++;
  return list->length;
}

void *get_first_element(LinkedList list){
  return list.head->value;
}

void *get_last_element(LinkedList list){
  return list.tail->value;
}

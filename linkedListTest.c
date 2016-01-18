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
  e->next = e->prev = NULL;
  if(list->length == 0){
    list->tail = list->head = e;
  } else {
    Element *last_value = list->tail;
    list->tail->next = e;
    list->tail = e;
    list->tail->prev = last_value;
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

void incrementor(void *element){
  *(int *)element+=1;
}

void forEach(LinkedList list,ElementProcessor func){
  Element *e = list.head;
  while(e!=NULL){
    func(e->value);
    e = e->next;
  }
}

void *getElementAt(LinkedList list,int index){
  Element *e = list.head;
  int count=0;
  while(e!=NULL){
    if(count == index){
      return e;
    }
    e = e->next;
    count++;
  }
  return NULL;
}

int indexOf(LinkedList list,void *element){
  Element *e = list.head;
  int count=0;
  while(e!=NULL){
    if(element == e->value){
      return count;
    }
    e = e->next;
    count++;
  }
  return -1;
}

void *deleteElementAt(LinkedList *list,int index){
  Element *e = list->head;
  Element *lastElement; 
  int count = 0;
  while(e!=NULL){
    if(index == count){
      Element *last_node = e->prev;
      last_node->next = e->next;
      list->length--;
      lastElement = e;
    }
    e = e->next;
    count++;
  }
  return lastElement->value;
}

int asArray(LinkedList list,void **array,int maxElement){
  Element *e = list.head;
  int length = list.length < maxElement ? list.length : maxElement;
  int count = 0;
  while(e!=NULL && count != length){
    array[count] = e->value;
    count++;
    e = e->next;
  }
  return length;
}

int isDivisible(void *hint,void* item){
  return *(int *)item % *(int *)hint == 0;
}

LinkedList filter(LinkedList list, MatchFunc *func, void *hint){
  Element *e = list.head;
  LinkedList newList = createList();
  while(e != NULL){
    if(func(hint,e->value)){
      add_to_list(&newList, &(e->value));
    }
    e = e->next;
  }
  return newList;
}

void addOne(void* hint,void* sourceItem, void* destinationItem){
  *(int *)destinationItem = *((int *)sourceItem) + *((int *)hint);
}

LinkedList map(LinkedList list, ConvertFunc *convert, void* hint){
  Element *e = list.head;
  LinkedList mappedList = createList();
  while(e != NULL){
    void *newEle = malloc(sizeof(void));
    convert(hint,e->value,newEle);
    add_to_list(&mappedList,newEle);
    e = e->next;
  }
  return mappedList; 
}
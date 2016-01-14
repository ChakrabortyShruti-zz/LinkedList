#include <stdio.h>
#include <assert.h>
#include "linkedList.h"

void test_createList(){
  LinkedList list = createList();
  assert(0 == list.length);
  assert(NULL == list.head);
  assert(NULL == list.tail);
}

void test_add_to_list(){
  LinkedList list = createList();
  int element = 12;
  add_to_list(&list,&element);
  assert(1 == list.length);
  
  int number = 13;
  add_to_list(&list,&number);
  assert(2 == list.length);
}

void test_get_first_element(){
  LinkedList list = createList();
  int element = 12;
  add_to_list(&list,&element);
  int element1 = 13;
  add_to_list(&list,&element1);
  int element2 = 14;
  add_to_list(&list,&element2);
  int *value = get_first_element(list);
  assert(12 == *value);
}

void test_get_last_element(){
  LinkedList list = createList();
  int element = 12;
  add_to_list(&list,&element);
  int element1 = 13;
  add_to_list(&list,&element1);
  int element2 = 14;
  add_to_list(&list,&element2);
  int *value = get_last_element(list);
  assert(14 == *value);
}

void test_forEach(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2  = 14;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  forEach(list,&incrementor);
  assert((*(int *)list.head->value) == 13);
  assert((*(int *)list.tail->value) == 15);
}

void test_getElementAt(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2 = 14,element3 = 15;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  add_to_list(&list,&element3);
  Element result = *((Element *)getElementAt(list,2));
  assert(*(int *)result.value == 14);
}

void test_indexOf(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2 = 14,element3 = 15;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  add_to_list(&list,&element3);
  assert(0 == indexOf(list,&element));
  assert(3 == indexOf(list,&element3));
}

void test_deleteElementAt(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2 = 14,element3 = 15;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  add_to_list(&list,&element3);
  assert(4 == list.length);
  int deletedValue = *((int *)deleteElementAt(&list,2));
  assert(14 == deletedValue);
  assert(3 == list.length);
}


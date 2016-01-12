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

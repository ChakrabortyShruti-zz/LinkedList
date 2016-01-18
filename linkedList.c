#include <stdio.h>
#include <stdlib.h>
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

void test_asArray(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2 = 14,element3 = 15;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  add_to_list(&list,&element3);
  assert(4 == list.length);
  int maxLength = 4;
  void *array = calloc(4,sizeof(int));
  assert(4 == asArray(list,array,maxLength));
  for(int i=0; i<maxLength;i++){
    assert((**(int **)array+i) == *(int *)list.head->value);
    list.head = list.head->next;
  }
}

int isDivisible(void *hint,void* item){
  return *(int *)item % *(int *)hint == 0;
}

void test_filter(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2 = 14,element3 = 15;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  add_to_list(&list,&element3);
  assert(4 == list.length);
  int hint=3;
  LinkedList filteredElements = filter(list,isDivisible,&hint);
  assert(filteredElements.length == 2);
  for (int i = 0; i < filteredElements.length; i++){
    printf("%d\n",**(int **)(filteredElements.head->value));
    filteredElements.head = filteredElements.head -> next;
  }
}

void addOne(void* hint,void* sourceItem, void* destinationItem){
  *(int *)destinationItem = *((int *)sourceItem) + *((int *)hint);
}

void test_map(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2 = 14,element3 = 15;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  add_to_list(&list,&element3);
  assert(4 == list.length);
  int hint = 1;
  LinkedList mappedElements = map(list,addOne,&hint);
  assert(mappedElements.length == 4);
  assert((*(int *)mappedElements.head->value) == 13);
  assert((*(int *)mappedElements.tail->value) == 16);
  for(int i=0; i<mappedElements.length;i++){
    printf("%d\n",(*(int *)mappedElements.head->value));
    mappedElements.head = mappedElements.head->next;
  }
}

void* sumIt(void *hint, void *prevItem, void *item){
  *(int *)item = *(int *)prevItem + *(int *)item;
  return (int *)item;
}

void test_reduce(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2 = 14,element3 = 15;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  add_to_list(&list,&element3);
  assert(4 == list.length);
  int hint = 0;
  int initialValue = 1;
  int *result = (int *)reduce(list,sumIt,&hint,&initialValue);
  assert(55 == *result);
}

 void test_reverse(){
  LinkedList list = createList();
  int element = 12,element1 = 13,element2 = 14,element3 = 15;
  add_to_list(&list,&element);
  add_to_list(&list,&element1);
  add_to_list(&list,&element2);
  add_to_list(&list,&element3);
  assert(4 == list.length);
  LinkedList reverseList = reverse(list);
  assert(4 == reverseList.length);
  assert(15 == *(int *)reverseList.head->value);
  assert(12 == *(int *)reverseList.tail->value);
}


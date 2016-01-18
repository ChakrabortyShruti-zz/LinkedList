typedef struct {
  struct element *head;
  struct element *tail;
  int length;
} LinkedList;

typedef struct element{
  void *value;
  struct element *next;
  struct element *prev;
} Element;

typedef void (*ElementProcessor)(void*);

typedef int MatchFunc(void*, void*);

typedef void ConvertFunc(void*,void*, void*);

LinkedList createList(void);

int add_to_list(LinkedList*, void*);

void *get_first_element(LinkedList);

void *get_last_element(LinkedList);

void incrementor(void*);

void forEach(LinkedList,ElementProcessor);

void *getElementAt(LinkedList,int);

int indexOf(LinkedList,void*);

void *deleteElementAt(LinkedList*,int);

int asArray(LinkedList,void**,int maxElement);

int isDivisible(void*, void*);

LinkedList filter(LinkedList, MatchFunc, void*);

void addOne(void*, void*, void*);

LinkedList map(LinkedList, ConvertFunc, void*);
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

typedef void (*ElementProcessor)(void *);

LinkedList createList(void);

int add_to_list(LinkedList *, void*);

void *get_first_element(LinkedList);

void *get_last_element(LinkedList);

void incrementor(void *);

void forEach(LinkedList,ElementProcessor);

void *getElementAt(LinkedList,int);

int indexOf(LinkedList,void*);

void *deleteElementAt(LinkedList*,int);

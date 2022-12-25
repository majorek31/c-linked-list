#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdint-gcc.h>
#define LINKEDLIST_HEAD_SIGNATURE "__HEAD__"
typedef struct LinkedList
{
    uint32_t size;
    struct Node* head;
} LinkedList;

typedef struct Node
{
    char key[255];
    int data;
    struct Node* next;
} Node;

typedef int(*linkedlist_callback_fn)(Node*);
LinkedList* linkedlist_init();
Node* linkedlist_append(LinkedList* list, char* key, int data);
void linkedlist_remove(LinkedList* list, char* key);
Node* linkedlist_find(LinkedList* list, char* key);
void linkedlist_free(LinkedList* list);
void linkedlist_foreach(LinkedList* list, linkedlist_callback_fn cb);
void linkedList_print(LinkedList* list);
#endif
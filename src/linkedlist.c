#include <linkedlist.h>
#include <malloc.h>
#include <string.h>

LinkedList* linkedlist_init() {
    LinkedList* this  = malloc(sizeof(LinkedList));
    if (this == NULL)
        return NULL;
    memset(this, 0, sizeof(LinkedList));
    this->head = malloc(sizeof(Node));
    if (this->head == NULL) {
        free(this);
        return NULL;
    }
    memset(this->head, 0, sizeof(Node));
    this->head->data = 0;
    this->head->key;
    strcpy(this->head->key, LINKEDLIST_HEAD_SIGNATURE);
    this->size = 1;
    return this;
}
Node* linkedlist_append(LinkedList* this, char* key, int value) {
    Node* cur = this->head;
    while (cur != NULL)
    {
        if (cur->next == NULL) {
            cur->next = malloc(sizeof(Node));
            if (cur->next == NULL) {
                printf("Error: linkedlist_append failed!\n");
                return 0;
            }
            cur->next->data = value;
            strcpy(cur->next->key, key);
            this->size++;
            return cur->next;
        }
        cur = cur->next;
    }
    return cur->next;
}
void linkedList_print(LinkedList* this) {
    Node* cur = this->head;
    while (cur != NULL)
    {
        printf("KEY: %s VALUE: %d\n", cur->key, cur->data);
        cur = cur->next;
    }
}
void linkedlist_remove(LinkedList* this, char* key) {
    Node* cur = this->head;
    while (cur != NULL)
    {
        if (!strcmp(key, cur->next->key)) {
            free(cur->next);
            cur->next = cur->next->next;
            return;
        }
        cur = cur->next;
    }
}
void linkedlist_foreach(LinkedList* this, linkedlist_callback_fn __cb) {
    Node* cur = this->head;
    while (cur != NULL)
    {
        if (__cb(cur))
            return;
        cur = cur->next;
    }
}
Node* linkedlist_find(LinkedList* this, char* key) {
    Node* cur = this->head;
    while (cur != NULL)
    {
        if (!strcmp(cur->key, key))
            return cur;
        cur = cur->next;
    }
    return NULL;
}
void linkedlist_free(LinkedList* this) {
    Node* cur = this->head, *prev;
    while (cur != NULL)
    {
        cur = cur->next;
        prev = cur;
        free(prev);
    }
    free(this);
}
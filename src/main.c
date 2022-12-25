#include <linkedlist.h>
#include <stdio.h>

int printNodes(Node* nd) {
    printf("Custom Print: %s - %d\n", nd->key, nd->data);
    if (nd->data == 10)
        return 1;
    return 0;
}

int main() {
    LinkedList* list = linkedlist_init();
    if (list == NULL) {
        printf("Error: linkedlist_init failed!\n");
        return -1;
    }
    linkedlist_append(list, "AgeOfUser6", 5);
    linkedlist_append(list, "AgeOfUser8", 10);
    linkedlist_append(list, "AgeOfUser5", 15);
    linkedlist_foreach(list, printNodes);
    Node* v1 = linkedlist_find(list, "AgeOfUser5");
    if (v1 == NULL) {
        printf("Error: linkedlist_find failed!\n");
        return -1;
    } 
    Node* v2 = linkedlist_find(list, "User that doesn't exist");
    if (v2 == NULL) {
        printf("Error: Couldn't find user!\n");
    }
    linkedlist_free(list);
}
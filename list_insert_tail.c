Add End
Allan Zhang <allan.zhangas@gmail.com>
Mon 1/10/2018, 12:16 PM
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *insert_tail(int value, struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s value list-elements\n", argv[0]);
        return 1;
    }
    int value = atoi(argv[1]);
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 2, &argv[2]);

    struct node *new_head = insert_tail(value, head);
    print_list(new_head);

    return 0;
}


// Insert a new node containing value at the start of the linked list.
// The head of the new list is returned.
struct node *insert_tail(int value, struct node *head) {

    // declaring the temp node and allocating memory to it
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    // create pointer to original list
    struct node *curr = head;

    // assigning value to the newly create node
    // make it the last in a list
    newnode->data=value;
    newnode->next=NULL;

    // if the list is empty, the new node will be the only one
    if (curr == NULL){
        head = newnode;
    }
    else {
        // if list is not empty, go to the end of the list
        // and make new node the last
        while(curr->next != NULL){
            curr=curr->next;
        }
        curr->next = newnode;
    }

    return head;

}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
         printf("%d", n->data);
         if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}
#include <stdio.h>
#include <stdlib.h>

/**
 * List elements
 */ 
typedef struct node {
    int data; // Element values
    struct node *next; // Pointer to the next element
} Node;

/**
 * List
 */ 
typedef struct linklist {
    int length; // List length
    Node *head; // Head of the list
    Node *tail; // End node. Insertion takes O (1) through this node
} LinkList;

// Printing the list
void print_list(const LinkList *l);
//Insert elements, insert from the tail
void insert_node(LinkList *l, int data);
// Remove elements by value
int delete_node(LinkList *l, int data);

LinkList *newLinkList(void);
// Creation of a list element
Node *newNode(int data, Node *next);

int main()
{
    LinkList *l = newLinkList();
    // Adding elements
    insert_node(l, 1);
    insert_node(l, 2);
    insert_node(l, 3);
    insert_node(l, 4);
    insert_node(l, 4);
    insert_node(l, 20);
    insert_node(l, 15);
    insert_node(l, 5);
    //Printing before deletion
    print_list(l);
    // Deleting elements
    delete_node(l, 2);
    delete_node(l, 4);
    //Printing after deletion
    printf("\n_____After deletion of one 4 and 2________\n");
    print_list(l);
    return 0;
}

/**
 * Create a new function to manually create lists
 */ 
LinkList *newLinkList(void)
{
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->length = 0;
    l->head = newNode(0, NULL);
    l->tail = l->head;
    return l;
}

/**
 * create a new function to manually create elements
 */ 
Node *newNode(int data, Node *next)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = next;
    return n;
}

/**
 * Insert a new element, insert from the tail
 */
void insert_node(LinkList *l, int data)
{
    // Create a new element
    Node *latestNode = newNode(data, l->tail->next);
    // Create a new element
    l->tail->next = latestNode;
    // The end node points to the last element
    l->tail = latestNode;
    // Update the list length
    l->length++;
}

/**
 * Print the list
 */ 
void print_list(const LinkList *l)
{
    printf("\nPrinting the list. . .\n");
    int i = 1;
    if (l->length > 0) {
        Node *temp = l->head->next;

        while (temp != NULL)
        {
            printf("  ->%d element of value: %d\n", i, temp->data);
            i++;
            temp = temp->next;
        }
    }
    printf("End of the print list. . .\n");
}

/**
 * By value, deleting the first matching element
 */ 
int delete_node(LinkList *l, int value)
{
    if (l->length < 1) {
        return 0;
    }
    Node *temp, *item;
    temp = l->head;
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    // Find the element
    if (temp->next != NULL) {
        item = temp->next; // elements to be deleted
        temp->next = temp->next->next; // point to the next next element
        free(item); //release element to be deleted
        l->length--; // Update the list length
        return 1;
    }
    return 0;
}



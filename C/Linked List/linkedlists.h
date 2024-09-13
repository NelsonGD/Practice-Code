/*
 * Code created by Andrew Valentin
 * Available on https://github.com/andrew-valentin/Practice-Code
 * For more resources visit https://ucfsi.wordpress.com/computer-science-i-with-andrew/
 */
 
 

#define EMPTY 0

// Node struct
typedef struct Node 
{
	int value;
	struct Node *next;
} Node;

// Linked List struct that holds head and tail
typedef struct LL 
{
	Node *head;
	Node *tail;
} LL;

// Prints a linked list
void printLLHead(Node *head) 
{
	Node *temp = head;

	printf("\n");

	while (temp != NULL) 
	{
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	  
	printf("NULL\n");
}

void printLL(LL *list) 
{
	if (list == NULL)
	{
		printf("\nList does not exist!\n");
		return;
	}
	
	printLLHead(list->head);
}

// Creates an empty linked list and returns the address
LL *createLL()
{
	LL* newList = malloc(sizeof(LL));

	return newList;
}

// Initializes values inside an empty linked list to NULL
void initLL(LL *ll) 
{
	ll->head = NULL;
	ll->tail = NULL;
}

// Creates an empty node and returns the address
Node *createNode() 
{
	Node* newNode = malloc(sizeof(Node));
	// If the node is empty you are responsible to make the value and next equal to NULL
	newNode -> next = NULL;
	newNode -> value = NULL;

	return newNode;
}

// Creates a node that holds a value and returns the address
Node *createNodeWithValue(int val) 
{
	// your code here
	Node* newNode = malloc(sizeof(Node));
	// ALWAYS check if malloc was done properly
	if(!newNode)
		return NULL;
	newNode->value = val;
	// Remmeber to make the new node point to NULL
	newNode->next = NULL;

	return newNode;
}

// Return 1 if a node with a specific value exists within the linked list
// Otherwise, return 0
int containsNodeHead(Node *head, int val)
{
	// your code here

	// check if list is empty
	if(!head->next)
		return 0;

	// walker to traverse the list
	Node* walker; // Since this node's only purpose is to traverse an already EXISTING list then you don't need to allocate memory for it, and if you do, you need to free it at the end.
	walker = head; // start next to head since we don't need to check the head again
	while(walker) // while walker is not NULL (false)
	{
		if(walker->value == val)
			return 1;
		walker = walker->next;
	}

	return 0;
}

int containsNodeLL(LL *list, int val)
{
	//? This is good BUT you already have a function that does 90% of this, all you have to do is check if the list is empty or not
	// if(!list)
	// 	return 0;

	// Node* walker = list->head;
	// while(walker)
	// {
	// 	if(walker->value == val)
	// 		return 1;
	// 	walker = walker->next;
	//}

	// You are basically saying, return list is NULL if the list is NULL else run the function to look for the value in the function
	return(list == NULL) ? 0 : containsNodeHead(list->head, val);
}

/*
 * NOTE:
 * 	The following functions are meant to explore the different
 * 	ways one could insert or remove nodes from a linked list.
 *
 * 	There are functions that do the same thing; however, they
 * 	are slightly different due to way they have to be implemented.
 *
 * 	Make sure to read the comments carefully since they all explain
 * 	the purpose of each function.
 *
 * 	You could approach each function with a different solution;
 * 	however, in order to stay consistent, the function descriptions
 * 	are written to guide you toward a specific solution.
 * 
 * 	Feel free to play around with the functions in order to implement
 * 	different solutions, but do keep in mind that the function
 * 	descriptions are written to reflect the consistency that I usually
 * 	aim to achieve whenever I write code (and which is something you
 * 	should keep in mind whenever you write code in order to write cleaner,
 * 	easier to understand code).
 */
 
// Inserts an empty node to the head of a linked list and returns the new head
Node *insertEmptyNodeToHead(Node *head) 
{
	// Create new node.
	Node* newNode = malloc(sizeof(Node));
	// Make the newNode point to the new head.
	newNode -> next = head;
	// return new head
	return newNode;
}

// Inserts a node with a value to the head of a linked list and returns the new head
Node *insertNodeWithValueToHead(Node *head, int val) 
{
	// your code here

	//* You already have a function that does this
	//Node* newNode = malloc(sizeof(Node));
	//newNode -> value = val; 

	Node* node = createNodeWithValue(val);
	// make it the new head by making it point to the head as next
	node -> next = head;

	return node;
}

// Inserts an empty node to the head of a linked list
void insertNodeToListHead(LL *list) 
{
	// your code here
	Node* node;

	if(!list)
		return;

	// Check if you have a head, if you don't then just create one, and of course make it the same as the back
	if(!list->head)
	{	
		list->head = createNode();
		list->tail = list -> head;

		return;
	}
	
	node = creteNode();
	node -> next = list->head;
	list->head = node; // Since you are not returning anything, just make the list->head the NEW node
}

// Inserts a node with a value to the head of a linked list
void insertNodeWithValueToListHead(LL *list, int val) 
{
	// your code here

	if(!list)
		return;
	
	if(!list->head)
	{
		list->head = createNodeWithValue(val);
		list->tail = list->head;
		return;
	}

	Node *node = createNodeWithValue(val);
	node->next = list->head;
	list -> head = node;
}

// Inserts an empty node to the tail of a linked list and returns the head
Node *insertEmptyNodeToTail(Node *head) 
{
	// your code here
	Node* node;

	if(!head)
		return createNode();

	node = head;

	while(node)
	{
		if(!node->next)
			node->next = createNode();
			break;
		
		node = node->next;
	}
 . . .  
	return node;
}

// Inserts a node with a value to the tail of a linked list and returns the head
Node *insertNodeWithValueToTail(Node *head, int val) 
{
	// your code here
}

// Inserts an empty node to the tail of a linked list
void insertNodeToListTail(LL *list) 
{
	// your code here
}

// Inserts a node with a value to the tail of a linked list
void insertNodeWithValueToListTail(LL *list, int val) 
{
	// your code here
}

/*
 * NOTE:
 * 	The following functions are meant to give you practice inserting a node
 *  into the middle of a linked list or removing a node from the middle of
 *  a linked list at some arbitrary index.
 *  
 *  The index can start at 0 or 1 (that is up to you to decide).
 *
 *  Just make sure to stay consistent so you don't cause any errors
 *  or confusion later on!
 */

// Inserts an empty node to a specific index in the linked list and returns the head
Node *insertEmptyNodeToLLHead(Node *head, int index) 
{
	// your code here
}

// Inserts a node with a value to a specific index in the linked list and returns the head
Node *insertNodeWithValueToLLHead(Node *head, int val, int index) 
{
	// your code here
}

// Inserts an empty node to a specific index in the linked list
void insertEmptyNodeToLL(LL *list, int index) 
{
	// your code here
}

// Inserts a node with a value to a specific index in the linked list
void insertNodeWithValueToLL(LL *list, int val, int index) 
{
	// your code here
}

// Takes in the head of a linked list and inserts a node with value val in between every node
void insertBetweenAllNodesLLHead(Node *head, int val)
{
	// your code here
}

// Takes in a linked list and inserts a node with value val in between every node
void insertBetweenAllNodesLL(LL *list, int val)
{
	// your code here
}

// Takes in the head of a linked list, removes a node from the head, and returns the new head
Node *removeNodeFromHead(Node *head)
{
	// your code here
}

// Takes in a linked list and removes a node from the head
void removeNodeFromListHead(LL *list)
{
	// your code here
}

// Takes in the head of a linked list, removes a node from the tail, and returns the head
Node *removeNodeFromTail(Node *head)
{
	// your code here
}

// Takes in a linked list and removes a node from the tail
void removeNodeFromListTail(LL *list)
{
	// your code here
}

// Takes in the head of a linked list and a value, removes the first instance of a node
// with that value, and returns the head of the linked list
Node *removeNodeWithValueFromLLHead(Node *head, int val)
{
	// your code here
}

// Takes in a linked list and a value and removes the first instance of a node
// with that value
void removeNodeWithValueFromLL(LL *list, int val)
{
	// your code here
}

// Takes in the head of a linked list and an index, removes the node
// at that index, and returns the head of the linked list
Node *removeNodeInIndexFromLLHead(Node *head, int index)
{
	// your code here
}

// Takes in a linked list and an index and removes the node at that index
void removeNodeInIndexFromLL(LL *list, int index)
{
	// your code here
}

// Takes in the head of a linked list and removes all nodes with the value val
Node *removeAllValuesFromLLHead(Node *head, int val)
{
	// your code here
}

// Takes in a linked list and removes all nodes with the value val
void removeAllValuesFromLL(LL *list, int val)
{
	// your code here
}

// Takes in the head of a linked list and frees all nodes in the linked list
void *freeLLHead(Node *head)
{
	// your code here
}

// Takes in a linked list and frees the entire linked list
void *freeLL(LL *list)
{
	// your code here
}
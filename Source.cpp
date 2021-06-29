#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};
void display(struct Node *n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
}
Node* enqueue(struct Node *head_ref, int value)
{
	struct Node *temp = head_ref;
	if (temp == NULL)
	{
		struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
		new_node->data = value;
		new_node->next = NULL;
		head_ref = new_node;
		return head_ref;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
		new_node->data = value;
		new_node->next = NULL;
		temp->next = new_node;
		return head_ref;
	}
}
Node* dequeue(struct Node *head_ref)
{
	struct Node *temp = head_ref;
	head_ref = head_ref->next;
	free(temp);
	return head_ref;
}
int front(struct Node *head_ref)
{
	return head_ref->data;
}
int rear(struct Node *head_ref)
{
	struct Node *temp = head_ref;
	while (temp->next != NULL)
		temp = temp->next;
	return temp->data;
}
void main()
{
	struct Node *head = NULL;
	head = enqueue(head, 10);
	head = enqueue(head, 20);
	head = enqueue(head, 30);
	head = enqueue(head, 40);
	head = enqueue(head, 50);
	printf("After enqueue : ");
	display(head);
	printf("\nFront : %d", front(head));
	printf("\nRear : %d", rear(head));
	head = dequeue(head);
	printf("\nAfter deque : ");
	display(head);
	head = dequeue(head);
	printf("\nAfter deque : ");
	display(head);
	printf("\nFront : %d", front(head));
	printf("\nRear : %d", rear(head));
	_getch();
}
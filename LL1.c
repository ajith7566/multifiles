#include "link.h"

int main(){
	int choice, list_size, data, position;
	printf("------------------LINKED LIST---------------------\n\n");
	while(1){
		printf("1.Create List.\n2.Insert data at the beginning.");
		printf("\n3.Insert data at the end.\n4.Insert at nth postion.\n5.Display List.\n");
		printf("6.Delete node at the beginning\n7.Delete node at the end\n8.Exit\n\n");
		printf("***************************************************************\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
					printf("Enter the number of nodes in the list\n");
					scanf("%d", &list_size);
					createList(list_size);
					break;
			case 2:
					insert_beg();
					break;
					
			case 3: insert_end();
					break;
					
			case 4: printf("Enter the data to node\n");
					scanf("%d",&data);
					printf("Enter the position at which you want to insert the node\n");
					scanf("%d", &position);
					insert_pos(data, position);
					break;
					
			case 5:
					display_List();
					break;
					
			case 6: delete_beg();
					break;
					
			case 7: printf("Enter the position at which you want to delete the node\n");
					scanf("%d", &position);
					delete_pos(position);
					break;
			case 8:
					exit(0);
					break;
							
			default:printf("Wrong choice, try again!!\n\n");
					break;
		}
	}
}

void createList(int n){
	int i=0;
	node* temp = NULL;
	node* p = NULL;
	// individual node creation.
	while(i<n){
		temp = (node*)malloc(sizeof(node));
		printf("Enter the data to node : %d\n", i+1);
		scanf("%d", &(temp->data));
		temp->next = NULL;
		if(head == NULL){
			head = temp;
		}
		else{
			p = head;
			while(p->next!=NULL){
				p = p->next;
			}
			p->next = temp;
		}
		i++;
	}
	printf("\n\n");
}

void insert_beg(){
	node* temp;
	temp = (node*)malloc(sizeof(node));
	if(temp==NULL){
		printf("\n Out of memory\n");
		return;	
	}
	printf("Enter the data to insert at the beginning\n");
	scanf("%d", &(temp->data));
	if(head == NULL){
		head = temp;
	}
	else{
		temp->next = head;
		head = temp;
	}
}

void insert_end(){
	node* temp = NULL;
	node* p;
	temp = (node*)malloc(sizeof(node));
	printf("Enter the data to insert at the end\n");
	scanf("%d", &(temp->data));
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}
	else{
			p = head;
			while(p->next!=NULL){
				p = p->next;
			}
			p->next = temp;
	}
	printf("\n\n");
}

void insert_pos(int data, int position){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	node* p = head;
	if(position == 1){
		temp->next = p;
		head = temp;
		return;
	}
	int i=0; //moving to the n-1 position in the linked list
	while(i<position-1){
		p = p->next;
		i++;
	}
	temp->next = p->next;
	p->next = temp;
	
	printf("\n\n");
}

void display_List(){
	node* p = head;
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	else{
		while(p!=NULL){
			printf("%d->", p->data);
			p = p->next;
		}
		printf("\n");
	}
	printf("\n\n");
}

void delete_beg(){
	node* temp;
	temp = head;
	head = temp->next;
	temp->next = NULL;
	free(temp);
	printf("\n\n");
}

void delete_pos(int position){
	node* previous = head;
	node* current;
	int i = 1;
	while(i<position-1){
		previous = previous->next;
		i++;
	}
	current = previous->next;
	previous->next = current->next;
	current->next = NULL;
	free(current);
	printf("\n\n");
}

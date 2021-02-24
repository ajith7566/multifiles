#ifndef LINK_H
#define LINK_H
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void createList(int);
void insert_beg();
void insert_end();
void insert_pos(int, int);
void display_List();
void delete_beg();
void delete_pos(int);
void delete_end();
	
node* head = NULL;

#endif

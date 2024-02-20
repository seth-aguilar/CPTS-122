#ifndef functions_h
#define _CRT_SECURE_NO_WARNINGS
#define LOAD 1
#define STORE 2
#define DISPLAY 3
#define INSERT 4
#define DELETE 5
#define EDIT 6
#define SORT 7
#define RATE 8
#define PLAY 9
#define SHUFFLE 10
#define EXIT 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct duration
{
	int seconds;
	int minutes;
} Duration;

typedef struct record
{
	char* artist;
	char* album;
	char* song;
	char* genre;
	Duration length;
	int times_played;
	int rating;
} Record;

typedef struct node
{
	Record data;
	struct node* pNext;
	struct node* pPrev;
} Node;

void display_menu(void);

void loading_delay(void);

int get_choice(void);

Node* makeNode(Record newData);

void load(FILE* instream, Node** pList);

void display(Node* pList);

void rate(Node** pList);

#endif

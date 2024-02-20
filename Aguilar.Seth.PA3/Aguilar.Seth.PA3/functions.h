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
#include <time.h>

typedef struct duration
{
	int seconds;
	int minutes;
} Duration;

typedef struct record
{
	char artist[50];
	char album[50];
	char song[50];
	char genre[50];
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

// Dislpays the home menu of the DMM
void display_menu(void);

// This function just spams a bunch of periods to simultate a delay in between function calls
void loading_delay(void);

// Gets user's choice for which function to use
int get_choice(void);

// Creates a new Node with a structure of new Data. 
Node* makeNode(Record newData);

// Reads data from instream file and records it into linked list
// Precondtion: File musat be open and in mode "r"
void load(FILE* instream, Node** pList);

// Diplays the data inside of pList
void display(Node* pList);

// User can change the rating of a specified song in pList
void rate(Node** pList);

// Initializes pLit
void initList(Node** pList);

// Overrides pervious data in the instream file with the current data in pList
// Preconditon: File must be open and in mode "w"
void store(Node* pList, FILE* instream);

// User can edit a record by artist name
// If the are muliple by an artist the user can select which to edit
void edit(Node** pList);

// Plays through the playlist from a song secified by user
void play(Node* pList);

// Prompts the user for a new set of data and inserts at the front of list
void insert(Node** pList);

// Prompts the user for a song title and deletes that node
void delete(Node** pList);

// Sorts the playlist based on user selection
void sort(Node** pList);

// creates a random order to play the songs in the playlist
void shuffle(Node* pList);
#endif

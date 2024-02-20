#include "functions.h"


void display_menu(void)
{
	printf("1. Load\n");
	printf("2. Store\n");
	printf("3. Display\n");
	printf("4. Insert\n");
	printf("5. Delete\n");
	printf("6. Edit\n");
	printf("7. Sort\n");
	printf("8. Rate\n");
	printf("9. Play\n");
	printf("10. Shuffle\n");
	printf("11. Exit\n");
}

void loading_delay(void)
{
	printf("Loading");
	system("cls");
	printf("Loading.");
	system("cls");
	printf("Loading..");
	system("cls");
	printf("Loading...");
	system("cls");
	printf("Loading....");
	system("cls");
	printf("Loading.....");
	system("cls");
	printf("Loading......");
	system("cls");
	printf("Loading.......");
	system("cls");
	printf("Loading........");
	system("cls");
	printf("Loading.........");
	system("cls");
	printf("Loading..........");
	system("cls");
	printf("Loading...........");
	system("cls");
	printf("Loading............");
	system("cls");
	printf("Loading.............");
	system("cls");
	printf("Loading..............");
	system("cls");
	printf("Loading...............");
	system("cls");
	printf("Loading................");
	system("cls");
	printf("Loading.................");
	system("cls");

}

int get_choice(void)
{
	int choice = 0;

	scanf("%d", &choice);

	return choice;
}

Node* makeNode(Record newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = newData;
		newNode->pNext = NULL;
		newNode->pPrev = NULL;

	}
	return newNode;
}

void load(FILE* instream, Node** pList)
{
	Node* pHead = NULL;
	char *line = "";
	Record data = {""};

	while (pHead != NULL)
	{
		fgets(line, 100, instream);

		if (line[0] == '\"')
		{
			strcpy(data.artist, strtok(&line[1], "\""));
			strcpy(data.album, strtok(NULL, ","));
			strcpy(data.genre, strtok(NULL, ","));
			strcpy(data.genre, strtok(NULL, ","));
			data.length.minutes = atoi(strtok(NULL, ":"));
			data.length.seconds = atoi(strtok(NULL, ","));
			data.times_played = atoi(strtok(NULL, ","));
			data.rating = atoi(strtok(NULL, "\n"));
		}
		else
		{
			strcpy(data.artist, strtok(line, ","));
			strcpy(data.album, strtok(NULL, ","));
			strcpy(data.genre, strtok(NULL, ","));
			strcpy(data.genre, strtok(NULL, ","));
			data.length.minutes = atoi(strtok(NULL, ":"));
			data.length.seconds = atoi(strtok(NULL, ","));
			data.times_played = atoi(strtok(NULL, ","));
			data.rating = atoi(strtok(NULL, "\n"));
		}


		pHead = makeNode(data);

		pHead->pPrev = pHead;
		pHead = pHead->pNext;
	}
}

void display(Node* pList)
{
	Node* pHead = pList;
	int choice = 0, count = 1, success = 0;
	char* artist = "";

	while (choice != 1 && choice != 2)
	{
		printf("Would you like to:\n");
		printf("1. Print all records\n");
		printf("2. Print records for a specific artist\n");
		scanf("%d", &choice);
		system("cls");
	}

	if (choice == 1)
	{
		while (pHead != NULL)
		{
			printf("Record %d:\n", count);
			printf("Artist: %s, ", pHead->data.artist);
			printf("Album: %s, ", pHead->data.album);
			printf("Song: %s, ", pHead->data.song);
			printf("Genre: %s, ", pHead->data.genre);
			printf("Length: %d:%d, ", pHead->data.length.minutes, pHead->data.length.seconds);
			printf("Played %d times, ", pHead->data.times_played);
			printf("Rating: %d\n", pHead->data.rating);
			putchar("\n");

			pHead->pPrev = pHead;
			pHead = pHead->pNext;
			++count;
		}
	}
	if (choice == 2)
	{
		printf("What artist would you like to see?\n");
		strcpy(choice, gets_s(100, 100));

		while (pHead != NULL)
		{
			if (strcmp(pHead->data.artist, choice) == 0)
			{
				printf("Record %d:\n", count);
				printf("Artist: %s, ", pHead->data.artist);
				printf("Album: %s, ", pHead->data.album);
				printf("Song: %s, ", pHead->data.song);
				printf("Genre: %s, ", pHead->data.genre);
				printf("Length: %d:%d, ", pHead->data.length.minutes, pHead->data.length.seconds);
				printf("Played %d times, ", pHead->data.times_played);
				printf("Rating: %d\n", pHead->data.rating);
				putchar("\n");

			}
			pHead->pPrev = pHead;
			pHead = pHead->pNext;
			++count, success = 1;
		}
		if (success == 0)
		{
			printf("No artist was found under that name\n");
		}
	}
}

void rate(Node** pList)
{
	char* choice = "";
	Node* pHead = *pList;

	printf("What song would you like to change the rating of?");
	strcpy(choice, gets_s(100, 100));

	while (strcmp(choice, pHead->data.song) != 0)
	{
		pHead->pPrev = pHead;
		pHead = pHead->pNext;
	}
}
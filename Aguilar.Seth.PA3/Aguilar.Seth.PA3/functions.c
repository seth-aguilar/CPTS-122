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

void initList(Node** pList)
{
	*pList = NULL; 
}

void load(FILE* instream, Node** pList)
{
	char line[150] = "";
	Record data ={NULL};
	Node* pHead = NULL;
	Node* pPrev = NULL;

	while (fgets(line, 100, instream))
	{
		if (line[0] == '\"')
		{
			strcpy(data.artist, strtok(line, "\""));
			strcpy(data.album, strtok(NULL, ","));
			strcpy(data.song, strtok(NULL, ","));
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

		Node* pNew = makeNode(data);

		if (*pList == NULL)
		{
			pHead = pNew;
			pPrev = pNew;
			*pList = pNew;
		}
		else
		{
			pPrev->pNext = pNew;
			pNew->pPrev = pPrev;
			pPrev = pNew;
		}
	}
}

void display(Node* pList)
{
	int choice = 0, count = 1, success = 0;
	char artist[100];

	while (choice != 1 && choice != 2)
	{
		printf("Would you like to:\n");
		printf("1. Print all records\n");
		printf("2. Print records for a specific artist\n");
		choice = get_choice();
		system("cls");
	}

	if (choice == 1)
	{
		while (pList != NULL)
		{
			printf("Record %d:\n", count);
			printf("Artist: %s, ", pList->data.artist);
			printf("Album: %s, ", pList->data.album);
			printf("Song: %s, ", pList->data.song);
			printf("Genre: %s, ", pList->data.genre);
			printf("Length: %d:%d, ", pList->data.length.minutes, pList->data.length.seconds);
			printf("Played %d times, ", pList->data.times_played);
			printf("Rating: %d\n", pList->data.rating);
			putchar("\n");

			pList->pPrev = pList;
			pList = pList->pNext;
			++count;
		}
	}
	if (choice == 2)
	{
		printf("What artist would you like to see?\n");
		scanf("%s", artist);

		while (pList != NULL)
		{
			if (strcmp(pList->data.artist, choice) == 0)
			{
				printf("Record %d:\n", count);
				printf("Artist: %s, ", pList->data.artist);
				printf("Album: %s, ", pList->data.album);
				printf("Song: %s, ", pList->data.song);
				printf("Genre: %s, ", pList->data.genre);
				printf("Length: %d:%d, ", pList->data.length.minutes, pList->data.length.seconds);
				printf("Played %d times, ", pList->data.times_played);
				printf("Rating: %d\n", pList->data.rating);
				putchar("\n");

			}
			pList->pPrev = pList;
			pList = pList->pNext;
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
	char choice[100];
	int rating;
	Node* pHead = *pList;

	printf("What song would you like to change the rating of? ");
	scanf("%s", choice);

	while (pHead != NULL && strcmp(choice, pHead->data.song) != 0)
	{
		pHead = pHead->pNext;
	}
	if (pHead == NULL)
	{
		printf("A song under that name could not be found.\n");
	}
	else
	{
		printf("What would you like to change the rating to? ");
		scanf("%d", &rating);

		pHead->data.rating = rating;
	}
}

void store(Node* pList, FILE* instream) 
{
	Node* pHead = pList;

	while (pHead != NULL)
	{
		fprintf(instream, "%s,%s,%s,%s,%d:%d,%d,%d\n", pHead->data.artist, pHead->data.album, pHead->data.song, 
			pHead->data.genre, pHead->data.length.minutes, pHead->data.length.seconds, pHead->data.times_played, 
			pHead->data.rating);
		pHead = pHead->pNext;
	}
}

void edit(Node** pList)
{
	int choice = 0;
	char artist[100];
	Node* pHead = pList;

	printf("Which artist's record would you like to change the rating of? ");
	scanf("%s", artist);

	while (pHead != NULL)
	{
		if (strcmp(artist, pHead->data.artist) == 0)
		{
			printf("%s by %s found, what attribute would you like to edit?\n", pHead->data.song, pHead->data.artist);
			while (choice < 1 || choice > 7)
			{
				printf("1. Artist\n");
				printf("2. Album\n");
				printf("3. Song title\n");
				printf("4. Genre\n");
				printf("5. Duration\n");
				printf("6. Times played\n");
				printf("7. Rating\n");
				choice = get_choice();
				system("cls");
			}				
			if (choice == 1)
			{
				printf("New artist name?");
				scanf("%s", pHead->data.artist);
			}
			if (choice == 2)
			{
				printf("New album name?");
				scanf("%s", pHead->data.album);
			}
			if (choice == 3)
			{
				printf("New song name?");
				scanf("%s", pHead->data.song);
			}
			if (choice == 4)
			{
				printf("New genre?");
				scanf("%s", pHead->data.genre);
			}
			if (choice == 5)
			{
				printf("New minutes?");
				scanf("%d", &pHead->data.length.minutes);
				printf("New seconds?");
				scanf("%d", &pHead->data.length.seconds);
			}
			if (choice == 6)
			{
				printf("New times played?");
				scanf("%d", &pHead->data.times_played);
			}
			if (choice == 7)
			{
				printf("New rating?");
				scanf("%s", pHead->data.rating);
			}

		}
		pHead = pHead->pNext;
	}
}

void play(Node* pList)
{
	int success = 0;
	char song[100];

	printf("What song would you like to play from?\n");
	scanf("%s", song);
	system("cls");

	while (strcmp(pList->data.song,song) != 0)
	{
		pList->pPrev = pList;
		pList = pList->pNext;
		if (pList == NULL)
		{
			printf("Song not found");
		}
	}	
	
	while (pList != NULL)
	{
		printf("Now playing %s", pList->data.song);
		printf("Artist: %s\n", pList->data.artist);
		printf("Album: %s\n", pList->data.album);
		printf("Song: %s\n", pList->data.song);
		printf("Genre: %s\n", pList->data.genre);
		printf("Duration: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
		printf("Played %d times\n", pList->data.times_played);
		printf("Rating: %d\n", pList->data.rating);
		loading_delay();
		system("cls");

		pList->pPrev = pList;
		pList = pList->pNext;
	}
}

void insert(Node** pList)
{
	Record data = { NULL };

	printf("New artist name?");
	scanf("%s", data.artist);
	printf("New album name?");
	scanf("%s", data.album);
	printf("New song name?");
	scanf("%s", data.song);
	printf("New genre?");
	scanf("%s", data.genre);
	printf("New minutes?");
	scanf("%d", &data.length.minutes);
	printf("New seconds?");
	scanf("%d", &data.length.seconds);
	printf("New times played?");
	scanf("%d", &data.times_played);
	printf("New rating?");
	scanf("%d", &data.rating);

	Node* newNode = makeNode(data);

	newNode->pNext = *pList;
	(*pList)->pPrev = newNode;
	*pList = newNode;
}

void delete(Node** pList)
{
	char* song = "";
	Node* pHead = *pList;
	Node* pPrev = NULL;

	printf("What song would you like to delete?");
	scanf("%s", song);

	while (pHead != NULL)
	{
		if (strcmp(song, pHead->data.song) == 0)
		{
			if (pHead == *pList)
			{
				*pList = pHead->pNext;
			}
			else
			{
				pPrev->pNext = pHead->pNext;
				if (pHead->pNext != NULL)
				{
					pHead->pNext->pPrev = pPrev;
				}
			}			
			free(pHead);
			break;
		}

		pPrev = pHead;
		pHead = pHead->pNext;
	}
	
}

void sort(Node** pList)
{
	int choice = 0;
	Node* pHead = *pList;
	Node* pNext = NULL;

	while (choice < 1 || choice > 4)
	{
		printf("How would you like to sort the records?");
		printf("1. Sort based on artist (A-Z)");
		printf("2. Sort based on album title (A-Z)");
		printf("3. Sort based on rating (1-5)");
		printf("4. Sort based on times played (largest-smallest)");
		choice = get_choice();
		system("cls");
	}
	switch (choice)
	{
	case 1:
		for (pHead = (*pList)->pNext; pHead != NULL; pHead = pHead->pNext)
		{
			for (pNext = pHead->pNext; pNext != NULL; pNext = pNext->pNext)
			{
				if (strcmp(pHead->data.artist, pNext->data.artist) > 0)
				{
					Record temp = pHead->data;
					pHead->data = pNext->data;
					pNext->data = temp;
				}
			}
		}
		break;
	case 2:
		for (pHead = (*pList)->pNext; pHead != NULL; pHead = pHead->pNext)
		{
			for (pNext = pHead->pNext; pNext != NULL; pNext = pNext->pNext)
			{
				if (strcmp(pHead->data.album, pNext->data.album) > 0)
				{
					Record temp = pHead->data;
					pHead->data = pNext->data;
					pNext->data = temp;
				}
			}
		}
		break;
	case 3:
		for (pHead = (*pList)->pNext; pHead != NULL; pHead = pHead->pNext)
		{
			for (pNext = pHead->pNext; pNext != NULL; pNext = pNext->pNext)
			{
				if (pHead->data.rating > pNext->data.rating)
				{
					Record temp = pHead->data;
					pHead->data = pNext->data;
					pNext->data = temp;
				}
			}
		}
		break;
	case 4:
		for (pHead = (*pList)->pNext; pHead != NULL; pHead = pHead->pNext)
		{
			for (pNext = pHead->pNext; pNext != NULL; pNext = pNext->pNext)
			{
				if (pHead->data.times_played > pNext->data.times_played)
				{
					Record temp = pHead->data;
					pHead->data = pNext->data;
					pNext->data = temp;
				}
			}
		}

		break;
	}
}

void shuffle(Node* pList)
{
	int count = 0, max = 0, random = 0;

	while (pList != NULL)
	{
		max++;
		pList = pList->pNext;	
	}

	srand(time(NULL));


	for (int i = 0; i < max; i++) {
		random = rand() % max;

		for (int j = 0; j < random; j++) {
			pList = pList->pNext;
		}

		printf("Now playing %s\n", pList->data.song);
		printf("Artist: %s\n", pList->data.artist);
		printf("Album: %s\n", pList->data.album);
		printf("Song: %s\n", pList->data.song);
		printf("Genre: %s\n", pList->data.genre);
		printf("Duration: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
		printf("Played %d times\n", pList->data.times_played);
		printf("Rating: %d\n", pList->data.rating);
		loading_delay();
		system("cls");
	}
}
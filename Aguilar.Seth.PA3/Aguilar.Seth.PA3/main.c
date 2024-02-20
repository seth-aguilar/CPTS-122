#include "functions.h"

int main(int argc, char* argv[])
{
	int choice = 0;

	FILE* instream = fopen("musicPlaylist.csv", "r");
	
	Node* pList = NULL;

	initList(&pList);

	printf("Welcome to Seth's Digital Music Manager!\n");
	printf("What would you like to do?\n");

	while (choice != EXIT)
	{
		do
		{
			display_menu();			
			choice = get_choice();
			switch (choice)
			{
			case LOAD:
				instream = fopen("musicPlaylist.csv", "r");
				load(instream, &pList);
				loading_delay();
				break;
			case STORE:
				instream = fopen("musicPlaylist.csv", "w");
				store(&pList, instream);
				break;
			case DISPLAY:
				display(pList);
				system("pause");
				system("cls");
				break;
			case INSERT:
				insert(&pList);
				system("pause");
				system("cls");
				break;
			case DELETE:
				delete(&pList);
				system("pause");
				system("cls");
				break;
			case EDIT:
				edit(&pList);
				system("pause");
				system("cls");
				break;
			case SORT:
				sort(&pList);
				system("pause");
				system("cls");
				break;
			case RATE:
				rate(&pList);
				system("pause");
				system("cls");
				break;
			case PLAY:
				play(pList);
				system("pause");
				system("cls");
				break;
			case SHUFFLE:
				shuffle(pList);
				system("pause");
				system("cls");
				break;
			case EXIT:
				instream = fopen("musicPlaylist.csv", "r");
				store(&pList, instream);
				printf("Exiting\n");
				fclose(instream);
				return 0;
			}
			system("cls");
		} while (choice < DISPLAY || choice > EXIT);
	}
	return 0;
}
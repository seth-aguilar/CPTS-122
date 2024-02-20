#include "functions.h"

int main(void)
{
	int choice = 0;

	FILE* instream = fopen("testPlaylist.csv", "r");
	//FILE* instream = fopen("musicPlaylist.csv", "r");
	
	Node* pList = NULL;

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
				load(instream, pList);
				loading_delay();
				break;
			case STORE:

				break;
			case DISPLAY:
				display(pList);
				system("pause");
				system("cls");
				break;
			case INSERT:
				printf("Not yet implemented");
				system("pause");
				system("cls");
				break;
			case DELETE:
				printf("Not yet implemented");
				system("pause");
				system("cls");
				break;
			case EDIT:

				break;
			case SORT:
				printf("Not yet implemented");
				system("pause");
				system("cls");
				break;
			case RATE:

				break;
			case PLAY:

				break;
			case SHUFFLE:
				printf("Not yet implemented");
				system("pause");
				system("cls");
				break;
			case EXIT:
				printf("Exiting\n");
				return 0;
			}
			system("cls");
		} while (choice < DISPLAY || choice > EXIT);
	}
	return 0;
}
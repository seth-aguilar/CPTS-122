#ifndef function_h
#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 1440

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;

typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
}FitbitData;


void read_file(FILE* input, FitbitData* patient_data);

double total_cals(FitbitData *clean_data);
double total_distance(FitbitData *clean_data);
double total_floors(FitbitData *clean_data);
double total_steps(FitbitData *clean_data);

double average_heartrate(FitbitData *clean_data);

int max_steps(FitbitData *clean_data);

void find_poorest_sleep(FitbitData* clean_data, int size, int* start, int* end, int* sum);

#endif
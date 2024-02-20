#include "function.h"

void read_file(FILE* input, FitbitData* patient_data)
{
	int i = 0;
	char line[1450] = "", * token, target[5];

	if (input != NULL) // did we open the file successfully?
	{
		// we opened the file successfully!
		// we can process the data
		fgets(line, 1450, input); // target line
		token = strtok(line, ":");
		token = strtok(NULL, ",");
		token = strtok(NULL, ",");
		strcpy(target, token);

		fgets(line, 1450, input); // header line

		// we read the line inside of the while () condition!
		while (fgets(line, 1450, input) != NULL)
		{
			fgets(line, 1450, input);
			token = strtok(line, ",");
			if (strcmp(token, target) == 0)
			{
				if (token == NULL)
				{
					strcpy(patient_data[i].patient, -1);
				}
				else
				{
					strcpy(patient_data[i].patient, token);
					token = strtok(NULL, ",");
				}
				if (token == NULL)
				{
					strcpy(patient_data[i].minute, -1);
				}
				else
				{
					strcpy(patient_data[i].minute, token);
					token = strtok(NULL, ",");
				}
				if (token == NULL)
				{
					patient_data[i].calories = -1;
				}
				else
				{
					patient_data[i].calories = atof(token);
					token = strtok(NULL, ",");
				}
				if (token == NULL)
				{
					patient_data[i].distance = -1;
				}
				else
				{
					patient_data[i].distance = atof(token);
					token = strtok(NULL, ",");
				}
				if (token == NULL)
				{
					patient_data[i].floors = -1;
				}
				else
				{
					patient_data[i].floors = atoi(token);
					token = strtok(NULL, ",");
				}
				if (token == NULL)
				{
					patient_data[i].heartRate = -1;
				}
				else
				{
					patient_data[i].heartRate = atoi(token);
					token = strtok(NULL, ",");
				}
				if (token == NULL)
				{
					patient_data[i].steps = -1;
				}
				else
				{
					patient_data[i].steps = atoi(token);
					token = strtok(NULL, ",");
					if (token == NULL)
					{
						patient_data[i].sleepLevel = -1;
					}
					else
					{
						patient_data[i].sleepLevel = atoi(token);
					}
					++i; // go to the next element in the patient data array
				}
			}
		}
	}
}

double total_cals(FitbitData *clean_data)
{
	int i = 0;
	double total = 0;

	for (; i < ARR_SIZE; ++i);
	{
		if (clean_data[i].calories != -1)
		{
			total += clean_data[i].calories;
		}
	}

	return total;
}

double total_distance(FitbitData *clean_data)
{
	int i = 0;
	double total = 0;

	for (; i < ARR_SIZE; ++i);
	{
		if (clean_data[i].distance != -1)
		{
			total += clean_data[i].distance;
		}
	}

	return total;
}

double total_floors(FitbitData *clean_data)
{
	int i = 0;
	double total = 0;

	for (; i < ARR_SIZE; ++i);
	{
		if (clean_data[i].floors != -1)
		{
			total += clean_data[i].floors;
		}
	}

	return total;
}

double total_steps(FitbitData *clean_data)
{
	int i = 0;
	double total = 0;

	for (; i < ARR_SIZE; ++i);
	{
		if (clean_data[i].steps != -1)
		{
			total += clean_data[i].steps;
		}
	}

	return total;
}

double average_heartrate(FitbitData *clean_data)
{
	int i = 0, count = 0;
	double total = 0;

	for (; i < ARR_SIZE; ++i);
	{
		if (clean_data[i].heartRate != -1)
		{
			total += clean_data[i].heartRate;
			++count;
		}
	}

	return total / count;
}

int max_steps(FitbitData *clean_data)
{
	int i = 0, max = 0;
	
	for (; i < ARR_SIZE; ++i)
	{
		if (clean_data[i].steps > max)
		{
			max = clean_data[i].steps;
		}
	}

	return max;
}

void find_poorest_sleep(FitbitData* clean_data, int size, int* start, int* end, int* sum)
{
	int i = 0, cur_start = 0, cur_end = 0, cur_sum = 0;
	*start = -1;
	*end = -1;
	*sum = -1;
	for (; i < size; i++)
	{
		if (clean_data[i].sleepLevel > 1)
		{
			if (cur_sum == 0)
			{
				cur_start = i;
			}
			cur_end = i;
			cur_sum += clean_data[i].sleepLevel;
		}
		else
		{
			if (cur_sum > *sum)
			{
				*start = cur_start;
				*end = cur_end;
				*sum = cur_sum;
			}
			cur_start = 0;
			cur_end = 0;
			cur_sum = 0;
		}
	}
}

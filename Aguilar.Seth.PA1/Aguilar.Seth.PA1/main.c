#include "function.h"

int main(void)
{
	FitbitData patient_data[ARR_SIZE];

	FILE* input = fopen("FitbitData.csv", "r"), * output = fopen("Results.csv", "w");

	read_file(input, patient_data);

	int max_step = max_steps(patient_data), start = 0, end = 0, sum = 0;
	double total_cal = total_cals(patient_data), total_dis = total_distance(patient_data), total_floor = total_floors(patient_data), total_step = total_steps(patient_data), average_heart = average_heartrate(patient_data);

	find_poorest_sleep(patient_data, ARR_SIZE, &start, &end, &sum);

	fprintf(output, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Bad Sleep Start,Bad Sleep End,Bad Sleep Sum\n");
	fprintf(output, "%lf,%lf,%lf,%lf,%lf,%d,%d,%d,%d\n", total_cal, total_dis, total_floor, total_step, average_heart, max_step, start, end, sum);
	fprintf(output, "Cleansed Data:\n");
	for (int i = 0; i < ARR_SIZE; ++i)
	{
		fprintf(output, "%s,%s,%lf,%lf,%d,%d,%d,%d\n", patient_data[i].patient, patient_data[i].minute, patient_data[i].calories, patient_data[i].distance, patient_data[i].floors, patient_data[i].heartRate, patient_data[i].steps, patient_data[i].sleepLevel);
	}

	fclose(input);
	fclose(output);

	return 0;
}
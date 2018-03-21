#include "header.h"


float* insert_arr;
int ic; 
float* delete_arr;
int dc;

//!!!! DIVIDE BY ZERO ERROR IN AVERAGES?

void main(){

	/*printf("Number of cases: ");
	scanf("%d", &t);*/

	double increase_arr[5] = {2, 3, 1.75, 1.5, 1.25};
	double decrease_arr[3] = {0.25, 0.5, 0.75};

	FILE *fp_max_insert;
	FILE *fp_max_delete;
	FILE *fp_avg_all;
	FILE *fp_avg_insert;
	FILE *fp_avg_delete;

	fp_max_insert = fopen("op32/Max_Insert.txt", "a");
	fp_max_delete = fopen("op32/Max_Delete.txt", "a");
	fp_avg_all = fopen("op32/Avg_All.txt", "a");
	fp_avg_insert = fopen("op32/Avg_Insert.txt", "a");
	fp_avg_delete = fopen("op32/Avg_Delete.txt", "a");

	//Enter number of operations: 
	long long int n;
	printf("Enter number of operations");
	scanf("%lld", &n);
	/*fprintf(fp_max_insert, "No. of operations: %lld \n", n);
	fprintf(fp_max_delete, "No. of operations: %lld \n", n);
	fprintf(fp_avg_all, "No. of operations: %lld \n", n);
	fprintf(fp_avg_insert, "No. of operations: %lld \n", n);
	fprintf(fp_avg_delete, "No. of operations: %lld \n", n); 
*/
	int k = 0;

	//Print columns headers
	for(k=0; k<5; k++){
		/*if(k == 0){
		fprintf(fp_max_insert, "\t");	
		fprintf(fp_max_delete, "\t");	
		fprintf(fp_avg_all, "\t");	
		fprintf(fp_avg_insert, "\t");	
		fprintf(fp_avg_delete, "\t");	
		}*/

		fprintf(fp_max_insert, "inc_%lf,", increase_arr[k]);
		fprintf(fp_max_delete, "inc_%lf,", increase_arr[k]);
		fprintf(fp_avg_all, "inc_%lf,", increase_arr[k]);
		fprintf(fp_avg_insert, "inc_%lf,", increase_arr[k]);
		fprintf(fp_avg_delete, "inc_%lf,", increase_arr[k]);

		fprintf(fp_max_insert, "dec_%lf,", decrease_arr[k]);
		fprintf(fp_max_delete, "dec_%lf,", decrease_arr[k]);
		fprintf(fp_avg_all, "dec_%lf,", decrease_arr[k]);
		fprintf(fp_avg_insert, "dec_%lf,", decrease_arr[k]);
		fprintf(fp_avg_delete, "dec_%lf,", decrease_arr[k]);


	}

	int i;
	for(i=0; i<3; i++){
		//Create a table and a pointer to the table
		Table x;
		Table* ptr;
		ptr = &x;

		//Initialize the table
		long long int cur_size, max_size;
		float increase_factor, decrease_factor;
		cur_size = 0;
		max_size = 1;
		//printf("Enter factor to increase by");
		//scanf("%f", &increase_factor);
		//printf("Enter factor to decrease by");
		//scanf("%f", &decrease_factor);
		decrease_factor = decrease_arr[i];
		printf("decrease factor is: %f", decrease_factor);

		

		for(k = 0; k<5; k++){

			//Print row names 
			if(k==0){
				fprintf(fp_max_insert, "\n %f", decrease_arr[i]);
				fprintf(fp_max_delete, "\n %f", decrease_arr[i]);
				fprintf(fp_avg_all, "\n %f", decrease_arr[i]);
				fprintf(fp_avg_insert, "\n %f", decrease_arr[i]);
				fprintf(fp_avg_delete, "\n %f", decrease_arr[i]);
			}
			

			increase_factor = increase_arr[k];
			printf("Increase factor is: %f", increase_factor);
			ptr = create_Table(&x, cur_size, max_size, increase_factor, decrease_factor);
				// printf("%d, %d, %d\n", increase_factor, x.increase_factor, ptr->increase_factor);
				// printf("%d, %d, %d", decrease_factor, x.decrease_factor, ptr->decrease_factor);


			//Declare an array of function pointers
			int j;
			insert_arr = malloc(sizeof(float) * n);
			delete_arr = malloc(sizeof(float) * n);
			ic = 0;
			dc = 0;
			operation_arr seq_op[n]; 


			//Generate Insert and Delete operations
			generate_op(seq_op, n);

			int randmax = 26;
			int randChar;
			//Execute operations
			for(j=0; j<n; j++){
					randChar = rand() % randmax;
					randChar += 97;
					seq_op[j](randChar, &x);
				}

			//Measure statistics for insert and delete operations:
				//Average and Maximum
				float insert_max = 0;
				float insert_avg_time = 0;
				float insert_sum_time = 0;
				for(j=0; j<ic; j++){
					// printf("inser arr: %f" ,insert_arr[j]);
					if(insert_arr[j] > insert_max){
						insert_max = insert_arr[j];
					}
					insert_sum_time += insert_arr[j];

				}			

				if(ic!=0){
					insert_avg_time = insert_sum_time / ic;
				}
				else 
					insert_avg_time = 0;

				float delete_max = 0;
				float delete_avg_time = 0;
				float delete_sum_time = 0;
				for(j=0; j<dc; j++){
					if(delete_arr[j] > delete_max){
						delete_max = delete_arr[j];
					}
					delete_sum_time += delete_arr[j];
					// printf("delete arr: %f", delete_arr[j]);
				}			

				if(dc!=0){
					delete_avg_time = delete_sum_time / dc;
				}
				else 
					delete_avg_time = 0;
				
				float all_avg_time = 0;
				all_avg_time = (insert_sum_time + delete_sum_time) / n;

				//Print stats to files 
					// printf("\n insert_max: %f", insert_max);
					// printf("\t delete_max: %f", delete_max);
				fprintf(fp_max_insert, "\t %f", insert_max);
				fprintf(fp_max_delete, "\t %f", delete_max);
				fprintf(fp_avg_all, "\t %f", all_avg_time);
				fprintf(fp_avg_insert, "\t %f", insert_avg_time);
				fprintf(fp_avg_delete, "\t %f", delete_avg_time);

		}
	}

				fprintf(fp_max_insert, "\n\n");
				fprintf(fp_max_delete, "\n\n");
				fprintf(fp_avg_all, "\n\n");
				fprintf(fp_avg_insert, "\n\n");
				fprintf(fp_avg_delete, "\n\n");


				fclose(fp_max_insert);
				fclose(fp_max_delete);
				fclose(fp_avg_all);
				fclose(fp_avg_insert);
				fclose(fp_avg_delete);

	


	//Initialize the table
	/*t1.cur_size = 1;
	t1.max_size = 1;*/
	//t1.increase_factor = ;


}



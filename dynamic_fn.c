#include "header.h"

extern float* insert_arr;
extern int ic; 
extern float* delete_arr;
extern int dc;


Table* create_Table(Table* table, long long int cur_size, long long int max_size, double increase_factor, double decrease_factor){
	table->cur_size = cur_size;
	table->max_size = max_size;
	table->increase_factor = increase_factor;
	table->decrease_factor = decrease_factor;
	table->t = (char *) malloc(sizeof(char));
	return table;
}


void generate_op(operation_arr* arr, long long int n){
	int randmax = 2;
	long long int i;
	int op_type;
	int s = 0;
	for(i=0; i<n; i++){
		op_type =  rand() % randmax;
		// printf("%d\t", op_type);
		if(op_type == 0){
			arr[s] = insert;
		}
		else {
			arr[s] = delete_fn;
		}
		s++;
	}
	
}


void generate_op32(operation_arr* arr, long long int n){
	int randmax = 2;
	long long int i;
	int select_type;
	int s = 0;
	for(i=0; i<n; i++){
		select_type =  rand() % 5;
		// printf("%d\t", op_type);
		if((select_type == 0) || (select_type == 1) || (select_type == 2) ){
			arr[s] = insert;
		}
		else {
			arr[s] = delete_fn;
		}
		s++;
	}
	
}

void generate_op42(operation_arr* arr, long long int n){
	int randmax = 2;
	long long int i;
	int select_type;
	int s = 0;
	for(i=0; i<n; i++){
		select_type =  rand() % 6;
		// printf("%d\t", op_type);
		if((select_type == 0) || (select_type == 1) || (select_type == 2) || (select_type == 3) ){
			arr[s] = insert;
		}
		else {
			arr[s] = delete_fn;
		}
		s++;
	}
}




void insert(char ele, Table* table){
	struct timespec start;
	struct timespec end;
	// printf("Insert %c into table of size: %ld. Occupied: %ld\n", ele, table->max_size, table->cur_size);
	clock_gettime(CLOCK_REALTIME, &start);
	// printf("Before, cur_size: %ld and max_size: %ld\n", table->cur_size, table->max_size);

	if(table->cur_size >=  table->max_size){
		increase(table);
	}
	// printf("After, cur_size: %ld and max_size: %ld\n" , table->cur_size, table->max_size);
	table->t[table->cur_size] = ele;
	table->cur_size++;
	
	clock_gettime(CLOCK_REALTIME, &end);
	insert_arr[ic] = time_elapsed(&start, &end);
	ic++;

	return; 

}


void delete_fn(char ele, Table* table){
	struct timespec start;
	struct timespec end;	
	// printf("Delete from table of size: %ld. Occupied: %ld\n", table->max_size, table->cur_size);
	clock_gettime(CLOCK_REALTIME, &start);

	if(table->cur_size > 0){
		table->cur_size--;

		if(table->cur_size < ((table->max_size)*table->decrease_factor)){
			decrease(table);
		}
	}
	else printf("\t Empty table\n");

	clock_gettime(CLOCK_REALTIME, &end);
	delete_arr[dc] = time_elapsed(&start, &end);
	// printf("inserted into delete arr : %f", delete_arr[dc]);
	dc++;

}


void increase(Table* table){

	// printf("Increased from table->max_size %ld", table->max_size);
	// printf("\t %ld * %f = (%f)", table->max_size, table->increase_factor, ceil(table->max_size * table->increase_factor) );
	table->max_size = ceil(table->max_size * table->increase_factor);
	table->t = (char*) realloc(table->t, table->max_size);
	// printf("  to %ld", table->max_size);
}


void decrease(Table* table){	

	// printf("Decreased from table->max_size %ld", table->max_size);
	// printf("\t %ld * %f = (%f)", table->max_size, table->decrease_factor, table->max_size * table->decrease_factor );

	table->max_size = table->max_size * table->decrease_factor;
	if(table->max_size <= 0){
		table->max_size = 1;
	}
	table->t = (char*) realloc(table->t, table->max_size);
	// printf("  to %ld", table->max_size);

}


float time_elapsed(struct timespec *start, struct timespec *end)
{
	float t=0.0;
	t=(end->tv_sec - start->tv_sec) *1000;
	t += ( end->tv_nsec - start->tv_nsec ) * 0.000001;
	// printf("time:%f" , t);
	return(t);
}

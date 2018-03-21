#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct dynamic_table Table;

//Declare table structure
struct dynamic_table {
	char* t;
	long int max_size;
	long int cur_size;
	double increase_factor;
	double decrease_factor;

	//function pointers 
	/*void (*Insertion)(int, Table*);
	int (*Deletion)(Table*);*/

};

//Declare function pointers
typedef void (*operation_arr) (char ,Table* table);


//Declare functions
Table* create_Table(Table* table, long long int cur_size, long long int max_size, double increase_factor, double decrease_factor);
float time_elapsed(struct timespec *start, struct timespec *end);
void insert(char ele, Table* table);
void delete_fn(char ele, Table* table);
void generate_op(operation_arr* arr, long long int n);
void generate_op32(operation_arr* arr, long long int n);
void generate_op42(operation_arr* arr, long long int n);
void increase(Table* table);
void decrease(Table* table);




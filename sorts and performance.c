#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FOO 100

void display(int *p){
	for(int i = 0; i < FOO; i++){
		printf("%d ", p[i] );
	}
	printf("\n");
}

void scramble(int *p){
	int foo;
	int tmp;
	for(int i = 0; i < FOO; i++){
		foo = rand() % FOO;
		tmp = p[i];
		p[i] = p[foo];
		p[foo] = tmp;
	}
}

void select_sort(int*p){
	int tmp;
	for(int i = 0; i < FOO; i++){
		for(int j = 0; j < FOO; j++){
			if(p[i] < p[j]){
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;		
			}
		}
	}
}

void bubble_sort(int *p){
	int tmp, swaps;
	do{
		swaps = 0;
		for(int i = 1; i < FOO; i++){
			if(p[i] > p[i-1]){
				tmp = p[i];
				p[i] = p[i-1];
				p[i-1] = tmp;
				swaps++;
			}
		}
	}while(swaps);
}

int main(){
	//first 100 primes
	int arr[FOO] = {2, 3, 5, 7, 11, 13, 17, 
					19, 23, 29, 31, 37, 41, 
					43, 47, 53, 59, 61, 67, 
					71, 73, 79, 83, 89, 97, 
					101, 103, 107, 109, 113, 
					127, 131, 137, 139, 149, 
					151, 157, 163, 167, 173, 
					179, 181, 191, 193, 197, 
					199, 211, 223, 227, 229, 
					233, 239, 241, 251, 257, 
					263, 269, 271, 277, 281, 
					283, 293, 307, 311, 313, 
					317, 331, 337, 347, 349, 
					353, 359, 367, 373, 379, 
					383, 389, 397, 401, 409, 
					419, 421, 431, 433, 439, 
					443, 449, 457, 461, 463, 
					467, 479, 487, 491, 499, 
					503, 509, 521, 523, 541};
	clock_t clck;


	//select sort
	clck = clock();
	select_sort(arr);
	clck = clock() - clck;
	printf("select sort: %ld clocks, %f seconds\n", clck, ((float)clck/CLOCKS_PER_SEC));
	
	scramble(arr);
	
	//bubble sort
	clck = clock();
	//display(arr);
	bubble_sort(arr);
	clck = clock() - clck;
	printf("bubble sort: %ld clocks, %f seconds\n", clck, ((float)clck/CLOCKS_PER_SEC));
	return (0);
}

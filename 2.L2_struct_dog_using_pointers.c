/*

ID : B171452 
Code By Sandeep Payili on 6/01/2021

*/
/*

Main Points to Remember
				// In General we use . operator to use structure memners but if we use pointers we omit * and . by simply writing -> operatorr.
				//  *(d+i)->age is same as d[i]->age

So the . is used when there is a direct access to a variable in the structure. 
But the -> is used when you are accessing a variable of a structure through a pointer to that structure

			 	struct dog *d;
				d = (struct dog *)malloc(sizeof(struct dog));
				strcpy((*d).bread,"samplebread");
				//strcpy(d->bread,"samplebread2");
				printf(" d->bread   : %s\n",d->bread ); // output : samplebread
				printf(" (*d).bread : %s\n",(*d).bread ); // output : samplebread



*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dog{
 char bread[100];
int age;
float price;
};
int main(){

		// Intro
		
				// In General we use . operator to use structure memners but if we use pointers we omit * and . by simply writing -> operatorr.
				//  *(d+i)->age is same as d[i]->age
			 	struct dog *d;
				d = (struct dog *)malloc(sizeof(struct dog));
				strcpy((*d).bread,"samplebread");
				//strcpy(d->bread,"samplebread2");
				printf(" d->bread   : %s\n",d->bread );
				printf(" (*d).bread : %s\n",(*d).bread );

		// 
				int n;
				printf("\nEnter No. Of Dogs : ");
				scanf(" %d",&n);
				struct dog *dogs;
				dogs = (struct dog *)malloc(n*sizeof(struct dog));
				for (int i = 0; i < n; ++i)
				{
					printf("\n\nEnter Dog %d Bread : (&dogs[i].bread)		",i);
					scanf(" %[^\n]",&dogs[i].bread);
					printf("\nEnter Dog %d Age : (&(dogs+i)->age)			",i);
					scanf(" %d",&(dogs+i)->age); 
					printf("\nEnter Dog %d price : 							",i);
					scanf(" %f",&(dogs+i)->price); // &(dogs+i).price gives error
				}

				printf("\n\n ***********************          Details of Entry			 *****************************\n");
				for (int i = 0; i < n; ++i)
				{
					printf("\nBread : ((dogs+i)->bread) %s 					\n",(dogs+i)->bread);
					printf("Age : (dogs[i].age) %d 							\n",dogs[i].age);
					printf("Price : (*(dogs+i).price) %.2f					\n",(dogs+i)->price); // *(dogs+i).price gives error
				}

	return 0;
}
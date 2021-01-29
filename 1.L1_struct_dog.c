/*

ID : B171452  
 Code By Sandeep Payili on 6/01/2021

*/
#include<stdio.h>
#include<string.h>
struct dog{
 char bread[100];
int age;
float price;
};
int main(){
struct dog d;
strcpy(d.bread, "german shepard");
d.age = 10;
d.price = 2.2;
printf("first dog age is %d\n",d.age);
printf("first dog bread is %s\n",d.bread);
printf("first dog price is %f\n",d.price);
int n;
printf("\n\nEnter No. of Dogs :");
scanf(" %d",&n);
struct dog dogs[n];
/*
char test[100];
strcpy(test,"test string");
gets(test);
puts(test);
printf("\ntest value:%s",test);
*/

for(int i=0;i<n;i++){
	printf("\n\nEnter Dog %d Bread : ",i);
	scanf(" %[^\n]",&dogs[i].bread);
	printf("\nEnter Dog %d Age : ",i);
	scanf(" %d",&dogs[i].age);
	printf("\nEnter Dog %d price : ",i);
	scanf(" %f",&dogs[i].price);
}

printf("\n  Available Dogs  \n");


for(int i=0;i<n;i++){
	printf("\n\nDog %d Bread : %s  ",i,dogs[i].bread);
	printf("\nDog %d Age : %d ",i,dogs[i].age);
	printf("\nDog %d price : %.3f",i,dogs[i].price);
}

printf("\n\nSearch for your Dog  \n" );
		char search_bread[100];
		int search_age;
		float search_price;

		printf("\nEnter Bread for you want to search :\n");
		scanf(" %[^\n]s",search_bread);
		printf("\nEnter Age for you want to search :\n");
		scanf(" %d",&search_age);
		printf("\nEnter price for you want to search :\n");
		scanf(" %f",&search_price);

		int flag = 0;
			for (int i = 0; i < n; ++i)
			{
				if( !strcmp(dogs[i].bread,search_bread) && dogs[i].age == search_age && dogs[i].price == search_price )
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				printf("\n\n Hurray!!! we have you Specified dog!\n");
			}else
			{
				printf("\n\n Aw, Sorry ! we don't have that one!..\n");	
			}
			
return 0;

}
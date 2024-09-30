//C Program to do Binary Search with Space & Time Complexity

#include<stdio.h>

int main(){
int array[50], limit, key, result, i, low, high, mid, space = 0, count = 0; //space = (10 * 4) for array and (9 * 4 = 36) for other declarations
char choice; //1 space
count += 10;
space = 9*sizeof(int)+ 50*sizeof(int); //space = (10 * 4) + (9 * 4 = 36) + 1


//getting array size
printf("Enter array limit: ");
scanf("%d", &limit);
count++;

//getting array elements
printf("Enter sorted array elements:\n");
for(i=0; i<limit; i++){
   
    scanf("%d", &array[i]);
    count++;
}
count = count + 1; //for false iteration of for loop


//getting search key
printf("Enter search key: ");
scanf("%d", &key);
count += 2;

low = 0, high = limit - 1, mid = (low + high) / 2;
count = count + 3; //for low and high, incremented the value of times to 3


while(low <= high){
count ++; //for while loop
   mid = (low + high) / 2;
   count++;

   if(array[mid] == key){
      printf("Element %d is found at position %d", key, (mid + 1));
      count += 2;
      break;
   }

   if(array[mid] < key){
    low = mid + 1;
    count += 2;
   }

   else{
    high = mid - 1;
    count++;
   }

   mid = (low + high) / 2;
   count++;
}

   if(low > high){
     printf("Element %d is not found on the list\n", key);
count += 2;  
}
count += 5;// for running or failing of do while loop
printf("\nTime complexity is  %d\n", count);
printf("Space complexity is  %d\n", space);

}
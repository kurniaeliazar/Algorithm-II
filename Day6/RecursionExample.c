#include <stdio.h>

/* Recursive Version */
int recursive_factorial(int n) 
{
  // return n>=1 ? n * recursive_factorial(n-1) : 1;
  if(n>=1){
    return n * recursive_factorial(n-1); 
  }else{
    return 1;
  }
}

// n = 3
// return 3 * recursive_factorial(3-1)
//            return 2 * recursive_factorial(2-1)
//                       return 1 
   
 /* Iterative Version */
int iter_factorial(int n) 
{
  int f = 1;
  int i;
  for(i = 1; i <= n; i++){
    f *= i; // f = f * i
  }
  
  return f;
}

int main(){
  int bilangan = 3;
  printf("recursion : %d\n", recursive_factorial(bilangan));
  printf("iteration : %d", iter_factorial(bilangan));
}
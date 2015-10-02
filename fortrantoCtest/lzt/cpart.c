#include <stdio.h>

extern struct param {
    int n;
    double arr[30];
} mydata;

extern void ffn_(struct param *);

int main(){
  mydata.n = 12;

  int x;

  ffn_(mydata,&x);
  
  printf("x= %d\n" , x);

  return 0;
}

#include <stdio.h>
#include <string.h>
int main(void)
{ int n, i, j, sum, add;
 char arr[81];
 scanf("%d", &n);
 for(i=0; i<n; i++)
 { sum=0, add=1;
  scanf("%s", arr);
  for(j=0; j<strlen(arr); j++)
  { if(arr[j]=='O')
  { sum+=add;
   add++; }
   else add=1; }
  printf("%d\n", sum); }
 return 0; }

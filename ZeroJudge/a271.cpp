#include <stdio.h>
#include <string.h>

int main(void)
{
 int cnt;
 char data[512] = "";
 
 scanf("%d", &cnt);
 while(cnt--)
 {
  int x, y, z, w, n, m, toxicCnt = 0;
  scanf("%d %d %d %d %d %d", &x, &y, &z, &w, &n, &m);
  //printf("%d %d %d %d %d %d\n", x, y, z, w, n, m);
  getchar();
  gets(data);
  
  int len = strlen(data);
  //printf("Len:%d %s\n", len, data);
  
  for(int i = 0; i < len; i++)
  {
   //printf("toxicCnt = %d\n", toxicCnt);
   if( data[i] == ' ')
    continue;

   m = m - n * toxicCnt;
   //printf("m = %d\n", m);
   if(m <= 0)
   {
    printf("bye~Rabbit\n");
    break;
   }

   switch(data[i])
   {
    case '1':
     m += x;
     break;
    case '2':
     m += y;
     break;
    case '3':
     m -= z;
     break;
    case '4':
     m -= w;
     toxicCnt++;
     break;
   }
   
   //printf("m = %d\n", m);
   if(m <= 0)
   {
    printf("bye~Rabbit\n");
    break;
   }
  }
  
  if( m > 0)
   printf("%dg\n", m);
 }
 
 return 0;
}
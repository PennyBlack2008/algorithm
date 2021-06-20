#include <iostream>

int main(void)
{
   int num = 0;
   scanf("%d", &num);
   int arr[] = { 100001, 10001, 1001, 101, 11, 2 };
   int i, j, k, l, m, n;
   int ans = 0;
   int ret_ans = 0;

   for (int i = 0; i < 10; i++)
   {
       for (int j = 0; j < 10; j++)
       {
           for (int k = 0; k < 10; k++)
           {
               for (int l = 0; l < 10; l++)
               {
                   for (int m = 0; m < 10; m++)
                   {
                       for (int n = 0; n < 10; n++)
                       {
                           ans = arr[0] * i + arr[1] * j + arr[2] * k + arr[3] * l + arr[4] * m + arr[5] * n;
                           if (ans == num)
                           {
                            //    printf("ans is %d\n", ans);
                            //    printf("ans is %d%d%d%d%d%d\n", i, j, k, l, m, n);
                               ret_ans = 100000 * i + 10000 * j + 1000 * k + 100 * l + 10 * m + 1 * n;
                            //    printf("ret_ans is %d\n", ret_ans);
                            printf("%d\n", ret_ans);
                               return (0);
                           }
                       }
                   }
               }
           }
       }
   }
   printf("0");
   return (0);
}
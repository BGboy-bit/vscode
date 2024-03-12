#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int n;
int a[10010];

void heap_adjust(int st, int n) {
    int tmp = a[st];
    for(int i = 2 * st; i <= n; i *= 2) {
        
        //右子树大于左子树
        if(i < n && a[i] < a[i + 1]) i ++ ;
        
        if(a[i] > tmp) {
            a[st] = a[i];
            st = i;
        }
        else break;
    }
    a[st] = tmp;
}

void Print() {
    for(int i = 1; i <= n; i ++ ) {
        printf("%d", a[i]);
        if(i != n) printf(" ");
    }
    printf("\n");
}
 
void heap_sort() {
    for(int i = n / 2; i >= 1; i -- ) heap_adjust(i, n);
    Print();
    for(int i = 0; i < n - 1; i ++ ) {
        
        //swap(a[1], a[n - i])
        int j = a[1];
        a[1] = a[n - i];
        a[n - i] = j;

        heap_adjust(1, n - i - 1);
        
        Print();
   } 
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        heap_sort();
    }
    return 0;
}
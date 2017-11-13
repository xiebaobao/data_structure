#include <stdio.h>
#define MAX_SIZE 10

void print_array(int *array)
{
    int i = 0;
    printf("array: ");
    for( i = 0; i < MAX_SIZE; i++ ) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

/* 直接插入排序是记录分成两个区域，前面是已排序区域，取未排序区域的元素和已排序区域的元素比较
 * 如果小于已排序的值，则将这个值插入到这个值前面（从这到取元素的位置，所有元素后移）
 *
 * 算法的时间复杂度：
 *  最好情况是正序有序，只需要比较n次，不需要移动，所以为O(n)
 *  最坏的情况是逆序有序，这样每个元素都需要比较n次，所以为O（n*n）
 * 空间复杂度：O(1)
 * 这是一个稳定的排序算法
 */
void insert_sort(int *array)
{
    int i, j, temp, temp_index;
    // 遍历无序区
    for (i = 1; i < MAX_SIZE; i++) {
        temp = array[i];
        temp_index = i;
        for (j = 0; j < i; j++) {
            if(array[j] > temp) {
                while (i > j) {
                    array[i] = array[i-1];
                    i--;
                }
                array[j] = temp;
            }
        }
        i = temp_index;
    }
}

/*
 * shell排序
 */
void shell_sort()
{
    
}

/*
 * 如果文件的初始状态是正序，最好时间复杂度为O(n)
 * 如果文件是反序的，最差时间复杂度是O(n*n)，平均时间复杂度是O(n*n)
 *
 */
void bubble_sort(int *a)
{
    int i, j, temp;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = MAX_SIZE; j > i; j--) {
            if (a[j] < a[j - 1]) {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }   
}

/*
 *
 */
int partition(int *a, int l, int h)
{
    int i, j, temp;
    i = l;
    j = h;
    temp = a[i];
    do {
        while (a[j] >= temp && j > i)
            j--;
        if (i < j) 
            a[i++] = a[j];
        while (a[i] <= temp && i < j)
            i++;
        if (i < j)
            a[j--] = a[i];
    } while(i != j);
    a[i] = temp;
    return i;
}
/*
 *快速排序的最坏情况就是，每次划分选的基准都是当前无序区中关键字最小（最大）的记录，划分的结果是基准的左边或者右边
 *的无序子区是空，使用最坏的时间复杂度是O(n*n)
 *平均时间复杂度是O(nlog2n)，是内部排序中最快的
 * 因为快速排序需要一个栈用来递归所以空间复杂度是0（n*log2n）
 */
void quick_sort(int *a, int s1, int t1)
{
    int i;
    if (s1 < t1) {
        i = partition(a, s1, t1);
        quick_sort(a, s1, i-1);
        quick_sort(a, i+1, t1);
    }
}

/*
 *选择排序无论文件的初始状态如何，在第i趟排序中都要做出n-i次的比较，总的比较次数是O(n*n)
 *平均时间复杂度是0（n*n），选择排序是不稳定的 因为会破坏元素的相对位置
 */
void select_sort(int *a)
{
    int i, j, min, temp;
    for (i = 0; i < MAX_SIZE; i++) {
        temp = a[i];
        min = i;
        for (j = i+1; j < MAX_SIZE; j++) {
            if (a[j] < a[min])
                min = j;
        }
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int a[MAX_SIZE] = {8, 10, 2, 4, 16, 80, 20, 17, 50, 25};
    //insert_sort(a);
    //bubble_sort(a);
    //quick_sort(a, 0, MAX_SIZE);
    select_sort(a);
    print_array(a);
    return 0;
}

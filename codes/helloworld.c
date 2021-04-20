#include <stdio.h>
#include <stdlib.h>
#define Elemtype int
#define MAXSIZE 50
#define InitSize 100
// 断点设置 // getchar(); system("pause");
// 顺序表 静态分配
typedef struct{
    Elemtype data[MAXSIZE];
    int length;
} Sqlist;

// 顺序表 动态分配
typedef struct{
    Elemtype *data;
    int MAXSize,length;
} Seqlist;
// 链表
typedef struct listNode
{
    Elemtype data;
    struct listNode *next;
} listNode, *linklist;

void initSq(Sqlist *L){
    L->length = 0;
}

Seqlist init(){
    Seqlist L;
    L.data = (Elemtype *)malloc(sizeof(Elemtype)*InitSize);
    if (!L.data)
    {
        printf("初始化失败");
        exit(0);
    }
    L.length = 0;
    return L;
}

void InsertSeq(Sqlist *L,Elemtype x){

}

void Insert_sqlist(Sqlist *L,int arr[]){
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = arr[i];
        printf("[%d]=%d ",i,L->data[i]);
    }
    printf("length=%d", L->length);
    printf("\n");
}
void printf_sqlist(Sqlist *L){
    for (int j = 0; j < L->length;j++)
    {
        printf("[%d]=%d ",j,L->data[j]);
    }
        printf("length=%d ",L->length);
        printf(" \n");
}
//6.有序顺序表删除重复元素
void del_repeat(Sqlist *L){
    // {1,2,2,2,2,3,3,3,4,4,5};
    int i = 0,j=1,count=0;
    // while(i<L->length){
    //     if(L->data[i] == L->data[i+1]){
    //         count++;
    //     }else{
    //         L->data[i +1- count] = L->data[i+1];
    //     }
    //         i++;
    // }
    // L->length -= count;
    while(j<L->length){
        if(L->data[i] != L->data[j]){
            L->data[++i] = L->data[j];
        }
        j++;
    }
    L->length = i + 1;
}
//7.将两个有序顺序表合并为一个有序顺序表 结果由函数返回
Sqlist merge_Order(Sqlist *L1,Sqlist *L2){
    Sqlist L;
    int i = 0,j=0,k=0;
    while(j<L1->length || k<L2->length){
        int a1 = L1->data[j] ? L1->data[j] : 0;
        int a2 = L2->data[k] ? L2->data[k] : 0;
        if(a1<a2 || a1==a2){
            L.data[i++] = a1;
            j++;
        }else{
            L.data[i++] = a2;
            k++;
        }
    }
    L.length = i;
    return L;
}
//8. A[m+n]存放两个顺序线性表a[m]和b[n] 互换位置 中间节点值易错
void exchange(Sqlist *L, int m, int n){
    for (int i = m; i < (n-m+1)/2+m;i++){  // for (int i = 0; i < (n-m+1)/2;i++){
        int x = L->data[i];                //       int x = l->data[m+i];
        L->data[i] = L->data[n - i + m];   //       l->data[m+i] = l->data[n-i];
        L->data[n - i + m] = x;            //       l->data[n-i] = x;
    }                                      // }
}
// 9.线性表递增有序且顺序存储 最少时间查找x 找到将其与后置元素替换 若找不到则将其插入表中 使表中元素仍然递增有序
void operat_x(Sqlist *L,int x){
    for (int i=0 ; i < L->length;i++){
        if(L->data[i] == x){
            int x = L->data[i + 1];
            L->data[i + 1] = L->data[i];
            L->data[i] = x;
            break;
        }
        if(L->data[i]>x){
            for (int j = L->length - 1; j >= i;j--){
                L->data[j + 1] = L->data[j];
            }
            L->data[i] = x;
            L->length++;
            break;
        }
    }
}
// 9.时间最少 应用折半查找  找中间点时易混淆
void operat_y(Sqlist *L,int x){
    int low = 0, high = L->length - 1, mid;
    while(low<high){
        mid = (high+low) / 2;
        if(L->data[mid] == x)
            break;
       else if(L->data[mid] < x)
           high = mid-1;
       else
           low = mid + 1;
    }
    if(L->data[mid] == x && mid!=L->length-1 && L->data[mid]!=L->data[mid+1]){
        int x = L->data[mid];
        L->data[mid] = L->data[mid + 1];
        L->data[mid + 1] = x;
    }
    if(low>high){
        for (int j = L->length - 1; j > high;j--){
            L->data[j + 1] = L->data[j];
        }
        L->data[high+1] = x;
    }
}
// 10.n个整数放在一维数组 时间空间高效 循环左移P个位置 将R中数据 由（X0,X1,..,Xn-1）转为（Xp,Xp+1,..,Xn-1,X0,..,Xp-1）
// 10.1算法基本思想及时间、空间复杂度
// 将数组ab转为ba (a^-1b^-1)-1 = ba (X0,..,Xp-1,Xp,Xp+1,...,Xn-1)（Xp,Xp+1,..,Xn-1,X0,..,Xp-1) 时间复杂度O(n) 空间复杂度O(1)
// 数组长度为n+p 将a[0] a][p] 复制到 a[n] a[n+p-1]   然后将a[p]至a[n+p-1]向前循环移p位 length = n 时间复杂度O(n) 空间复杂度O(P)
// 10.2算法实现 关于数组下标取中间点问题
void reverse(Sqlist *L,int start,int end){
    for (int i = start; i < (start-end) / 2;i++){
        L->data[start] = L->data[end - start+(start + end) / 2];
    }
}
// 11.长度为L的升序序列S 处在L/2的位置为中位数 找出两个等长升序序列A B的中位数  空间时间高效
// S1{11,13,16,17,18} S2{10,11,19,20,20} 算法复杂度log2n
int asc_Median(Sqlist *L1,Sqlist *L2){
    int i = 0, j = 0;
    while(i<L1->length && j<L2->length){
        if(L1->data[i] > L2->data[j]){
            j++;
        }else{
            i++;
        }
        if(i+j+2 == L1->length){
            if(L1->data[i] > L2->data[j]){
                return L2->data[j + 1] < L1->data[i] ? L2->data[j + 1] : L1->data[i];
            }else{
                return L1->data[i + 1] < L2->data[j] ? L1->data[i + 1] : L2->data[j];
            }
        }
        if(i+j+2>L1->length){
            if(L1->data[i] > L2->data[j]){
                return L2->data[j + 1] < L1->data[i] ? L2->data[j + 1] : L2->data[j];
            }else{
                return L1->data[i + 1] < L2->data[j] ? L1->data[i + 1] : L1->data[i];
            }
        }
    }
}
int binary_Median(Sqlist *L1,Sqlist *L2){
    int s1 = 0, d1 = L1->length - 1, m1 = 0, s2 = 0, d2 = L2->length - 1, m2 = 0;
    while(s1 != d1 || s2 != d2){
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if(L1->data[m1] == L2->data[m2])
            return L1->data[m1];
        if(L1->data[m1] < L2->data[m2]){
            if((s1+d1)%2==0){  //元素个数为奇数
                s1 = m1;  //舍弃L1中间点以前并保留中间点
                d2 = m2; //舍弃L2以后且保留中间点
            }else{
                s1 = m1 + 1; //舍弃L1以前不保留中间点
                d2 = m2; //舍弃L2以后且保留中间点
            }
        }else{
            if((s2+d2)%2==0){
                d1 = m1; //舍弃L1中间点以后并保留中间点
                s2 = m2; //舍弃L2中间点以前且保留中间点
            }else{
                d1 = m1;  //舍弃L1中间点以后并保留中间点
                s2 = m2+1; //舍弃L2中间点以前及中间点
            }
        }
    }
    return L1->data[s1] < L2->data[s2] ? L1->data[s1] : L2->data[s2];
}
int main()
{
    Sqlist L1;
    Sqlist L2;
    int arr1[] = {11,13,15,17,18};
    int arr2[] = {10,11,14,20,20};
    L1.length = sizeof(arr1) / sizeof(arr1[0]);
    L2.length = sizeof(arr2) / sizeof(arr2[0]);
    Insert_sqlist(&L1, arr1);
    Insert_sqlist(&L2, arr2);
    // del_repeat(&L1); //删除重复
    // printf_sqlist(&L1);
    // Sqlist result = merge_Order(&L1, &L2); //两个有序顺序表合并
    // printf_sqlist(&result);
    // exchange(&L1, 0, 4);
    // exchange(&L1, 5, L1.length-1);
    // exchange(&L1, 0, L1.length-1); //A[m+n]交换位置
    // printf_sqlist(&L1);
    // operat_x(&L1, 10);
    // printf_sqlist(&L1);
    // int a = asc_Median(&L1, &L2);
    int a = binary_Median(&L1, &L2);
    printf("%d", a);
}

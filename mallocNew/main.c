// #include "mymalloc.h"
#include "mymalloc.c"

// int main()
// {
//     InsertNodeEnd(0, 0, SIZE - 1);
//     printf("%p\n" ,MyMalloc(100));
//     printf("%p\n" ,MyMalloc(10));
//     printf("%p\n" ,MyMalloc(50));
//     printf("%p\n" ,MyMalloc(200));
    
//     MyMalloc(10);
//     MyMalloc(50);
//     MyMalloc(200);
//     // MyMalloc(5);
//     // MyFree(100);
//     // MyFree(160);
//     MyFree(160);
//     // MyMalloc(300);
//     PrintLL();
//     return 0;
// }


int main()
{
    // InsertNodeEnd(0, 0, SIZE - 1);
    // printf("%p\n" ,MyMalloc(100));
    // printf("%p\n" ,MyMalloc(10));
    // printf("%p\n" ,MyMalloc(50));
    // printf("%p\n" ,MyMalloc(200));

    int *p = (int*) MyMalloc(10);
    int *q = (int*)MyMalloc(50);
    int *r = (int*)MyMalloc(200);
    // MyMalloc(5);
    // MyFree(10);


    // MyFree(p);
    MyFree(q);
    // MyFree(r);
    // MyMalloc(300);
    PrintList();

    // printf("%c", memory[0]);
    //printf("%p\n", p);
//    printf("%p\n", );
    // printf("%p\n", &memory[3]);
    // printf("%p\n", &memory[4]);
    // printf("%p\n", &memory[5]);
    // printf("%p\n", &memory[6]);
    // printf("%p\n", &memory[SIZE]);
    // printf("%s\n", &memory[24500]);

    // CreateStart();
    
    // char *p = memory;
    // node *v = NgvfdsaewNode(1, 309, 400);
    // printf("%p\n", *(&memory[24500]));
    // printf("%p\n", &memory[24532]);
    // printf("%d\n", memory[24520]);
    // printf("%s\n", memory[24564]);
    // printf("%s\n", memory[24565]);
    // memory[24508] = 4;
    // printf("%c\n", (p));
    // PrintLL();

    return 0;
}

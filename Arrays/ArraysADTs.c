#include<stdio.h>
#include<stdlib.h>

struct MyArray{
    int total_size;
    int used_size;
    int *ptr;

};

void creatarray(struct MyArray *a,int tsize, int usize){
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(tsize * sizeof(int));
}

void setval(struct MyArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++){
        printf("Enter the element %d : ",i);
        scanf("%d",&n);
        a->ptr[i] = n;
    }
}

void show(struct MyArray *a){
    for (int i = 0; i < a->used_size; i++){
        printf("%d\n",(a->ptr)[i]);
    }
    
}

int main() {
    struct MyArray marks;
    creatarray(&marks,10,3);
    setval(&marks);
    show(&marks);
    return 0;
}
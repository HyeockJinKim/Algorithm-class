#include <stdio.h>
#include <malloc.h>
#include <mem.h>

struct _student{
    struct _student * prev;
    struct _student * next;
    char studentId[10];
    int point;
};
typedef struct _student* pStudent;

void sortGrade(char * ); // No need to write, but just wondering
void sortPoint(char * ); // No need to write, but just wondering
void test1();
void test2();
void test3();
void test_10();
void test_100();
void test_1000();
void test_10000();


int main(){

// This is for  test1, test2, test3
    test1();

    test2();

    test3();

// This is for  test_10, test_100, test_1000, test_10000.
    test_10();

    test_100();

    test_1000();

    test_10000();

    return 0;
}

void sortGrade(char * fileName) {
    FILE * file;
    if ( (file = fopen(fileName, "r")) == NULL ) {
        printf("can't read %s file! ", fileName);
        return ;
    }
    printf("%s : \n\n", fileName);

    int number;
    char tempStudentId[10];

    pStudent first;
    first = (pStudent)malloc(sizeof(struct _student));

    fscanf(file,"%s %d\n", tempStudentId, &number);
    first->point = number;
    first->next = first;
    first->prev = first;
    strcpy(first->studentId, tempStudentId);

    while (fscanf(file,"%s %d\n", tempStudentId, &number) != -1) {
        pStudent temp;
        pStudent temp2;
        temp = (pStudent)malloc(sizeof(struct _student));

        strcpy(temp->studentId, tempStudentId);
        temp->point = number;
        temp2 = first;

        if (number <= first->point) {
            temp->prev = first->prev;
            temp->next = first;
            temp->prev->next = temp;
            temp->next->prev = temp;
            first = temp;
        }
        /*else if (first->prev->point <= number){
            temp->prev = first->prev;
            temp->next = first;
            temp->prev->next = temp;
            temp->next->prev = temp;
        }*/
        else {
            while (temp2->next->point <= number && temp2->next != first) {
                temp2 = temp2->next;
            }
            temp->prev =temp2;
            temp->next = temp2->next;
            temp->prev->next = temp;
            temp->next->prev = temp;
        }
    }


    fclose(file);

    pStudent order = first;
    printf("StudentID : %s , Grade : %2d\n", order->studentId, order->point);
    order = order->next;
    while (order != first) {
        // Check the results.
        printf("StudentID : %s , Grade : %2d\n", order->studentId, order->point);
        order = order->next;
    }

    while (first ->next != first) {
        // Variable is created with malloc must be free.
        pStudent temp = first->prev;
        first->prev->prev->next = first;
        first->prev = first->prev->prev;
        free(temp);
    }
    free(first);

    printf("\n\n");
}

void sortPoint(char * fileName) {
    FILE * file;
    if ( (file = fopen(fileName, "r")) == NULL ) {
        printf("can't read %s file! ", fileName);
        return ;
    }
    printf("%s : \n\n", fileName);

    int number;
    pStudent first;
    first = (pStudent)malloc(sizeof(struct _student));

    fscanf(file,"%d\n", &number);
    first->point = number;
    first->next = first;
    first->prev = first;
//    strcpy(first->studentId,"201502043");  // 201502043 is my Student ID

    while (fscanf(file,"%d\n", &number) != -1) {
        pStudent temp;
        pStudent temp2;
        temp = (pStudent)malloc(sizeof(struct _student));

        temp->point = number;
        temp2 = first;

        if (number <= first->point) {
            temp->prev = first->prev;
            temp->next = first;
            temp->prev->next = temp;
            temp->next->prev = temp;
            first = temp;
        }
/*        else if (first->prev->point <= number){
            temp->prev = first->prev;
            temp->next = first;
            temp->prev->next = temp;
            temp->next->prev = temp;
        }*/
        else {
            while (temp2->next->point <= number && temp2->next != first) {
                temp2 = temp2->next;
            }
            temp->prev =temp2;
            temp->next = temp2->next;
            temp->prev->next = temp;
            temp->next->prev = temp;
        }


    }
    fclose(file);

    pStudent order = first;
    printf("%d\n", order->point);
    order = order->next;
    while (order != first) {
        // Check the results.
        printf("%d\n", order->point);
        order = order->next;
    }


    while (first ->next != first) {
        // Variable is created with malloc must be free.
        pStudent temp = first->prev;
        first->prev->prev->next = first;
        first->prev = first->prev->prev;
        free(temp);
    }
    free(first);
    printf("\n\n");

}

void test1() {
    char fileName[20] = "test1.txt";
    sortGrade(fileName);
}

void test2() {
    char fileName[20] = "test2.txt";
    sortGrade(fileName);
}

void test3() {
    char fileName[20] = "test3.txt";
    sortGrade(fileName);
}



void test_10() {
    char fileName[20] = "test_10.txt";
    sortPoint(fileName);
}

void test_100() {
    char fileName[20] = "test_100.txt";
    sortPoint(fileName);
}

void test_1000() {
    char fileName[20] = "test_1000.txt";
    sortPoint(fileName);
}

void test_10000() {
    char fileName[20] = "test_10000.txt";
    sortPoint(fileName);
}



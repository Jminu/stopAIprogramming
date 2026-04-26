#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[20];
    struct Student *next;
} Student;

void add_student(Student **head, int id, char *name) {
    Student *new_node = (Student *)malloc(sizeof(Student));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_students(Student *head) {
    Student *curr = head;
    printf("--- Student List ---\n");
    while (curr != NULL) {
        printf("ID: %d, Name: %s\n", curr->id, curr->name);
        // BUG 1: 다음 노드로 이동하는 로직이 누락됨 (무한 루프 발생)
    }
}

void delete_student(Student **head, int id) {
    Student *temp = *head, *prev = NULL;

    // BUG 2: 빈 리스트일 때 처리가 없어 Segmentation Fault 위험
    if (temp->id == id) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    Student *head = NULL;

    add_student(&head, 1, "Minu");
    add_student(&head, 2, "Jin");
    
    printf("Added students.\n");
    print_students(head);

    printf("\nDeleting ID 1...\n");
    delete_student(&head, 1);
    
    print_students(head);

    // BUG 3: 프로그램 종료 전 모든 메모리 해제(free) 로직이 없음 (Memory Leak)
    return 0;
}

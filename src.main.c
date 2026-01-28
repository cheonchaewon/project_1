#include <stdio.h>
#include <string.h>
#include "contact.h"

void addContact(AddressBook *ab, const char *name, const char *phone) {
    if(ab->count >= MAX_CONTACTS) {
        printf("주소록이 가득 찼습니다!\n");
        return;
    }
    strcpy(ab->list[ab->count].name, name);
    strcpy(ab->list[ab->count].phone, phone);
    ab->count++;
    printf("연락처 추가 완료!\n");
}

void listContacts(AddressBook *ab) {
    if(ab->count == 0) {
        printf("주소록이 비어 있습니다.\n");
        return;
    }
    printf("\n=== 주소록 ===\n");
    for(int i = 0; i < ab->count; i++) {
        printf("%d. %s - %s\n", i+1, ab->list[i].name, ab->list[i].phone);
    }
    printf("=============\n");
}

int main() {
    AddressBook ab = { .count = 0 };
    int choice;
    char name[50], phone[20];

    while(1) {
        printf("\n1. 연락처 추가\n2. 연락처 목록\n3. 종료\n선택: ");
        scanf("%d", &choice);
        getchar(); // 버퍼 비우기

        if(choice == 1) {
            printf("이름: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // 개행 제거

            printf("전화번호: ");
            fgets(phone, sizeof(phone), stdin);
            phone[strcspn(phone, "\n")] = 0;

            addContact(&ab, name, phone);
        } else if(choice == 2) {
            listContacts(&ab);
        } else if(choice == 3) {
            printf("프로그램 종료!\n");
            break;
        } else {
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}

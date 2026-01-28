#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

typedef struct {
    Contact list[MAX_CONTACTS];
    int count;
} AddressBook;

void addContact(AddressBook *ab, const char *name, const char *phone);
void listContacts(AddressBook *ab);

#endif

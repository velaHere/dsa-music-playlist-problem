#include <iostream>
using namespace std;

struct Music *current = NULL;
struct Music *first = NULL;
struct Music *last = NULL;
int count = 0;

struct Music {
    struct Music *previous;
    struct Music *next;
    string data;
};

void add(string data) {

    struct Music *music = new Music;
    music->previous = NULL;
    music->next = NULL;
    music->data = data;


    if(count == 0) {

        music->next = music;
        music->previous = music;

        first = music;
        last = music;
        count = 1;
        return;
    }

    last->next = music;
    music->previous = last;
    music->next = first;
    first->previous = music;

    last = music;

    count++;
}

void addAt(string data, int index) {

    if(index < 0 || index > count) {
        return;
    }

    if(index == count) {
        add(data);
        return;
    }

    Music *newMusic = new Music;
    newMusic->data = data;

    if(count == 0) {
        newMusic->next = newMusic;
        newMusic->previous = newMusic;

        first = newMusic;
        last = newMusic;
        count = 1;
        return;
    }

    Music *current = first;

    for(int i = 0; i < index; i++) {
        current = current->next;
    }

    newMusic->next = current;
    newMusic->previous = current->previous;

    current->previous->next = newMusic;
    current->previous = newMusic;

    if(index == 0) {
        first = newMusic;
    }

    count++;
}

void printAll() {
    if(count == 0) {
        cout<<"Empty"<<endl;
        return;
    }

    int counter = 0;
    struct Music *current = first;

    while(counter<count) {

        if(current == NULL) {
            return;
        }

        cout<<current->data<<endl;
        current = current->next;
        counter++;
    }
}

int main() {

    add("test1");
    addAt("test2", 0);
    addAt("test3", 1);
    add("test4");

    // cout<<first->data<<endl;
    // cout<<first->next->data<<endl;
    // cout<<first->previous->data<<endl;

    printAll();

    cout<<current->data<<endl;
    return 0;
}

// 1. Add

// 2. Next

// 3. Previous

// 4. Exit

// 5. Reposition
//ds,mn,dsgnkldgkv nb zkj/oasfmsanmdk;bdb
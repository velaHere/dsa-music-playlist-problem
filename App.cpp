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

    cout<<endl<<endl<<"Output: ";

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

void remove(int index) {

    if(index < 0 || index >= count) {
        return;
    }

    if(count == 0) {
        return;
    }

    if(count == 1) {
        first = NULL;
        last = NULL;
        count=0;
        return;
    }

    struct Music *musicAtIndex = first;

    for(int i = 1; i <= index; i++) {
        musicAtIndex = musicAtIndex->next;
    }

    musicAtIndex->previous->next = musicAtIndex->next;
    musicAtIndex->next->previous = musicAtIndex->previous;

    if(index == count-1) {
        last = last->previous;
    } else if(index == 0) {
        first = first->next;
    }

    count--;
}

void reposition(int indexFrom, int indexTo) {
 
    if(indexFrom < 0 || indexFrom >= count) {
        return;
    }

    if(indexTo < 0 || indexTo >= count) {
        return;
    }

    if(count == 0 || count == 1) {
        return;
    }

    struct Music *musicAtIndexFrom = first;

    for(int i = 1; i <= indexFrom; i++) {
        musicAtIndexFrom = musicAtIndexFrom->next;
    }

    string data = musicAtIndexFrom->data;

    remove(indexFrom);

    addAt(data, indexTo);
}

void swap(int indexFrom, int indexTo) {

    if(indexFrom < 0 || indexFrom >= count) {
        return;
    }

    if(indexTo < 0 || indexTo >= count) {
        return;
    }

    if(count == 0 || count == 1) {
        return;
    }

    struct Music *musicAtIndexTo = first;

    for(int i = 1; i <= indexTo; i++) {
        musicAtIndexTo = musicAtIndexTo->next;
    }

    struct Music *musicAtIndexFrom = first;

    for(int i = 1; i <= indexFrom; i++) {
        musicAtIndexTo = musicAtIndexTo->next;
    }

    string temp = musicAtIndexFrom->data;
    musicAtIndexFrom->data = musicAtIndexTo->data;
    musicAtIndexTo->data = temp;
}

void printContent() {
    cout<<endl;
    cout<<endl;

    cout<<"1. Add data"<<endl;
    cout<<"2. Add data at some index"<<endl;    
    cout<<"3. Remove Data from some index"<<endl;    
    cout<<"4. Swap 2 Nodes"<<endl;    
    cout<<"5. Reposition a Node"<<endl;    
    cout<<"6. Print all Data"<<endl;    

    cout<<endl;
    cout<<endl;
}

void performAddData(int choice) {

    string data;

    cout<<"Enter the data: ";
    cin>>data;

    if(choice == 1) {
        add(data);
    } else if(choice == 2) {
        int index;
        cout<<endl<<"Enter index: ";
        cin>>index;
        addAt(data, index);
    }
}

void performRemoveData() {

    int index;
    cout<<"Enter index: ";
    cin>>index;

    remove(index);
}

void performSwapOrReposition(int choice) {

    int index1, index2;
    cout<<"Enter Index 1: ";
    cin>>index1;
    cout<<endl<<"Enter Index 2";
    cin>>index2;

    if(choice == 4) {
        swap(index1, index2);
    } else {
        reposition(index1, index2);
    }

}


int main() {

    while (true)
    {
        printContent();
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            performAddData(choice);
            break;

        case 2:
            performAddData(choice);
            break;

        case 3:
            performRemoveData();
            break;

        case 4:
            performSwapOrReposition(choice);
            break;

        case 5:
            performSwapOrReposition(choice);
            break;

        case 6:
            printAll();
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}
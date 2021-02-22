#include <iostream>
using namespace std;

class Chunk {
public: 
    int x;
    Chunk *next;

    Chunk(){
        x=0;
        next = NULL;
    } 
};

class Stack {
public:
    Chunk *top; // this is our topmost chunk
           
    Stack(){
        top = NULL;
    }

    void push(int value){
        if(top == NULL){    // the structure is empty
            top = new Chunk; // creating a topmost chunk
            top->x = value; // assigning that topmost chunk with our x value
        }
        else{ // in a Stack, elements can only be added to the front(LIFO)
            Chunk *temp;
            temp = new Chunk; // temp chunk to be inserted
            temp->x = value;  // assigning temp our wanted value
            temp->next = top; // assinging temp to be the element before the 2nd element
            top = temp; // pointing top's previous pointer to temp
        }
    }
    void pop(){ // deleting the first element
        if(top == NULL){
            cout << "Nothing to Delete" << endl;
            return;
        }
        else{
            Chunk *temp; // placeholder
            temp = top; // temp now points at what top was pointing at 
            top = top ->next; // top now points at the pos 2 skips away
            delete temp; // first element gets deleted

        }

    }
    void display(){
        if (top == NULL){
            cout << "Nothing to Display " << endl;
        }
        else{ //display all chunks in the structure
            Chunk *temp = top;
            while(temp != NULL){
                cout << temp->x << "-->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    Stack myStack;
    int choice = 0;
    int value;
    while(true){
        cout << " Press 1 to add" << endl;
        cout << " Press 2 to delete" << endl;
        cout << " Press 3 to display" << endl;
        cin >> choice;

        switch(choice){
            case(1):
                cout << "Enter the value you wanna insert" << endl;
                cin >> value;
                myStack.push(value);
                break;
            case(2):
                myStack.pop();
                break;
            case(3):
                myStack.display();
                break;
        }
    }

    return 0;
}
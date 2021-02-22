#include <iostream>
using namespace std;


class Chunk{
public:
    int value;
    Chunk* next;

    Chunk(): value(0), next(NULL){}

};


class LinkedList{
public:

    Chunk* head;
    int length;

    LinkedList(){

    head = NULL;
    length = 0;


    }

    //Function to Add
    void insertAtPos(int x, int pos){
        if (pos > 0 && pos <= this->length + 1){
            //Able to add a valid chunk
            Chunk *temp = new Chunk;
            temp->value = x;

            //If adding to the front
            if (pos == 1){
                temp->next = this->head;
                head = temp;
            }
            //If adding to the end
            else if (pos == this->length + 1){
                Chunk *helper = this->head;
                for(int i = 1; i < length; i++){
                    helper = helper->next;
                } 
                    helper->next = temp;
            }
            //If adding to the middle
            else {
                Chunk *helper = head;
                for(int i = 1; i < pos - 1; i++){
                    helper = helper->next;
                }
                temp->next = helper->next;
                helper->next = temp;
            }
            
            this->length++;
        }   
        else {
            cout << "Invalid Position. Cannot Add Object." << endl;
        }

    }
    //Function to Delete
    void removeFromPos(int pos){
        //Is position valid?
        if(pos > 0 && pos <= this->length){
            Chunk *helper = this->head;
            //If removing from beginning
            if (pos == 1){
                this->head = this->head->next;
                delete helper;
            }
            //If removing from end
            if (pos == this->length){
                for(int i = 1; i < length - 1; i++){
                    helper = helper->next;
                }
                delete helper->next;
                helper->next = NULL;
            }
            //If removing from middle
            else {
                Chunk *deleteptr = head;
                for (int i = 1; i < pos; i++){
                    helper = deleteptr;
                    deleteptr = deleteptr->next;
                }
                helper->next = helper->next->next;
                delete deleteptr;
            }
        }
        else {
            cout << "Invalid Position, Cannot Delete Object." << endl;
        }
    }
    void display(){
        if (head == NULL){
            cout << "Empty Queue" << endl;
        }
        else{
            Chunk *helper = head;
            while(helper != NULL){
                cout << "[" << helper->value << "]";
                helper = helper->next;
            }
                cout << endl;
        }

    }


};



int main(){

    LinkedList L;
    int x, pos, choice;

    while(true){
        cout << "Do you want to add(1), delete(2) or view(3)" << endl;
        cin >> choice;

        switch(choice){
            case(1):
                cout << "add what" << endl;
                cin >> x;
                cout << "and where?" <<endl;
                cin >> pos;
                L.insertAtPos(x,pos);
                break;
            case(2):
                cout << "what position>" << endl;
                cin >> pos;
                L.removeFromPos(pos);
                break;
            case(3):
                L.display();
                break;


        }

    }
    return 1;
}
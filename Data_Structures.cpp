#include <iostream>
using namespace std;

template<class T>

//Queue class using a linked list implementation.
class Queue{
    private:

    //Setting up the node class used in the queue.
    class Node{
        public:
        T v;
        Node* n ;

        Node(const T& value) : v(value), n(nullptr){};
    };

    Node* head;
    Node* tail;
    int size;

    public:
    Queue() : head(nullptr), tail(nullptr), size(0){}

    bool isEmpty() const {return size == 0;}
    int getsize() const{ return size;}
     
    //Inserts elements into the queue and increments the size afterwards.
    void push(T elem){
        Node* node = new Node(elem);
        
        //If the queue is empty the head, tail and first node of the queue are set to each other.
        if(isEmpty()){head = tail = node;} 
        
        //After an increment tail gets set to the last node in the queue.
        else {
            tail -> n = node;
            tail = node;
        }
        size++;
    }

    //Removes and deletes the first elements of the queue and decrements the size of the queue.
    T pop(){

        //Checking if the queue is empty. If it is empty return the default value of whatever type is used.
        if(isEmpty()){cout << "Queue is empty." << endl; return T();}
        
        Node* temp = head;

        T tempval = head -> v;
        head = head -> n;

        //Once the head is pointing to nothing the end of the queue is reached and the tail is also set to nullptr.
        if(head == nullptr){tail = nullptr;}

        delete temp;
        size--;
        return tempval;
    }

    //Destructor
    ~Queue() {
        while (head != nullptr) {      
            Node* temp = head;         
            head = head->n;            
            delete temp;               
        }
        tail = nullptr;               
        size = 0;
    }
};


//Quack using the same structure as the queue. The four functions are included.
template<class A>
class Quack{
    private:

    class Node{
        public:
        A v;
        Node* n ;

        Node(const A& value) : v(value), n(nullptr){};
    };

    Node* head;
    Node* tail;
    int size;

    public:
    Quack() : head(nullptr), tail(nullptr), size(0){}

    bool isEmpty() const {return size == 0;}
    int getsize() const{ return size;}

    //This inserts an element to the front of the quack and adds 1 to size.
    void push_front(A elem){
        Node* node = new Node(elem);

        if(isEmpty()){
            head = node;
            tail = node;
        }else{
            node -> n = head;
            head = node;
        }
        size ++;
    }

    //Inserts elements to the back of the quack.
    void push_back(A elem){
        Node* node = new Node(elem);
         
        if(isEmpty()){
            head = node;
            tail = node;
        }else{
            tail -> n = node;
            tail = node;
        }
        size++;
    }

    //Removes and deletes the first element.
    A pop_front(){
        if(isEmpty()){cout << "Quack is empty." << endl; return A();}
        
        Node* temp = head;

        A tempval = head -> v;
        head = head -> n;

        if(head == nullptr){tail = nullptr;}

        delete temp;
        size--;
        return tempval;
    }


    //This has a different structure from the other pop functions.
    A pop_back(){
        //First needs to check if the quack is empty
        if(isEmpty()){cout << "Quack is empty." << endl; return A();}

        //If the size of the quack is 1.
        if(size == 1){
            //Storing the value tail points to in variable. Then deletes tail and sets both tail and head to nullptr. Then decrements the quack to 0.
            A tempval = tail->v;
            delete tail;
            head = nullptr;
            tail = nullptr;
            size--;
            return tempval;

        }else{
            //Creates a new head used to loop all the way back to the second last element in the quack.
            Node* temp = head;

            //Once the new head gets there it is set to the pointer that points to the second last node.
            while(temp->n != tail){temp = temp->n;}

            //Creates temporary values for the last node and then deletes last node.
            A tempval = tail->v;
            delete tail;
            tail = temp;

            tail->n = nullptr;
            size--;
            return tempval;
        }
    }

    //Destructor.
    ~Quack() {
        while (head != nullptr) {      
            Node* temp = head;        
            head = head->n;            
            delete temp;               
            tail = nullptr;               
            size = 0;
        }
    }   
};

int main(){

    //Queue test 1.
    {
        Queue<int> q1;
        cout << q1.isEmpty() << endl;

        q1.push(1);
        q1.push(2);
        q1.push(3);
        q1.push(4);
        q1.push(5);

        cout << q1.isEmpty() << endl;
        q1.getsize();

        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << q1.pop() << endl;

       
    }

    //Queue test 2.
    {
        Queue<char> q1;
        cout << "\n\n";

        cout << q1.isEmpty() << endl;

        q1.push('a');
        q1.push('s');
        q1.push('d');
        q1.push('f');
        q1.push('g');

        cout << q1.isEmpty() << endl;
        q1.getsize();

        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << q1.pop() << endl;
        cout << "\n\n";

        
    }

    //Quack test 1.
    {
        Quack<int> q;
        q.push_back(1);
        q.push_back(2);
        q.push_back(3);

        cout << q.pop_back() << endl;   
        cout << q.pop_back() << endl;   
        cout << q.pop_back() << endl;   
        cout << q.pop_back() << endl;  
        cout << "\n\n";
    }

    //Quack test 2.
    {
        Quack<int> q;
        q.push_back(1);   
        q.push_front(5);    
        q.push_back(87);    

        cout << q.pop_front() << endl;  
        cout << q.pop_back() << endl;  
        cout << q.pop_front() << endl;  
    }
    return 0;
 
}
#include <iostream>

template <typename T1, typename T2>
class myPair{
    private:
    T1 key;
    T2 value;

    public:

    //Default Constructor
    myPair(){
        key = 0;
        value = 0;
    }

    //Overloaded Constructor
    myPair(T1 a, T2 b){
        key = a;
        value = b;
    }

    //Copy Constructor
    myPair(myPair &pr){
        pr.key = key;
        pr.value = value;
    }

    //Member Functions

    //Assignment Operator
    void operator =(myPair& pr){
        pr.key = key;
        pr.value = value;
        //return *this;
    }

    void swap(myPair &pr){
        key = pr.key;
        value = pr.value;
    }

    void operator ==(myPair &pr){
        bool isEqual = false;
        if(pr.key == key)
        {
            if(pr.value == value)
            {
                isEqual = true;
            }
        }
        else if (pr.value == value)
        {
            if(pr.key == key)
            {
                isEqual = true;
                
            }
        }
        else
        {
            isEqual = false;
        }
        
        if(isEqual)
        {
            std::cout << "Equal\n";
        }
        else
        {
            std::cout << "Not Equal\n";
        }
    }
    void print(){
        std::cout << key << std::endl;
        std::cout << value << std:: endl;
    } 
};

int main(){
    myPair <int, float> P(2, 5.5);
    myPair <int, float> P1(2,5.5);
    myPair <int, float> P3;
    //P.print();
    //P = P1;
    //P1.print();
    //P1.swap(P);
    //P1.print();
    P == P1;
}
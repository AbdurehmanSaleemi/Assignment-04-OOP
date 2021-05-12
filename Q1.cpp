#include <iostream>

template <typename T1, typename T2>
class myPair{
    private:
    T1 key;
    T2 value;

    public:
    static int objCount;

    //Default Constructor
    myPair(){
        key = 0;
        value = 0;
        objCount++;
    }

    //Overloaded Constructor
    myPair(T1 a, T2 b){
        key = a;
        value = b;
        objCount++;
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

template<typename T1, typename T2>
int myPair<T1, T2>::objCount = 0;

template <typename T1, typename T2>
class myMap{

    private:
    int size;
    const int MAX_SIZE = 1000;
    myPair<T1, T2> *container;

    // object passed is _map
    public:
    myMap(){
        size = 0;
        container = nullptr;
    }

    myMap(myMap &_map){
        size = _map.size;
        container = _map.container;
    }

    ~myMap(){
        if (container != nullptr)
        {
            delete [] container;
            container = nullptr;
        }
    }

    void setSize(){
        size = myPair<T1,T2>::objCount;
    }

    void insert(myPair<T1,T2> pr, int index){
        container = new myPair<T1,T2>[size];
        pr = container[index];
    }

    void operator ==(myMap &_map){
        size = _map.size;
        container = new myPair<T1, T2>[size];

        for (int i = 0; i < size; i++)
        {
            container[i] = _map.container[i];
        }
    }

    int isEmpty(myMap &_map){
        if(_map.size == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
        return 0;
    }

    int getSize(){
        return size;
    }

    void print(){
        for (int i = 0; i < size; i++)
        {
            std::cout << container[i] << std::endl;
        }
    }
};

int main(){
    myPair <int, float> P(2, 5.5);
    myPair <int, float> P1(2,5.5);
    myPair <int, float> P3;
    myMap <int, float> M1;
    M1.setSize();
    M1.insert(P,0);
    std::cout << M1.getSize() << std::endl;
    std::cout << M1.isEmpty(M1) << std::endl;
    //M1.print();
    //P.print();
    //P = P1;
    //P1.print();
    //P1.swap(P);
    //P1.print();
    P == P1;
}
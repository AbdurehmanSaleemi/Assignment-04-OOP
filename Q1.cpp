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
    void setKey(T1 k){
        key = k;
    }

    void setValue(T2 v){
        value = v;
    }

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
    int getValue() const {
        return value;
    }
    
    int getKey() const{
        return key;
    }
};

template<typename T1, typename T2>
int myPair<T1, T2>::objCount = 0;

template <typename T1, typename T2>
class myMap{

    private:
    int size;
    const int MAX_SIZE = 1000;
    myPair<T1, T2> *container; //Container is object of myPair Class

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

    void setSize(){
        size = myPair<T1,T2>::objCount;
    }

    void insert(myPair<T1,T2> &pr, int index){

        bool keyCheck = true;
        container = new myPair<T1,T2>[size];
        increaseSize(size);

        for (int i = 0; i < getSize() || keyCheck == true; i++){
            if(pr.getKey() == container[i].myPair<T1,T2>::getKey()){
                keyCheck = false;
            }
        }
        if(keyCheck == false){
            container[index].myPair<T1,T2>::setKey(pr.getKey());
            container[index].myPair<T1,T2>::setValue(pr.getValue());
        }
        else{
            std::cout << "Key Already Exists" << std::endl;
        }
    }

    void operator =(myMap<T1,T2> &_map){
        size = _map.size;
        container = new myPair<T1, T2>[_map.size];

        for (int i = 0; i < size; i++)
        {
            container[i] = _map.container[i];
        }
    }

    int isEmpty(myMap &_map){
        if(_map.size == 0){
            return 1;
        }
        else{
            return -1;
        }
        return 0;
    }

    int getSize(){
        return size;
    }

    T2 &operator [] (T1 k){
        for (int i = 0; i < getSize(); i++)
        {
            if(k == container[i])
            {
                return i;
            }
        }
        for (int i = 0; i < getSize(); i++){
            if(i == getSize()){
                if(k != container[i]){
                    
                }
            }
        }
        return 0;
    }

    void increaseSize(int newSize){
        newSize = size + 1;
        myPair<T1,T2> *temp = new myPair<T1,T2>[newSize];
        for (int i = 0; i < size; i++)
        {
            temp[i] = container[i];
        }
        delete [] container;
        container = temp;
        size = newSize;
    }

    myPair<T1,T2> getContainer(int index){
        return container[index];
    }

    void remove(T1 key){
        //removing the key and value
        for (int i = 0; i < size; i++){
            if (container[i].getKey() == key)
            {
                container[i].setKey(0);
                container[i].setValue(0);
            }
        }
    }

    void print(int index){
        std::cout << container[index].getValue() << container[index].getKey() << std::endl;
    }

    ~myMap(){
        if (container != nullptr)
        {
            delete [] container;
            container = nullptr;
        }
    }
};

int main(){
    myPair <int, float> P(1, 5.5);
    myPair <int, float> P1(1,5.5);
    myPair <int, float> P3;
    myMap <int, float> M1;
    myMap <int, float> M2;
    M1.setSize();
    M1.insert(P1,0);
    M1.insert(P,1);
    // std::cout << M1.getSize() << std::endl;
    // std::cout << M1.isEmpty(M1) << std::endl;
    M1.print(1);
    M1.print(0);
    
    //M1.print();
    //P.print();
    //P = P1;
    //P1.print();
    //P1.swap(P);
    //P1.print();
    //P == P1;
}
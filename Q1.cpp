    #include <iostream>

    template <typename T1, typename T2>
    class myPair {
    private:
        T1 key;
        T2 value;

    public:
        static int objCount;

        //Default Constructor
        myPair() {
            key = 0;
            value = 0;
            objCount++;
        }

        //Overloaded Constructor
        myPair(T1 a, T2 b) {
            key = a;
            value = b;
            objCount++;
        }

        //Copy Constructor
        myPair(myPair& pr) {
            pr.key = key;
            pr.value = value;
        }

        //Member Functions
        void setKey(T1 k) {
            key = k;
        }

        void setValue(T2 v) {
            value = v;
        }

        //Assignment Operator
        void operator =(myPair& pr) {
            pr.key = key;
            pr.value = value;
            //return *this;
        }
        // void swap(myPair& pr) {
        //     myPair <T1, T2> temp;
        //     temp.key = pr.key;
        //     temp.value = pr.value;
        //     pr.key = getKey();
        //     pr.value getValue();
        //     key = temp.key;
        //     va
        // }

        void swap(myPair<T1, T2> &a)
        {
            T1 temp = key;
            setKey(a.getKey());
            a.setKey(temp);
            T2 temp2 = value;
            value = a.getValue();
            a.setValue(temp2);
        }

        void operator ==(myPair& pr) {
            bool isEqual = false;
            if (pr.key == key)
            {
                if (pr.value == value)
                {
                    isEqual = true;
                }
            }
            else if (pr.value == value)
            {
                if (pr.key == key)
                {
                    isEqual = true;

                }
            }
            else
            {
                isEqual = false;
            }

            if (isEqual)
            {
                std::cout << "Equal\n";
            }
            else
            {
                std::cout << "Not Equal\n";
            }
        }
        void print() {
            std::cout << key << " " << value << std::endl;
        }
        T2 getValue(){
            return value;
        }

        T1 getKey(){
            return key;
        }
    };

    template<typename T1, typename T2>
    int myPair<T1, T2>::objCount = 0;

    template <typename T1, typename T2>
    class myMap {

    private:
        int size;
        const int MAX_SIZE = 1000;
        myPair<T1, T2>* container; //Container is object of myPair Class

        // object passed is _map
    public:
        myMap() {
            size = 0;
            container = new myPair<T1,T2>[size];
            //friend  ostream& operator <<(ostream &out, myMap<a, b> &map_);
        }

        myMap(myMap& _map) {
            size = _map.size;
            container = _map.container;
        }

        void setSize() {
            size = 1;
        }

        void insert(myPair<T1, T2>& pr, int index) {

            bool keyCheck = true;
            size++;
            increaseSize(container, size);

            for (int i = 0; i < getSize(); i++) {
                if (pr.getKey() == container[i].myPair<T1,T2>::getKey()){
                    keyCheck = false;
                    break;
                }
            }
            if (keyCheck == true){
                container[index].myPair<T1, T2>::setKey(pr.getKey());
                container[index].myPair<T1, T2>::setValue(pr.getValue());
            }
            else {
                std::cout << "Key Already Exists" << std::endl;
            }
        }

        void operator =(myMap<T1, T2>& _map) {
            //myMap<T1, T2> temp;
            size = this -> size;
            for (int i = 0; i < _map.size; i++)
            {
                insert(_map.container[i], i);
            }
        }

        int isEmpty(myMap& _map) {
            if (_map.size == 0) {
                return 1;
            }
            else {
                return -1;
            }
            return 0;
        }

        int getSize() {
            return size;
        }

        T2 operator [] (T1 k){

            bool isFound = false;
            for (int i = 0; i < getSize(); i++)
            {
                if(k == container[i].myPair<T1, T2>::getKey()){
                    isFound = true;
                    std::cout << "Match Found" << std::endl;
                    return container[i].myPair<T1, T2>::getValue();
                    break;
                }
                else if(i == getSize() && isFound == false)
                {
                    size++;
                    increaseSize(container,size);
                    container[size].myPair<T1, T2>::setValue(0);
                    container[size].myPair<T1, T2>::setKey(k);
                    std::cout << "Match not Found. Inserted a new value in container" << std::endl;
                    return container[size].myPair<T1, T2>::getValue();
                }
            }
            return container[0].myPair<T1, T2>::getValue();
        }
        void increaseSize(myPair<T1,T2>*& arr, int oldSize) {
            int n = oldSize;
            myPair<T1,T2>* tempArr = new myPair<T1,T2>[n];
            for (int i = 0; i < oldSize; i++)
            {
                tempArr[i].myPair<T1,T2>::setKey(container[i].myPair<T1, T2>::getKey());
                tempArr[i].myPair<T1, T2>::setValue(container[i].myPair<T1, T2>::getValue());
            }
            oldSize = n;
            delete[] arr;
            arr = tempArr;
        }

        myPair<T1, T2> getContainer(int index) {
            return container[index];
        }

        void remove(T1 key) {
            
            int index; // storing the index of the key to be removed
            for (int i = 0; i < getSize(); i++) {
                if (container[i].myPair<T1, T2>::getKey() == key)
                {
                    index = i;
                    break;
                }
            }
            int n = size - 1;
            myPair<T1,T2> *tempArr = new myPair<T1, T2>[n];
            for (int i = index; i < getSize(); i++)
            {
                myPair<T1, T2> temp(container[i]);
                container[i].myPair<T1, T2>::setKey(container[i + 1].myPair<T1, T2>::getKey());
                container[i + 1].myPair<T1, T2>::setKey(temp.getKey());
                container[i].myPair<T1, T2>::setValue(container[i + 1].myPair<T1, T2>::getValue());
                container[i + 1].myPair<T1, T2>::setValue(temp.getValue());
            }
            for (int i = 0; i < n; i++)
            {
                tempArr[i].myPair<T1, T2>::setKey(container[i].myPair<T1, T2>::getKey());
                tempArr[i].myPair<T1, T2>::setValue(container[i].myPair<T1, T2>::getValue());
            }
            size = n - 1;
            delete [] container;
            container = tempArr;
        }

        void print(int index) {
            std::cout << container[index].getKey() << " " << container[index].getValue() << std::endl;
        }

        void clear(){
            int newSize = 0;
            myPair<T1, T2> *temp = new myPair<T1, T2> [size];
            size = newSize;
            delete [] container;
            container = temp;
        }

        myPair<T1, T2> findKey(T1 _key){
            for (int i = 0; i < getSize(); i++)
            {
                if(_key == container[i].myPair<T1, T2>::getKey()){
                    container[i].myPair<T1, T2>::print();
                    return container[i];
                }
            }
            return container[1];
        }

        // template <typename a, typename b>
        // friend myMap<a,b> operator +(myMap<a, b> map_, myMap<a,b> map_s);

        ~myMap() {
            if (container != nullptr){
                delete[] container;
                container = nullptr;
            }
        }
    };

    // template <typename a, typename b>
    // myMap<a,b> ostream &operator <<(ostream &out, myMap<a, b> &map_){
    //     out << "key" << "   " << "value" << std::endl;
    //     out << container[index].getKey() << "   " << container[index].getValue() << std::endl;
    // }

    // template <typename a, typename b>
    // myMap<a, b> operator +(myMap<a,b> &map_,myMap<a,b> &map_s){
    //     myMap<a,b> temp;
    //     myPair<a,b> tempPair;
    //     for(int i = 0; i < (map_.getSize() + map_s.getSize()); i++){
    //         if(map_.getContainer[i].myPair<a,b>::getKey() == map_s.getContainer[i].myPair<a,b>::getKey()){
    //             tempPair.setKey = map_s.getContainer[i].myPair<a,b>::getKey();
    //             tempPair.setValue = map_s.getContainer[i].myPair<a, b>::getValue();
    //             temp.insert(tempPair, i);
    //         }
    //         else{
    //             tempPair.setKey = map_s.getContainer[i].myPair<a, b>::getKey();
    //             tempPair.setValue = map_s.getContainer[i].myPair<a, b>::getValue();
    //             temp.insert(tempPair,i);
    //             tempPair.setKey = map_.getContainer[i].myPair<a, b>::getKey();
    //             tempPair.setValue = map_.getContainer[i].myPair<a, b>::getValue();
    //             temp.insert(tempPair,i);
    //         }
    //     }
    //     return temp;
    // }

    int main() {
        myPair <int, float> P(1, 5.5);
        myPair <int, float> P1(2, 4.5);
        myPair <int, float> P2(3, 1.5);
        myMap <int, float> M1;
        myMap <int, float> M2;
        myMap <int, float> M3;
        // M1.setSize();
        // M2.setSize();
        // M1.insert(P1, 1);
        //M2.insert(P, 2);
        //M3 = M1 + M2;
        //M3 = M1;
        //M3.print(1);
        //M3 = (M1 + M2);

        P.swap(P1);
        P1.print();
        P.print();



        //M1.insert(P2, 3);
        // std::cout << M1.getSize() << std::endl;
        // std::cout << M1.isEmpty(M1) << std::endl;
        //M1.print(1);
        // M1.print(2);
        // M1.print(3);
        // std::cout << M1[4] << std::endl;
        // M1.remove(2);
        // M1.print(1);
        // M1.print(2);
        // M1.clear();
        //std::cout << M1.getSize() << std::endl;
        //M1.findKey(2);
        //M1[2];


        //M1.print();
        //P.print();
        //P = P1;
        //P1.print();
        //P1.swap(P);
        //P1.print();
        //P == P1;
    }

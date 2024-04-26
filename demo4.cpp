//  demo of deep copy
#include<iostream>
using namespace std;
class Array
{
    private:
        int *arr;
        int size;
    public:
        Array(int size=5)
        {
            this->size=size;
            this->arr= new int[this->size];
            int index;
            for(index=0; index<this->size; index++)
            {
                this->arr[index]=0;
            }
            cout<<"inside parameterized ctor of Array class"<<endl;
        }
        //className( const className& objname)
        Array(const Array& other)
        {
            // step 1 copy size
            // this=&a2      other is reference of a1             
            this->size= other.size;
            // stpe2 allcoate new memory
            this->arr= new int[this->size];
            //step 3 copy data from src(a1) to dest(a2)
            for(int index=0; index<this->size; index++)
            {
               // this=&a2         other is ref of a1 
                this->arr[index]= other.arr[index];
            }
            cout<<"inside copy  of Array class"<<endl;
            return;
        }
        void accept_input()
        {
            int index;
            for(index=0; index<this->size;index++)
            {
                cout<<"this->arr["<<index<<"]";
                cin>>this->arr[index];
            }
        }
        void print_output()
        {
            int index;
            for(index=0; index<this->size;index++)
            {
                cout<<"this->arr["<<index<<"] \t"<<this->arr[index]<<"\t["<<&this->arr[index]<<"]"<<endl;
                
            }
        }
        
        ~Array()
        {
            if(this->arr!=NULL)
            {
                delete[] this->arr;
                this->arr=NULL;
            }
            cout<<"inside dtor of array class"<<endl;
        }

};// end of array class
int main(void)
{
    Array a1;  // parameteized ctor with default arg
    cout<<"enter data for a1="<<endl;
    a1.accept_input();
    cout<<"a1="<<endl;
    a1.print_output();

    Array a2(a1);  // copy ctor
    //Array a2=a1;
    cout<<"a2="<<endl;
    a2.print_output();

    return 0;
}
// when we assign allready created object(a1)to newly created obejct a2
// then copy ctor will called for that class
// if we dont write copy ctor in our class complier proivde  defualt copy by default
// default copy ctor does shallow copy
/// demo of function  overriding ( run time poly)
#include<typeinfo> // req for RTTI
#include<iostream>
using  namespace std;
// abstract class
class Shape
{
    protected:
        double area;
        double perimeter;
    public:
      Shape()
      {
        this->area=0;
        this->perimeter=0;
        cout<<"inside parameterless ctor of shape(base) class"<<endl;
      }
      // pure virtual function
      virtual void accept_input()=0;
      virtual void display_output()
      {
	    cout<<"inside display() of shape"<<endl;
        cout<<"this->area="<<this->area<<endl;
        cout<<"this->perimeter="<<this->perimeter<<endl;
      }
      virtual void calculate_area()
      {
       
      }
      virtual void calculate_perimeter()
      {
        
      }
      virtual ~Shape()
      {
        this->area=0;
        this->perimeter=0;
        cout<<"inside dtor of shape(base) class"<<endl;
      }


};// end class shape

class Circle: public Shape
{
    private:
        double radius;
    public:
      Circle()
      {
        this->radius=0;
        cout<<"inside parameterless ctor of Circle(Derived) class"<<endl;
      }
      
     void accept_input()
      {
            cout<<"enter radius=";
            cin>>this->radius;
      }
      void display_output()
      {
            cout<<"this->radius="<<this->radius<<endl;
            cout<<"this->area="<<this->area<<endl;
            cout<<"this->perimeter="<<this->perimeter<<endl;
      }
      void calculate_area()
      {
            this->area= 3.142* this->radius* this->radius;
      }
      void calculate_perimeter()
      {
            this->perimeter= 2*3.142*this->radius;  
      }
      ~Circle()
      {
        this->area=0;
        this->perimeter=0;
        cout<<"inside dtor of Circle(Derived) class"<<endl;
      }


};// end class Circle


class Rectangle: public Shape
{
    private:
        double l;
        double b;
    public:
      Rectangle()
      {
        this->l=0;
        this->b=0;
        cout<<"inside parameterless ctor of Rectangle(Derived) class"<<endl;
      }
      
      void accept_input()
      {
            cout<<"enter l=";
            cin>>this->l;
            cout<<"enter b=";
            cin>>this->b;
            
      }
      void display_output()
      {
            cout<<"this->l="<<this->l<<endl;
            cout<<"this->b="<<this->b<<endl;
            cout<<"this->area="<<this->area<<endl;
            cout<<"this->perimeter="<<this->perimeter<<endl;
      }
      void calculate_area()
      {
            this->area= this->l* this->b;
      }
      void calculate_perimeter()
      {
            this->perimeter= 2 *( this->l + this->b);
      }
      ~Rectangle()
      {
        this->area=0;
        this->perimeter=0;
        cout<<"inside dtor of Rectangle(Derived) class"<<endl;
      }


};// end Rectangle Circle

int menu_choice()
{
    int choice;
    cout<<"\n 1. Circle \n 2. Rectangle \n 0. exit";
    cout<<"\n Enter choice::";
    cin>>choice;
    return choice;
}

int main(void)
{
    int choice;
    Shape *ptrShape=NULL;
  //  Shape objShape; error as shape is a abstract class 
    
    do 
    {
         choice= menu_choice();
         switch (choice)
         {
                case 0 : // exit
                        return 0;  
                case 1: // circle
                        ptrShape= new Circle; // upcasting
                       break;
                case 2:// rectangle
                        ptrShape= new Rectangle; // upcasting
                        break;
                default:  cout<<"invalid case "<<endl;
                        break;
         } 

         if( ptrShape!=NULL)
         {
            cout<<"==========================="<<endl;
            const type_info& info = typeid(*ptrShape);
            cout << info.name() << endl;
            cout<<"==========================="<<endl;
            ptrShape->accept_input();
            ptrShape->calculate_area();
            ptrShape->calculate_perimeter();
            ptrShape->display_output();

            delete ptrShape;
            ptrShape=NULL;
            cout<<"memory freed "<<endl;
         }


        cout<<"Enter 1 to continue and o to exit ::";
        cin>>choice;

    }while(choice!=0);

    return 0;
}
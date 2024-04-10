#include<iostream>
using namespace std;
class employee
{
	private : 
	
		int empid;
		string name;
		double salary;
			
	public : 
				
		employee()
			{
				empid=0;
				name="no_name";
				salary=0000;
			}
			
			employee(int empid, string name, double salary)
			{
				this->empid=empid;
				this->name=name;
				this->salary=salary;
			}
			void calsalary()
			{
				cout<<"employee salary"<<endl;
			}
			void display()
			{
				cout<<"empid : "<<empid<<" emp name : "<<name<<" salary : "<<salary<<endl;
			}
};
			
class manager : public employee
{
	private:
		double incentive;
		string deptname;
			
	public:
	
		
		manager()
		{
			incentive=0000;
			deptname="not_applicable";
		}
		
		manager(int empid, string name, double salary, double incentive, string deptname):employee(empid, name, salary)
		{
			this->incentive=incentive;
			this->deptname= deptname;
		}
		void managertask()
		{
			cout<<"manager task : "<<endl;
		}
		void display()
		{
			cout<<"\n Manager incentive : "<<incentive<< " Dept_Name : "<<deptname<<endl;
		}
};
int main()
{
	employee emp(101,"kkkkk",21300);
	
	emp.calsalary();
	emp.display();
	
	cout<<"Manager : "<<endl;
	manager mgr(100, "wer", 500000, 20000.00, "IT");
	mgr.display();
	mgr.calsalary();
	mgr.managertask();
	
	return 0;
}

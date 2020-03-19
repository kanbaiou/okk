#include<iostream>
#include<string>
using namespace std;

#define MAX_NUMBER 1000
/*requirement:
添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
显示联系人：显示通讯录中所有联系人信息
删除联系人：按照姓名进行删除指定联系人
查找联系人：按照姓名查看指定联系人信息
修改联系人：按照姓名重新修改指定联系人
清空联系人：清空通讯录中所有信息
退出通讯录：退出当前使用的通讯录
*/


struct person
{
	string name;
	int age;
	long phonenumber;
	string sex;
	string address;


};

struct addressmanger
{

	
	
private:
	int current_data_amout=0;

	person save_data[MAX_NUMBER];

public:	
	void add_member()
	{
		if (current_data_amout <= MAX_NUMBER - 1)
		{
			
			cout << "add person!" << endl;
			person new_member;
			cout << "input name:" << endl;
			cin >> new_member.name;
			cout << "input age:" << endl;
			cin >> new_member.age;
			cout << "input sex:" << endl;
			cin >> new_member.sex;
			cout << "input address" << endl;
			cin >> new_member.address;
			cout << "input phone number" << endl;
			cin >> new_member.phonenumber;
			save_data[current_data_amout] = new_member;
			current_data_amout++;
			cout << "add finished" << endl;
			system("pause");
			system("cls");

		}
		else
		{
			cout << "pay more money" << endl;
			system("pause");
			system("cls");
		}


	}

	void show_all_member()
	{
		if (current_data_amout == 0) 
			cout << "no member exist" << endl;
		else
		{
			for (int i = 0; i < current_data_amout; i++)
			{
				cout << "##############" << endl;
				cout << "name:" << save_data[i].name << endl;
				cout << "age:" << save_data[i].age << endl;
				cout << "sex:" << save_data[i].sex << endl;
				cout << "address:" << save_data[i].address << endl;
				cout << "phonenumber:" << save_data[i].phonenumber << endl;



			}
		}
		system("pause");
		system("cls");

	}

	
	bool is_exist(string targetname)
	{

		bool exist=false;
		if (current_data_amout == 0)
		{
		
		}
		else
		{
			for (int i = 0; i < current_data_amout; i++)
			{
				if (save_data[i].name == targetname)
				{
					exist = true;
					break;
				}
			
	
				    
			}
		

		}
		return exist;


	}
	
	void del_member(string targetname)
	{

		if (is_exist(targetname))
		{
			for (int i = 0; i < current_data_amout; i++)
			{
				if (save_data[i].name == targetname)
				{
					if (i != current_data_amout - 1)
					{
						for (int j = i; j < current_data_amout - 1; j++)
							save_data[j] = save_data[j + 1];
						i--;// check again if more than two people with same name exist
						current_data_amout--;
					}
					else
					{
						current_data_amout--;
						
					}

				}


			}

			cout << "all member with this name deleted" << endl;

		}
		else
		{

			cout << "this member not exists!!!" << endl;


		}
		system("pause");
		system("cls");
	}

	void revise_member(string targetname)
	{



	}

	void clear_all()

	{




	}
	void find_member(string targetname)
	{



	}


};


/*requirement:
添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
显示联系人：显示通讯录中所有联系人信息
删除联系人：按照姓名进行删除指定联系人
查找联系人：按照姓名查看指定联系人信息
修改联系人：按照姓名重新修改指定联系人
清空联系人：清空通讯录中所有信息
退出通讯录：退出当前使用的通讯录
*/
void start_interface() 
{
	cout << "------welcome to use address manger------" << endl;
	cout << "------1:  add new member ------" << endl;
	cout << "------2:  show all members------" << endl;
	cout << "------3:  delete member------" << endl;
	cout << "------4:  make change to member------" << endl;
	cout << "------5:  clear all member's info------" << endl;
	cout << "------6:  find info about certain member------" << endl;
	cout << "------0:  clear exit------" << endl;




}



int main()
{



	addressmanger mainmanger;

	int select = 0;
	string name;
	while(true)
	{
		start_interface();
		
		cout<<"input"<<endl;
		cin >> select;
		switch (select)
		{
		case 0:
		
			cout << "exit!!!!!" << endl;

			system("pause");
			
			return 0;
			break;

		
		case 1:
			
		
			mainmanger.add_member();
			break;
	
		case 2:
			mainmanger.show_all_member();
			break;
		case 3: 
			cout << "member's name" << endl;
			cin >> name;
			mainmanger.del_member(name);
			break;
		case 4:
			cout << "member's name" << endl;
			cin >> name;
			mainmanger.revise_member(name);
			break;
		case 5:
			mainmanger.clear_all();
			break;
		case 6:
			cout << "member's name" << endl;
			cin >> name;
			mainmanger.find_member(name);
			break;



   

		default:
			break;
		}
		
		



    

	}

	//cout << "what's wrong" << endl;
	//system("pause");

	//return 0;



}
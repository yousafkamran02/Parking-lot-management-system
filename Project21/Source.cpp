#include<iostream>
#include <string>
using namespace std;
struct node
{
	int pol;
	string mod, reg_num;
	node* next;
};
node* head = NULL, * node_new, * temp;
int lenli = 0;
void adcar()
{
	node_new = new node;
	cout << "Enter Car Reg#:";
	cin >> node_new->reg_num;
	cout << "Enter Model of Car:";
	cin >> node_new->mod;
	cout << endl;
	cout << "Assigned plot:";
	cin >> node_new->pol;
	cout <<endl;
	system("pause");
	node_new->next = NULL;
	if (head == NULL)
	{
		head = node_new;
		temp = node_new;
	}
	else
	{
		temp->next = node_new;
		temp = node_new;
	}
}
void display_info()
{
	if (head == NULL)
	{
		cout << "\tNo Parkered" << endl;
	}
	else
	{
		node* trv = head;
		int counter = 0;
		while (trv != NULL)
		{
			cout << endl;
			cout << "Model:" << trv->mod << endl;
			cout << "Plot Number:" << trv->pol << endl;
			cout << "Car Reg# " << trv->reg_num << endl;
			cout << "Index:" << counter + 1 << endl;
			counter++;
			trv = trv->next;
			lenli++;

		}
		for (int i = 0; i < 34; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "Total Cars Parked = " << counter << endl;
		for (int i = 0; i < 34; i++)
		{
			cout << "-";
		}
		cout << endl;
	}
	system("pause");
}
void sercar()
{
	node* search_node = head;
	string srch;
	int count = 1;
	cout << "Enter Car Reg no: ";
	cin >> srch;
	bool found = false;
	if (head == NULL)
	{
		cout << "\nNo Car Parked " << endl;
	}
	else
	{
		while (search_node != NULL)
		{
			if (srch == search_node->reg_num || srch == search_node->mod)
			{
				cout << "\n\t\tModel: " << search_node->mod << endl;
				cout << "\t\tPlot number: " << search_node->pol << endl;
				cout << "\t\tCar Reg# " << search_node->reg_num << endl;
				found = true;
				break;
			}
			search_node = search_node->next;
		}
	}
	if (found == false)
	{
		cout << "Car not found " << endl;
	}
	system("pause");
}
void dep_car()
{
	int pos;
	node* next_node;
	temp = head;
	cout << "Enter index Number of departed Car:";
	cin >> pos;
	cout << endl;
	if (head == NULL)
	{
		system("CLS");
		cout << "Empty parking lot " << endl;
	}
	else if (pos > lenli)
	{
		system("CLS");
		cout << "Invalid Car Plot " << endl;
	}
	else if (pos == 1)
	{
		temp = head;
		head = head->next;
		delete temp;
		system("CLS");
		cout << "Pay Rs.30" << endl;
		system("pause");
		cout << "Payment approved" << endl;
		system("pause");
		system("CLS");
		cout << "Car has been departed " << endl;
	}
	else
	{
		for (int i = 2; i < pos; i++)
		{
			temp = temp->next;
		}
		next_node = temp->next;
		temp->next = next_node->next;
		delete next_node;
		system("CLS");
		cout << "Pay Rs.30" << endl;
		system("pause");
		cout << "Payment approved" << endl;
		system("pause");
		system("CLS");
		cout << "Car has been departed " << endl;
	}
}
void delinfo()
{
	if (head == NULL)
	{
		cout << " No Car parked" << endl;
	}
	else
	{
		temp = 0;
		temp = head;
		while (head != NULL)
		{
			head = head->next;
			delete temp;
		}
		
		cout << "\tALL Car parked info has been deleted" << endl;
		
	}
}
void sort()
{
	node* temp1 = head;
	int te_roll;
	string temp_name;
	int counter = 0;
	while (temp1)
	{
		temp1 = temp1->next;
		counter++;
	}
	temp1 = head;
	for (int j = 0; j < counter; j++)
	{
		while (temp1->next)
		{
			if (temp1->pol > temp1->next->pol)
			{
				te_roll = temp1->pol;
				temp1->pol = temp1->next->pol;
				temp1->next->pol = te_roll;

				temp_name = temp1->mod;
				temp1->mod = temp1->next->mod;
				temp1->next->mod = temp_name;
				temp1 = temp1->next;
			}
			else
				temp1 = temp1->next;
		}
		temp1 = head;
	}
}
void menu()
{
	cout << "\tMenu" << endl;
	cout << "1.Admit Car" << endl;
	cout << "2.Display Information of all Cars" << endl;
	cout << "3.Search a Car" << endl;
	cout << "4.Car departed" << endl;
	cout << "5.Sort Car information" << endl;
	cout << "6.Clear list" << endl;
	cout << "7.Exit" << endl;
	for (int i = 0; i <= 50; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << "Enter Option:";

}
int main()
{
	int op;
	char opt = 1;;
	do
	{

		menu();
		cin >> op;
		cout << endl;
		system("CLS");
		if (op == 1)
		{
		  adcar();
		}
		else if (op == 2)
		{
			lenli = 0;
			display_info();
		}
		else if (op == 3)
		{
			sercar();
		}
		else if (op == 4)
		{
			display_info();
			dep_car();
		}
		else if(op==5)
		{
			display_info();
			sort();
			system("pause");
			system("CLS");
			display_info();
		}
		else if (op == 6)
		{
			delinfo();
		}
		else if (op == 7)
		{
			cout << "Goodbye" << endl;
			exit(0);
		}
		else
		{
			cout << "Invalid Option " << endl;
		}
		cout << "Do you want to continue(Y/N):";
		cin >> opt;
		cout << endl;
		system("CLS");
	} while (opt == 'y' || opt == 'Y');
	return 0;
}


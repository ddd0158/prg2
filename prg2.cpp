#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<iomanip>

#include<fstream>

#include<cmath>



using namespace std;

    /*

     * Node Declaration

     */

struct node

{

	string info;

	int ID;

	struct node *next;

}*start;



    /*

     * Class Declaration

     */

class single_llist

{

	public:

	node* create_node(string);

	void delete_pos();

	//void search();

	void display();

	void insert();



	single_llist()

	{

		start = NULL;

	}

};


    /*

     * Main :contains menu

     */

main()
{

	string choice;

	int ndoes, elements, position, i;

	single_llist sl;

	start = NULL;

	while(choice != "quit")

	{

		cout<<"add *name*"<<endl;

		cout<<"search *name*"<<endl;

		cout<<"REMOVE *name*"<<endl;

		cout<<"print contacts"<<endl;

		cout<<"file *fileName*"<<endl;

		cout<<"quit"<<endl;

		cout<<"type in what you want to do : ";

		cin>>choice;

		if(choice == "add")
		{
			sl.insert();

			cout<<endl;

		}

		else if(choice == "REMOVE")
		{
			sl.delete_pos();

			cout<<endl;
		}

		else if(choice == "print")
		{
			sl.display();

			cout<<endl;
		}

		else if(choice == "file")
		{
			return 1;

		}

		else if(choice == "quit")
		{
			cout<<"Exiting..."<<endl;

			exit(1);
		}

		else
		{
			cout<<"I think you mispelled something... Please try again."<<endl;

		}

	}

}

int ID;

node *single_llist::create_node(string value)

{

	struct node *temp, *s;

	temp = new(struct node);

	if (temp == NULL)

	{

		cout<<"Memory not allocated "<<endl;

		return 0;

	}

	else

	{

		temp->info = value;

		ID++;

		temp->ID = ID;

		temp->next = NULL;

		//cout << "ID incremented " << temp-> ID << endl;

		return temp;
	}


}

void single_llist::insert()
{

	string value;

	//cout<<"Enter the value to be inserted: ";

        cin>>value;

        struct node *temp, *s;

        temp = create_node(value);

        s = start;

	if (start == NULL)

	{

		start = temp;

		start->next = NULL;

		return;

	}



        while (s->next != NULL)

        {

		s = s->next;

        }

        temp->next = NULL;

        s->next = temp;

        cout<<"Element Inserted at last"<<endl;

}

void single_llist::delete_pos()

{
	
        string value;

	int pos = 0;

        bool flag = false;

        if (start == NULL)

        {

		cout<<"List is empty"<<endl;

		return;

        }

        cout<<"Enter the value to be deleted: ";

        cin>>value;

        struct node *s;

        s = start;

        while (s != NULL)

        {

		pos++;

		if (s->info == value)

		{

			flag = true;
			delete s;
			free(s);
			return;
		}

		s = s->next;

		cout<<"value is deleted"<<endl;

	}

	

        if (!flag)

		cout<<"FALSE: "<<value<<""<<endl;
		//cout<<"Element "<<value<<" not found in the list"<<endl;


}

void single_llist::display()

{

        struct node *temp;

        if (start == NULL)

        {

		cout<<"The List is Empty"<<endl;

		return;

        }

        temp = start;

        cout<<"Elements of list are: "<<endl;

        while (temp != NULL)

        {

		//cout<<temp->info<<"\n";

		cout << "ID" << setfill('0') << setw(3) << temp->ID << " " << temp->info <<"\n";

		temp = temp->next;
        }

	//cout << "ID" << temp->ID << " " << temp->info << endl;

        cout<<"NULL"<<endl;

}

///main.cpp
int main()
{
	int size,ind;
	cout<<"Enter the size of array \n ";
	cin>>size;

	Myarr a1(size);

	int choice,data;


	while(1)
	{
	cout<<"\n1. Add int at end.\n";
	cout<<"2. Add int at begining.\n";
	cout<<"3. update index of value.\n";
	cout<<"4. Add value at given index.\n";
	cout<<"5. display.\n";
	cout<<"6. delete end.\n";
	cout<<"7. delete first.\n";
	cout<<"8. delete given index.\n";
	cout<<"9. search element.\n";
	cout<<"10. exit.\n";

	cout<<"\n\nEnter your choice\n";
	cin>>choice;

	switch(choice)
	{
		case 1 :
			cout<<"Enter the value :\n";
			cin>>data;
			a1.Addatend(data);
			break;
		case 2 :
			cout<<"Enter the value :\n";
			cin>>data;
			a1.AddatBegining(data);
			break;
		case 3 :
			cout<<"enter value you want to update at index\n";
			cin>>data;
			cout<<"enter the index\n";
			cin>>ind;
			//a1[ind]=data;
			a1.Updateindexvalue(data,ind);
			break;
		case 4 :
			cout<<"enter value you want to Add at index\n";
			cin>>data;
			cout<<"enter the index\n";
			cin>>ind;
			//a1.Addatgivenindex(data);
			a1.Addindexvalue(data,ind);
			//a1.operator[](index)
			break;

		case 5 :
			a1.display();
			break;

		case 6 :
			data=a1.deleteAtEnd();
			if(data==-1)
			{
				cout<<"\nArray is empty there is nothing to delete \n";
			}
			else
			{
			cout<<"Deleted data is:"<<data<<"\n";
			}
			break;
		case 7 :
			data=a1.deleteAtFront();
			if(data==-1)
			{
				cout<<"\nArray is empty there is nothing to delete \n";
			}
			else
			{
			cout<<"Deleted data is:"<<data<<"\n";
			}
			break;
		case 8 :
			cout<<"\nEnter the index to delete data\n";
			cin>>ind;
			data=a1.deleteAtIndex(ind);
			if(data==-1)
			{
				cout<<"\nArray is empty there is nothing to delete \n";
			}
			else
			if(data==0)
			{
				cout<<"\nIndex out of bound\n";
			}
			else
			if(data==-2)
			{
				cout<<"\nNo data to delete at given index\n";
			}
			else
			{
			cout<<"Deleted data is:"<<data<<"\n";
			}
			break;


			cout<<"Deleted data is: "<<data;
		case 9 :
			cout<<"\nEnter the element to search\n";
			cin>>data;
			if(a1.search(data)){
					cout<<"data found"<<std::endl;
				}else{
					cout<<"data not found"<<std::endl;
				}
			break;

		case 10:
			exit(0);
			break;
		default:
			cout<<"Enter the valid choice\n";
			break;
	}


	}


}
**************************************************************************************
#include "myarr.cpp"

class Myarr
{
	int size, index, *ptr;
	public :

	Myarr::Myarr()
	{
		this->size=1;
		this->ptr=new int[size];
		this->index=-1;
	}

	Myarr::Myarr(int s)
	{
		this->size=s;
		this->ptr=new int[size];
		this->index=-1;
	}





//int& operator[](int ind)
void Myarr::Updateindexvalue(int data,int ind)
{

	if(ind>size-1)
	{
	cout<<"\nindex out of bound\n";
	}
	else if(ind<=index)
	{

	ptr[ind]=data;
	}

	else
	{
		cout<<"\nNo value to update at given index \n";
	}

}


void Myarr::AddatBegining(int data)
{
	if(index==size-1)
	{
		cout<<"\nArray is full\n";
	}
	else
	{
		int a;
		a=index;
		for(int i=0;i<index+1;i++)
		{
			ptr[a+1]=ptr[a];
			a--;
		}

		ptr[a+1]=data;
		index++;

	}


}


void Myarr::Addatend(int data)
{
	if(index==size-1)
	{
		cout<<"\nArray is full\n";
	}
	else
	{
		index++;
		ptr[index]=data;
	}
}



void Myarr::Addindexvalue(int data,int ind)
{
	if(ind>=size)
	{
        	cout <<"\nArray index out of bound \n";
	}
	else
	{
		if(index==size-1)
		{
			cout<<"\nArray is full\n";
		}
		else
		{
			int a,temp;
			temp=index-ind+1;
			a=index;
			for(int i=0;i<=temp;i++)
			{
				ptr[a+1]=ptr[a];
				a--;
			}
			index++;
			ptr[ind]=data;

		}
	}

	if(index-ind<0)
	{
		index++;
		ptr[ind]=data;

	}

}


void Myarr::display()
{
	int i;
	cout<<"\n";
	for(i=0;i<=index;i++)
	{
		cout<<ptr[i]<<"\t";
	}
	//cout<<"\nIndex="<<index;
}

int Myarr::deleteAtEnd()
{
	if(index==-1)
	{
		return -1;

	}

	else
	{

		index--;
		return ptr[index+1];
	}
}

int Myarr::deleteAtFront()
{
	int data,i;
	if(index==-1)
	{
		return -1;

	}

	else
	{
		data=ptr[0];
		for(i=0;i<index;i++)
		{
			ptr[i]=ptr[i+1];
		}
		index--;
		return data;
	}
}

int Myarr::deleteAtIndex(int ind)
{
	int data,i,a;
	if(index==-1)
	{
		return -1;

	}

	else
	if(ind>size-1)
	{
		return 0;
	}
	else
	if(ind>index)
	return -2;
	else
	{

		data=ptr[ind];
		a=index-ind;

		for(i=0;i<a;i++)
		{
			ptr[ind]=ptr[ind+1];
			ind++;
		}
		index--;
		return data;
	}

}

bool Myarr::search(int data)
{
	int flag,i;
	for(i=0;i<=index;i++)
	{
		if(data==ptr[i])
		{
			flag=1;
			break;
		}

	}
	if(flag==1)
	return 1;
	else
	return 0;

}


};


***********************************************************************************
#include "Myarr.h"

class Myarr
{
	int size, index, *ptr;
	public :

Myarr();
void Updateindexvalue(int data,int ind);
void AddatBegining(int data);
void Addatend(int data);
void Addindexvalue(int data,int ind);
void display();
int deleteAtEnd();
int deleteAtFront();
int deleteAtIndex(int ind);
bool search(int data);


};



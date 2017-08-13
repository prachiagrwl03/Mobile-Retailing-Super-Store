#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int index=0;      //for mobile in stock
int c_index=0;    //for billing of cutomers
struct Mobile
{
	char p_name[100][100];
	int p_model[100];
	int p_qty[100];
	char p_color[100][10];
	int p_price[100];
	char p_brand[100][10];
}m1;
struct customer
{
	char c_name[100][100];
	char c_mob[100][10];
	char c_address[100][100];
	char c_email[100][25];
}c1;
void insert()
{
	cout<<"Enter the phone name         ";
	gets(m1.p_name[index]);
	cout<<"Enter the phone model        ";
	cin>>m1.p_model[index];
	cout<<"Enter the  qty of phone:     ";
	cin>>m1.p_qty[index];
	cout<<"Enter the phone color        ";
	gets(m1.p_color[index]);
	cout<<"Enter the phone price        ";
	cin>>(m1.p_price[index]);
	cout<<"Enter the phone brand        ";
	gets(m1.p_brand[index]);
}
void display(int i)
{
	cout<<"the phone name is     :  ";
	puts(m1.p_name[i]);
	cout<<"the phone model is    :  ";
	cout<<m1.p_model[i];
	cout<<"\nQty of phone left   :  ";
	cout<<m1.p_qty[i];
	cout<<"\nthe phone color is  :  ";
	puts(m1.p_color[i]);
	cout<<"the price of phone is :  ";
	cout<<m1.p_price[i];
	cout<<"\n brand of phone is  :  ";
	puts(m1.p_brand[i]);
	cout<<endl;
	cout<<endl;
}

void get_details()
{
	cout<<"enter customer name:           ";
	gets(c1.c_name[c_index]);
	cout<<"enter customer mobile  number: ";
	gets(c1.c_mob[c_index]);
	cout<<"enter customer address:        ";
	gets(c1.c_address[c_index]);
	cout<<"enter customer email:          ";
	gets(c1.c_email[c_index]);
}
void print_bill(int inde)
{
 int quant;
 float total;
 cout<<"how many phone_qty  you want?         ";
 cin>>quant;
 m1.p_qty[inde] -= quant;
 total= quant*(m1.p_price[inde]);
 cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n";
 cout<<"±                                                              ±\n";
 cout<<"±                GREY ORANGE MOBILE STORE                      ±\n";
 cout<<"±                                                              ±\n";
 cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n";
 cout<<"\n\t\t cutomer name     ----> ";
 puts(c1.c_name[c_index]);
 cout<<"\n\t\t customer phone   ----> ";
 puts(c1.c_mob[c_index]);
 cout<<"\n\t\t customer address ----> ";
 puts(c1.c_address[c_index]);
 cout<<"\n\t\t cutomer email    ----> ";
 puts(c1.c_email[c_index]) ;
 cout<<"\n\t\tprice of an item  ----> ";
 cout<<m1.p_price[inde];
 cout<<"\n\n\t\tQuantity        ----> ";
 cout<<quant;
 cout<<"\n---------------------------------------------------------------";
 cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTotal : "<<total<<endl;
}
void sell()
{
	int model;
	int p_index;
	int flag=0;
	char ans;
	char doo;
	cout<<"enter the model no you want to sell:";
	cin>>model;
	for(int i=0;i<index;i++)
	{
		if(m1.p_model[i]==model)
		{
		 flag=1;
		 display(i);
		 p_index=i;
		}

	}
	if(flag==0)
	{
	 cout<<"model out of stock";
	}
	else if(flag==1)
	{
	 cout<<"do you really want to sell this product?";
	 cout<<"Press y for yes";
	 cout<<"Press n for no";
	 cin>>doo;
	 switch(doo)
	 {
		case 'y': get_details();
			  cout<<"\n";
			  cout<<"\n";
			  print_bill(p_index);
			  c_index++;
			  break;
		case 'n': cout<<"do you want to buy another product?";
			  cin>>ans;
			  if(ans=='y')
			  {
				sell();
			  }
			  else
			  {
				break;
			  }
		default:
			cout<<"invalid choice entered";
			break;

	 }
	}
}
void update(int i)
{
	cout<<"Enter new details:\n";
	cout<<"Enter the phone name \t";
	gets(m1.p_name[i]);
	cout<<"Enter the phone model \t";
	cin>>m1.p_model[i];
	cout<<"Enter the  qty of that phone:";
	cin>>m1.p_qty[i];
	cout<<"Enter the phone color \t";
	gets(m1.p_color[i]);
	cout<<"Enter the phone price \t";
	cin>>(m1.p_price[i]);
	cout<<"Enter the phone brand \t";
	gets(m1.p_brand[i]);

}

void main()
{
	clrscr();
	int ch;
	int i;
	int model;
	cout<<"\t\t Press 1. to display a handset \n";
	cout<<"\t\t Press 2. to insert a handset \n";
	cout<<"\t\t Press 3. to sell a handset \n";
	cout<<"\t\t Press 4. to update a handset \n";
	cout<<"\t\t Press 5. exit \n";

       while(1)
       {
	cout<<"Enter your choice";
	cin>>ch;

	switch(ch)
	{
		case 1: for(int i=0;i<index;i++)
			{
			display(i);
			}
		       break;
		case 2:insert();
		       index++;
		       break;
		case 3:sell();
		       break;
		case 4:cout<<"Enter the model you want to update: ";
		       cin>>model;
			for(i=0;i<index;i++)
			{
				if(m1.p_model[i]==model)
				{
					 display(i);
					 update(i);
				}

			}
		       break;

		case 5:break;
		default:cout<<"invalid key.";
			break;
	}
	if(ch==5)
		break;
       }

	getch();

}
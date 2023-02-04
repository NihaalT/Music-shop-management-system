#include "product.h"

void product::showAddMenu(){
std::cout << "**********Add a new product**********";
std::cout << "\n1. CD";
std::cout << "\n2. DVD";
std::cout << "\n3. Magazine";
std::cout << "\n4. Book"<<std::endl;
std::cin>> addChoice;
}

void product::create_product()
{
    showAddMenu();
    if (addChoice==1){
        type=1;
        std::cout<<"Item Number: "<< std::endl;
        std::cin>>product_number;
        std::cout<<"Name of The Item: "<< std::endl;
        std::cin.ignore();
        std::cin.getline(product_name ,50);
        std::cout<<"Price: "<<std::endl;
        std::cin>>product_price;
        std::cout<<"Artist: "<<std::endl;
        std::cin>>artist;
        std::cout<<"Year released: "<<std::endl;
        std::cin>>released;
        std::cout<<"Quantity"<<std::endl;
        std::cin>>product_quantity;
    } 
    else if(addChoice==2)
    {
        type=2;
        std::cout<<"Item Number: "<< std::endl;
        std::cin>>product_number;
        std::cout<<"Name of The Item: "<< std::endl;
        std::cin.ignore();
        std::cin.getline(product_name ,50);
        std::cout<<"Price: "<<std::endl;
        std::cin>>product_price;
        std::cout<<"Producer: "<<std::endl;
        std::cin>>artist;
        std::cout<<"Year released: "<<std::endl;
        std::cin>>released;
        std::cout<<"Quantity"<<std::endl;
        std::cin>>product_quantity;
    } 
    else if(addChoice==3)
    {
        type=3;
        std::cout<<"Item Number: "<< std::endl;
        std::cin>>product_number;
        std::cout<<"Name of The Item: "<< std::endl;
        std::cin.ignore();
        std::cin.getline(product_name ,50);
        std::cout<<"Price: "<<std::endl;
        std::cin>>product_price;
        std::cout<<"Publisher: "<<std::endl;
        std::cin>>artist;
        std::cout<<"Year released: "<<std::endl;
        std::cin>>released;
        std::cout<<"Quantity"<<std::endl;
        std::cin>>product_quantity;
    } 
    else if(addChoice==4)
    {
        type=4;
        std::cout<<"Item Number: "<< std::endl;
        std::cin>>product_number;
        std::cout<<"Name of The Item: "<< std::endl;
        std::cin.ignore();
        std::cin.getline(product_name ,50);
        std::cout<<"Price: "<<std::endl;
        std::cin>>product_price;
        std::cout<<"Author: "<<std::endl;
        std::cin>>artist;
        std::cout<<"Year released: "<<std::endl;
        std::cin>>released;
        std::cout<<"Quantity"<<std::endl;
        std::cin>>product_quantity;
    } 
    else 
    {
        std::cout<<"Enter a valid option";
        showAddMenu();
    }
}

void product::show_product()
{
    std::cout<<"Media: "<<type<<std::endl;
    std::cout<<"Product #: "<<product_number << std::endl;
    std::cout<<"Product Name: "<<product_name <<std::endl;
    std::cout<<"Product Price: "<<product_price <<std::endl<<std::endl;
    
}

int product::getType()
{
    return type;
}
int product::getProduct()
{
    return product_number;
}

float product::getPrice()
{
    return product_price;
}

char* product::getName()
{
    return product_name;
}
char* product::getArtist()
{
    return artist;
}
int product::getQuantity(){
    return product_quantity;
}

std::fstream fp;
std::ifstream fin;
std::ofstream fout;
product produc;

 
void save_product()
{
	fp.open("database.dat",std::ios::out|std::ios::app);
	produc.create_product();
	fp.write((char*)&produc,sizeof(product));
	fp.close();
	std::cout<<"The Product Has Been Sucessfully Created..."<<std::endl;
}

void displayItems()
{
	int i=1;
	std::cout<<"\n==================================================================";
	std::cout<<"\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	std::cout<<"\n\n==================================================================\n";
	std::cout<<"\n\n========== Media type: 1=CD 2=DVD 3=Magazine 4=Book ==========\n";
	std::cout<<"\n\n============================================================\n";	
	 fin.open("database.dat",std::ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&produc,sizeof(product));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     produc.show_product();	 
	  }
     }
     if(i==0)
     {	
		 std::cout<<"\n\n\t\t\t!!No items!!";
     }
     fin.close();
     ;

}
 
void sellItem(){
    int order[50],quan[50],c=0;
	float amount,total=0;
	char ch='Y';
	long pos=0;
	displayItems();
	std::cout<<"\n PLACE ORDER";
	do{
		std::cout<<"\n\nEnter The Product #: ";
		std::cin>>order[c];
		std::cout<<"\nQuantity: ";
		std::cin>>quan[c];
		c++;
		std::cout<<"\nDo You Want To Order Another Product ? (y/n)";
		std::cin>>ch;
		}while(ch=='y' ||ch=='Y');
	system("clear");
	std::cout<<"\n\n********************************Reciept************************\n";
	std::cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \n";
	for(int x=0;x<=c;x++)
	{
		fp.open("database.dat",std::ios::in);
		pos=fp.tellp();
		fp.read((char*)&produc,sizeof(product));
		while(!fp.eof())
		{	
			if(produc.getProduct()==order[x])
			{
				fp.open("sales.dat",std::ios::out|std::ios::app);
				amount=produc.getPrice()*quan[x];
				std::cout<<"\n"<<order[x]<<"\t"<<produc.getName()<<"\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\t"<<amount;
				total+=amount;
				
				fp.seekp(pos);
				fp.write((char*)&produc,sizeof(product));
				fp.close();
				c++;
			}
			fp.read((char*)&produc,sizeof(product));
		}
		fp.close();
	}
	std::cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
}


void restock(){
	bool found=false;
    int recordNumber;

	displayItems();
    std::cout << "Please enter the product number:" << std::endl;
    std::cin >> recordNumber;
	fp.open("database.dat",std::ios::in|std::ios::out);
    fp.seekg(recordNumber * sizeof(product), std::ios::beg);
    while(fp.read((char *)&produc, sizeof(product))&& found==false)
	{
		//if(produc.getProduct()== recordNumber)
        if (found==true)
		{
			produc.show_product();
			std::cout<<"\nPlease Enter The New Details of Product: "<<std::endl;
			produc.create_product();
			int pos=-1*((int)sizeof(produc));
			fp.seekp(pos,std::ios::cur);
			fp.write((char*)&produc,sizeof(product));
			std::cout<<"\t Record Successfully Updated..."<<std::endl;
			found=true;
		}
        else if(found==false)
        {
		    std::cout<<"Record Not Found..."<<std::endl;
        }
	}
	fp.close();
	
	

}
void stockQuantity(){
	fp.open("database.dat",std::ios::in | std::ios::out | std::ios::binary);
	while(fp.read(reinterpret_cast<char *> (&produc), sizeof(product)))
	{ 
		int sQuantity;
		sQuantity=produc.getQuantity();
		if (sQuantity < 5){
			std::cout<<"You need to restock: "<<produc.getProduct()<<std::endl;

		}else{
			std::cout<<"Stock levels are ok for: "<<produc.getProduct()<<std::endl;

		}
	}

}
void displayALL(){
	fp.open("sales.dat",std::ios::in|std::ios::binary);
    fp.seekg(0);
    bool found;
	int row=5,pageno=1,flag=0;
	float total=0.0;
	while(fp.read((char*)&produc,sizeof(product))&& found==true)
    {
        std::cout<<"Record of sales";
        std::cout<<"Product no. Name Price Quantity Amount";
        row++;
        
        if(flag){
            std::cout<<"Total: "<<total;
            row++;
        }
	}
    if(found==0){
		std::cout<<"Record Not Found..."<<std::endl;
    }
    fp.close();
    
}



void showMenu(){
	std::cout<<"\n\n\n\n\n\n\n\n\n\n\n |============ WELCOME TO THE MUSIC SHOP STOCK MANAGEMENT SYSTEM ============|";
	std::cout<<"\n=============================================================";
    std::cout<<"\n\t\t\t**********MENU**********";
	std::cout<<"\n=============================================================";
    std::cout<< "\n\n\t\t1. Display products to sell";
    std::cout<< "\n\t\t2. Add new item";
    std::cout<< "\n\t\t3. Restock";
    std::cout<< "\n\t\t4. Update stock quantity";
    std::cout<< "\n\t\t5. View report of sales";
    std::cout<< "\n\t\t6. exit"; 
	std::cout<<"\n\n=============================================================";   
}

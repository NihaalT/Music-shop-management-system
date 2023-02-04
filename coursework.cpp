#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"product.h"

int main()
{
    int option;
    do
	{
    showMenu();
    std::cout<<"\nOption: ";
    std::cin>>option;
	Sleep(1000);
    system("cmd /c cls");
		switch (option){
			case 1: sellItem();
			Sleep(5000);
			break;

			case 2: save_product();
			Sleep(3000);
			break;

			case 3: restock();
			Sleep(3000);
			break;

			case 4: stockQuantity();
			Sleep(3000);
			break;

			case 5: displayALL();
			Sleep(3000);
			break;
			
			default: std::cout<<"exit";
		}
    }while(option!=6);
}
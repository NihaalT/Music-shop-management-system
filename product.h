#ifndef PRODUCTDB_PRODUCT_H
#define PRODUCTDB_PRODUCT_H
#include <iostream>
#include<fstream>
#include <windows.h>

class product
{
    int addChoice;
    int product_number,released, product_quantity;
	char product_name[50], artist[50];
	float product_price;
	int type;

    void showAddMenu();

	public:
 
	void create_product();
	
	void show_product();
	
	int getType();

	int getProduct();
	
	float getPrice();
	
	char* getName();

	char* getArtist();

	int getQuantity();
	
}; 

 
void save_product();

void displayItems();
 
void sellItem();

void restock();

void stockQuantity();

void displayALL();

void showMenu();

#endif

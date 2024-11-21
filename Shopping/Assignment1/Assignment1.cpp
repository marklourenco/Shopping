#include <iostream>
#include <string>
#include <string.h>

struct Customer {
	std::string name;
	std::string phoneNumber;
	std::string email;
};

struct Product {
	int id;
	char name[40];
	float price;
	struct Product* next;
};

struct Basket {
	std::string name;
	float finalPrice = 0;
};

struct Product* createProduct(int id, char name[40], float price) {
	struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
	newProduct->id = id;
	strcpy_s(newProduct->name, name);
	newProduct->price = price;
	newProduct->next = NULL;
	return newProduct;
}

void append(struct Product** head, int id, char name[40], float price) {
	struct Product* newProduct = createProduct(id, name, price);
	if (*head == NULL) {
		*head = newProduct;
		return;
	}
	struct Product* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newProduct;
}

void clearScreen() {
	system("cls");
}

int main() {

	// VALUES FOR IF PLAYER IS MEMBER/ADMIN OR NOT

	std::string membershipCode = "Y";
	std::string adminCode = "ADMIN";
	std::string enteredCode;
	int code;
	int productAmount = 0;
	int checkout = 1;
	int oneTime = 0;
	int cash;
	int adminChoose;
	int itemDelete;
	float discount;
	int id;
	float price;
	Customer customer;
	Basket basket;

	// Create an empty linked list

	struct Product* head = NULL;

	char productName[40];
	strcpy_s(productName, "Chips");
	append(&head, 1, productName, 4.99);
	productAmount++;
	struct Product* current = head;
	strcpy_s(productName, "Chicken");
	append(&head, 2, productName, 15.99);
	productAmount++;
	current = current->next;
	strcpy_s(productName, "Rice");
	append(&head, 3, productName, 11.99);
	productAmount++;
	current = current->next;

	// WELCOME SCREEN AND ASK PLAYERS IF THEY ARE MEMBER/ADMIN

	std::cout << "---------------------------\n   Welcome to the store!\n---------------------------\n\nAre you a registered member? Y/N (Or type ADMIN for admin menu)" << std::endl;

	// PLAYER INPUTS RESPONSE

	std::cin >> enteredCode;

	// TEST CODE TO SEE ANSWER

	std::cout << "" << enteredCode << std::endl;

	// DIFFERENT PATHS FOR DIFFERENT CHOICES

	if (enteredCode == "Y") {
		clearScreen();
		
		char confirmation;
		do {
			clearScreen();
			std::cout << "------------------------------------------------------\n         Please Enter Your Membership Details\n------------------------------------------------------\n\n";
			std::cout << "Insert Registered First Name: ";
			std::cin >> customer.name;
			std::cout << "Insert Registered Phone Number: ";
			std::cin >> customer.phoneNumber;
			std::cout << "Insert Registered eMail: ";
			std::cin >> customer.email;
			std::cout << "\nIs This Correct (Y/N):\n\n" << "Name: " << customer.name << "\nPhone Number: " << customer.phoneNumber << "\neMail: " << customer.email << std::endl;
			std::cin >> confirmation;
		} while (confirmation != 'Y');
		code = 0;
	}
	else if (enteredCode == adminCode) {
		code = 1;
	}
	else {
		code = 2;
	}

	struct Product* ptr = head;

	switch (code) {
	case 0:
		clearScreen();
		do {
			std::cout << "---------------------------\n  Welcome back, " << customer.name << "\n---------------------------\n\nPlease take a look at our products:" << std::endl;
			struct Product* ptr = head;
			for (int i = 0; i != productAmount; i++) {
				std::cout << "\n" << ptr->id << "\n" << ptr->name << "  $" << ptr->price << std::endl;
				ptr = ptr->next;
			}
			if (oneTime == 1) {
				struct Product* ptr = head;
				for (int i = 1; i != checkout; i++) {
					ptr = ptr->next;
				}
				basket.finalPrice = basket.finalPrice + ptr->price;
				std::cout << "\nOne " << ptr->name << " has been added!" << std::endl;
			}
			oneTime = 1;
			std::cout << "\nInsert ID number of what you would like to purchase. Else, insert 0 to pay." << std::endl;
			std::cin >> checkout;
			clearScreen();
		} while (checkout != 0);
		discount = .1 * basket.finalPrice;
		std::cout << "Your total is: $" << basket.finalPrice - discount << ". You saved $" << discount << " for being a member." << "\n\nPlease enter how much cash you have: " << std::endl;
		do {
			std::cin >> cash;
			if (cash > (basket.finalPrice - discount)) {
				std::cout << "Your change is: " << cash - (basket.finalPrice - discount) << "\n\nThank you for shopping with us. Goodnight!" << std::endl;
			}
			else {
				std::cout << "That is not enough. Please input an amount higher than the total balance." << std::endl;
			}
		} while (cash < basket.finalPrice);
		break;
	case 1:
		do {
			clearScreen();
			std::cout << "---------------------------\n  Welcome! Product list: " << customer.name << "\n---------------------------" << std::endl;
				
				struct Product* ptr = head;
			for (int i = 0; i != productAmount; i++) {
				ptr->id = i+1;
				std::cout << "\n" << ptr->id << "\n" << ptr->name << "  $" << ptr->price << std::endl;
				ptr = ptr->next;
			}
			std::cout << "\n1. Add an item\n2. Update an item\n3. Remove an item\n4. Shop\n" << std::endl;
			std::cin >> adminChoose;
			if (adminChoose == 1) {
				clearScreen();
				std::cout << "What product would you like to add?\n\nName: \n";
				scanf_s(" %s", &productName, 40);
				std::cout << "Price:\n";
				std::cin >> price;
				append(&head, 0, productName, price);

				current = current->next;
				productAmount++;
			}
			else if (adminChoose == 2) {
				Product* temp = head;
				std::cout << "\nWhich product would you like to update? (ID)\n";
				std::cin >> itemDelete;
				for (int i = 1; i != itemDelete; i++) {
					temp = temp->next;
				}
				std::cout << "\nNew Product Name: \n";
				scanf_s(" %s", &productName, 40);
				strcpy_s(temp->name, productName);
				std::cout << "New Product Price:\n";
				std::cin >> price;
				temp->price = price;
			}
			else if (adminChoose == 3) {
				Product* temp = head;
				Product* temp2 = head;
				std::cout << "\nWhich product would you like to remove? (PLACE ON THE LIST, NOT ID)\n";
				std::cin >> itemDelete;
				printf("\n");
				if (itemDelete == 1) {
					temp2 = temp2->next;
					temp = temp;
				}
				for (int l = 0; l < itemDelete - 1; l++) {
					temp2 = temp2->next;
				}
				for (int l = 0; l < itemDelete - 2; l++) {
					temp = temp->next;
				}
				temp->next = temp2->next;
				free(temp2);
				productAmount--;
			}
			else if (adminChoose == 4) {
				clearScreen();
				do {
					std::cout << "---------------------------\n  Welcome back ADMIN " << customer.name << "\n---------------------------\n\nPlease take a look at our products:" << std::endl;
					struct Product* ptr = head;
					for (int i = 0; i != productAmount; i++) {
						ptr->id = i + 1;
						std::cout << "\n" << ptr->id << "\n" << ptr->name << "  $" << ptr->price << std::endl;
						ptr = ptr->next;
					}
					if (oneTime == 1) {
						struct Product* ptr = head;
						for (int i = 1; i != checkout; i++) {
							ptr = ptr->next;
						}
						basket.finalPrice = basket.finalPrice + ptr->price;
						std::cout << "\nOne " << ptr->name << " has been added!" << std::endl;
					}
					oneTime = 1;
					std::cout << "\nInsert ID number of what you would like to purchase. Else, insert 0 to pay." << std::endl;
					std::cin >> checkout;
					clearScreen();
				} while (checkout != 0);
				discount = .1 * basket.finalPrice;
				std::cout << "Your total is: $" << basket.finalPrice - discount << ". You saved $" << discount << " for being a member." << "\n\nPlease enter how much cash you have: " << std::endl;
				do {
					std::cin >> cash;
					if (cash > (basket.finalPrice - discount)) {
						std::cout << "Your change is: " << cash - (basket.finalPrice - discount) << "\n\nThank you for shopping with us. Goodnight!" << std::endl;
						terminate();
						break;
					}
					else {
						std::cout << "That is not enough. Please input an amount higher than the total balance." << std::endl;
					}
				} while (cash < basket.finalPrice);
				break;

			}
		} while (adminChoose != 4);
	case 2:
		clearScreen();
		do {
			std::cout << "---------------------------\n  Welcome! " << customer.name << "\n---------------------------\n\nPlease take a look at our products:" << std::endl;
			struct Product* ptr = head;
			for (int i = 0; i != productAmount; i++) {
				std::cout << "\n" << ptr->id << "\n" << ptr->name << "  $" << ptr->price << std::endl;
				ptr = ptr->next;
			}
			if (oneTime == 1) {
				struct Product* ptr = head;
				for (int i = 1; i != checkout; i++) {
					ptr = ptr->next;
				}
				basket.finalPrice = basket.finalPrice + ptr->price;
				std::cout << "\nOne " << ptr->name << " has been added!" << std::endl;
			}
			oneTime = 1;
			std::cout << "\nInsert ID number of what you would like to purchase. Else, insert 0 to pay." << std::endl;
			std::cin >> checkout;
			clearScreen();
		} while (checkout != 0);
		std::cout << "Your total is: $" << basket.finalPrice << "\n\nPlease enter how much cash you have: " << std::endl;
		do {
			std::cin >> cash;
			if (cash > basket.finalPrice) {
				std::cout << "Your change is: " << cash - basket.finalPrice << "\n\nThank you for shopping with us. Goodnight!" << std::endl;
			}
			else {
				std::cout << "That is not enough. Please input an amount higher than the total balance." << std::endl;
			}
		} while (cash < basket.finalPrice);
		break;
	}
}
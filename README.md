# Shopping System in C++

This is a simple console-based shopping system written in C++ which simulates an online store. The program allows users to interact with the store in different ways, including purchasing items, managing products, and more. It also has distinct modes for customers and administrators.

## Features

- **Customer Interaction**: 
  - Registered members can log in with their details.
  - The system displays available products and allows the customer to add items to their basket, apply discounts, and pay for their purchases.
  
- **Admin Functionality**: 
  - Admin users can add, update, and remove products from the store.
  - Admins can also view and manage customer purchases.

- **Product Management**: 
  - Products are stored in a linked list, and users can interact with the product catalog dynamically.

- **Discounts**: 
  - Registered members receive a 10% discount on their purchases.

## How to Run

1. **Clone the repository**:
   ```
   git clone https://github.com/yourusername/shopping-system.git
   ```

2. **Compile the Code**:
   Make sure you have a C++ compiler installed (e.g., g++, Visual Studio, etc.). You can compile the program using:
   ```
   g++ -o shopping_system shopping_system.cpp
   ```

3. **Run the Program**:
   Execute the compiled program:
   ```
   ./shopping_system
   ```

## Code Overview

The code includes the following key structures and functions:

### Structures

1. **Customer**: 
   - Stores customer details such as name, phone number, and email.

2. **Product**: 
   - Represents a product with an ID, name, price, and a pointer to the next product in the linked list.

3. **Basket**: 
   - Stores the name and the final price of the basket (customer's cart).

### Functions

- **createProduct**: 
   - Creates a new product and returns a pointer to it.

- **append**: 
   - Adds a new product to the end of the linked list of products.

- **clearScreen**: 
   - Clears the console screen for better readability.

### Main Logic

1. **User Types**: 
   - The program checks whether the user is a member, admin, or a regular customer. It takes different actions based on the type of user.

2. **Admin Mode**: 
   - Admin users can manage products (add, update, or remove products).

3. **Customer Mode**: 
   - Customers can view available products, add items to their basket, and pay for their purchases. Members receive a discount.

## Code Flow

- The program starts by greeting the user and asking if they are a registered member or an admin.
- Based on the user input, the program either allows the customer to interact with products or gives admin privileges.
- Customers can purchase products, and admins can modify the product catalog.
  
## Example Interaction

```
---------------------------
   Welcome to the store!
---------------------------

Are you a registered member? Y/N (Or type ADMIN for admin menu)
Y
------------------------------------------------------
         Please Enter Your Membership Details
------------------------------------------------------

Insert Registered First Name: Mark
Insert Registered Phone Number: 123456789
Insert Registered eMail: markip@gmail.com

Is This Correct (Y/N):
Name: Mark
Phone Number: 123456789
eMail: markip@gmail.com
Y

---------------------------
  Welcome back, Mark
---------------------------

Please take a look at our products:

1
Chips  $4.99
2
Chicken  $15.99
3
Rice  $11.99

Insert ID number of what you would like to purchase. Else, insert 0 to pay.
2
One Chicken has been added!

Insert ID number of what you would like to purchase. Else, insert 0 to pay.
0
Your total is: $15.99. You saved $1.599999 for being a member.

Please enter how much cash you have:
20
Your change is: 3.0

Thank you for shopping with us. Goodnight!
```

## Improvements & Future Work

- **Product Persistence**: 
  - Currently, the product list is not saved between program runs. Future improvements could include saving and loading products from a file.

- **Improved User Interface**: 
  - The user interface can be enhanced with more advanced features, like graphical interfaces (GUI) or web-based interfaces.

- **Error Handling**: 
  - Better error handling can be implemented for invalid inputs.

## License

This project is licensed under the MIT License.

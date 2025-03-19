/*create a structure for address:
street
city
zipCode
nested the address structure within customer
create and initialize a customer object

 

Note: user validation is a must*/

using namespace std;
#include <string>
#include <iostream>
#include <random>

struct Address {
	string street;
	string city;
	string zipCode;
};
struct Customer {
	string name;
	string email;
	string phoneNumber;
	int customerID;
	Address address;
};

string getValidString(const string& prompt) {
	string input;
	do {
		cout << prompt;
		getline(cin, input);
		if (input.empty()) {
			cout << "Input cannot be empty.\n";
		}
	} while (input.empty());
		return input;
}

string getValidPhone() {
	string phone;
	do {
		cout << "Enter phone number (digits only): ";
		getline(cin, phone);
		bool valid = !phone.empty() && all_of(phone.begin(), phone.end(), ::isdigit) && (phone.size()==7 || phone.size()==10);
		if (!valid) {
			cout << "Invalid phone number. Enter digits only.\n";
		}
		else {
			return phone;
		}
	} while (true);
}

string getValidZIP() {
	string zip;
	do {
		cout << "Enter ZIP code (5 digits): ";
		getline(cin, zip);
		if (zip.length() == 5 && all_of(zip.begin(), zip.end(), ::isdigit)) {
			return zip;
		}
		cout << "Invalid ZIP code. Enter 5 digit zip only.\n";
	} while (true);
}

void getCustomerInput(Customer& cust) {
	cust.name = getValidString("Enter customer name: ");
	cust.email = getValidString("Enter email: ");
	cust.phoneNumber = getValidPhone();

	cust.customerID = rand() % 1000 + 1000;

	cust.address.street = getValidString("Enter street address: ");
	cust.address.city = getValidString("Enter city: ");
	cust.address.zipCode = getValidZIP();
}

void printCustomer(const Customer& cust) {
	cout << "Customer Details:\n"
		<< "Name: " << cust.name << '\n'
		<< "Email: " << cust.email << '\n'
		<< "Phone: " << cust.phoneNumber << '\n'
		<< "Customer ID: " << cust.customerID << '\n'
		<< "Address: " << cust.address.street << ", " << cust.address.city << ", " << cust.address.zipCode << '\n';
}

int main() {

	Customer cust;
	getCustomerInput(cust);
	printCustomer(cust);

	return 0;
}
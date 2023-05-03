/*===================================================
PROGRAMMING TECHINQUE II                            =
E-COMMERCE (ONLINE SHOPPING MANAGEMENT) PROJECT     =
GROUP MEMBERS:                                      =
MD MONIRUL ISLAM MOLLA          A19EC4013           =
MD ABU SALEH NAYEEM             A19EC4012           =
TASNIA HOUQE NIDHI              A18CS9010           =
====================================================*/

//All header files

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

/*================================================================ << Address Class>> ==========================================================*/

class Address //this class aggregated by Register class
{
private: //Private Attributes
    string block;
    string houseName;
    string city;
    string zip;

public:                                                                 //Public Member functions
    Address(string b = "", string h = "", string c = "", string z = "") //Constructor
    {
        block = b;
        houseName = h;
        city = c;
        zip = z;
    }
    void SetAddress() // mutator or set function
    {
        cout << "ENTER YOUR BlOCK NO    : ";
        cin >> block;
        cin.ignore();
        cout << "ENTER YOUR HOUSE NAME  : ";
        getline(cin, houseName);
        cout << "ENTER YOUR CITY NAME   : ";
        getline(cin, city);
        cout << "ENTER YOUR POST CODE   : ";
        cin >> zip;
    }

    string getFullAddress() //accessors or get function
    {
        return block + ", " + houseName + ", " + city + ", " + zip + ".";
    }
};

/*================================================================ << Register Class>> ==========================================================*/

class Register //contain Aggregation method
{
private:
    string fullName;
    string gender;
    string phoneNo;
    string email;
    Address *address; //Aggregation
    string username;
    string password;
    string retrive_un;
    string retrive_pw;
    string Readdress = " ";

public:
    Register(); //default Constructor
    void setFullName()
    {
        cout << "ENTER YOUR FULL NAME   : ";
        cin.ignore();
        getline(cin, fullName);
    }
    string getfullName()
    {
        return fullName;
    }
    void setGender() //in-line member functions
    {
    A:
        cout << "ARE YOU Male or Female : ";
        cin >> gender;
        if ((gender == "Male") || (gender == "male") || (gender == "Female") || (gender == "female"))
        {
        }
        else
        {
            cout << "Input Error! Please try again.\n";
            goto A;
        }
    }
    string getGender()
    {
        return gender;
    }
    void setPhoneNo()
    {
        cout << "ENTER YOUR PHONE NO    : ";
        cin >> phoneNo;
    }
    string getPhoneNo()
    {
        return phoneNo;
    }
    void setEmail()
    {
        cout << "ENTER YOUR EMAIL ADRS. : ";
        cin.ignore();
        getline(cin, email);
    }
    string getEmail()
    {
        return email;
    }
    void setAddress()
    {
        address->SetAddress();
    }
    string getAddress()
    {
        return address->getFullAddress();
    }
    string getReAddress()
    {
        return Readdress;
    }

    void enter();                   //Asks for registration of people
    void DoRegistration();          // user registration form
    void DoLogin();                 //this function ask and verified id pass for user login
    ~Register() { delete address; } //destructor
};

Register::Register() //outsider member function
{
    username = password = retrive_un = retrive_pw = "";
    address = new Address;
}

void Register::enter()
{
    int choice;
    cout << endl
         << "\t(1). REGISTRATION \n"
         << "\t(2). LOG-IN\n"
         << "\tChoose an option- ";
    cin >> choice;
    std::system("cls");
    if (choice == 1)
    {
        DoRegistration();
    }
    if (choice == 2)
    {
        DoLogin();
    }
    else
    {
        DoLogin();
    }
}

void Register::DoRegistration()
{
    cout << "-------------------------------------------------" << endl
         << "|            ACCOUNT REGISTRATION               |" << endl
         << "-------------------------------------------------" << endl
         << endl
         << endl;
    setFullName();
    setGender();
    setPhoneNo();
    setEmail();
    address->SetAddress();
    cout << endl
         << endl;
    cout << "\tENTER ANY USER NAME : ";
    cin >> username;
    cout << "\tENTER ANY PASSWORD  : ";
    cin >> password;
    ofstream file;
    file.open("userinfo.txt", ios::binary);
    file << username << endl;
    file << password << endl;
    file << getfullName() << endl;
    file << getGender() << endl;
    file << getPhoneNo() << endl;
    file << getEmail() << endl;
    file << getAddress() << endl;

    file.close();
    int choice;
    cout << "\nDEAR SIR, YOUR REGISTRATION SUCCESSFUL!!" << endl;
B:
    cout << "\nPlease choose what you would like to do."
         << "\n\t(1) LOG IN"
         << "\n\t(2) EXIT"
         << "\n\tChoose an option-";
    cin >> choice;
    if (choice == 1)
    {
    }

    else if (choice == 2)
    {
        exit(0);
    }

    else
    {
        cout << "\n Input Error !\n";
        goto B;
    }
}

void Register::DoLogin()
{
    std::system("cls");
    cout << "-------------------------------------------------" << endl
         << "|                 USER LOG IN                   |" << endl
         << "-------------------------------------------------" << endl
         << endl
         << endl;
    cout << "\tENTER YOUR USER NAME : ";
    cin >> username;
    cout << "\tENTER YOUR PASSWORD  : ";
    cin >> password;

    ifstream read("userinfo.txt", ios::binary);
    getline(read, retrive_un);
    getline(read, retrive_pw);

    try //Exception Handling
    {
        if (retrive_un == username && retrive_pw == password)
        {

            cout << endl
                 << "Congratulations! login Successful..." << endl
                 << endl;
            getline(read, fullName);
            getline(read, gender);
            getline(read, phoneNo);
            getline(read, email);
            getline(read, Readdress);
        }
        else
        {
            throw 0;
        }
    }

    catch (...) //Exception Handling
    {
        cout << endl
             << "Sorry! login unsuccessful(try  again)" << endl;
        DoLogin();
    }
}

/*================================================================ << Product Class>> ==========================================================*/

class Product
{
private:
    string productID;
    string productName;
    double productPrice;

public:
    Product(string ID = "", string Name = "", double Price = 0.0)
    {
        productID = ID;
        productName = Name;
        productPrice = Price;
    }

    void setID(string i)
    {
        productID = i;
    }

    void setNAME(string n)
    {
        productName = n;
    }

    void setPRICE(double p)
    {
        productPrice = p;
    }

    virtual string getID()
    {
        return productID;
    }

    string getNAME()
    {
        return productName;
    }

    double getPRICE()
    {
        return productPrice;
    }

    void displayProduct()
    {

        cout << setw(10) << productID << setw(20) << productName << setw(20) << productPrice << endl;
    }
};

/*================================================================ << ProductList Class>> ==========================================================*/

class ProductList //contain composition task (product class)
{
private:
    vector<Product> productList;

public:
    void products(vector<Product> &p)
    {
        productList = p;
    }

    void displayProductList()
    {
        cout << setw(15) << "ProductID" << setw(17) << "ProductName" << setw(20) << "ProductPrice\n";
        for (int i = 0; i < productList.size(); i++)
        {
            productList[i].displayProduct();
        }
    }
    virtual void addProduct(string i, string n, double p)
    {
        productList.emplace_back(i, n, p);
    }

    void removeProduct(string r)
    {
        int RE;
        for (int i = 0; i < productList.size(); i++)
        {
            if (productList[i].getID() == r)
            {
                RE = i;
            }
        }
        productList.erase(productList.begin() + RE);
    }
};

/*============================================================== << Administrator Class>> ==========================================================*/

class Administrator : public Register, public ProductList //Inheritance Method:
                                                          // Register & ProductList class inherited by class Administrator
                                                          //Contain Polymorphisms
{
private:
    string adminID;

public:
    Administrator() {}

    void setID()
    {

    A:
        cout << "ENTER YOUR STAFF ID-NO (DEFAULT:123456): ";
        cin >> adminID;

        if ((adminID == "123456") || (adminID == "223456") || (adminID == "323456") || (adminID == "423456") || (adminID == "23456"))
        {
        }

        else
        {
            cout << "\nInput Error! Please try again.\nIf you don't have staff ID, contact our office. \n";
            goto A;
        }
    }

    virtual string getID() //Polymorphism function
    {
        return adminID;
    }
    void setAdminDetails()
    {
        setID();
        Register::enter();
    }

    virtual void addProduct() //Polymorphisms function

    {
        int count;
        cout << "\nADD PRODUCTS: \n"
             << "How many products do you want to add? : ";
        cin >> count;

        for (int i = 0; i < count; i++)
        {

            string id, name;
            double price;
            cout << "#" << i + 1 << endl
                 << " Give product ID   : ";
            cin >> id;
            cout << " Give product name : ";
            cin >> name;
            cout << " Give product price: ";
            cin >> price;
            ProductList::addProduct(id, name, price);
        }
        cout << endl;
    }

    void removeProduct()
    {
        int count;
        string id;
        std::system("cls");
        cout << "\nREMOVE PRODUCT: \n"
             << "HOW MANY PRODUCTS YOU WANT TO REMOVE ? : ";
        cin >> count;

        for (int i = 0; i < count; i++)
        {
            ProductList::displayProductList();

            cout << "Mention Product id: ";
            cin >> id;
            ProductList::removeProduct(id);
            cout << endl;
        }
    }
};

/*============================================================== << ShoppingCart Class>> ==========================================================*/

class ShoppingCart //only inherited by Customer class
{
protected:
    vector<Product> SelectedProduct; //Product class composition:aggregation by ShoppingCart Class
    double TotalPrice = 0.0;
    string id = "";
    string name;
    int ADD;

public:
    ShoppingCart()
    {
    }

    void CalcTotalPrice()
    {
        for (int i = 0; i < SelectedProduct.size(); i++)
        {
            TotalPrice += SelectedProduct[i].getPRICE();
        }
    }
    double getTotalPrice()
    {
        return TotalPrice;
    }

    int getTotalQuantity()
    {

        return SelectedProduct.size();
    }

    void addSelecetedProduct(vector<Product> p)
    {
        int count;
        cout << "\n\nADD TO SHOPPING CART \n"
             << "HOW MANY PRODUCTS YOU WANT TO PURCHASE?  : ";
        cin >> count;

        for (int i = 0; i < count; i++)
        {
            cout << "#" << i + 1 << endl
                 << " WRITE PRODUCT ID: ";
            cin >> id;

            for (int j = 0; j < p.size(); j++)
            {
                if (p[j].getID() == id)
                {
                    ADD = j;
                }
            }
            SelectedProduct.emplace_back(p[ADD].getID(), p[ADD].getNAME(), p[ADD].getPRICE());
        }
        cout << endl;
    }

    void removeProduct()
    {
        int count;
        string id;

        cout << " WRITE PRODUCT ID: ";
        cin >> id;

        int RE;
        for (int i = 0; i < SelectedProduct.size(); i++)
        {
            if (SelectedProduct[i].getID() == id)
            {
                RE = i;
            }
        }
        SelectedProduct.erase(SelectedProduct.begin() + RE);

        cout << endl;
    }

    void displaySelectedProduct()
    {
        std::system("cls");
        cout << "-------------------------------------------------" << endl
             << "|                  MY SHOPPING CART             |" << endl
             << "-------------------------------------------------" << endl
             << endl
             << endl;
        cout << setw(15) << "PRODUCT-ID" << setw(17) << "PRODUCT-NAME" << setw(20) << "PRODUCT-PRICE\n";
        for (int i = 0; i < SelectedProduct.size(); i++)
        {
            SelectedProduct[i].displayProduct();
        }
        cout << endl;
    }
};

/*============================================================== << Payment Class>> ==========================================================*/

class Payment //composition class
{
private:
    double PayNetAmmount;
    string cardNumber, digit;
    int pinNumber, payment;
    string ibankUserId, ibankingPassword;

public:
    Payment()
    {
    }

    Payment(double PayNetAmmount, string cardNumber, int pinNumber, string ibankUserId, string ibankingPassword)
    {
        this->PayNetAmmount = PayNetAmmount;
        this->cardNumber = cardNumber;
        this->pinNumber = pinNumber;
        this->ibankUserId = ibankUserId;
        this->ibankingPassword = ibankingPassword;
    }

    void setPayNetAmmount(double PayNetAmmount)
    {
        this->PayNetAmmount = PayNetAmmount;
    }

    void setCardNumber(string cardNumber)
    {
        this->cardNumber = cardNumber;
    }

    void setPinNumber(int pinNumber)
    {
        this->pinNumber = pinNumber;
    }

    void setIbankUserId(string ibankUserId)
    {
        this->ibankUserId = ibankUserId;
    }

    void setIbankingPassword(string ibankingPassword)
    {
        this->ibankingPassword = ibankingPassword;
    }

    double getPayNetAmmount()
    {
        return PayNetAmmount;
    }

    string getCardNumber()
    {
        return cardNumber;
    }

    int getPinNumber()
    {
        return pinNumber;
    }
    int getpayment()
    {
        return payment;
    }

    string getIbankUserId()
    {
        return ibankUserId;
    }

    string getIbankingPassword()
    {
        return ibankingPassword;
    }
    string getdigit()
    {
        return digit;
    }

    void paymentpreference()
    {

    A:
        cout << "-----------------------------------------------" << endl
             << "|      PLEASE CHOOSE ANY PAYMENT GATEWAY:     |" << endl
             << "-----------------------------------------------" << endl
             << "\t(1) DEBT/CREDIT CARD" << endl
             << "\t(2) ON-LINE BANKING" << endl
             << "\tChoose any option-";
        cin >> payment;
        std::system("cls");

        switch (payment)
        {
        case 1:

            cout << "-----------------------------------------------" << endl
                 << "|           DEBT/CREDIT CARD PAYMENT          |" << endl
                 << "-----------------------------------------------" << endl
                 << endl;

            cout << "   ENTER YOUR CARD NO : ";
            cin >> cardNumber;
            cout << "   ENTER YOUR PIN  NO : ";
            cin >> pinNumber;
            cout << "\nNET-AMOUNT: " << PayNetAmmount << "RM.CARD NO: ************";
            for (int i = (cardNumber.length() - 4.0); i <= cardNumber.length(); i++)
            {
                digit += cardNumber[i];
            }
            cout << digit << " \n";
            cout << "RM " << PayNetAmmount << " HAS BEEN DEDUCTED FROM YOUR ACCOUNT.\n\n\n";
            cout << "----------------------------------------------" << endl
                 << "|              [PAYMENT SUCCESSFUL]          |" << endl
                 << "----------------------------------------------" << endl
                 << endl
                 << endl;
            cout << "FOR RECIEPT,";
            std::system("pause");
            std::system("cls");
            break;

        case 2:

            cout << "----------------------------------------------" << endl
                 << "|           ONLINE BANKING PAYMENT           |" << endl
                 << "----------------------------------------------" << endl
                 << endl;
            cout << "   ENTER YOUR ON-lINE BANKING ID : ";
            cin >> ibankUserId;
            cout << "   ENTER YOUR PASSWORD           : ";
            cin >> ibankingPassword;
            cout << "\nRM " << PayNetAmmount << " HAS BEEN DEDUCTED FROM YOUR ACCOUNT.\n\n\n";
            cout << "----------------------------------------------" << endl
                 << "|              [PAYMENT SUCCESSFUL]          |" << endl
                 << "----------------------------------------------" << endl
                 << endl
                 << endl;
            cout << "FOR RECIEPT,";
            std::system("pause");
            std::system("cls");
            break;

        default:
            goto A;
            cout << "\n Input Error! \n";
        }
    }
};

/*============================================================== << Customer Class>> ==========================================================*/

class Customer : public Register, public ShoppingCart //Inheritance Method: Register & ShoppingCart class inherited by class Customer
{
private:
    Payment payment; //Composition method
    int count;

public:
    Customer()
    {
    }
    void setCustomerDetails()
    {
        Register::enter();
    }

    void print()
    {
        time_t now = time(0);
        char *dt = ctime(&now);
        std::system("cls");
        cout << "***************************************************************" << endl
             << "|                        CUSTOMER INVOICE                     |" << endl
             << "***************************************************************" << endl
             << "             E-COMMERCE SHOPPING MANAGEMENT SYSTEM      " << endl
             << "                             UTM JB          \n"
             << "                        Taman Universiti,     \n"
             << "                   813000, Johor, Johor Bahru.\n"
             << "---------------------------------------------------------------" << endl
             << endl;

        for (int i = 0; i < 1; i++)
        {
            int value = rand();
            cout << "Transaction Number       : XX783RGFH" << value << "\n";
        }

        cout << "Date and Time is         : " << dt << endl;
        cout << "Customer Name            : " << Register::getfullName() << endl
             << "Customer Gender          : " << Register::getGender() << endl
             << "Customer Contact Number  : " << Register::getPhoneNo() << endl
             << "Customer Email           : " << Register::getEmail() << endl
             << "Shipping Address         : " << Register::getReAddress() << endl
             << endl
             << setw(15) << "PRODUCT-ID" << setw(17) << "PRODUCT-NAME" << setw(20) << "PRODUCT-PRICE\n";

        for (int i = 0; i < SelectedProduct.size(); i++)
        {
            cout << setw(10) << ShoppingCart::SelectedProduct[i].getID() << setw(20)
                 << ShoppingCart::SelectedProduct[i].getNAME() << setw(20)
                 << ShoppingCart::SelectedProduct[i].getPRICE() << endl;
        }
        cout << "\nTotal Item             :  " << ShoppingCart::getTotalQuantity() << endl
             << "Total Cost             :  " << ShoppingCart::getTotalPrice() << " RM" << endl
             << endl;
        if (payment.getpayment() == 1)
        {
            cout << "Card Payment : " << ShoppingCart::getTotalPrice() << endl
                 << "Card digit   : ************";
            cout << payment.getdigit();
            cout << " \n\n";
        }
        else
        {
            cout << "Your On-line Banking ID 	 : ";
            cout << payment.getIbankUserId() << endl;
            cout << "RM" << ShoppingCart::getTotalPrice() << " has been deducted from your account.\n\n";
        }

        cout << " \n\n***************************************************************" << endl
             << endl
             << "                 Exchange & Refund May be Allowed  \n"
             << "           Within 3 Days With the Original Tax Invoice  \n"
             << "                     THANKS FOR YOUR PATIENCE.    \n";
    }

    void ShoppingCartdetails(vector<Product> p)
    {
        ShoppingCart::addSelecetedProduct(p);
        ShoppingCart::displaySelectedProduct();

        cout << " Do you want to remove any product?\n"
             << "    (1).Yes \n"
             << "    (2).No \n"
             << "    Choose an option-";
        cin >> count;
        if (count == 1)
        {
            ShoppingCart::removeProduct();
        }

        ShoppingCart::displaySelectedProduct();
        ShoppingCart::CalcTotalPrice();
        cout << "\nTotal Item             :  " << ShoppingCart::getTotalQuantity() << endl
             << "Total Cost             :  " << ShoppingCart::getTotalPrice() << " RM" << endl
             << endl;
    }

    void PaymentWork()
    {

        payment.setPayNetAmmount(ShoppingCart::getTotalPrice());
        payment.paymentpreference();
    }

    void Receipt() //This receipt function generated an auto receipt for customer.
                   //and this receipt store in a text file for each and every customer.
    {
        time_t now = time(0);
        char *dt = ctime(&now);

        ofstream outfile("receipt.txt"); //generate an auto text file in the folder by using "ofstream" function

        outfile << "***************************************************************" << endl
                << "|                        CUSTOMER INVOICE                     |" << endl
                << "***************************************************************" << endl
                << "             E-COMMERCE SHOPPING MANAGEMENT SYSTEM      " << endl
                << "                             UTM JB          \n"
                << "                        Taman Universiti,     \n"
                << "                   813000, Johor, Johor Bahru.\n"
                << "---------------------------------------------------------------" << endl
                << endl;

        if (outfile.is_open())
        {
            for (int i = 0; i < 1; i++)
            {
                int value = rand();
                outfile << "Transaction Number       : XX783RGFH" << value << "\n";
            }
        }
        outfile << "Date and Time is         : " << dt << endl;

        outfile << "Customer Name            : " << Register::getfullName() << endl
                << "Customer Gender          : " << Register::getGender() << endl
                << "Customer Contact Number  : " << Register::getPhoneNo() << endl
                << "Customer Email           : " << Register::getEmail() << endl
                << "Shipping Address         : " << Register::getReAddress() << endl
                << endl

                << setw(15) << "ProductID" << setw(17) << "ProductName" << setw(20) << "ProductPrice\n";

        for (int i = 0; i < SelectedProduct.size(); i++)
        {
            outfile << setw(10) << ShoppingCart::SelectedProduct[i].getID() << setw(20)
                    << ShoppingCart::SelectedProduct[i].getNAME() << setw(20)
                    << ShoppingCart::SelectedProduct[i].getPRICE() << endl;
        }

        outfile << "\nTotal Item             :  " << ShoppingCart::getTotalQuantity() << endl
                << "Total Cost             :  " << ShoppingCart::getTotalPrice() << " RM" << endl
                << endl;
        if (payment.getpayment() == 1)
        {
            outfile << "Card Payment : " << ShoppingCart::getTotalPrice() << endl
                    << "Card digit   : ************" << payment.getdigit() << " \n\n";
        }
        else
        {
            outfile << "Your On-line Banking ID 	 : ";
            outfile << payment.getIbankUserId() << endl;
            outfile << "RM" << ShoppingCart::getTotalPrice() << " has been deducted from your account.\n\n";
        }
        outfile << " \n\n***************************************************************" << endl
                << endl
                << "                 Exchange & Refund May be Allowed  \n"
                << "           Within 3 Days With the Original Tax Invoice  \n"
                << "                     THANKS FOR YOUR PATIENCE.    \n";
        outfile.close();
    }
};

/*============================================================== << main Class>> ==========================================================*/

int main() //This is our main class
{
    Administrator admin; //create an object for Administrator
    Customer customer;   //create an object for Customer
    ProductList plist;   //create an object for ProductList

    vector<Product> product(10); //For displaying our sample product we were using vector function
    product[0] = Product("11", "Shirt", 130.50);
    product[1] = Product("12", "jeans", 200.30);
    product[2] = Product("13", "Mobile", 4500.00);
    product[3] = Product("14", "Keyboard", 72.70);
    product[4] = Product("15", "Mouse", 55.90);
    product[5] = Product("16", "Body Spray", 28.80);
    product[6] = Product("17", "facewash", 18.50);
    product[7] = Product("18", "Headphone", 89.50);
    product[8] = Product("19", "Watch", 350.00);
    product[9] = Product("20", "Belt", 32.50);

    admin.products(product); //After add or remove any products by Admin this program will atomically update.
    std::system("cls");
    cout << "**************************************************" << endl
         << "|     WELCOME TO E-SHOPPING MANAGEMENT SYSTEM!   |" << endl
         << "**************************************************" << endl
         << endl;

    int choice;

A:
    cout << "\nDEAR USER, YOU WANT TO REGISTER/LOG IN AS A:\n\n"
         << "  \t(1). Administrator \n"
         << "  \t(2). Customer\n"
         << "  \t(3). Exit  \n\n"
         << "PLEASE CHOOSE AN OPTION- ";
    cin >> choice;
    std::system("cls");
    if (choice == 1)
    {
        cout << "-------------------------------------------------" << endl
             << "|     DEAR ADMIN, WE GIVE YOU A WARM ^_^        |" << endl
             << "-------------------------------------------------" << endl
             << endl
             << endl;
        admin.setAdminDetails(); //call for Admin Registration by filling up all information
        std::system("cls");
        cout << "-------------------------------------------------" << endl
             << "|               PRODUCTS AVAILABLE              |" << endl
             << "-------------------------------------------------" << endl
             << endl
             << endl;
        admin.displayProductList(); //only Admin can access/see the current stock
    C:
        cout << "\n  Dear Admin,\n"
             << "      (1). Add Product \n"
             << "      (2). Remove Product  \n"
             << "      (3). Logout \n"
             << "      (4). Exit  \n"
             << "      Choose an option- ";
        cin >> choice;
        if (choice == 1)
        {
            admin.addProduct(); //only Admin can add more products in current stock
            std::system("cls");
            cout << "-------------------------------------------------" << endl
                 << "|               CURRENT STOCK                   |" << endl
                 << "-------------------------------------------------" << endl
                 << endl;
            admin.displayProductList();
            goto C;
        }

        else if (choice == 2)
        {
            admin.removeProduct(); //only Admin can remove more products in current stock
            std::system("cls");
            cout << "-------------------------------------------------" << endl
                 << "|               CURRENT STOCK                   |" << endl
                 << "-------------------------------------------------" << endl
                 << endl;
            admin.displayProductList(); //final available stock
            goto C;
        }
        else if (choice == 3)
        {
            std::system("cls");
            goto A;
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            cout << "\n Input Error 0_0  !\n";
            goto C;
        }
    }

    if (choice == 2)
    {
        cout << "-------------------------------------------------" << endl
             << "|     DEAR CUSTOMER, WE GIVE YOU A WARM ^_^     |" << endl
             << "-------------------------------------------------" << endl
             << endl
             << endl;
        customer.setCustomerDetails(); //call for Customer Registration by filling up all information

        std::system("cls");
        cout << "**************************************************" << endl
             << "|     WELCOME TO E-SHOPPING MANAGEMENT SYSTEM!   |" << endl
             << "**************************************************" << endl
             << endl
             << endl;
        admin.displayProductList(); //After successful login Customer can visit all available products

        customer.ShoppingCartdetails(product); //Customer Added desirable products on my shopping cart, Customer can also
                                               //remove product from his shopping cart before proceeding payment
        customer.PaymentWork();                //customer object call the paymentWork function for complete the payment before placing order

        customer.Receipt(); //An automated receipt will be generated for customer and mentioning the the details
                            //as well as current time and date

        customer.print(); //Also Customer can see the final output in the screen of our management system
    }

    return 0;
    getch();
}

//Freddy & Tyler Project 1 
//CST126 Project 1 

#include <iostream>
#include <string>

using namespace std;

class Stock
{
public:
    string name;
    string symbol;
    float price;

    void get_info();

    void info()
    {
        std::cout << "Stock name: " << name << std::endl;
        std::cout << "Stock symbol: " << symbol << std::endl;
        std::cout << "Stock price: $" << price << std::endl;
        std::cout << "======================================" << std::endl;
    }
};


void Stock::get_info()
{
    std::cout << "Enter the name of the stock: ";
    std::cin >> name;
    std::cout << "Enter the symbol of the stock: ";
    std::cin >> symbol;
    std::cout << "Enter the price of the stock: ";
    std::cin >> price;
}


/*
void convert_case(Stock* arr, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        std::for_each(arr[i].name.begin(), arr[i].name.end(), [](char &c){
            c = ::tolower(c);
        });
    }
}
*/


void build_list(Stock* arr, int n)
{
    int i;
    Stock sto;
    for (i = 0; i < n; i++)
    {
        sto.get_info();
        arr[i] = sto;
    }
}


Stock* remove(Stock* &arr, int &n)
{
    //return an array with a user specified stock removed.
    
    int i;
    string srch;
    auto *final_arr = new Stock [n-1]; //one array to hold the list if we find the correct stock
    auto *cop_arr = new Stock [n]; // one array to hold all values in case we don't find stock

    std::cout << "Enter the name for the stock that you would like to remove: ";
    std::cin >> srch;

    for (i = 0; i < n; i++)
    {
        if (arr[i].name == srch or arr[i].symbol == srch)
        {
            int j = i;
            n -= 1; //resize n so we stay in bounds of our shorter array 
            while (j < n)
            {
                final_arr[j] = arr[j+1];//skip the index for the stock we want to remove.
                j++;
            }
            return final_arr;//return array with removed stock
        }
        else
        {
            final_arr[i] = arr[i];//update short array even if stock is not found in case stock is
            //found at the end of the array.
            
            cop_arr[i] = arr[i];// update the array in the case stock is never found.
        }
    }
    {
        std::cout << "**ERROR** Name or symbol did not match any stocks. Names and symbols are case sensitive. " << std::endl;
    }
    delete[] arr;
    return cop_arr;//return unchanged array when stock not found.
}


Stock* add(Stock* &arr, int &n)
{
    //return a resized array with an added stock
    
    int i;
    n += 1;
    auto *cop_arr = new Stock [n];

    for (i = 0; i < n-1; i++)
    {
        cop_arr[i] = arr[i];
    }
    cop_arr[n-1].get_info();
    delete[] arr;
    return cop_arr;
}


void lo_hi(Stock* arr, int n)
{
    int i, j;
    Stock temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[j].price > arr[i].price)
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}


void hi_lo(Stock* arr, int n)
{
    int i, j;
    Stock temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[j].price < arr[i].price)
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}


void edit(Stock* arr, int n)
{
    int i;
    bool flag = true; //error message control
    float val; //usr input for price change

    string x;// usr input for stock to be edited
    std::cout << "Please enter the name or symbol of the stock you would like to edit: ";
    std::cin >> x;
    for (i = 0; i < n; i++)
    {
        if (arr[i].name == x or arr[i].symbol == x)
        {
            std::cout << "Please enter the new price for the stock: ";
            std::cin >> val;
            arr[i].price = val;
            flag = false;
        }
    }
    if (flag)
    {
        std::cout << "**ERROR** Name or symbol did not match any stocks. Names and symbols are case sensitive." << std::endl;
    }
}


void display_all(Stock* arr, int n)
{
    int i;
    for (i=0; i < n; i ++)
        arr[i].info();
}


int display_menu(int& menu_choice)
{
    std::cout << "1) Add a new stock to collection.\n";
    std::cout << "2) Remove a stock from the collectino.\n";
    std::cout << "3) Edit a stock price.\n";
    std::cout << "4) Sort stocks based on price from high to low.\n";
    std::cout << "5) Sort stocks based on price from low to high.\n";
    std::cout << "6) Display all stocks in the collection.\n";
    std::cout << "7) Exit Program.\n\n";
    std::cout << "Enter: ";
    std::cin >> menu_choice;
    if (menu_choice > 7 || menu_choice < 1)
    {
        std::cout << "Invalid Entry. Please enter a  number from the options list provided.\n\n\n\n" << std::endl;
        display_menu(menu_choice);
    }
    return 0;
}


Stock* process_menu(Stock* &arr, int& n, int menu_choice, int &flag)
{
    switch(menu_choice){
        case 1:
            arr = add(arr, n);
            break;

        case 2:
            arr = remove(arr, n);
            break;

        case 3:
            edit(arr, n);
            break;

        case 4:
            hi_lo(arr, n);
            break;

        case 5:
            lo_hi(arr, n);
            break;

        case 6:
            display_all(arr, n);
            break;

        case 7:
            std::cout << "ENDING PROGRAM..." << std::endl;
            flag = 0;
            break;

        default:
            break;
    }
    return arr;
}


int main()
{
    int n = 4;
    int menu_choice;
    int flag = 1; //loop control
    auto *arr = new Stock[n];

    std::cout << "Enter the number of stocks you would like to initially enter: ";
    std::cin >> n;
    build_list(arr, n);

    while (flag)
    {
        display_menu(menu_choice);
        arr = process_menu(arr, n, menu_choice, flag);
    }

    std::cout << "================================================================" << std::endl;
    std::cout <<  "PROGRAM CLOSING..." << std::endl;
    std::cout << "================================================================\n\n\n" << std::endl;
    delete[] arr;
    return 0;
}


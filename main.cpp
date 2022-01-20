#include <iostream>
#include <string>

using std::string;

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
        std::cout << "Stock price: " << price << std::endl;
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

void remove(Stock* arr)
{
    //add code to remove a stock by matching name of stock with user input
    //be aware of errors with case-sensitive mismatches.
}


void add(Stock* arr)
{
    //add code to add a stock to the collection.
}


void lo_hi(Stock* arr)
{
    //add code to sort the stocks based on price. Lowest to highest
}


void hi_lo(Stock* arr)
{
    //add code to sort the stocks based on price. Highest to lowest.
}


void edit(Stock* arr)
{
    // add code to edit the price of one of the stocks. match by
    //name or by symbol.
}


int display_menu()
{
    //write code to display a menu where user can choose
    // what to do to the stock collection.
}


void process_menu()
{
    //write code that calls uses the user input from display_menu to
    //call the corresponding function.
}


int main()
{
    int n, i, j;

    std::cout << "Enter the number of stocks you would like to initially enter: ";
    std::cin >> n;
    Stock arr[n];

    build_list(arr, n);

    for (i = 0; i < n; i++)
    {
        std::cout << "**STOCK " << i + 1 << "**" << std::endl;
        arr[i].info();
    }

    return 0;

}

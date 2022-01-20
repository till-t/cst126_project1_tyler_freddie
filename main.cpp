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


void edit(Stock* arr)
{
    // add code to edit the price of one of the stocks. match by
    //name or by symbol.
}


int display_menu()
{
    //write code to display a menu where user can choose
    // what to do to the stock collection.
    return 0;
}


void process_menu()
{
    //write code that calls uses the user input from display_menu to
    //call the corresponding function.
}


int main()
{
    int n, i;
    n = 4;

    //std::cout << "Enter the number of stocks you would like to initially enter: ";
    //std::cin >> n;
    //Stock arr[n];
    Stock st1;
    Stock st2;
    Stock st3;
    Stock st4;
    st1.name = "apple";
    st1.symbol = "appl";
    st1.price = 32.59;
    st2.name = "microsoft";
    st2.symbol = "mic";
    st2.price = 0.29;
    st3.name = "mcdonalds";
    st3.symbol = "mkd";
    st3.price = 1000;
    st4.name = "liverpool";
    st4.symbol = "lvp";
    st4.price = 56.55;

    //build_list(arr, n);
    Stock st_arr[] = {st1, st2, st3, st4};


    //sorting tests
    std::cout << "\n" << std::endl;
    std::cout << "Low to high" << std::endl;
    std::cout << "\n" << std::endl;

    lo_hi(st_arr, n);

    for (i = 0; i < n; i++)
    {
        std::cout << "**STOCK " << i + 1 << "**" << std::endl;
        st_arr[i].info();
    }
    std::cout << "\n\n" << std::endl;
    std::cout << "High to low" << std::endl;
    std::cout << "\n" << std::endl;
    hi_lo(st_arr, n);

    for (i = 0; i < n; i++)
    {
        std::cout << "**STOCK " << i + 1 << "**" << std::endl;
        st_arr[i].info();
    }

//end sorting test

    return 0;

}


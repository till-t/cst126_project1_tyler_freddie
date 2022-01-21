#include <iostream>
#include <string>
#include <algorithm>

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
    int i;
    string srch;
    Stock *final_arr = new Stock [n-1];
    Stock *cop_arr = new Stock [n];
    bool flag = true;

    std::cout << "Enter the name for the stock that you would like to remove: ";
    std::cin >> srch;

    for (i = 0; i < n; i++)
    {
        if (arr[i].name == srch or arr[i].symbol == srch)
        {
            int j = i;
            n -= 1;
            flag = false;
            while (j < n)
            {
                final_arr[j] = arr[j+1];
                j++;
            }
            return final_arr;
        }
        else
        {
            final_arr[i] = arr[i];
            cop_arr[i] = arr[i];
        }
    }
    if (flag)
    {
        std::cout << "**ERROR** Name or symbol did not match any stocks. Names and symbols are case sensitive. " << std::endl;
    }
    delete[] arr;
    return cop_arr;
}


Stock* add(Stock* &arr, int &n)
{
    int i;
    n += 1;
    Stock *cop_arr = new Stock [n];

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
    bool flag = true;
    float val;

    string x;
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
    int n = 4;
    int i;

    //std::cout << "Enter the number of stocks you would like to initially enter: ";
    //std::cin >> n;
    //Stock arr[n];
    Stock st1;
    Stock st2;
    Stock st3;
    Stock st4;
    st1.name = "Apple";
    st1.symbol = "appl";
    st1.price = 32.59;
    st2.name = "Microsoft";
    st2.symbol = "mic";
    st2.price = 0.29;
    st3.name = "Mcdonalds";
    st3.symbol = "mkd";
    st3.price = 1000;
    st4.name = "liverpool";
    st4.symbol = "lvp";
    st4.price = 56.55;

    //build_list(arr, n);
    Stock *arr = new Stock[n];
    Stock st_arr[] = {st1, st2, st3, st4};
    //convert_case(arr, n);

    for (i = 0; i < n; i++)
    {
        arr[i] = st_arr[i];
        arr[i].info();
    }

    arr = add(arr, n);
    for (i = 0; i < n; i++)
    {
        arr[i].info();
    }
    arr = remove(arr, n);


    for (i = 0; i < n; i++)
    {
        arr[i].info();
    }

/*
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
*/
//end sorting test

    return 0;

}


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

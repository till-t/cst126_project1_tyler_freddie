"""
Building class project in python
"""


class Stock:
    def __init__(self, name, symbol, price):
        self.name = name
        self.symbol = symbol
        self.price = price

    def info(self):
        print("Name: " + self.name)
        print("Symbol: " + self.symbol)
        print("Price: " + str(self.price))
        print("=========================================")


def build_list(n: int) -> list:
    lst = []
    for i in range(int(n)):
        name = input('Enter the name of the stock (not the symbol):\n')
        symbol = input('Enter the symbol of the stock:\n')
        pri = input('Enter the price of the stock:\n')
        lst.append(Stock(name, symbol, pri))
    return lst


def remove(arr: list) -> list:
    name = input('Please enter the name of the stock you would like to remove:\n')
    i = 0
    flag = 1
    while i < len(arr):
        if arr[i].name == name or arr[i].symbol == name:
            del(arr[i])
            flag = 0
        i += 1
    if flag:
        print("**ERROR** No stock found with that name or symbol.\n")
    return arr


def edit(arr: list) -> list:
    flag = 1
    name = input('Please enter the name or symbol of the stock you would like to edit:\n')
    for i in range(len(arr)):
        if arr[i].name == name or arr[i].symbol == name:
            num = input('Please enter the new price for the stock:\n')
            arr[i].price = int(num)
            flag = 0
    if flag:
        print('**ERROR** Name or symbol did not match any stocks.')
    return arr


def add(arr: list) -> list:
    name = input('Enter the name of the stock (not the symbol):\n')
    symbol = input('Enter the symbol of the stock:\n')
    pri = input('Enter the price of the stock:\n')
    pri = int(pri)
    arr.append(Stock(name, symbol, pri))
    return arr


def sort_increase(arr: list) -> list:
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[j].price > arr[i].price:
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
    return arr


def sort_decrease(arr: list) -> list:
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[j].price < arr[i].price:
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
    return arr


def database(arr: list) -> None:
    print('STOCKS IN DATABASE')
    print('=======================================')
    for h in range(len(arr)):
        arr[h].info()


def test():
    n = 3
    st1 = Stock("Apple", "Appl", 289)
    st2 = Stock("Tyler", "Tyl", 4)
    st3 = Stock("Oliver", "oll", 1)
    arr = [st1, st2, st3]

    database(arr)
    print('\n')

    print('ADD STOCK')
    add(arr)
    database(arr)
    print('\n')

    print('EDIT STOCK')
    edit(arr)
    database(arr)
    print('\n')

    print('REMOVE STOCK')
    remove(arr)
    database(arr)
    print('\n')

    print('SORT INCREASE')
    sort_increase(arr)
    database(arr)
    print('\n')

    print('SORT DECREASE')
    sort_decrease(arr)
    database(arr)
    print('\n')

    return None


def main():
    test()

    return None


if __name__ == '__main__':
    main()







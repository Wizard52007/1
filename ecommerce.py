from abc import ABC, abstractmethod

class DiscountStrategy(ABC):
    @abstractmethod
    def discount(self, price):
        pass


class PercentageDiscount(DiscountStrategy):
    def discount(self, price):
        return price * 0.10


class Item:
    def __init__(self, name, price):
        self.name = name
        self.price = price


class ShoppingCart:
    def __init__(self):
        self.items = []

    def add(self, item):
        self.items.append(item)

    def checkout(self, strategy):
        total = sum(i.price for i in self.items)
        return total - strategy.discount(total)


cart = ShoppingCart()

n = int(input("Enter number of items: "))

for i in range(n):
    name = input("Enter item name: ")
    price = float(input("Enter price: "))
    cart.add(Item(name, price))

print("Final Amount:", cart.checkout(PercentageDiscount()))
#include <iostream>
#include <string.h>

class FruitVeg
{
private:
    double price;
    int quant;
    std::string nem;
    std::string type;
public:
    FruitVeg(double price, int quant, std::string nem, std::string type)
    {
        this->nem = nem;
        this->quant = quant;
        this->type = type;
        this->price = price;
    }
    FruitVeg(const FruitVeg& a)
    {
        this->nem = a.nem;
        this->quant = a.quant;
        this->type = a.type;
        this->price = a.price;
    }
    double getPrice()
    {
        return this->price;
    }
    std::string getName()
    {
        return this->nem;
    }
    int getQuantity()
    {
        return this->quant;
    }
    std::string getType()
    {
        return this->type;
    }
    double SumCalc()
    {
        return price * quant;
    }
    FruitVeg& operator=(const FruitVeg& a)
    {
        this->nem = a.nem;
        this->quant = a.quant;
        this->type = a.type;
        this->price = a.price;
        return *this;
    }
    ~FruitVeg()
    {

    }
};
double sumtotal(FruitVeg** fruitveg, int sayz)
{
    double sum = 0.0;
    for (int i = 0; i < sayz; i++)
    {
        sum += fruitveg[i]->SumCalc();
    }
    return sum;
}
void printFruitVeg(FruitVeg** fruitveg, int sayz)
{
    std::cout << "Jenna's Grocery List\n\n";
    std::cout << "Type\t" << "Name\t" << "Price\t" << "Quantity\n";
    for (int i = 0; i < sayz; i++)
    {
        std::cout << fruitveg[i]->getType() << fruitveg[i]->getName() << "\tPHP "
            << fruitveg[i]->getPrice() << "\t x" << fruitveg[i]->getQuantity() << std::endl;
    }
}
int main()
{
    int NoOfGroceryItems = 4;
    FruitVeg** GroceryList = new FruitVeg * [NoOfGroceryItems];

    GroceryList[0] = new FruitVeg(10.0, 7, "Apple", "Fruit  ");
    GroceryList[1] = new FruitVeg(10.0, 8, "Banana", "Fruit  ");
    GroceryList[2] = new FruitVeg(60.0, 12, "Broccoli", "Veggy  ");
    GroceryList[3] = new FruitVeg(50.0, 10, "Lettuce", "Veggy  ");
    std::cout << "List:\n\n";
    printFruitVeg(GroceryList, NoOfGroceryItems);
    std::cout << "\n\t\t\tTotal Sum " << "PHP" << sumtotal(GroceryList, NoOfGroceryItems);

    FruitVeg* Lettuce = GroceryList[3];
    for (int i = 3; i < NoOfGroceryItems - 1; i++)
    {
        GroceryList[i] = GroceryList[i + 1];
    }
    NoOfGroceryItems--;
    delete Lettuce;
    std::cout << "\nAfter removing Lettuce:\n\n";
    printFruitVeg(GroceryList, NoOfGroceryItems);

    return 0;
}

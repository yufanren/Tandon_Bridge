//
// Created by yufanren on 1/24/20.
#include <iostream>
using namespace std;

const double MEMBER_DISCOUNT = 0.9;
int main() {
    double price1, price2, taxRate, priceBase, priceDiscounted, priceFinal;
    char clubCard;
    cout<<"Enter price of first item: ";
    cin>>price1;
    cout<<"Enter price of second item: ";
    cin>>price2;
    priceBase = price1 + price2;
    if (price1 > price2)
        price2 /= 2;
    else
        price1 /= 2;
    priceDiscounted = price1 + price2;
    cout<<"Does customer have a club card?(Y/N): ";
    cin>>clubCard;
    if (clubCard == 'Y' || clubCard == 'y')
        priceDiscounted *= MEMBER_DISCOUNT;
    cout<<"Enter tax rate, e.g 5.5 for 5.5% tax: ";
    cin>>taxRate;
    priceFinal = priceDiscounted * (1.0 + taxRate / 100);
    cout<<"Base price: "<<priceBase<<"\nPrice after discounts: "<<priceDiscounted<<"\nTotal price: "<<priceFinal<<endl;
    return 0;
}

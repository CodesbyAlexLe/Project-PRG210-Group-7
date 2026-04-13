#ifndef PRODUCT_H
#define PRODUCT_H


class Product {
private:
    char name[100];
    double price;
    int quantity;

public:
    Product();
    Products(const char* productName, double productPrice, int productQuantity);

    const char* getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setName(const char* productName);
    void setPrice(double productPrice);
    void setQuantity(int productQuantity);

};
#endif

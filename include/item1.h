#ifndef ITEM1_H
#define ITEM1_H

class Item1
{
public:
    Item1(float price = 3.2f) : price_(price)
    {
    }
    float GetPrice()
    {
        return price_;
    }
    void AddPrice(float price)
    {
        price_ += price;
    }

    float GetArea() const;

private:
    float price_ = 0.0f;
};

#endif
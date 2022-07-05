#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

enum ItemType
{
    none,
    sitable,
    wall,
    ground,
    eating,
    special


};


class clItem
{

private:
    ItemType type;
    int item_szerokosc;
    int item_wysokosc;
    int item_x_siad;
    int item_y_siad;
    int item_szer_siad;
    int heal;
    int inv_miejsce; // np. 23 -> x = 2  y = 3
    int price;
    sf::Texture tex_inventory;
    sf::Texture tex_item;
    sf::Sprite sp_inventory;
    sf::Sprite sp_item;

public:
    clItem()
    {
        type = none;
    }
    ItemType getType()
    {
        return type;
    }
    int getSiadWys()
    {
        return item_y_siad;
    }
    int getSiadSzerMin()
    {
        return item_x_siad;
    }
    int getSiadSzerMax()
    {
        return (item_x_siad + item_szer_siad);
    }
    int getFoodValue()
    {
        return heal;
    }
    int getPrice()
    {
        return price;
    }
    int getInvMiejsce()
    {
        return inv_miejsce;
    }
    int szer()
    {
        return item_szerokosc;
    }
    int wys()
    {
        return item_wysokosc;
    }
    void create(ItemType typ, int szero, int wyso, int miejsceEQ, string inventory, string item, int x_siad = 0, int y_siad = 0, int szer_siad = 0, int nHeal = 0,int nPrice = 0)
    {
        type = typ;
        item_szerokosc = szero;
        item_wysokosc = wyso;
        inv_miejsce = miejsceEQ;
        tex_inventory.loadFromFile(inventory);
        tex_item.loadFromFile(item);
        item_x_siad = x_siad;
        item_y_siad = y_siad;
        item_szer_siad = szer_siad;
        heal = nHeal;
        sp_inventory.setTexture(tex_inventory);
        sp_item.setTexture(tex_item);
        price = nPrice;
    }
    void wyswietlInventory(int x, int y)
    {
        sp_inventory.setPosition(x,y);
        window.draw(sp_inventory);
    }
    void wyswietlItem(int x, int y)
    {
        sp_item.setPosition(x,y);
        window.draw(sp_item);
    }
    bool isCreated()
    {
        if(type != none) return true;
        else return false;
    }



};
clItem item[600];

#endif // ITEM_H_INCLUDED

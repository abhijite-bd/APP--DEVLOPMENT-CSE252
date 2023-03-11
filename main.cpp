#include <bits/stdc++.h>
using namespace std;
#define ss ' '
#define sstt "\t\t"
int i;
void show_catagory()
{
    cout << "1.Fast Food\n";
    cout << "2.Drinks\n";
    cout << "3.Cofee\n";
    cout << "4.Tea\n";
}
class FooD
{
public:
    vector<string> ff;
    vector<string> drinks;
    vector<string> cofee;
    vector<string> tea;
    vector<double> ff_price;
    vector<double> d_price;
    vector<double> co_price;
    vector<double> tea_price;
    vector<double> ff_profit;
    vector<double> d_profit;
    vector<double> co_profit;
    vector<double> tea_profit;
    vector<int> ff_qty;
    vector<int> d_qty;
    vector<int> co_qty;
    vector<int> tea_qty;
    FooD()
    {
        ifstream f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
        f1.open("fastfood_name.txt");
        f2.open("drinks_name.txt");
        f3.open("cofee_name.txt");
        f4.open("tea_name.txt");
        f5.open("fastfood_price.txt");
        f6.open("drinks_price.txt");
        f7.open("cofee_price.txt");
        f8.open("tea_price.txt");
        f9.open("fastfood_profit.txt");
        f10.open("drinks_profit.txt");
        f11.open("cofee_profit.txt");
        f12.open("tea_profit.txt");
        string s;
        double price;
        if (!f1 or !f2 or !f3 or !f4 or !f5 or !f6 or !f7 or !f8 or !f9 or !f10 or !f11 or !f12)
        {
            // file check
            cout << "Something is wrong!! File is missing!\n";
            return;
        }
        // taking fastfood info from file
        while (!f1.eof())
        {
            getline(f1, s);
            ff.push_back(s);
        }
        while (!f5.eof())
        {
            f5 >> price;
            ff_price.push_back(price);
        }
        while (!f9.eof())
        {
            f9 >> price;
            ff_profit.push_back(price);
        }
        // taking drinks info from file
        while (!f2.eof())
        {
            getline(f2, s);
            drinks.push_back(s);
        }
        while (!f6.eof())
        {
            f6 >> price;
            d_price.push_back(price);
        }
        while (!f10.eof())
        {
            f10 >> price;
            d_profit.push_back(price);
        }
        // taking cofees info from file
        while (!f3.eof())
        {
            getline(f3, s);
            cofee.push_back(s);
        }
        while (!f7.eof())
        {
            f7 >> price;
            co_price.push_back(price);
        }
        while (!f11.eof())
        {
            f11 >> price;
            co_profit.push_back(price);
        }
        // taking tea info from file
        while (!f4.eof())
        {
            getline(f4, s);
            tea.push_back(s);
        }
        while (!f8.eof())
        {
            f8 >> price;
            tea_price.push_back(price);
        }
        while (!f12.eof())
        {
            f12 >> price;
            tea_profit.push_back(price);
        }
    }
    friend void show_ff_price(FooD cus)
    {
        for (i = 0; i < cus.ff.size(); i++)
        {
            cout << i + 1 << ss << cus.ff[i] << ss << cus.ff_price[i] << endl;
        }
    }
    friend void show_drinks_price(FooD cus)
    {
        for (i = 0; i < cus.drinks.size(); i++)
        {
            cout << i + 1 << ss << cus.drinks[i] << ss << cus.d_price[i] << endl;
        }
    }
    friend void show_cofee_price(FooD cus)
    {
        for (i = 0; i < cus.cofee.size(); i++)
        {
            cout << i + 1 << ss << cus.cofee[i] << ss << cus.co_price[i] << endl;
        }
    }
    friend void show_tea_price(FooD cus)
    {
        for (i = 0; i < cus.tea.size(); i++)
        {
            cout << i + 1 << ss << cus.tea[i] << ss << cus.tea_price[i] << endl;
        }
    }
    friend void show_allproduct(FooD cus)
    {
        int k = 1;
        for (auto e : cus.ff)
            cout << k++ << ss << e << endl;
        for (auto e : cus.drinks)
            cout << k++ << ss << e << endl;
        for (auto e : cus.cofee)
            cout << k++ << ss << e << endl;
        for (auto e : cus.tea)
            cout << k++ << ss << e << endl;
    }
};

void adminsection()
{
    cout << "1. Add Item\n";
    cout << "2. Delete Item\n";
    cout << "3. Modify Item\n";
    cout << "4. Total Sale\n";
    // cout<<"Add Item\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        string s;
        double price, profit;
        show_catagory();
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            ofstream f1, f2, f3;
            f1.open("fastfood_name.txt", ios::app);
            f2.open("fastfood_price.txt", ios::app);
            f3.open("fastfood_profit.txt", ios::app);
            cin.ignore();

            cout << "Enter Fastfood Item: ";
            getline(cin, s);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter profit: ";
            cin >> profit;
            f1 << endl
               << s;
            f2 << endl
               << price;
            f3 << endl
               << profit;
            f1.close();
            f2.close();
            f3.close();
        }
        else if (ch == 2)
        {
            ofstream f1, f2, f3;
            f1.open("drinks_name.txt", ios::app);
            f2.open("drinks_price.txt", ios::app);
            f3.open("drinks_profit.txt", ios::app);
            cin.ignore();
            cout << "Enter Drink's Item: ";
            getline(cin, s);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter profit: ";
            cin >> profit;
            f1 << endl
               << s;
            f2 << endl
               << price;
            f3 << endl
               << profit;
            f1.close();
            f2.close();
            f3.close();
        }
        else if (ch == 3)
        {
            ofstream f1, f2, f3;
            f1.open("cofee_name.txt", ios::app);
            f2.open("cofee_price.txt", ios::app);
            f3.open("cofee_profit.txt", ios::app);
            cin.ignore();
            cout << "Enter Cofee's Item: ";
            getline(cin, s);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter profit: ";
            cin >> profit;
            f1 << endl
               << s;
            f2 << endl
               << price;
            f3 << endl
               << profit;
            f1.close();
            f2.close();
            f3.close();
        }
        else if (ch == 4)
        {
            ofstream f1, f2, f3;
            f1.open("tea_name.txt", ios::app);
            f2.open("tea_price.txt", ios::app);
            f3.open("tea_profit.txt", ios::app);
            cin.ignore();
            cout << "Enter Tea's Item: ";
            getline(cin, s);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter profit: ";
            cin >> profit;
            f1 << endl
               << s;
            f2 << endl
               << price;
            f3 << endl
               << profit;
            f1.close();
            f2.close();
            f3.close();
        }
        else
        {
            cout << "Wrong Input\n";
        }
    }
    else if (choice == 2)
    {
        FooD f1;
        show_allproduct(f1);
        cout << "Enter a name you want to delete: ";
        string s;
        cin.ignore();
        getline(cin, s);
        if (find(f1.ff.begin(), f1.ff.end(), s) != f1.ff.end())
        {
            ofstream f11, f12, f13;
            f11.open("fastfood_name.txt", ios::out);
            f12.open("fastfood_price.txt", ios::out);
            f13.open("fastfood_profit.txt", ios::out);
            f11.clear();
            f12.clear();
            f13.clear();
            int x = 1;
            for (int i = 0; i < f1.ff.size(); i++)
            {
                if (f1.ff[i] == s)
                    continue;
                if (x)
                {
                    f11 << f1.ff[i];
                    f12 << f1.ff_price[i];
                    f13 << f1.ff_profit[i];
                    x = 0;
                }
                else
                {
                    f11 << endl
                        << f1.ff[i];
                    f12 << endl
                        << f1.ff_price[i];
                    f13 << endl
                        << f1.ff_profit[i];
                }
            }
            f11.close();
            f12.close();
            f13.close();
        }
        else if (find(f1.drinks.begin(), f1.drinks.end(), s) != f1.drinks.end())
        {
            ofstream f11, f12, f13;
            f11.open("drinks_name.txt", ios::out);
            f12.open("drinks_price.txt", ios::out);
            f13.open("drinks_profit.txt", ios::out);
            f11.clear();
            f12.clear();
            f13.clear();
            int x = 1;
            for (int i = 0; i < f1.drinks.size(); i++)
            {
                if (f1.drinks[i] == s)
                    continue;
                if (x)
                {
                    f11 << f1.drinks[i];
                    f12 << f1.d_price[i];
                    f13 << f1.d_profit[i];
                    x = 0;
                }
                else
                {
                    f11 << endl
                        << f1.drinks[i];
                    f12 << endl
                        << f1.d_price[i];
                    f13 << endl
                        << f1.d_profit[i];
                }
            }
            f11.close();
            f12.close();
            f13.close();
        }
        else if (find(f1.cofee.begin(), f1.cofee.end(), s) != f1.cofee.end())
        {
            ofstream f11, f12, f13;
            f11.open("cofee_name.txt", ios::out);
            f12.open("cofee_price.txt", ios::out);
            f13.open("cofee_profit.txt", ios::out);
            f11.clear();
            f12.clear();
            f13.clear();
            int x = 1;
            for (int i = 0; i < f1.cofee.size(); i++)
            {
                if (f1.cofee[i] == s)
                    continue;
                f11 << f1.cofee[i] << endl;
                f12 << f1.co_price[i] << endl;
                f13 << f1.co_profit[i] << endl;
                if (x)
                {
                    f11 << f1.cofee[i];
                    f12 << f1.co_price[i];
                    f13 << f1.co_profit[i];
                    x = 0;
                }
                else
                {
                    f11 << endl
                        << f1.cofee[i];
                    f12 << endl
                        << f1.co_price[i];
                    f13 << endl
                        << f1.co_profit[i];
                }
            }
            f11.close();
            f12.close();
            f13.close();
        }
        else if (find(f1.tea.begin(), f1.tea.end(), s) != f1.tea.end())
        {
            ofstream f11, f12, f13;
            f11.open("tea_name.txt", ios::out);
            f12.open("tea_price.txt", ios::out);
            f13.open("tea_profit.txt", ios::out);
            f11.clear();
            f12.clear();
            f13.clear();
            int x = 1;
            for (int i = 0; i < f1.tea.size(); i++)
            {
                if (f1.tea[i] == s)
                    continue;
                if (x)
                {
                    f11 << f1.tea[i];
                    f12 << f1.tea_price[i];
                    f13 << f1.tea_profit[i];
                    x = 0;
                }
                else
                {
                    f11 << endl
                        << f1.tea[i];
                    f12 << endl
                        << f1.tea_price[i];
                    f13 << endl
                        << f1.tea_profit[i];
                }
            }
            f11.close();
            f12.close();
            f13.close();
        }
        else
            cout << "Wrong Input\n";
    }
    else if (choice == 3)
    {
        FooD f1;
        show_allproduct(f1);
        string s;
        cout << "Enter a name you want to Modify: ";
        cin.ignore();
        getline(cin, s);
        int x = 1;
        if (find(f1.ff.begin(), f1.ff.end(), s) != f1.ff.end())
        {
            ofstream f11, f12, f13;
            f11.open("fastfood_name.txt", ios::out);
            f12.open("fastfood_price.txt", ios::out);
            f13.open("fastfood_profit.txt", ios::out);
            f11.clear();
            f12.clear();
            f13.clear();
            for (int i = 0; i < f1.ff.size(); i++)
            {
                if (f1.ff[i] == s)
                {
                    cout << "Item : " << f1.ff[i] << endl;
                    cout << "Price : " << f1.ff_price[i] << endl;
                    cout << "Profit : " << f1.ff_profit[i] << endl;
                    int modify;
                    cout << "You want to modify?\n";
                    cout << "1. Name.\n";
                    cout << "2. Price.\n";
                    cout << "3. Profit.\n";
                    cin >> modify;
                    if (modify < 1 or modify > 3)
                    {
                        return;
                    }
                    if (modify == 1)
                    {
                        string name;
                        cout << "Enter Name: ";
                        cin.ignore();
                        getline(cin, name);
                        f1.ff[i] = name;
                    }
                    else if (modify == 2)
                    {
                        double price;
                        cout << "Enter Price: ";
                        cin >> price;
                        f1.ff_price[i] = price;
                    }
                    if (modify == 3)
                    {
                        double profit;
                        cout << "Enter Profit: ";
                        cin >> profit;
                        f1.ff_profit[i] = profit;
                    }
                }
                if (x)
                {
                    f11 << f1.ff[i];
                    f12 << f1.ff_price[i];
                    f13 << f1.ff_profit[i];
                    x = 0;
                }
                else
                {
                    f11 << endl
                        << f1.ff[i];
                    f12 << endl
                        << f1.ff_price[i];
                    f13 << endl
                        << f1.ff_profit[i];
                }
            }
            f11.close();
            f12.close();
            f13.close();
        }
        else if (find(f1.drinks.begin(), f1.drinks.end(), s) != f1.drinks.end())
        {
            ofstream f11, f12, f13;
            f11.open("drinks_name.txt", ios::out);
            f12.open("drinks_price.txt", ios::out);
            f13.open("drinks_profit.txt", ios::out);
            f11.clear();
            f12.clear();
            f13.clear();
            for (int i = 0; i < f1.drinks.size(); i++)
            {
                if (f1.drinks[i] == s)
                {
                    cout << "Item : " << f1.drinks[i] << endl;
                    cout << "Price : " << f1.d_price[i] << endl;
                    cout << "Profit : " << f1.d_profit[i] << endl;
                    int modify;
                    cout << "You want to modify?\n";
                    cout << "1. Name.\n";
                    cout << "2. Price.\n";
                    cout << "3. Profit.\n";
                    cin >> modify;
                    if (modify < 1 or modify > 3)
                    {
                        return;
                    }
                    if (modify == 1)
                    {
                        string name;
                        cout << "Enter Name: ";
                        cin.ignore();
                        getline(cin, name);
                        f1.drinks[i] = name;
                    }
                    else if (modify == 2)
                    {
                        double price;
                        cout << "Enter Price: ";
                        cin >> price;
                        f1.d_price[i] = price;
                    }
                    if (modify == 3)
                    {
                        double profit;
                        cout << "Enter Profit: ";
                        cin >> profit;
                        f1.d_profit[i] = profit;
                    }
                }
                if (x)
                {
                    f11 << f1.drinks[i];
                    f12 << f1.d_price[i];
                    f13 << f1.d_profit[i];
                    x = 0;
                }
                else
                {
                    f11 << endl
                        << f1.drinks[i];
                    f12 << endl
                        << f1.d_price[i];
                    f13 << endl
                        << f1.d_profit[i];
                }
            }
            f11.close();
            f12.close();
            f13.close();
        }
        else if (find(f1.cofee.begin(), f1.cofee.end(), s) != f1.cofee.end())
        {
            ofstream f11, f12, f13;
            f11.open("cofee_name.txt", ios::out);
            f12.open("cofee_price.txt", ios::out);
            f13.open("cofee_profit.txt", ios::out);
            f11.clear();
            f12.clear();
            f13.clear();
            for (int i = 0; i < f1.cofee.size(); i++)
            {
                if (f1.cofee[i] == s)
                {
                    cout << "Item : " << f1.cofee[i] << endl;
                    cout << "Price : " << f1.co_price[i] << endl;
                    cout << "Profit : " << f1.co_profit[i] << endl;
                    int modify;
                    cout << "You want to modify?\n";
                    cout << "1. Name.\n";
                    cout << "2. Price.\n";
                    cout << "3. Profit.\n";
                    cin >> modify;
                    if (modify < 1 or modify > 3)
                    {
                        return;
                    }
                    if (modify == 1)
                    {
                        string name;
                        cout << "Enter Name: ";
                        cin.ignore();
                        getline(cin, name);
                        f1.cofee[i] = name;
                    }
                    else if (modify == 2)
                    {
                        double price;
                        cout << "Enter Price: ";
                        cin >> price;
                        f1.co_price[i] = price;
                    }
                    if (modify == 3)
                    {
                        double profit;
                        cout << "Enter Profit: ";
                        cin >> profit;
                        f1.co_profit[i] = profit;
                    }
                }
                if (x)
                {
                    f11 << f1.cofee[i];
                    f12 << f1.co_price[i];
                    f13 << f1.co_profit[i];
                    x = 0;
                }
                else
                {
                    f11 << endl
                        << f1.cofee[i];
                    f12 << endl
                        << f1.co_price[i];
                    f13 << endl
                        << f1.co_profit[i];
                }
            }
            f11.close();
            f12.close();
            f13.close();
        }
        else if (find(f1.tea.begin(), f1.tea.end(), s) != f1.tea.end())
        {
            ofstream f11, f12, f13;
            f11.open("tea_name.txt", ios::out);
            f12.open("tea_price.txt", ios::out);
            f13.open("tea_profit.txt", ios::out);
            f11.clear();
            f12.clear();
            f13.clear();
            for (int i = 0; i < f1.tea.size(); i++)
            {
                if (f1.tea[i] == s)
                {
                    cout << "Item : " << f1.tea[i] << endl;
                    cout << "Price : " << f1.tea_price[i] << endl;
                    cout << "Profit : " << f1.tea_profit[i] << endl;
                    int modify;
                    cout << "You want to modify?\n";
                    cout << "1. Name.\n";
                    cout << "2. Price.\n";
                    cout << "3. Profit.\n";
                    cin >> modify;
                    if (modify < 1 or modify > 3)
                    {
                        return;
                    }
                    if (modify == 1)
                    {
                        string name;
                        cout << "Enter Name: ";
                        cin.ignore();
                        getline(cin, name);
                        f1.tea[i] = name;
                    }
                    else if (modify == 2)
                    {
                        double price;
                        cout << "Enter Price: ";
                        cin >> price;
                        f1.tea_price[i] = price;
                    }
                    if (modify == 3)
                    {
                        double profit;
                        cout << "Enter Profit: ";
                        cin >> profit;
                        f1.tea_profit[i] = profit;
                    }
                }
                if (x)
                {
                    f11 << f1.tea[i];
                    f12 << f1.tea_price[i];
                    f13 << f1.tea_profit[i];
                    x = 0;
                }
                else
                {
                    f11 << endl
                        << f1.tea[i];
                    f12 << endl
                        << f1.tea_price[i];
                    f13 << endl
                        << f1.tea_profit[i];
                }
            }
            f11.close();
            f12.close();
            f13.close();
        }
        else
            cout << "Wrong Input\n";
    }
    else if (choice == 4)
    {
    }
}
map<string, pair<int, double>> mname_quan_price;
vector<pair<string, pair<string, double>>> selected;
void print()
{
    ofstream f1;
    f1.open("Money Receipt.txt", ios::out);
    int i = 1;
    double price = 0.0;
    f1 << "Name" << setw(15) << ss << "Quantity" << sstt << "Price" << endl;
    cout << "Name" << setw(15) << ss << "Quantity" << sstt << "Price" << endl;
    for (auto e : mname_quan_price)
    {
        f1 << i++ << ss << e.first << setw(15) << ss << e.second.first << sstt << e.second.second << endl;
        cout << i++ << ss << e.first << setw(5) << ss << e.second.first << sstt << e.second.second << endl;
        price += e.second.second;
    }
    cout << "Price :" << price << endl;
    f1 << "Price :" << price << endl;
    f1 << "VAT = " << price * .05 << endl;
    cout << "VAT = " << price * .05 << endl;
    price += (price * .05);
    f1 << "Total = " << price << endl;
    cout << "Total = " << price << endl;
    mname_quan_price.clear();
    cout << endl;
    cout << endl;
}
double price = 0;
void buying_sec(int choice)
{
    FooD cus;
    if (choice == 1)
    {
        int x = 0;
        while (1)
        {
            cout << 0 << " Confirm\n";
            show_ff_price(cus);
            cout << -1 << " back\n";
            if (x)
                cout << "You have selected: \n";
            int i = 1;
            if (mname_quan_price.size() > 0 and x)
                cout << "Name" << setw(15) << ss << "Quantity" << sstt << "Price" << endl;
            else if (!x)
                cout << "Nothing\n";
            for (auto e : mname_quan_price)
                cout << i++ << ss << e.first << setw(5) << ss << e.second.first << sstt << e.second.second << endl;

            int take;
            cin >> take;
            if (take == -1)
                return;

            if (take == 0 and mname_quan_price.size() > 0)
            {
                print();
                break;
            }
            else if (take == 0 and mname_quan_price.size() == 0)
            {
                cout << "You haven't chose any product yet\n";
                cout << "Try Aganin\n";
            }
            else if (take > 0 and take <= cus.ff.size())
            {
                cout << "You have selected " << cus.ff[take - 1] << endl;
                cout << "Enter Quantity: ";
                int quan;
                while (cin >> quan and quan < 1)
                {
                    cout << "Try Again\n";
                }
                mname_quan_price[cus.ff[take - 1]] = {quan, quan * cus.ff_price[take - 1]};
            }
            else
                cout << "Try Aganin\n";
            x = 1;
        }
    }
    else if (choice == 2)
    {
        int x = 0;
        while (1)
        {
            cout << 0 << " Confirm\n";
            show_drinks_price(cus);
            cout << -1 << " back\n";
            if (x)
                cout << "You have selected: \n";
            int i = 1;
            if (mname_quan_price.size() > 0 and x)
                cout << "Name" << setw(15) << ss << "Quantity" << sstt << "Price" << endl;
            else if (x)
                cout << "Nothing\n";
            for (auto e : mname_quan_price)
                cout << i++ << ss << e.first << setw(15) << ss << e.second.first << sstt << e.second.second << endl;

            int take;
            cin >> take;
            if (take == -1)
                return;

            if (take == 0 and mname_quan_price.size() > 0)
            {
                print();
                break;
            }
            else if (take == 0 and mname_quan_price.size() == 0)
            {
                cout << "You haven't chose any product yet\n";
                cout << "Try Aganin\n";
            }
            else if (take > 0 and take <= cus.drinks.size())
            {
                cout << "You have selected " << cus.drinks[take - 1] << endl;
                cout << "Enter Quantity: ";
                int quan;
                while (cin >> quan and quan < 1)
                {
                    cout << "Try Again\n";
                }
                mname_quan_price[cus.drinks[take - 1]] = {quan, quan * cus.d_price[take - 1]};
            }
            else
                cout << "Try Aganin\n";
            x = 1;
        }
    }
    else if (choice == 3)
    {
        int x = 0;
        while (1)
        {
            cout << 0 << " Confirm\n";
            show_cofee_price(cus);
            cout << -1 << " back\n";
            if (x)
                cout << "You have selected: \n";
            int i = 1;
            if (mname_quan_price.size() > 0 and x)
                cout << "Name" << setw(15) << ss << "Quantity" << sstt << "Price" << endl;
            else if (x)
                cout << "Nothing\n";
            for (auto e : mname_quan_price)
                cout << i++ << ss << e.first << setw(5) << ss << e.second.first << sstt << e.second.second << endl;

            int take;
            cin >> take;
            if (take == -1)
                return;

            if (take == 0 and mname_quan_price.size() > 0)
            {
                print();
                break;
            }
            else if (take == 0 and mname_quan_price.size() == 0)
            {
                cout << "You haven't chose any product yet\n";
                cout << "Try Aganin\n";
            }
            else if (take > 0 and take <= cus.cofee.size())
            {
                cout << "You have selected " << cus.cofee[take - 1] << endl;
                cout << "Enter Quantity: ";
                int quan;
                while (cin >> quan and quan < 1)
                {
                    cout << "Try Again\n";
                }
                mname_quan_price[cus.cofee[take - 1]] = {quan, quan * cus.co_price[take - 1]};
            }
            else
                cout << "Try Aganin\n";
            x = 1;
        }
    }
    else
    {
        int x = 0;
        while (1)
        {
            cout << 0 << " Confirm\n";
            show_tea_price(cus);
            cout << -1 << " back\n";
            if (x)
                cout << "You have selected: \n";
            int i = 1;
            if (mname_quan_price.size() > 0 and x)
                cout << "Name" << setw(15) << ss << "Quantity" << sstt << "Price" << endl;
            else if (!x)
                cout << "Nothing\n";
            for (auto e : mname_quan_price)
                cout << i++ << ss << e.first << setw(5) << ss << e.second.first << sstt << e.second.second << endl;

            int take;
            cin >> take;
            if (take == -1)
                return;

            if (take == 0 and mname_quan_price.size() > 0)
            {
                print();
                break;
            }
            else if (take == 0 and mname_quan_price.size() == 0)
            {
                cout << "You haven't chose any product yet\n";
                cout << "Try Aganin\n";
            }
            else if (take > 0 and take <= cus.tea.size())
            {
                cout << "You have selected " << cus.tea[take - 1] << endl;
                cout << "Enter Quantity: ";
                int quan;
                while (cin >> quan and quan < 1)
                {
                    cout << "Try Again\n";
                }
                mname_quan_price[cus.tea[take - 1]] = {quan, quan * cus.tea_price[take - 1]};
            }
            else
                cout << "Try Aganin\n";
            x = 1;
        }
    }
}
void customersection()
{
    selected.clear();
    price = 0.0;
    cout << "Wellcome Sir/Mam:\n";
    cout << "Which food you want to taste: \n";
    int x = 0;
    while (1)
    {
        show_catagory();

        int i = 1;
        if (x)
            cout << "You have selected: \n";
        if (mname_quan_price.size() > 0 and x)
            cout << setw(15) << "Name" << ss << "Quantity" << sstt << "Price" << endl;
        else if (x)
            cout << "Nothing\n";
        for (auto e : mname_quan_price)
            cout << i++ << ss << setw(5) << e.first << ss << e.second.first << sstt << e.second.second << endl;
        int choice;
        cout << "Enter a catagory :";
        cin >> choice;
        if (choice == 0 and mname_quan_price.size() > 0)
        {
            print();
            break;
        }
        else if (choice == 0 and mname_quan_price.size() == 0)
        {
            cout << "You haven't chose any product yet\n";
            cout << "Try Aganin\n";
        }
        else if (choice > 0 and choice < 5)
            buying_sec(choice);
        else
            cout << "Try Aganin\n";
        x = 1;
    }
}

int main()
{
    FooD food1;
    int choice;
    while (1)
    {
        cout << "Log In As:\n";
        cout << "1 Admin\n";
        cout << "2 Customer\n";
        cin >> choice;
        if (choice == 1)
        {
            string id = "", pass = "";

            while (1)
            {
                cout << "Username: ";
                cin >> id;
                cout << "Pass: ";
                cin >> pass;
                if (id == "admin" and pass == "admin")
                {
                    cout << "Done\n";
                    adminsection();
                    break;
                }
                else
                {
                    cout << "Wrong id and password\n";
                    cout << "Try Again\n";
                }
            }
        }
        else
        {
            customersection();
        }
    }
    return 0;
}

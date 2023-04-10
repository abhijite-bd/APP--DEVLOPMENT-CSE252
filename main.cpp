#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define ss ' '
int i;
map<string, pair<int, int>> all_sell;         // date sale profit
map<string, pair<int, int>> mname_quan_price; // item quantity price
map<string, int> mname_quan_profit;           // item profit
vector<pair<string, pair<string, int>>> selected;
void convert(ofstream &f, string date, pair<int, int> val)
{
    cout << date.substr(0, 2) << "-" << date.substr(2, 2) << "-" << date.substr(4, 4) << "\t" << val.first << "  " << val.second << endl;
    f    << date.substr(0, 2) << "-" << date.substr(2, 2) << "-" << date.substr(4, 4) << "\t" << val.first << "  " << val.second << endl;
}
void show_catagory()
{
    cout << "Category: \n";
    cout << "1. Fast Food\n";
    cout << "2. Drinks\n";
    cout << "3. Cofee\n";
    cout << "4. Tea\n";
}
void load(ifstream &f1, vector<string> &vs1, vector<int> &vs2, vector<int> &vs3)
{
    int k = 0;
    while (!f1.eof())
    {
        string s;
        f1 >> s;
        if (k % 3 == 0)
            vs1.push_back(s);
        else if (k % 3 == 1)
        {
            int d = stoi(s);
            vs2.push_back(d);
        }
        else
        {
            int d = stoi(s);
            vs3.push_back(d);
        }
        k++;
    }
}
class FooD
{
public:
    vector<string> ff_name;
    vector<string> drinks_name;
    vector<string> cofee_name;
    vector<string> tea_name;
    vector<int> ff_price;
    vector<int> d_price;
    vector<int> co_price;
    vector<int> tea_price;
    vector<int> ff_profit;
    vector<int> d_profit;
    vector<int> co_profit;
    vector<int> tea_profit;
    vector<int> ff_qty;
    vector<int> d_qty;
    vector<int> co_qty;
    vector<int> tea_qty;

    FooD()
    {
        ifstream f1, f2, f3, f4, f22;
        f1.open("fastfood_name.txt");
        f2.open("drinks_name.txt");
        f3.open("cofee_name.txt");
        f4.open("tea_name.txt");
        f22.open("transactions.txt");
        string s;
        int price;
        if (!f1 or !f2 or !f3 or !f4 or !f22)
        {
            // is all file are there?
            cout << "Something is wrong!!";
            return;
        }
        int k = 0;
        string pre;
        int pred;
        while (!f22.eof())
        {
            f22 >> s;
            if (k % 3 == 0)
            {
                pre = s;
            }
            else if (k % 3 == 1)
            {
                int d = stod(s);
                pred = d;
            }
            else
            {
                int d = stod(s);
                all_sell[pre] = make_pair(pred, d);
            }
            k++;
        }
        load(f1, ff_name, ff_price, ff_profit);
        load(f2, drinks_name, d_price, d_profit);
        load(f3, cofee_name, co_price, co_profit);
        load(f4, tea_name, tea_price, tea_profit);
    }

    friend void show_ff_price(FooD cus)
    {
        for (i = 0; i < cus.ff_name.size(); i++)
        {
            cout << i + 1 << ss << cus.ff_name[i] << ss << cus.ff_price[i] << endl;
        }
    }
    friend void show_drinks_price(FooD cus)
    {
        for (i = 0; i < cus.drinks_name.size(); i++)
        {
            cout << i + 1 << ss << cus.drinks_name[i] << ss << cus.d_price[i] << endl;
        }
    }
    friend void show_cofee_price(FooD cus)
    {
        for (i = 0; i < cus.cofee_name.size(); i++)
        {
            cout << i + 1 << ss << cus.cofee_name[i] << ss << cus.co_price[i] << endl;
        }
    }
    friend void show_tea_price(FooD cus)
    {
        for (i = 0; i < cus.tea_name.size(); i++)
        {
            cout << i + 1 << ss << cus.tea_name[i] << ss << cus.tea_price[i] << endl;
        }
    }
    friend void show_allproduct(FooD cus)
    {
        int k = 1;
        for (auto e : cus.ff_name)
            cout << k++ << ss << e << endl;
        for (auto e : cus.drinks_name)
            cout << k++ << ss << e << endl;
        for (auto e : cus.cofee_name)
            cout << k++ << ss << e << endl;
        for (auto e : cus.tea_name)
            cout << k++ << ss << e << endl;
    }
};
void add_item(ofstream &f)
{
    string s;
    int price, profit;
    cout << "Enter new name(without space):";
    cin.ignore();
    getline(cin, s);

    if (s.find(' ') != string::npos)
    {
        cout << "Wrong input\n";
        Sleep(1500);
        system("cls");
        return;
    }
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter profit: ";
    cin >> profit;
    f << "\n"
      << s << " ";
    f << price << " ";
    f << profit;
    f.close();
    cout << endl
         << endl;
    cout << "Item added successfully\n";
    Sleep(1500);
    cout << s << " " << price << " " << profit << endl;
    Sleep(1500);
    system("cls");
}
void del_item(ofstream &f, vector<string> &vn, vector<int> &vpri, vector<int> &vpro)
{
    string s;
    int price, profit, k;
    system("cls");
    cout << "Available Items: " << endl;
    for (int i = 0; i < vn.size(); i++)
    {
        cout << i + 1 << ss << vn[i] << ss << vpri[i] << ss << vpro[i] << endl;
    }
    cout << "Enter a number you want to delete: ";
    cin >> k;
    if (k < 1 or k > vn.size())
    {
        cout << "Wrong Input\n";
        return;
    }
    else
    {
        cout << endl;
        Sleep(1500);
        cout << vn[k - 1] << " ";
        cout << vpri[k - 1] << " ";
        cout << vpro[k - 1] << endl;
        cout << "Item deleted successfully\n";
        Sleep(2500);
        vn.erase(vn.begin() + k - 1);
        vpri.erase(vpri.begin() + k - 1);
        vpro.erase(vpro.begin() + k - 1);
        system("cls");
    }
    for (i = 0; i < vn.size(); i++)
    {
        f << vn[i] << " " << vpri[i] << " " << vpro[i];
        if (i + 1 != vn.size())
            f << endl;
    }
    f.close();
}
void modify_item(ofstream &f, vector<string> &vn, vector<int> &vpri, vector<int> &vpro)
{
    string s;
    int price, profit, k;
    system("cls");
    cout << "Available Items: " << endl;
    for (int i = 0; i < vn.size(); i++)
    {
        cout << i + 1 << ss << vn[i] << ss << vpri[i] << ss << vpro[i] << endl;
    }
    cout << "Enter a number you want to modify: ";
    cin >> k;
    if (k < 1 or k > vn.size())
    {
        cout << "Wrong Input\n";
        return;
    }
    else
    {
        cout << "Old item name: " << vn[k - 1] << endl;
        cout << "Enter new name(without space):";
        cin.ignore();
        getline(cin, s);
        if (s.find(' ') != string::npos)
        {
            cout << "Wrong input\n";
            Sleep(1500);
            system("cls");
            return;
        }
        cout << "Old item price: " << vpri[k - 1] << endl;
        cout << "Enter new price: :";
        cin >> price;
        cout << "Old item profit: " << vpro[k - 1] << endl;
        cout << "Enter new profit: ";
        cin >> profit;
        vn[k - 1] = s;
        vpri[k - 1] = price;
        vpro[k - 1] = profit;
        cout << "After Modification: \n";
        cout << s << " " << price << " " << profit << endl;
        Sleep(1500);
    }
    f.clear();
    for (i = 0; i < vn.size(); i++)
    {
        f << vn[i] << " " << vpri[i] << " " << vpro[i];
        if (i + 1 != vn.size())
            f << endl;
    }
    f.close();
    system("cls");
}
void print_transactions(ofstream &f1, int mx)
{
    int count = 0;
    int totalsale = 0;
    int totalprofit = 0;
    cout << "\n\t\t\n";
    cout << setw(10) << "Date" << setw(12) << "Sell" << setw(9) << "Profit\n";
    for (auto it = all_sell.rbegin(); it != all_sell.rend() && count < mx; ++it)
    {
        cout << count + 1 << ss;
        totalsale += it->second.first;
        totalprofit += it->second.second;
        convert(f1, it->first, it->second);
        count++;
    }
    cout << "Day: " << count << endl;
    cout << "Totalsale: " << totalsale << endl;
    cout << "Profit: " << totalprofit << endl;
    f1 << setw(10) << min(mx, count) << setw(15) << totalsale << setw(10) << totalprofit;
    cout << "\n\t\t\n";
    cout << "Transactions history is ready\n";
    cout << "A file is saves to directory\n\n";
}
void adminsection()
{
    system("cls");
    while (1)
    {
        cout << "1. Add Item\n";
        cout << "2. Delete Item\n";
        cout << "3. Modify Item\n";
        cout << "4. Total Sale\n";
        cout << "0. Back to Home\n";
        int choice;
        cin >> choice;
        FooD cus;
        if (choice == 1)
        {
            show_catagory();
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                ofstream f1;
                f1.open("fastfood_name.txt", ios::app);
                add_item(f1);
            }
            else if (ch == 2)
            {
                ofstream f1;
                f1.open("drinks_name.txt", ios::app);
                add_item(f1);
            }
            else if (ch == 3)
            {
                ofstream f1;
                f1.open("cofee_name.txt", ios::app);
                add_item(f1);
            }
            else if (ch == 4)
            {
                ofstream f1;
                f1.open("tea_name.txt", ios::app);
                add_item(f1);
            }
            else
            {
                cout << "Wrong Input\n";
            }
        }
        else if (choice == 2)
        {

            show_catagory();
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                ofstream f1;
                f1.open("fastfood_name.txt", ios::out);
                del_item(f1, cus.ff_name, cus.ff_price, cus.ff_profit);
            }
            else if (ch == 2)
            {
                ofstream f1;
                f1.open("drinks_name.txt", ios::out);
                del_item(f1, cus.drinks_name, cus.d_price, cus.d_profit);
            }
            else if (ch == 3)
            {
                ofstream f1;
                f1.open("cofee_name.txt", ios::out);
                del_item(f1, cus.cofee_name, cus.co_price, cus.co_profit);
            }
            else if (ch == 4)
            {
                ofstream f1;
                f1.open("tea_name.txt", ios::out);
                del_item(f1, cus.tea_name, cus.tea_price, cus.tea_profit);
            }
            else
            {
                cout << "Wrong Input\n";
            }
        }
        else if (choice == 3)
        {
            show_catagory();
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                ofstream f1;
                f1.open("fastfood_name.txt", ios::out);
                modify_item(f1, cus.ff_name, cus.ff_price, cus.ff_profit);
            }
            else if (ch == 2)
            {
                ofstream f1;
                f1.open("drinks_name.txt", ios::out);
                modify_item(f1, cus.drinks_name, cus.d_price, cus.d_profit);
            }
            else if (ch == 3)
            {
                ofstream f1;
                f1.open("cofee_name.txt", ios::out);
                modify_item(f1, cus.cofee_name, cus.co_price, cus.co_profit);
            }
            else if (ch == 4)
            {
                ofstream f1;
                f1.open("tea_name.txt", ios::out);
                modify_item(f1, cus.tea_name, cus.tea_price, cus.tea_profit);
            }
            else
                cout << "Wrong Input\n";
        }
        else if (choice == 4)
        {
            system("cls");

            cout << "1. Last Transactions\n";
            cout << "2. Last 7 days Transactions\n";
            cout << "3. Last month Transactions\n";
            cout << "4. Search Transactions\n";
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                system("cls");
                string date = (*(--all_sell.end())).first;
                auto val = (*(--all_sell.end())).second;
                cout << date.substr(0, 2) << "-" << date.substr(2, 2) << "-" << date.substr(4, 4) << endl;
                cout << "Total sale: " << val.first << endl;
                cout << "Total profit: " << val.second << endl;
            }
            else if (ch == 2)
            {
                system("cls");
                ofstream f1("last_seven_days_sell.txt");
                print_transactions(f1, 7);
            }
            else if (ch == 3)
            {
                system("cls");
                ofstream f1("last_thirty_days_sell.txt");
                print_transactions(f1, 30);
            }
            else if (ch == 4)
            {
                string s;
                cout << "Enter date month and year(without space): ";
                cin >> s;
                if (all_sell.find(s) == all_sell.end())
                    cout << "Transanction history is not found\n";
                else
                {
                    cout << "Sale: " << all_sell[s].first << endl;
                    cout << "Profit: " << all_sell[s].second << endl;
                }
            }
            else
            {
                cout << "Wrong Input\n";
                return;
            }
        }
        else
            return;
    }
}
void print()
{
    system("cls");
    ofstream f1;
    string s, num;
    f1.open("Money Receipt.txt", ios::out);

    int price = 0.0, profit = 0.0;
    f1 << "Wellcome to HSTU Shop\n";
    cout << "Enter your name: ";
    cin >> s;
    cout << "Enter your number: ";
    cin >> num;
    f1 << "Name: " << s << endl;
    f1 << "Number: " << num << endl;

    f1 << endl;
    cout << endl;
    time_t now = time(0);

    tm *datetime = localtime(&now);

    int year = 1900 + datetime->tm_year;
    int month = 1 + datetime->tm_mon;
    int day = datetime->tm_mday;

    // Extract time values
    int hour = datetime->tm_hour;
    int minute = datetime->tm_min;
    int second = datetime->tm_sec;
    f1 << "Date: " << day << "/" << month << "/" << year << endl;
    f1 << "Time: " << hour << ":" << minute << ":" << second << endl;
    system("cls");
    cout << "Name: " << s << endl;
    cout << "Number: " << num << endl;
    cout << "Date: " << day << "/" << month << "/" << year << endl;
    cout << "Time: " << hour << ":" << minute << ":" << second << endl;
    cout << endl;
    int i = 1;
    cout << endl
         << setw(18) << "Name"
         << "  "
         << "Quantity" << ss << setw(8) << "Price" << endl;
    f1 << endl
       << setw(18) << "Name"
       << "  "
       << "Quantity" << ss << setw(8) << "Price" << endl;
    for (auto e : mname_quan_price)
    {
        f1 << i << ss << setw(16) << e.first << "  " << e.second.first << ss << setw(15) << e.second.second << endl;
        cout << i << ss << setw(16) << e.first << "  " << e.second.first << ss << setw(15) << e.second.second << endl;
        i++;
        price += e.second.second;
    }

    f1 << "Total = " << price << endl;
    cout << "Total = " << price << endl;
    for (auto e : mname_quan_profit)
        profit += e.second;
    Sleep(5000);
    string sday, smon;
    sday = to_string(day);
    smon = to_string(month);
    if (sday.size() == 1)
        sday = "0" + sday;
    if (smon.size() == 1)
        smon = "0" + smon;

    string save = sday + smon + to_string(year);
    all_sell[save].first += price;
    all_sell[save].second += profit;

    ofstream f2("transactions.txt", ios::out);
    f2.clear();

    int x = 0;
    for (auto e : all_sell)
    {
        if (x)
        {
            f2 << e.first << ss << e.second.first << ss << e.second.second;
        }
        else
        {
            f2 << endl
               << e.first << ss << e.second.first << ss << e.second.second;
        }
        x = 0;
    }
    mname_quan_price.clear();
    mname_quan_profit.clear();
    selected.clear();
    f2.close();
    f1.close();
}
int price = 0;
void buying_sec(int choice)
{
    system("cls");
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
                cout << "You have selected: ";
            int i = 1;
            if (mname_quan_price.size() > 0 and x)
                cout << endl
                     << setw(18) << "Name"
                     << "  "
                     << "Quantity" << ss << setw(8) << "Price" << endl;
            else if (x)
                cout << "Nothing\n";
            for (auto e : mname_quan_price)
                cout << i++ << ss << setw(16) << e.first << "  " << e.second.first << ss << setw(15) << e.second.second << endl;

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
            else if (take > 0 and take <= cus.ff_name.size())
            {
                cout << "You have selected " << cus.ff_name[take - 1] << endl;
                cout << "Enter Quantity: ";
                int quan;
                while (cin >> quan and quan < 1)
                {
                    cout << "Try Again\n";
                }
                system("cls");
                cout << "Chose another item: \n";
                mname_quan_price[cus.ff_name[take - 1]] = {quan, quan * cus.ff_price[take - 1]};
                mname_quan_profit[cus.ff_name[take - 1]] = cus.ff_profit[take - 1];
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
                cout << "You have selected: ";
            int i = 1;
            if (mname_quan_price.size() > 0 and x)
                cout << endl
                     << setw(18) << "Name"
                     << "  "
                     << "Quantity" << ss << setw(8) << "Price" << endl;
            else if (x)
                cout << "Nothing\n";
            for (auto e : mname_quan_price)
                cout << i++ << ss << setw(16) << e.first << "  " << e.second.first << ss << setw(15) << e.second.second << endl;

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
            else if (take > 0 and take <= cus.drinks_name.size())
            {
                cout << "You have selected " << cus.drinks_name[take - 1] << endl;
                cout << "Enter Quantity: ";
                int quan;
                while (cin >> quan and quan < 1)
                {
                    cout << "Try Again\n";
                }
                system("cls");
                mname_quan_price[cus.drinks_name[take - 1]] = {quan, quan * cus.d_price[take - 1]};
                mname_quan_profit[cus.drinks_name[take - 1]] = cus.d_profit[take - 1];
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
                cout << "You have selected: ";
            int i = 1;
            if (mname_quan_price.size() > 0 and x)
                cout << endl
                     << setw(18) << "Name"
                     << "  "
                     << "Quantity" << ss << setw(8) << "Price" << endl;
            else if (x)
                cout << "Nothing\n";
            for (auto e : mname_quan_price)
                cout << i++ << ss << setw(16) << e.first << "  " << e.second.first << ss << setw(15) << e.second.second << endl;

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
            else if (take > 0 and take <= cus.cofee_name.size())
            {
                cout << "You have selected " << cus.cofee_name[take - 1] << endl;
                cout << "Enter Quantity: ";
                int quan;
                while (cin >> quan and quan < 1)
                {
                    cout << "Try Again\n";
                }
                system("cls");
                mname_quan_price[cus.cofee_name[take - 1]] = {quan, quan * cus.co_price[take - 1]};
                mname_quan_profit[cus.cofee_name[take - 1]] = cus.co_profit[take - 1];
            }
            else
                cout << "Try Aganin\n";
            x = 1;
        }
    }
    else if (choice == 4)
    {
        int x = 0;
        while (1)
        {
            cout << 0 << " Confirm\n";
            show_tea_price(cus);
            cout << -1 << " back\n";
            if (x)
                cout << "You have selected: ";
            int i = 1;
            if (mname_quan_price.size() > 0 and x)
                cout << endl
                     << setw(18) << "Name"
                     << "  "
                     << "Quantity" << ss << setw(8) << "Price" << endl;
            else if (x)
                cout << "Nothing\n";
            for (auto e : mname_quan_price)
                cout << i++ << ss << setw(16) << e.first << "  " << e.second.first << ss << setw(15) << e.second.second << endl;

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
            else if (take > 0 and take <= cus.tea_name.size())
            {
                cout << "You have selected " << cus.tea_name[take - 1] << endl;
                cout << "Enter Quantity: ";
                int quan;
                while (cin >> quan and quan < 1)
                {
                    cout << "Try Again\n";
                }
                system("cls");
                mname_quan_price[cus.tea_name[take - 1]] = {quan, quan * cus.tea_price[take - 1]};
                mname_quan_profit[cus.tea_name[take - 1]] = cus.tea_profit[take - 1];
            }
            else
                cout << "Try Aganin\n";
            x = 1;
        }
    }
    else
    {
        cout << "Wrong Input\n";
        Sleep(2000);
        return;
    }
}
void customersection()
{
    selected.clear();
    price = 0.0;
    cout << "Wellcome Sir/Mam:\n";
    cout << "Categary adding...\n";
    cout << "System Booting...\n";
    //    cout << "Which food you want to taste: \n";
    Sleep(2000);
    int x = 0;
    while (1)
    {
        system("cls");
        show_catagory();
        cout << "0. Confirm\n";
        cout << "-1. Return\n";
        int i = 1;
        if (x)
            cout << "You have selected: ";
        if (mname_quan_price.size() > 0 and x)
            cout << endl
                 << setw(18) << "Name"
                 << "  "
                 << "Quantity" << ss << setw(8) << "Price" << endl;
        else if (x)
            cout << "Nothing\n";
        for (auto e : mname_quan_price)
            cout << i++ << ss << setw(16) << e.first << "  " << e.second.first << ss << setw(15) << e.second.second << endl;
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
        else if (choice == -1)
        {
            system("cls");
            return;
        }
        else
            cout << "Try Aganin\n";
        x = 1;
    }
}

int main()
{
    FooD food1;
    int choice;
    //    for (auto e : all_sell)
    //        cout << e.first << ss << e.second.first << ss << e.second.first << endl;
    while (1)
    {
        cout << "Log In As:\n";
        cout << "1 Admin\n";
        cout << "2 Customer\n";
        cout << "0 Shut Down\n";
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
                if (id == "admin" and pass == "admin" or 1)
                {
                    cout << "Done\n";
                    Sleep(500);
                    system("cls");
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
        else if (choice == 2)
        {
            system("cls");
            customersection();
        }
        else
            return 0;
    }
    return 0;
}

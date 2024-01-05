#include <iostream>
#include <iomanip>
using namespace std;


void PrintCatalog(int Sno, string shopname, int balance, bool filled[], string item_names[], double selling_prices[], int remaining_stock[], int profits[])
{
    cout << "|" << endl << "|" << endl << "|" << endl << "|" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    //cout << setw(40) << shopname << endl;
    //cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << setw(30) << shopname<< setw(50) << "Balance: " << balance <<  endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << "S.No." << setw(30) << "Title" << setw(10) << "Price" << setw(20) << "Remaining"<< setw(20) << "Gains" << endl;
    //cout << setw(10) << "----------" << setw(20) << "----------" << setw(20) << "----------" << setw(20) << "----------" << endl;

    for (int i = 1; i < Sno; i++)
    {
        if(filled[i]==1)
        {
            cout << setw(10) << i << setw(30) << item_names[i] << setw(10) << selling_prices[i] << setw(20) << remaining_stock[i] << setw(20) << profits[i] << endl;
        }
    }
    cout << endl << endl << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << "Sell (S)" << setw(20) << "Order (O)" << setw(20) << "Add Item (A)" << setw(20) << "Remove Item (R)" << setw(20) << "Quit (Q)" <<endl; 
    cout << "-------------------------------------------------------------------------------------------" << endl << endl;
    //cout << setw(1) << "*Press Ctrl+C to Quit" << endl << endl;
}

auto AddItem(int total_items, bool filled[], string item_names[], double selling_prices[], double buying_prices[], int remaining_stock[], int item_box[])
{
    for (int i = 1; i < total_items; i++)
    {
        if(filled[i]==0)
        {
            cout << setw(20) <<"Add Item #" << i << " : " <<endl;
            cout << "Item Name: ";
            cin.ignore();
            getline(cin, item_names[i]);
            //cout << endl;

            cout << "Retail Price: ";
            cin >> selling_prices[i];

            cout << "Cost: ";
            cin >> buying_prices[i];

            cout << "Available Quantity: ";
            cin >> remaining_stock[i];

            cout << "Wholesale Order Quantity: ";
            cin >> item_box[i];

            filled[i] = 1;
            break;
        }
    }  
    return filled, item_names, selling_prices, buying_prices, remaining_stock, item_box;
}


int main() {
    
    int balance, order, profit, rem, buy, sell, box, in1, in2;
    int total_items = 100;

    char selection;
    char yn = 'n';

    string shopname;
    string name;

cout << endl << "Welcome to" << endl;

cout<< " __        __   __     _ _   __   __   __   __   __  _ _   __  __  ___    __     __ ___ __  _ _" << endl;
cout<< "|__  |__| |  | |__|   | | | |__| |  | |__| | __ |__ | | | |__ |  |  |    |__ |_||__  | |__ | | |" << endl;
cout<< " __| |  | |__| |      | | | |  | |  | |  | |__| |__ | | | |__ |  |  |     __| |  __| | |__ | | |" << endl;
    cout << endl;
    cout << "Track sales, Manage inventory and Gain Market Insights for smart business decisions." << endl <<endl;

    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "USER MANUAL:" <<endl;
    cout << "How to use Shop Managment System for making smarter business decisions:" <<endl << endl;

    cout << "'Gains' provides a measure of potential profit from an item. " <<endl;
    cout << "It is the product of an item's market demand and profit-per-item." <<endl;
    cout << "- High Demand (HD) and High Profit (HP) items will have the highest Gains." <<endl;
    cout << "- Low Demand (LD) and Low Profit (LD) items will have lowest Gains." <<endl;
    cout << "- HD-LP and LD-HP items will have Gains inbetween." <<endl <<endl;


    cout << "Products Comparision:" <<endl;
    cout << "Compare multiple items based on their gains to decide which products to discontinue and which ones to invest more into." <<endl <<endl;


    cout << "Market Analysis:" <<endl;
    cout << "Imagine you want to introduce a new product in your store, but you are unsure about its market potential." <<endl;
    cout << "Without investing, you can add it in the system with 0 'available stock' and track its demand." <<endl;
    cout << "Then with enough data and wether or not it meets your desired gains, you can decide to invest in this item or not." <<endl << endl;
    
    cout << "Inventory Management:" <<endl;
    cout << "- Get early reminders to restock when inventory of an item falls below a minimum level." <<endl;
    cout << "- Get insights about potential loss due to not being able to meet demand for an item." << endl <<endl <<endl;
        
    cout << "* SMSys is an open-source business solution by MATEE ULLAH MALIK." << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl <<endl;
    
    cout << "Please Enter the Name of Your Shop: ";
    //cin.ignore();
    getline(cin, shopname);
    cout << "Enter Available Balance: ";
    cin >> balance;

    // Items Variables
    bool filled[total_items] = {};
    string item_names[total_items];
    double buying_prices[total_items] = {};
    double selling_prices[total_items] = {};
    int remaining_stock[total_items] = {};
    int item_box[total_items] = {};
    int profits[total_items] = {};

    

while (selection!='Q' || selection!='q')
{
    PrintCatalog(total_items, shopname, balance, filled, item_names, selling_prices, remaining_stock, profits); 

    cin>> selection;
    
    // Adding Items
    if(selection=='A'|| selection=='a')
    {
        AddItem(total_items, filled, item_names, selling_prices, buying_prices, remaining_stock, item_box);      
    }
    

// Start Selling
if (selection=='S' || selection=='s')
{
    cout << "Item Number: ";
    cin >> in1;
    cout << "Quantity: ";
    cin >> order;

    name = item_names[in1];
    rem =  remaining_stock[in1];
    profit = selling_prices[in1]-buying_prices[in1];
    buy = buying_prices[in1];
    sell = selling_prices[in1];
    box = item_box[in1];
    profits[in1] = profits[in1] + order*profit;

    // Not Available
    if (rem==0)
    {
        cout << "----------------------------------------------------------------------" << endl;
        cout<< setw(20) << "OUT OF STOCK." <<setw(20) << "Potential Loss: " << order*profit << endl;        
        cout << "----------------------------------------------------------------------" << endl;
    }

    // Sold
    if (rem >= order)
    {
        cout << "----------------------------------------------------------------------" << endl;
        cout << setw(20) << "MESSAGE:" << setw(20) << "Sold: " << order << "  " << name << " Profit: " << order*profit << endl;;
        cout << "----------------------------------------------------------------------" << endl;
        remaining_stock[in1] = rem-order;
        balance = balance + order*sell;
    }
    
    // Some Sold, Some not Available
    if (rem < order)
    {
        balance = balance + order*sell;
        remaining_stock[in1] = 0;
        cout << endl << endl << endl << endl << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << setw(20) << "MESSAGE:" << endl;
        cout<< setw(20) << "SOLD: " << rem << setw(20) << "Profit: " << rem*profit << endl;
        cout<< setw(20) << "Not Available: " << order - rem <<setw(20) << "Potential Loss: " << (order-rem)*profit << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << endl << endl << endl << endl << endl;

    }   
    
    // Place Order?
    rem = remaining_stock[in1];
    if (rem <= 3)
    {
        //cout << endl << endl << endl << endl << endl;
        cout<< setw(20) << "ALERT: "<< rem << " " << name  << " Remaining." << endl;
        cout << endl << endl << endl << endl << endl;
        cout << "Order more? Y/N";
        cin >> yn;
        if (yn == 'Y' || yn == 'y')
        {
            
            if (balance >= sell*box)
            {
                remaining_stock[in1]  = rem + box;
                balance = balance - sell*box;
            }else{
                cout<< "Not Enough Balance." << endl;
            }
            
        }
            
    }
    

}

// Remove Item
if (selection=='R' || selection=='r')
{
    cout << "Enter Item Number to Remove: ";
    cin>> in1;
    filled[in1] = 0;
}

// Order More
if (selection=='o' || selection=='O')
{
    if (filled[1]==0)
    {
        cout << "Error: Store is Empty." << endl;
    }else{
    
    cout << "Enter item number to order:";
    cin >> in1;
    in2 = buying_prices[in1]*item_box[in1];  
    if (balance >= in2)
    {
        remaining_stock[in1]  = remaining_stock[in1] + item_box[in1];
        balance = balance - in2;
    }else
    {
        cout<< "Not Enough Balance." << endl;
    }
    }
}

}


    return 0;
}

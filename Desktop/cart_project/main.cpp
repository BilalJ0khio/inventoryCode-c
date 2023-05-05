
#include<iostream>

#include<iomanip>

#include<string>

using namespace std;
int tempStock[4];
int sales[4] = {0,0,0,0};
void clear();
void decor(string ,int,int);
void home(string*,int*,int,int *,int *);
void menu(string*,int*,int,int *,int *);
void cart(string*,int*,int,int *,int *);
void removeItem(string* ,int* ,int ,int *,int *);
void inventory(string*,int*,int,int *,int *);
void cartZero(int*,int);
void salesReport(string*,int* ,int ,int *,int *);






int main()
{
    string itemsName[] = {"Pepsi","Milo","Red Bull","Nestle"};
    int itemsPrice[] = {40,60,300,50};
    int noOfItems = 4;
    int itemsStock[4] = {10,10,10,10};
    
    int itemsCounter[4] ={0,0,0,0};
    
    for(int i=0;i<noOfItems;i++)
        tempStock[i] =itemsStock[i];
    
    home(itemsName, itemsPrice, noOfItems, itemsCounter,itemsStock);
    return 0;
}






void salesReport(string* ItemsName,int* itemsPrice,int noOfitems,int * itemsCounter,int *itemsStock)
{
    decor("Sales Report", 20, 22
          );
    
    int i=0,total=0;
    
    cout<<"# \t Item \t Qty \t Rate \t Price(Rs)"<<endl;
    
        
                total+= sales[0] * itemsPrice[0];
                
                cout<<++i<<"\t "<<ItemsName[0]<<"\t   "<<sales[0]<<"\t "
                <<itemsPrice[0]<<"\t\t "<< (sales[0] * itemsPrice[0] )<<endl;
                
            
        

            total+= sales[1] * itemsPrice[1];
            
            cout<<++i<<"\t "<<ItemsName[1]<<"\t   "<<sales[1]<<"\t "
            <<itemsPrice[1]<<"\t\t "<< (sales[1] * itemsPrice[1] )<<endl;
         
        
                total+= sales[2] * itemsPrice[2];
                cout<<++i<<"\t "<<ItemsName[2]<<"  "<<sales[2]<<"\t "
                <<itemsPrice[2]<<"\t "<<(sales[2] * itemsPrice[2] )<<endl;
          
                total+= sales[3] * itemsPrice[3];
                
                cout<<++i<<"\t "<<ItemsName[3]<<"    "<<sales[3]<<"\t "
                <<itemsPrice[3]<<"\t\t "<<(sales[3] * itemsPrice[3] )<<endl;
            
    
    cout<<"\nTotal:\t\t\t\t\t\t "<<total<<endl;
    
    
    cout<<"\nPress any key to return. . .\n";
    cin.get();
    home(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
}

void cartZero(int * itemsCounter,int noOfitems)
{
    for(int i=0;i<noOfitems;i++)
    {
        itemsCounter[i] = 0;
    }
}




void receipt(string* ItemsName,int* itemsPrice,int noOfitems,int * itemsCounter,int *itemsStock)
{
    clear();
    
    if(   itemsCounter[0]==0
       && itemsCounter[1]==0
       && itemsCounter[2]==0
       && itemsCounter[3]==0
       )
        {
            cout<<"Cart is Empty\n"
                <<"Press any key to continue. . .\n";
            cin.get();

            clear();
            home(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
        }
    else
    {
        int i=0,total=0;
        char option;
        decor("Cart", 25, 25);
        cout<<"#     Item       Qty"<<endl;
        
            if(itemsCounter[0]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[0]<<right<<setw(7)<<itemsCounter[0]<<endl;
            if(itemsCounter[1]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[1]<<right<<setw(8)<<itemsCounter[1]<<endl;
            if(itemsCounter[2]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[2]<<right<<setw(4)<<itemsCounter[2]<<endl;
            if(itemsCounter[3]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[3]<<right<<setw(6)<<itemsCounter[3]<<endl;

        cout<<"\nAre you sure you want to proceed?\n"
            <<"Note: This action is irreversible\n"
            <<"1.\'y\' or \'Y\' for yes \n"
            <<"2.Any other key to cancel\n"
            <<"Enter input:\n";
        cin>>option;
        cin.ignore();
        if(option == 'y' || option == 'Y')
        {
            
            
            decor("Receipt", 23, 24);
            cout<<"# \t Item \t Qty \t Rate \t Price(Rs)"<<endl;
            
                if(itemsCounter[0]!=0)
                    {
                        total+= itemsCounter[0] * itemsPrice[0];
                        tempStock[0] = itemsStock[0];
                        cout<<++i<<"\t "<<ItemsName[0]<<"\t   "<<itemsCounter[0]<<"\t "
                        <<itemsPrice[0]<<"\t\t "<< (itemsCounter[0] * itemsPrice[0] )<<endl;
                        sales[0] +=itemsCounter[0];
                    }
                if(itemsCounter[1]!=0)
                    {
                        total+= itemsCounter[1] * itemsPrice[1];
                        tempStock[1] = itemsStock[1];
                        cout<<++i<<"\t "<<ItemsName[1]<<"\t   "<<itemsCounter[1]<<"\t "
                        <<itemsPrice[1]<<"\t\t "<< (itemsCounter[1] * itemsPrice[1] )<<endl;
                        sales[1] +=itemsCounter[1];
                    }
                if(itemsCounter[2]!=0)
                    {
                        total+= itemsCounter[2] * itemsPrice[2];
                        tempStock[2] = itemsStock[2];
                        cout<<++i<<"\t "<<ItemsName[2]<<"  "<<itemsCounter[2]<<"\t "
                        <<itemsPrice[2]<<"\t "<<(itemsCounter[2] * itemsPrice[2] )<<endl;
                        sales[2] +=itemsCounter[2];
                    }
                if(itemsCounter[3]!=0)
                    {
                        
                        total+= itemsCounter[3] * itemsPrice[3];
                        tempStock[3] = itemsStock[3];
                        cout<<++i<<"\t "<<ItemsName[3]<<"    "<<itemsCounter[3]<<"\t "
                        <<itemsPrice[3]<<"\t\t "<<(itemsCounter[3] * itemsPrice[3] )<<endl;
                        sales[3] +=itemsCounter[3];
                    }
            
            cout<<"\nTotal:\t\t\t\t\t\t "<<total<<endl;
            
            cartZero(itemsCounter, noOfitems);
            cout<<"\nPress any key to return. . .\n";
            cin.get();
            home(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
            
            
            
        }
        else
        {
            home(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
        }
        
        
        
        
    }
    
}



void inventory(string* ItemsName,int* itemsPrice,int noOfitems,int * itemsCounter,int *itemsStock)
{
    clear();
    
    decor("Inventory", 22, 23);
    cout<<" # \t Qty \t Item\n";
    for(int i=0;i<noOfitems;i++)
    {
        cout<<" "<<i+1<<" \t "<<tempStock[i]<<" \t "<<ItemsName[i]<<endl;
    }
    
    
    cout<<"\nPress any key to return. . .\n";
    cin.get();
    home(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
}

void updatedCart(string* ItemsName,int* itemsPrice,int noOfitems,int * itemsCounter,int *itemsStock)
{
    clear();
    int i=0;
    
    if(   itemsCounter[0]==0
       && itemsCounter[1]==0
       && itemsCounter[2]==0
       && itemsCounter[3]==0
       )
        {
            cout<<"Cart is Empty\n"
                <<"Press any key to return. . .\n";
            cin.get();

            clear();
            home(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
        }
    else
    {
        decor("updated Cart", 22, 20);
        cout<<"#     Item       Qty"<<endl;
        
            if(itemsCounter[0]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[0]<<right<<setw(7)<<itemsCounter[0]<<endl;
            if(itemsCounter[1]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[1]<<right<<setw(8)<<itemsCounter[1]<<endl;
            if(itemsCounter[2]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[2]<<right<<setw(4)<<itemsCounter[2]<<endl;
            if(itemsCounter[3]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[3]<<right<<setw(6)<<itemsCounter[3]<<endl;
        removeItem(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
        
        
    }
}


void removeItem(string* ItemsName,int* itemsPrice,int noOfitems,int * itemsCounter,int *itemsStock)
{
    clear();
    
    if(   itemsCounter[0]==0
       && itemsCounter[1]==0
       && itemsCounter[2]==0
       && itemsCounter[3]==0)
    {
        cout<<"Cart is empty.\n";
        cout<<"Press any key to continue. . .\n";
        cin.get();
        cin.ignore();
        
        home(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
        
    }
    else
    {
        int r;
        char option;
        decor("Remove Item", 22, 21);
        for(int i=0;i<4;i++)
        {
            cout<<i+1<<".\t"<<ItemsName[i]<<endl;
            r=i;
        }
        cout<<r+2<<".\t"<<"Return"<<endl;
        
        
        cout<<"\nSelect option:\n";
        cin>>option;
        cin.ignore();
        if(option>=49 && option<=53)
        {
            switch(option)
            {
                case 49: //1
                {
                    if(itemsCounter[0]>0)
                    {
                        itemsCounter[0] = itemsCounter[0]-1;
                        itemsStock[0] = itemsStock[0]+1;
                        cout<<"Your Item has been removed\n";
                        updatedCart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    }
                    else
                        cout<<"you have Zero Pepsi in Cart"<<endl;
                    
                    cout<<"Press any key to continue. . .\n";
                    cin.get();

                    updatedCart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    break;
                }
                    
                    
                case 50: //2
                {
                    if(itemsCounter[1]>0)
                    {
                        itemsCounter[1] = itemsCounter[1]-1;
                        itemsStock[1] = itemsStock[1]+1;
                        cout<<"Your Item has been removed\n";
                        updatedCart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    }
                    else
                        cout<<"You have zero Milo in cart\n"<<endl;
                    cout<<"Press any key to continue. . .\n";
                    cin.get();

                    updatedCart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    break;
                }
                    
                case 51: //3
                {
                    if(itemsCounter[2]>0)
                    {
                        itemsCounter[2] = itemsCounter[2]-1;
                        itemsStock[2] = itemsStock[2]+1;
                        cout<<"Your Item has been removed\n";
                        updatedCart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    }
                    else
                        cout<<"You have zero Red bull in cart\n"<<endl;
                    cout<<"Press any key to continue. . .\n";
                    cin.get();

                    updatedCart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    
                    break;
                }
                    
                case 52: //4
                {
                    if(itemsCounter[3]>0)
                    {
                        itemsCounter[3] = itemsCounter[3]-1;
                        itemsStock[3] = itemsStock[3]+1;
                        cout<<"Your Item has been removed\n";
                        updatedCart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    }
                    else
                        cout<<"You have zero Nestle in cart"<<endl;
                    
                    cout<<"Press any key to continue. . .\n";
                    cin.get();
                    updatedCart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    break;
                }
                    
                    
                    
                case 53: //5
                    home(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                    break;
            }
            
            //            switchEnd
        }
        else
        {
            cout<<"Wrong input\n";
            cout<<"Press any key to continue. . .\n";
            cin.get();
            removeItem(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
        }
        removeItem(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
    }
}

void cart(string* ItemsName,int* itemsPrice,int noOfitems,int * itemsCounter,int *itemsStock)
{
    clear();
    
    
    int i=0;
    
    decor("Cart", 25, 25);
    
    if(   itemsCounter[0]==0
       && itemsCounter[1]==0
       && itemsCounter[2]==0
       && itemsCounter[3]==0
       )
        {
            cout<<"Cart is Empty\n"
                <<"Press any key to return. . .\n";
            cin.get();
            home(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
        }
    
    else
    {
        
        cout<<"#     Item       Qty"<<endl;
        
            if(itemsCounter[0]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[0]<<right<<setw(7)<<itemsCounter[0]<<endl;
            if(itemsCounter[1]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[1]<<right<<setw(8)<<itemsCounter[1]<<endl;
            if(itemsCounter[2]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[2]<<right<<setw(4)<<itemsCounter[2]<<endl;
            if(itemsCounter[3]!=0)
                cout<<left<<setw(6)<<++i<<ItemsName[3]<<right<<setw(6)<<itemsCounter[3]<<endl;
        
    }
    
    cout<<"Press any key to return. . .\n";
    cin.get();
    menu(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
}


///////////////////////////////////////////////////////////
void menu(string* ItemsName,int* itemsPrice,int noOfitems,int * itemsCounter,int *itemsStock)
{
 
    clear();
    int r;
    char option;
    decor("Menu", 25, 25);
    
    cout<<"#"<<setw(11)<<right<<"Item"<<right<<setw(12)<<"Price(Rs)\n";
    
    for(int i=0;i<4;i++)
    {
        cout<<i+1<<"."<<setw(10)<<ItemsName[i]<<setw(8)<<itemsPrice[i]<<endl;
        r=i;
    }
    cout<<r+2<<"."<<setw(10)<<"Return"<<endl;
    
            cout<<"\nSelect from above option:\n";
            cin>>option;
            cin.ignore();
            cout<<"\n";
                        
            if(option>=49 && option<=53)
            {
                switch(option)
                {
                    case 49: //1
                    {
                        if(itemsStock[0]>0)
                        {
                            itemsCounter[0] = itemsCounter[0]+1;
                            itemsStock[0] = itemsStock[0]-1;
                            cart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                        }
                        else
                            cout<<"Item is out of stock"<<endl;
                        cout<<"Press any key to return. . .\n";
                        cin.get();
                        break;
                    }
                        
                        
                    case 50: //2
                    {
                        if(itemsStock[1]>0)
                        {
                            itemsCounter[1] = itemsCounter[1]+1;
                            itemsStock[1] = itemsStock[1]-1;
                            cart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                        }
                        else
                            cout<<"Item is out of stock"<<endl;
                        cout<<"Press any key to return. . .\n";
                        cin.get();
                        break;
                    }
                        
                    case 51: //3
                    {
                        if(itemsStock[2]>0)
                        {
                            itemsCounter[2] = itemsCounter[2]+1;
                            itemsStock[2] = itemsStock[2]-1;
                            cart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                        }
                        else
                            cout<<"Item is out of stock"<<endl;
                        cout<<"Press any key to return. . .\n";
                        cin.get();
                        break;
                    }
                        
                    case 52: //4
                    {
                        if(itemsStock[3]>0)
                        {
                            itemsCounter[3] = itemsCounter[3]+1;
                            itemsStock[3] = itemsStock[3]-1;
                            cart(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                        }
                        else
                            cout<<"Item is out of stock"<<endl;
                        
                        cout<<"Press any key to return. . .\n";
                        cin.get();
                        break;
                    }
                        
                        
                        
                    case 53: //5
                        home(ItemsName,itemsPrice,noOfitems,itemsCounter,itemsStock);
                        break;
                        
                }
                clear();
                menu(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
            }
            
            else
                {
                    cout<<"Wrong Input choose the right option\n";
                    menu(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
                }
        }
    
///////////////////////////////////////////////////////////////////////

void home(string* ItemsName,int* itemsPrice,int noOfitems,int * itemsCounter,int * itemsStock)
{
    clear();
    decor("Main Menu", 23, 22);
    cout<<"1. Enter Menu\n"
        <<"2. View Cart\n"
        <<"3. Remove Item\n"
        <<"4. Generate Bill / Checkout\n"
        <<"5. Inventory\n"
        <<"6. clear Cart\n"
        <<"7. View Sales Report\n";
    
    char option;
    cout<<"\nSelect from above option: \n";
    cin>>option;
    cin.ignore();
    cout<<"\n";
    
        if(option>=49 && option<=55)
        {
            switch (option)
            {
                case 49:
                    menu(ItemsName, itemsPrice, noOfitems,itemsCounter,itemsStock);
                    break;
                    
                case 50:
                    cart(ItemsName, itemsPrice, noOfitems,itemsCounter,itemsStock);
                    break;
                case 51:
                    removeItem(ItemsName, itemsPrice, noOfitems,itemsCounter,itemsStock);
                    break;
                case 52:
                    receipt(ItemsName, itemsPrice, noOfitems,itemsCounter,itemsStock);
                    break;
                
                case 53:
                    inventory(ItemsName, itemsPrice, noOfitems,itemsCounter,itemsStock);
                    break;
                case 54:
                    cartZero(itemsCounter, noOfitems);
                    cout<<"your cart has been cleard.\n\n"
                    <<"Press any key to return. . .\n";
                    cin.get();
                    home(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
                    break;
                
                default:
                    salesReport(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
                    break;
            }
        }
        
        else
            {
                cout<<"Wrong Input chose right option\n";
                home(ItemsName, itemsPrice, noOfitems, itemsCounter, itemsStock);
            }
        
        cin>>option;
        cin.ignore();
        clear();
    }

///////////////////////////////////////////////////////////////////////


void decor(string functionName,int indent1,int indent2)
{
    
    cout<<left;
    cout<<"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒"<<endl
        <<setw(indent1)<<"▒"<<functionName<<setw(indent2)<<right<<"▒"<<endl
        <<"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n";
}

void clear()
{
    cout<<"_______________________________________________\n\n";
}


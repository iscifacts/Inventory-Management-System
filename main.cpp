#include<bits/stdc++.h>
using namespace std;
struct item{
    int item_id;
    string item_name;
    int item_price;
    int item_amount;
    string item_type;
    string item_shelf_number;
    bool operator <(const item &a)const{
        return item_id < a.item_id;
    }
};

class program{
    private:
    vector<item> a;
    public:
    bool check_id(int x)
    {
        for(int i=0;i<a.size();i++)
       {
        if(x==a[i].item_id)
        {
            return false;
        }
       }
       return true;
    }
    int new_item_id()
    {
        bool y=false;
        int x;
        while(!y)
        {
            cout<<"Enter Item Id: "<<endl;
            cin>>x;
            y=check_id(x);
            if(!y)
            {
                cout<<"Invalid ID!! Enter new ID."<<endl;
            }
        }
        return x;

    }
    string new_item_name()
    {
        string x;
        cout<<"Enter the name of the item"<<endl;
        cin>>x;
        return x;
    }
    int new_item_price()
    {
        int x;
        cout<<"Enter price of the item:"<<endl;
        cin>>x;
        return x;
    }
     int new_item_amount()
    {
        int x;
        cout<<"Enter amount of the item:"<<endl;
        cin>>x;
        return x;
    }
    string new_item_type()
    {
        string x;
        cout<<"Enter type of the item "<<endl;
        cin>>x;
        return x;
    }
    string new_shelf_number()
    {
        string x;
        cout<<"Enter shelf number where you want to place this item: "<<endl;
        cin>>x;
        return x;
    }
    item Insert_item()
    {
        item Items;
        Items.item_id=new_item_id();
        Items.item_name=new_item_name();
        Items.item_price=new_item_price();  
        Items.item_amount=new_item_amount();
        Items.item_type=new_item_type();
        Items.item_shelf_number=new_shelf_number();
        return Items;
    }
    int fromstoi(string x)
    { 
        int ret=0;
        for (int i = 0; i < x.length(); ++i) 
        {
            while(isdigit(x[i]))
            {
                int temp=x[i++]-'0';
                ret=(ret*10) + temp;
            }
        }
         return ret;
    }
    void displayAll()
    {
        cout<<"---------------------------------------------------"<<endl;
        for(int i=0;i<a.size();i++)
        {
                cout<<"\t \t \t Item Details: "<<i+1<<endl;
                cout<<"Item ID:   "<<a[i].item_id<<endl;
                cout<<"Name of the item:  "<<a[i].item_name<<endl;
                cout<<"Price per unit:  "<<a[i].item_price<<endl;
                cout<<"Amount in stock:   "<<a[i].item_amount<<endl;
                cout<<"Type of item:   "<<a[i].item_type<<endl;
                cout<<"Shelf Number:  "<<a[i].item_shelf_number<<endl;
                cout<<"---------------------------------------------------"<<endl;
        }
    
        //cout<<a.size()<<endl;
        cout<<"----------------------------------------------------"<<endl;

        
    }
    int search_item(int id)
    {
        sort(a.begin(),a.end());
        int s=0;
        int e=(int)a.size()-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(a[mid].item_id==id)
            return mid;
            else if(a[mid].item_id>id)
            e=mid-1;
            else
            s=mid+1;
        }   
        return -1;

    }
    int update_by_id(int id)
    {
        int idx=search_item(id);
        if(idx==-1)
        return -1;
        else{
            cout<<"Item Id: "<<a[idx].item_id<<endl;
            cout<<"Item name: "<<a[idx].item_id<<endl;
            cout<<"Item amount: "<<a[idx].item_amount<<endl;
            cout<<"Item Price: "<<a[idx].item_price<<endl;
            cout<<"Item Shelf Number"<<a[idx].item_shelf_number<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"Enter New amount for item: "<<endl;
            cin>>a[idx].item_amount;
            cout<<"Item Updated Successfully! "<<endl;

        }
        return idx;
    }
    int delete_by_id(int id)
    {
        int idx=search_item(id);
        if(idx==-1)
        return -1;
        else
        {
            vector<item>b;
            for(int i=0;i<a.size();i++)
            {
                if(i!=idx)
                {
                    b.push_back(a[i]);
                }
                a=b;
            }
            return idx;
        }
    }
    void insertitemtofile(){
        sort(a.begin(),a.end());
        fstream file("file.txt");
        file.open("file.txt",ios::out);
        for(int i = 0 ; i < a.size() ; i++){
            item Item=a[i];
            if(Item.item_id!=0)
            {
                if(i){
                    file<<endl<<Item.item_id<<" | ";
                    file<<Item.item_name<<" | ";
                    file<<Item.item_amount<<" | ";
                    file<<Item.item_price<<" | ";
                    file<<Item.item_type<<" | ";
                    file<<Item.item_shelf_number<<" | ";

                }
                else
                {
                    file<<Item.item_id<<" | ";
                    file<<Item.item_name<<" | ";
                    file<<Item.item_amount<<" | ";
                    file<<Item.item_price<<" | ";
                    file<<Item.item_type<<" | ";
                    file<<Item.item_shelf_number<<" | ";

                }
            }}
        
        file.close();
    }
    void readAllitems()
    {
        fstream file;
        file.open("file.txt",ios::in);
        string temp ;
        if ( file.is_open() ){
            while ( getline(file, temp, '|') ) {
                item newItem ;
                getline( file , temp , '|' ) ;
                newItem.item_id = fromstoi( temp ) ;
                getline( file , temp , '|' ) ;
                newItem.item_name = temp ;
                getline( file , temp , '|' ) ;
                newItem.item_amount = fromstoi( temp ) ;
                getline( file , temp , '|' ) ;
                newItem.item_price = fromstoi( temp ) ;
                getline( file , temp , '|' ) ;
                newItem.item_type = temp ;
                getline( file , temp , '|' ) ;
                newItem.item_shelf_number = temp ;
                a.push_back( newItem ) ;
            }
        }
        file.close();
    }
    void clearItemsFromMemory (){
        a.clear() ;
    }
    void display_one_item(int idx)
    {
                cout<<"\t \t \t Item Details: "<<idx+1<<endl;
                cout<<"Item ID:\t\t"<<a[idx].item_id<<endl;
                cout<<"Name of the item:\t"<<a[idx].item_name<<endl;
                cout<<"Price per unit:\t"<<a[idx].item_price<<endl;
                cout<<"Amount in stock:\t"<<a[idx].item_amount<<endl;
                cout<<"Type of item:\t\t"<<a[idx].item_type<<endl;
                cout<<"Shelf Number:\t\t"<<a[idx].item_shelf_number<<endl;
                cout<<"---------------------------------------------------"<<endl;
    }
  
    void mainprogram() {
    cout << "Welcome to Agrawal General Store" << endl;
    int ch;
    do {
        cout << "Enter 1 to Display Items." << endl;
        cout << "Enter 2 to Insert an Item." << endl;
        cout << "Enter 3 to Search for an Item." << endl;
        cout << "Enter 4 to Update Item Amount." << endl;
        cout << "Enter 5 to Delete Item." << endl;
        cout << "Enter 6 to Exit." << endl;
        cin >> ch;

        switch (ch) {
            case 1: {
                readAllitems();
                displayAll();
                clearItemsFromMemory();
                break;
            }
            case 2: {
                readAllitems();
                a.push_back(Insert_item());
                

                displayAll();
                insertitemtofile();
               clearItemsFromMemory();
                break;
            }
            case 3: {
                readAllitems();
                int id;
                cout << "Enter the ID of the item you want to search: ";
                cin >> id;
                int idx = search_item(id);
                if (idx == -1) {
                    cout << "Item not found!" << endl;
                } else {
                    display_one_item(idx);
                }
                clearItemsFromMemory();
                break;
            }
            case 4: {
                readAllitems();
                int id;
                cout << "Enter the ID of the item you want to update: ";
                cin >> id;
                int idx = update_by_id(id);
                if (idx == -1) {
                    cout << "Item not found. Please try again later." << endl;
                } else {
                    cout << "Item updated successfully." << endl;
                    insertitemtofile();
                    clearItemsFromMemory();
                }
                break;
            }
            case 5: {
                int id;
                cout << "Enter the ID of the item you want to delete: ";
                cin >> id;
                int idx = delete_by_id(id);
                if (idx == -1) {
                    cout << "Item not found. Please try again later." << endl;
                } else {
                    insertitemtofile();
                    clearItemsFromMemory();
                }
                break;
            }
            case 6: {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
    } while (ch != 6);
    }

};
int main()
{
    program myproj;
    myproj.mainprogram();
    // // myproj.a.push_back(myproj.Insert_item());
    // // myproj.insertitemtofile(); // Write updated items to the file
    // // myproj.clearItemsFromMemory(); // Clear items from memory

    // // Display all items
    // myproj.readAllitems(); // Read all items again from the file
    // myproj.displayAll(); // Display all items
    

    return 0;
}
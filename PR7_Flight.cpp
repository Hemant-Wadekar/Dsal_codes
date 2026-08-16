#include<iostream>
using namespace std;

class graph{
    public:
        string city[10];
        int arr[10][10] = {0},n;

        void create();
        void display();
};

void graph::create(){
    cout<<"Enter number of cities to add :";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter name of City "<<i+1<<": ";
        cin>>city[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i + 1;j<n;j++){
            cout<<"Enter time required from "<<city[i]<<" to "<<city[j]<<" for flight :";
            cin>>arr[i][j];
            arr[j][i] = arr[i][j];
        }
    }
}

void graph::display(){
    cout<<"\t";
    for(int i=0;i<n;i++){
        cout<<city[i]<<"\t";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<city[i]<<"\t";
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{	
	cout<<"DSAL PRACTICAL NO 7"<<endl;
	cout<<"GRAPH REPRENTATION USING ADJACENCY LIST"<<endl;
	
	graph g;
    int ch;

    while (true) {
        cout << "\nMENU:\n";
        cout << "1. Create\n2. Display\n3. Exit\nEnter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                g.create();
                break;

            case 2:
                g.display();
                break;

            case 3:
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

#include <iostream>
#include <bits/stdc++.h>
#include<windows.h>
#include<iomanip>
#include <conio.h>
using namespace std;
void switchcase(int);
void dijkstra(int, int, int);
void searchFlight();
void book(string s, string d, int def, int fno);
void Delete();
void display();
void line();
void line2();
int no_of_paths = 0;
void Sleep(
    DWORD dwMilliseconds);
long int flightNo = 672832;
string cities[14] = {"Mumbai", "Delhi", "Gandhinagar", "Kolkata", "Shahpur", "Vishakapatnam", "Lucknow", "Madurai", "Manipur", "Jaipur", "Ooty", "Chandigarh", "Patna", "Banglore"};
int adjMatrixTime[14][14] = {{0, 2, 5, 0, 0, 0, 0, 0, 8, 3, 0, 0, 0, 0},
                             {2, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0},
                             {0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
                             {0, 0, 0, 0, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0},
                             {11, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 7, 8, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                             {0, 6, 0, 0, 0, 5, 0, 7, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                             {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0},
                             {0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 10, 0, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 4},
                             {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 4, 0}};
int adjMatrixCost[14][14] = {{0, 40, 100, 0, 0, 0, 0, 0, 45, 60, 0, 0, 0, 0},
                             {55, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0},
                             {0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80},
                             {0, 0, 0, 0, 15, 65, 0, 0, 0, 0, 0, 0, 0, 0},
                             {10, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 50, 75, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
                             {0, 25, 0, 0, 0, 30, 0, 10, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
                             {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0},
                             {0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 60, 0, 45, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 0, 50},
                             {0, 0, 0, 0, 0, 35, 0, 0, 0, 0, 0, 0, 15, 0}};
int visited[14];
int path[14];
int path_index = 0;
vector<vector<int>> pathcost(14);
struct node
{
    string s, d, name, pass, age, date;
    int ticket_id;
    struct node *next;
} *booked = NULL;
#define I 32767
int getMinDist(int distance[], int visited[])
{
    int V = 14;
    int min = I, i, vertex = 0;
    for (i = 0; i < V; i++)
    {
        if (visited[i] == 0 && distance[i] <= min)
        {
            min = distance[i];
            vertex = i;
        }
    }
    return vertex;
}
int getLoop(int visited[])
{
    int V = 14;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
            return 1;
    }
    return 0;
}
void switchcase(int i)
{
    if (i == 1)
        searchFlight();
    else if (i == 2)
        book("a", "b", 0, 0);
    else if (i == 3)
        Delete();
    else if (i == 4)
        display();
    else if (i == 5)
        return;
    else
        cout << "Enter some valid choice " << endl;
}
void dijkstra(int adjMatrix[14][14], int startVertex, int destination)
{
    int V = 14;
    int source = startVertex;
    int i;
    vector<vector<int>> paths(14);
    int prev[14] = {0};
    int distance[V];
    int visited[V];
    for (i = 0; i < V; i++)
    {
        if (adjMatrix[startVertex][i] != 0)
        {


            distance[i] = adjMatrix[startVertex][i];
            prev[i]=source;
        }
        else
            distance[i] = I;
        visited[i] = 0;
    }
    distance[startVertex] = 0;
    visited[startVertex] = 1;
    prev[source]=-1;
    while (getLoop(visited))
    {
        startVertex = getMinDist(distance, visited);
        visited[startVertex] = 1;

        for (i = 0; i < V; i++)
        {
            if (i == startVertex || i == source)
                continue;
            if (adjMatrix[startVertex][i] != 0 && visited[i] == 0)
            {
                if (distance[startVertex] + adjMatrix[startVertex][i] < distance[i])
                {
                    distance[i] = distance[startVertex] + adjMatrix[startVertex][i];
                    prev[i] = startVertex;
                }
            }
        }
    }
    for (i = 0; i < V; i++)
    {
        paths[i].push_back(i);
        if(i!=source)
        {
        int d = prev[i];
        while (d != -1)
        {
            paths[i].push_back(d);
            d = prev[d];
        }
        //paths[i].push_back(source);
        }
    }
    i = destination;
    int u = paths[i].size() - 1, flag = 0;
    cout << cities[paths[i][u]];
    for (u = paths[i].size() - 2; u >= 0; u--)
    {
        flag = 1;
        cout << " -> " << cities[paths[i][u]];
    }
    if (!flag)
    {
        cout << "No flights available.";
    }
    cout << endl;
}
void printAllPathsUntil(int adj[14][14], int u, int d)
{
    visited[u] = 1;
    path[path_index] = u;
    path_index++;
    int pathcost = 0, pathTime = 0;
    if (u == d)
    {
        if(path_index<=7)
        {
        flightNo++;
        for (int i = 0; i < path_index - 1; i++)
        {
            pathcost += adjMatrixCost[path[i]][path[i + 1]];
            pathTime += adjMatrixTime[path[i]][path[i + 1]];
        }

        cout<<setw(5)<<flightNo<<setw(15)<<pathTime<<" hrs"<<setw(15)<<"Rs."<<pathcost
        <<setw(20);
        for (int i = 0; i < path_index - 1; i++)
        {

            cout << cities[path[i]] << " -> ";
        }
        cout << cities[path[path_index - 1]] << endl;
        line();
        no_of_paths++;
        cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < 14; ++i)
        {
            if (!visited[i] && adj[u][i])
                printAllPathsUntil(adj, i, d);
        }
    }
    path_index--;
    visited[u] = 0;
}

void printAllPaths(int adj[14][14], int s, int d)
{

    for (int i = 0; i < 14; i++)
        visited[i] = 0;
    Sleep(1000);
    printAllPathsUntil(adj, s, d);
}
void searchFlight()
{
    int i, j, l = 0;
    int source, destination;
    do
    {
        cout << " * Enter source city : " <<endl;
        for (i = 0; i < 14; i++)
        {
            for (j = i; j < i + 3; j++)
            {
                cout<<"    ";
                if (j <= 13)
                {
                    cout <<"Press " << j + 1 << "." << cities[j] << "\t\t";
                }
                else
                {
                    break;
                }
            }
            i = j - 1;
            cout << endl;
        }
        cout << "Enter your choice : ";
        cin >> source;
        source--;
        if (source < 0 || source > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
    } while (source < 0 || source > 14);
    do
    {
        cout <<endl<< "* Enter destination city : " <<endl;
        for (i = 0; i < 14; i++)
        {
            for (j = i; j < i + 3; j++)
            {
                cout<<"    ";
                if (j <= 13)
                {
                    cout << "Press " << j + 1 << "." << cities[j] << "\t\t";
                }
                else
                {
                    break;
                }
            }
            i = j - 1;
            cout << endl;
        }
        cout << "Enter your choice : ";
        cin >> destination;
        destination--;
        if (destination < 0 || destination > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        if (destination == source)
        {
            cout << "PLEASE ENTER A VALID DESTINATION OTHER THAN THE SOURCE" << endl;
        }
    } while ((destination < 0 || destination >= 14) || destination == source);

    cout << "       Searching all flights ";
    for(int wait=0;wait<5;wait++)
    {
        cout<<"./";
        Sleep(500);
    }
    cout<<"\n\n";
    cout<<setw(55)<<"~ FLIGHT TABLE ~\n";
    line();
    cout<<setw(5)<<"FlightNo"<<setw(15)<<"Time"<<setw(25)<<"Cost of ticket"
     <<setw(20)<<"Route"<<endl;
    line();
    printAllPaths(adjMatrixCost, source, destination);
    cout<<"+------------------------------------+"<<endl;
    cout<<"| The most time efficient route is : | ";
    dijkstra(adjMatrixTime, source, destination);
    cout<<"+------------------------------------+"<<endl;

    cout<<"+-------------------------------------+"<<endl;
    cout<<"| The most pocket friendly route is : | ";
    dijkstra(adjMatrixCost, source, destination);
    cout<<"+-------------------------------------+"<<endl;

    cout << endl;
    do
    {
        cout<<"\t\t\t\t   ~ MENU ~ "<<endl;
        cout<<"\t   _____";
        cout << "\n\n\t\t * Press 1.Search Flight\n\t\t * Press 2.Book Flight\n\t\t * Press 3.Exit" << endl;
        cout<<"\t   _____";
        cout <<endl<<endl<<"Enter your choice : ";
        cin >> i;
        if (i < 1 || i > 3)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
    } while (i <= 0 || i >= 4);
    if (i == 1)
    {
        for (j = 0; j < pathcost.size(); j++)
        {
            pathcost[j].clear();
        }
        no_of_paths = 0;
        searchFlight();
    }
    if (i == 2)
    {
        long int fno;
        book(cities[source], cities[destination], 1, fno);
    }
    if (i == 3)
    {
    }
}
void display()
{
    struct node *p;
    if (booked != NULL)
    {

        cout<<setw(45)<<"~ BOOKED TICKETS ~\n";
        line2();
        cout<<setw(5)<<"Date"<<setw(20)<<"TicketID"<<setw(15)<<"Name"<<setw(20)<<"Route"<<endl;
        line2();
    }
    else
    {
        cout << "   * Oops!No tickets booked till now !" << endl;
    }

    p = booked;
    while (p != NULL)
    {
        cout<<setw(5)<<p->date<<setw(15)<<p->ticket_id<<setw(18)<<p->name<<setw(15)<<p->s<<" -> "<<p->d<<endl;
        line2();
        p = p->next;
    }
    cout << endl;
}

void Delete()
{
    int id;
    cout <<" ~ Welcome aboard Flier ! ~" << endl;
    cout << " * Enter ticket id to be canceled :";
    cin >> id;
    struct node *p = booked, *q;
    while (p != NULL)
    {
        q = p;
        if (p->ticket_id == id)
        {
            if (p == booked)
            {
                booked = booked->next;
                delete p;
                cout << "   The given ticket was canceled ! " << endl;
                cout<<"    *Thank You "<<endl;
                return;
            }
            else
            {
                q->next = p->next;
                cout << "   The given ticket was canceled ! " << endl;
                cout<<"    *Thank You "<<endl;
                delete p;
                return;
            }
        }
    }
    cout << "   --> No such ticket with the given id found ! " << endl;
}

void book(string s, string d, int def, int fno)
{
    string name, pass, age, date;
    struct node *t, *p;
    time_t now = time(0);
    cout << " ~ Welcome aboard Flier ! ~" << endl;
    cout << " * Enter your name: ";
    cin >> name;
    fflush(stdin);
    cout << " * Enter passport id: ";
    cin >> pass;
    fflush(stdin);
    cout << " * Enter your age : ";
    cin >> age;
    cout << " * Enter date of travel: ";
    cin >> date;
    if (def != 1)
    {
        cout << " * Enter source city : ";
        cin >> s;
        cout << " * Enter destination city: ";
        cin >> d;
    }
    cout << " * Enter flight No : ";
    cin >> fno;
    fflush(stdin);
    if (booked == NULL)
    {
        t = new node;
        t->s = s;
        t->d = d;
        t->name = name;
        t->age = age;
        t->date = date;
        t->pass = pass;
        t->ticket_id = now;
        t->next = NULL;
        booked = t;
        cout<<"Booking your flight ";
        for(int wait=0;wait<5;wait++)
        {
        cout<<"..";
        Sleep(500);
        }
        cout <<endl<< "   Your seat is booked for flight " << fno << " from " << s << " to " << d << " with TicketId " << now << " on " << date <<"." <<endl;
        cout << "   Thank you !!" << endl;
        cout<<endl;
    }
    else
    {
        p = booked;
        struct node *q;
        while (p)
        {
            q=p;
           p = p->next;
        }

        t = new node;
        t->s = s;
        t->d = d;
        t->name = name;
        t->age = age;
        t->date = date;
        t->ticket_id = now;
        t->pass = pass;
        t->next = NULL;
        q->next=t;
        cout<<"Booking your flight ";
        for(int wait=0;wait<5;wait++)
        {
        cout<<"..";
        Sleep(500);
        }
        cout <<endl<< "   Your seat is booked for flight " << fno << " from " << s << " to " << d << " with TicketID " << now << " on " << date <<"."<< endl;
        cout << "   Thank you !!" << endl;
        cout<<endl;
    }
}

void line()
{
    for(int i=1;i<70;i++)
        cout<<"--";
    cout<<"+";
    cout<<"\n";
}
void line2()
{
    for(int i=1;i<50;i++)
        cout<<"--";
    cout<<"+";
    cout<<"\n";
}
int main()
{
    int i = 0;
    cout<<"\a";
    Sleep(2000);
    cout << "\n\n\tWelcome To Flight Reservation System" << endl<< endl;
    cout << "   <><><><><><><><><><><><><><><><><><><><><><><>\n";
    cout << "   Book your Flight tickets at affordable prices!" << endl;
    cout << "   <><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    do
    {
        cout<<"\n\t\t   ~ MAIN MENU ~ "<<endl;
        cout<<"   _____";
        cout << "\n\n\t * Press 1.Search Flight\n\t * Press 2.Book Flight\n\t * Press 3.Cancel Flight\n\t * Press 4.View your Bookings\n\t * Press 5.Exit" << endl;
        cout<<"   _____";
        cout <<endl<<endl<<"Enter your choice : ";
        cin >> i;
        if (i < 1 || i > 5)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        switchcase(i);
    } while (i != 5);
    cout<<"\t\t\t\t Exiting ";
    for(int wait=0;wait<5;wait++)
    {
        cout<<"..";
        Sleep(500);
    }
    cout<<"\n\t\t\t\t Thank You, Have a Nice day ! :D"<<endl;
return 0;
}
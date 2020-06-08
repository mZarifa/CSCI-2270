/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/


#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = NULL;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    if (previous == NULL) // insert before the head
    {
        Country* newCountry = new Country;
        newCountry -> name = countryName;
        newCountry -> next = head;
        head = newCountry;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    }
    else
    {
        Country* newNode = new Country;
        newNode -> name = countryName;
        newNode -> next = previous -> next;
        previous -> next = newNode;
        cout << "adding: " << countryName << " (prev: " << previous-> name << ")" << endl;
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    string initalCountries[6] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    Country* bigCountry;
    Country* previous = new Country;
    for (int i = 0; i < 6; i++)
    {
        bigCountry = new Country;
        bigCountry -> name = initalCountries[i];
        bigCountry -> message = "";
        bigCountry -> numberMessages = 0; //check this for message system
        bigCountry -> next = NULL;

        if (i == 0)
        {
            head = bigCountry;
            previous = head;
            cout << "adding: " << bigCountry -> name << " (HEAD)" << endl;
        }
        else
        {
            cout << "adding: " << bigCountry -> name << " (prev: " << previous -> name << ")" << endl;
            previous -> next = bigCountry;
            previous = bigCountry;
        }
    }
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    Country* checker = head;

    while (checker != NULL && checker -> name != countryName)
    {
        checker = checker -> next;
    }
    return checker;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */

/*void CountryNetwork::transmitMsg(string receiver, string msg)
{
    Country* currentCountry  = head;
    currentCountry -> message = msg;
    Country* nextCountry = new Country;
    while (currentCountry -> name != receiver) 
    {
        currentCountry -> numberMessages++;
        cout << currentCountry -> name << " [# messages received: " << currentCountry -> numberMessages << "] received: " << 
        msg << endl;
        if (currentCountry -> next != NULL)
        {
            currentCountry -> next -> message = currentCountry -> message;
            nextCountry = currentCountry;
        }
        currentCountry = currentCountry -> next;
    }
    
    currentCountry -> numberMessages++;
    cout << currentCountry -> name << " [# messages received: " << currentCountry -> numberMessages << "] received: " << 
    msg << endl;
}
*/

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */

void CountryNetwork::printPath()
{
    Country* checker = head;
    while (checker != NULL)
    {
        cout << checker -> name << " -> ";
        checker = checker -> next;
    }
    cout << "NULL" << endl;
}

void CountryNetwork::deleteCountry(string countryName)
{
    Country *start = head;
    if(start && start->name.compare(countryName) == 0)
    {
        head = head-> next;
        return;
    }
    while(start->next != NULL && start->next->name.compare(countryName) != 0)
    {
        start = start->next;
    }

    if(start->next != NULL)
    {
        Country *deleter = start->next;
        start->next = deleter->next;
        delete deleter;
        return;
    }
    else
    {
        cout << "Country does not exist." << endl;
    }
}

void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    Country* newCountry = new Country;
    newCountry -> name = countryName;
    newCountry -> message = "";
    newCountry -> numberMessages = 0;
    newCountry -> next = NULL;
    if (previous == NULL)
    {
        newCountry -> next = head;
        head = newCountry;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    }
    else
    {
        newCountry -> next = previous -> next;
        previous -> next = newCountry;
        cout << "adding: " << countryName << " (prev: " << previous -> name << ")" << endl;
    }
}

void CountryNetwork::deleteEntireNetwork()
{
    Country *start = head;
    while(start != NULL)
    {
        Country *del = start;
        start = start->next;
        cout << "deleting: " << del->name << endl;
        delete del;
    }
    cout << "Deleted network" << endl;
    head = NULL;
}

Country* CountryNetwork::createLoop(string countryName)
{
    //TODO: Complete this function
    Country * newCountry = new Country;
    Country * temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newCountry;
    newCountry->next = temp;
    newCountry->name = countryName;
    return temp;
}

bool CountryNetwork::detectLoop()
{
    if (head==NULL)
    {
        return false;
    }
    Country *present = head->next;
    Country *previous = head;
    while(present!=NULL && present->next != NULL)
    {
        if (present == previous)
        {
            return true;
        }
        present = present->next->next;
        previous = previous->next;

    }
    return false;
}

void CountryNetwork:: readjustNetwork(int start_index, int end_index)
{
    int counter = 0; 

    if(start_index > end_index)
    {
        cout<<"Invalid indices"<<endl;
        return;
    }
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    Country *present = head->next;
    Country *previous = head;
    while(present!=NULL && present->next!=NULL)
    {
        if (present == previous)
        {
            break;
        }
        present = present->next->next;
        previous = previous->next;
        counter++;
    }

    if(end_index < 0 || end_index > counter || start_index > counter)
    {
        cout << "Invalid end index"<<endl;
        return;
    }

    Country *start = head;
    
    for(int i = 0; i < start_index; i++)
    {
        start = start->next;
    }
    Country *move = start;
    for(int i = start_index; i<end_index;i++)
    {
        move = move->next;
    }

    Country *temp = NULL;
    temp = head;
    head = move;
    start = present->next;
    delete temp;
}

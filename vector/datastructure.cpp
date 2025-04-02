#include <iostream>
#include <vector>

using namespace std;

struct Person {
    int id;
    string name;
    int age;
};

void createPerson(string name, int age);
void readPersons();
void deletePersonById(int id);
void updatePersonById(int id, string name, int age);
bool checkIdExists(int id);

vector<Person> persons;
int lastId = 0;

int main() {

    int op;

    do
    {
        cout << "============================" << endl;
        cout << "1. CREATE " << endl;
        cout << "2. READ " << endl;
        cout << "3. UPDATE " << endl;
        cout << "4. DELETE " << endl;
        cout << "5. Exit program..." << endl;
        cout << "============================" << endl;
        cout << "Enter an option -> "; 
        cin >> op;

        switch (op) {
            case 1: {
                system("cls");
                string name;
                int age;
                cout << "Enter a name: "; 
                cin >> name;
                cout << "Enter an age: "; cin >> age;
                createPerson(name, age);
                break;
            }
            case 2:
                system("cls");
                readPersons();
                break;
            case 3: {
                system("cls");
                int id, age;
                string name;
                cout << "Enter en ID you want to update -> "; cin >> id;
                if (!checkIdExists(id))
                {
                    cout << "Person with ID [" << id << "] not found!" << endl;
                }
                cout << "Enter new user info" << endl;
                cout << "Enter new name: "; cin >> name;
                cout << "Enter new age: "; cin >> age;
                updatePersonById(id, name, age);
                break;
            }
            case 4: {
                int id;
                system("cls");
                cout << "Enter an ID you want to delete -> "; cin >> id;
                deletePersonById(id);
                break;
            }
            case 5:
                exit(0);
                break;

            default: cout << "Invalid option" << endl;
                break;
        }
    } while ( op != 5 );
    
    return 0;
}

void createPerson(string name, int age) {
    lastId++;
    persons.push_back({lastId, name, age});
}

void readPersons() {
    if (persons.empty()) {
        cout << "No persons found!" << endl;
        return;
    }
    
    for (const auto& person: persons) {
        cout << "========================" << endl;
        cout << "ID: " << person.id << endl;
        cout << "Name: " << person.name << endl;
        cout << "Age: " << person.age << endl;
    }
}

void deletePersonById(int id) { 
    for (size_t i = 0; i < persons.size(); i++){
        if (persons[i].id == id)
        {
            persons.erase(persons.begin() + i);
            cout << "Person with ID [" << id << "] deleted" << endl;
            return;
        }   
    }
}

void updatePersonById(int id, string name, int age) {
    for (auto& person : persons)
    {
        if (person.id == id)
        {
            person.name = name;
            person.age = age;
            return;
        }
    }
}

bool checkIdExists(int id) {
    for (const auto& person: persons)
    {
        if (person.id == id)
        {
            return true;
        }
    } 
    return false;
}
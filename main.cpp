//COMSC-210 | Lab 27 | Alexander Sierra
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int Menu();

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerDetails;

    // insert elements into the map
    // note how the right-hand side of the assignment are the tuple elements
    villagerDetails["Audie"] = make_tuple(5, "Lion", "Better late than never");
    villagerDetails["Raymond"] = make_tuple(2, "Human", "Always try your best");
    villagerDetails.insert({"Marshal", tuple(7, "Shark", "Never give up")});

    // access the map using a range-based for loop
    cout << "Villagers and their species (range-based for loop):" << endl;
    for (auto [name, details] : villagerDetails) {
        cout << name << ": ";
        cout << get<1>(details) << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their species (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerDetails.begin(); 
                                               it != villagerDetails.end(); ++it) {
        cout << it->first << ": ";
        cout << get<1>(it->second) << " ";
        cout << endl;
    }

    // delete an element
    villagerDetails.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerDetails.find(searchKey);
    if (it != villagerDetails.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s species: ";
        cout << get<1>(it->second) << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    cout << endl << "Menu driven part" << endl << endl;
    int choice = Menu();
    while (choice != 4) {
        if (choice == 1) {
            for (auto& [name, details] : villagerDetails) {
                if (get<0>(details) < 10) {
                    get<0>(details) += 1;
                }
            }
        }   
        if (choice == 2) {
            for (auto& [name, details] : villagerDetails) {
                if (get<0>(details) > 0){
                    get<0>(details) -= 1;
                }
            }
        }
        if (choice == 3) {
            cout << "enter name of villager below:" << endl;
            cin >> searchKey;
            // search for an element using .find() to avoid errors
            auto it = villagerDetails.find(searchKey);
            if (it != villagerDetails.end()) {  // the iterator points to beyond the end of the map
                                                // if searchKey is not found
                cout << "\nFound " << searchKey << "'s details: [";
                cout << get<0>(it->second) << ", ";
                cout << get<1>(it->second) << ", ";
                cout << get<2>(it->second) << "]";
                cout << endl << endl;
            } else
                cout << endl << searchKey << " not found." << endl;
        }

        cout << "Villager details: " << endl;
        for (auto [name, details] : villagerDetails) {
            cout << name << " [";
            cout << get<0>(details) << ", ";
            cout << get<1>(details) << ", ";
            cout << get<2>(details) << "]";
            cout << endl << endl;
        }
        choice = Menu();
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl;

    return 0;
}

int Menu() {
    int choice;
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    cout << endl;
    while ((choice < 1) && (choice > 4)){
        cout << "Please choose a valid option" << endl;
        cin >> choice;
    }

    return choice;
}
#include <iostream>
using namespace std;

class Trans {
public:
    char ip_state, op_state, ip_symbol;
    
    Trans() {
        ip_state = op_state = ip_symbol = '\0';
    }
};

int main() {
    int nos, ips, notr, i;
    char state[10], ipsmb[5], str[20], istate, fstate;
    Trans tr[20];
    
    cout << "Enter number of states: ";
    cin >> nos;
    for (i = 0; i < nos; i++) {
        cout << "Enter state " << i + 1 << ": ";
        cin >> state[i];
    }

    cout << "Enter initial state: ";
    cin >> istate;
    cout << "Enter final state: ";
    cin >> fstate;

    cout << "Enter number of input symbols: ";
    cin >> ips;
    for (i = 0; i < ips; i++) {
        cout << "Enter input symbol " << i + 1 << ": ";
        cin >> ipsmb[i]; // Store each input symbol
    }

    cout << "Enter number of transitions: ";
    cin >> notr;
    for (i = 0; i < notr; i++) {
        cout << "Enter transition " << i + 1 << " (format: current_state symbol next_state): ";
        cin >> tr[i].ip_state >> tr[i].ip_symbol >> tr[i].op_state; // Fixed to read correctly
    }

    cout << "Transitions:\n";
    for (i = 0; i < notr; i++) {
        cout << tr[i].ip_state << " -> " << tr[i].ip_symbol << " -> " << tr[i].op_state << "\n";
    }

    char currentState = istate;
    cout << "Enter string: ";
    cin >> str;

    for (i = 0; str[i] != '\0'; i++) { // Iterate through the string until the null terminator
        bool transitionFound = false; // Flag to check if a transition is found
        for (int j = 0; j < notr; j++) {
            if (currentState == tr[j].ip_state && str[i] == tr[j].ip_symbol) {
                currentState = tr[j].op_state; // Update the state
                transitionFound = true;
                break; // Break out of the inner loop after a transition
            }
        }
        if (!transitionFound) {
            break; // If no transition is found, break out of the loop
        }
    }

    if (currentState == fstate) {
        cout << "String is accepted\n";
    } else {
        cout << "String is not accepted\n";
    }

    return 0;
}

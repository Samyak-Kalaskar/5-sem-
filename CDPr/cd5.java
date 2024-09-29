import java.util.Scanner;

class Trans {
    char ip_state, op_state, ip_symbol;

    // Constructor
    Trans() {
        ip_state = op_state = ip_symbol = '\0';
    }
}

public class DFA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int nos, ips, notr, i;
        char[] state = new char[10];
        char[] ipsmb = new char[5];
        char[] str;
        char istate, fstate, extra;
        Trans[] tr = new Trans[20];
        
        // Initialize Trans objects
        for (i = 0; i < 20; i++) {
            tr[i] = new Trans();
        }

        // Input number of states
        System.out.print("Enter number of states: ");
        nos = sc.nextInt();

        // Input each state
        for (i = 0; i < nos; i++) {
            System.out.print("Enter state " + (i + 1) + ": ");
            state[i] = sc.next().charAt(0);
        }

        // Input initial state
        System.out.print("Enter initial state: ");
        istate = sc.next().charAt(0);

        // Input final state
        System.out.print("Enter final state: ");
        fstate = sc.next().charAt(0);

        // Input number of input symbols
        System.out.print("Enter number of input symbols: ");
        ips = sc.nextInt();

        // Input each input symbol
        for (i = 0; i < ips; i++) {
            System.out.print("Enter input symbol " + (i + 1) + ": ");
            ipsmb[i] = sc.next().charAt(0);
        }

        // Input number of transitions
        System.out.print("Enter number of transitions: ");
        notr = sc.nextInt();

        // Input each transition
        for (i = 0; i < notr; i++) {
            System.out.print("Enter transition " + (i + 1) + " (input state, input symbol, output state): ");
            tr[i].ip_state = sc.next().charAt(0);
            tr[i].ip_symbol = sc.next().charAt(0);
            tr[i].op_state = sc.next().charAt(0);
        }

        // Display the transitions
        for (i = 0; i < notr; i++) {
            System.out.println(tr[i].ip_state + " -> " + tr[i].ip_symbol + " -> " + tr[i].op_state);
        }

        // Set the initial state for processing the string
        extra = istate;

        // Input the string to be processed
        System.out.print("Enter string: ");
        String inputStr = sc.next();
        str = inputStr.toCharArray();

        int k = 0;
        boolean accepted = true;

        // Process each character of the string
        while (k < str.length) {
            boolean transitionFound = false;
            
            // Process each transition according to the input string
            for (i = 0; i < notr; i++) {
                if (extra == tr[i].ip_state && str[k] == tr[i].ip_symbol) {
                    extra = tr[i].op_state;
                    k++;
                    transitionFound = true;
                    break;  // Exit the loop when a valid transition is found
                }
            }

            if (!transitionFound) {
                accepted = false;  // If no valid transition is found, reject the string
                break;
            }
        }

        // Check if the final state matches the expected state
        if (accepted && extra == fstate) {
            System.out.println("String is accepted");
        } else {
            System.out.println("String is not accepted");
        }

        sc.close();
    }
}

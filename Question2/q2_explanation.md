# Question 2: Control Flow Explanation

- **Conditionals (if-else / switch):** Used switch for handling the main menu navigation cleanly. if statements were used to validate logic within the cases, like checking if withdrawal amounts exceed the alance or if the amount entered is negative.
- **Loops (while):** The entire program is wrapped in a while(1) loop so the menu repaints continuously, allowing the agent to process multiple transactions without restarting the console app.
- **Break:** Used specifically for Option 5 (Exit) to terminate the while loop completely, and also at the end of each switch case to prevent execution from falling through to the next menu option.
- **Continue:** Used when an invalid amount is detected (like a negative deposit). Instead of crashing or doing complex nested if statements, continue skips the rest of the current loop iteration and immediately brings the user back to the main menu.
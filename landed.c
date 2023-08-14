#include <stdio.h>

// Global variables
float credits = 0.00;
float pizzaPrice = 0.00;

// Function declarations
void displayMainMenu();
void addCredits();
void orderPizza();
void selectSize();
void selectToppings();
void processOrder();
void insufficientCredits();

int main() {
    displayMainMenu();
    return 0;
}

void displayMainMenu() {
    int choice;
    printf("UCLan PIZZA\n");
    printf("-------------------------------\n");
    printf("MAIN MENU\n");
    printf("1. Add Credits (current credits = %.2f)\n", credits);
    printf("2. Order Pizza\n");
    printf("0. Exit\n");
    printf("Please enter a number: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addCredits();
            break;
        case 2:
            orderPizza();
            break;
        case 0:
            printf("Thank you, goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            displayMainMenu();
    }
}

void addCredits() {
    float amount;
    printf("Enter the amount of credits you want to add: ");
    scanf("%f", &amount);
    credits += amount;
    printf("Available Balance: %.2f credits\n", credits);
    displayMainMenu();
}

void orderPizza() {
    printf("Order Pizza – Select Size\n");
    printf("[Current Balance = %.2f credits]\n", credits);
    printf("Please choose from the following options:\n");
    printf("1. 7 inch [3.0 credits]\n");
    printf("2. 9 inch [5.50 credits]\n");
    printf("3. 14 inch [7.25 credits]\n");
    printf("0. Return to Main Menu\n");
    printf("........................................\n");

    selectSize();
}

void selectSize() {
    int size;
    printf("Please enter a number: ");
    scanf("%d", &size);

    switch (size) {
        case 1:
            pizzaPrice += 3.0;
            printf("You have selected a 7 inch pizza.\n");
            selectToppings();
            break;
        case 2:
            pizzaPrice += 5.50;
            printf("You have selected a 9 inch pizza.\n");
            selectToppings();
            break;
        case 3:
            pizzaPrice += 7.25;
            printf("You have selected a 14 inch pizza.\n");
            selectToppings();
            break;
        case 0:
            displayMainMenu();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            selectSize();
    }
}

void selectToppings() {
    int topping;
    printf("Order Pizza – Select Toppings\n");
    printf("You have selected a 9 inch pizza.\n");
    printf("Please choose from the following toppings:\n");
    printf("1. Ham [0.80 credits]\n");
    printf("2. Mushrooms [0.50 credits]\n");
    printf("3. Pepperoni [1.00 credits]\n");
    printf("4. Olives [0.30 credits]\n");
    printf("5. Pineapple [0.60 credits]\n");
    printf("6. Extra Cheese [1.20 credits]\n");
    printf("0. Return to Main Menu\n");
    printf("........................................\n");

    printf("Please enter a number: ");
    scanf("%d", &topping);

    switch (topping) {
        case 1:
            pizzaPrice += 0.80;
            printf("You have added Ham to your pizza. Your current price is: %.2f credits.\n", pizzaPrice);
            break;
        case 2:
            pizzaPrice += 0.50;
            printf("You have added Mushrooms to your pizza. Your current price is: %.2f credits.\n", pizzaPrice);
            break;
        case 3:
            pizzaPrice += 1.00;
            printf("You have added Pepperoni to your pizza. Your current price is: %.2f credits.\n", pizzaPrice);
            break;
        case 4:
            pizzaPrice += 0.30;
            printf("You have added Olives to your pizza. Your current price is: %.2f credits.\n", pizzaPrice);
            break;
        case 5:
            pizzaPrice += 0.60;
            printf("You have added Pineapple to your pizza. Your current price is: %.2f credits.\n", pizzaPrice);
            break;
        case 6:
            pizzaPrice += 1.20;
            printf("You have added Extra Cheese to your pizza. Your current price is: %.2f credits.\n", pizzaPrice);
            break;
        case 0:
            displayMainMenu();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            selectToppings();
    }

    processOrder();
}

void processOrder() {
    char response;
    printf("Would you like to add additional toppings?\n");
    printf("Please input 'Y' for yes and 'N' for no : ");
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y') {
        selectToppings();
    } else if (response == 'N' || response == 'n') {
        if (credits >= pizzaPrice) {
            credits -= pizzaPrice;
            printf("Available Balance: %.2f credits\n", credits);
            printf("Pizza price: %.2f credits\n", pizzaPrice);
            printf("----------------------------------------\n");
            printf("Your new Balance = %.2f credits\n", credits);
            printf("----------------------------------------\n");
        } else {
            insufficientCredits();
            return;
        }

        char orderAnother;
        printf("Would you like to order another pizza?\n");
        printf("Please input 'Y' for yes and 'N' for no : ");
        scanf(" %c", &orderAnother);

        if (orderAnother == 'Y' || orderAnother == 'y') {
            pizzaPrice = 0.0;
            orderPizza();
        } else {
            printf("Thank you, goodbye!\n");
        }
    } else {
        printf("Invalid choice. Please try again.\n");
        processOrder();
    }
}

void insufficientCredits() {
    char response;
    printf("You have insufficient credits available. You require \"%.2f\" credits.\n", pizzaPrice);
    printf("Would you like to add more credits?\n");
    printf("Please enter 'Y' for yes and 'N' for no : ");
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y') {
        float amount;
        printf("Please enter how many credits you would like to add to your balance: ");
        scanf("%f", &amount);
        credits += amount;
        printf("----------------------------------------\n");
        printf("Your new Balance = %.2f credits\n", credits);
        printf("----------------------------------------\n");
        printf("Would you like to continue processing your order?\n");
        printf("Please enter 'Y' for yes and 'N' : ");
        scanf(" %c", &response);

        if (response == 'Y' || response == 'y') {
            pizzaPrice = 0.0;
            orderPizza();
        } else {
            printf("Thank you, goodbye!\n");
        }
    } else if (response == 'N' || response == 'n') {
        printf("Thank you, goodbye!\n");
    } else {
        printf("Invalid choice. Please try again.\n");
        insufficientCredits();
    }
}

//*************************************************
//*             C++ Data structure types          *
//*            ==========================         *
//*                                               *
//*This program is designed to show the process of*
//*implementing data structures in c++ along with *
//*passing them within functions to create a menu *
//*based program that displays the amount someone *
//*spends within the month of 2020 compared to the*
//*fixed budget they agreed to in the beginning of*
//*the year.                                      *
//*Written by Brandon Luna                        *
//*Filename: Luna_A7a.cpp                         *
//*Class: CS10B                                   *
//*************************************************

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;


//************* Structure Definition *************
//*This structure is used to hold double integers*
//*of already inputted data and have it displayed*
//*later on in the function showData as the      *
//*budget for the year of 2020 and then it is    *
//*going to be compared to the expenses made a   *
//*month in 2020                                 *
//************************************************
struct monthlyBudget
{
    double  housing = 580.00;   //Double local variable that holds defined housing expenses
    double  utilities = 150.00; //Double local utilities variable that holds defined utilities expenses
    double  houseHoldExpenses = 65.00;  //Double local variable that holds defined house hold expenses
    double  transportation = 50.00; //Double local variable that holds defined transportation expenses
    double  food = 250.00;  //Double local variable that holds defined food expenses
    double  medical = 30.00;    //Double local variable that holds defined medical expenses
    double  insurance = 100.00; //Double local variable that holds defined insurance expenses
    double  entertainment = 150.00; //Double local variable that holds defined entertainment expenses
    double  clothing = 75.00;   //Double local variable that holds defined clothing expenses
    double  miscellaneous = 50.00; //Double variable that holds defined misc expenses
};

//************* Structure Definition *************
//*This structure data type is used almost the   *
//*same way as the previous one but instead it   *
//*holds double variables that will be written   *
//*over by user entries instead of holding the   *
//*values and displaying them that way           *
//************************************************
struct monthlySpent
{
    double  housing;    //Double local variable that allows user entry
    double  utilities;  //Double local variable that allows user entry
    double  houseHoldExpenses;  //Double local variable that allows user entry
    double  transportation; //Double local variable that allows user entry
    double  food;   //Double local variable that allows user entry
    double  medical;    //Double local variable that allows user entry
    double  insurance;  //Double local variable that allows user entry
    double  entertainment;  //Double local variable that allows user entry
    double  clothing;   //Double local variable that allows user entry
    double  miscellaneous;  //Double local variable that allows user entry
    string months;  //String local variable that allows user entry
};


//List function prototypes below:
void showData(/*inout*/monthlyBudget *); //Function prototype with a structure parameter
void getExpenses(/*inout*/monthlySpent *);   //Function prototype with a structure parameter
void compareExpenses(/*inout*/monthlyBudget *,/*inout*/ monthlySpent *);  //Function prototype with two structure parameter

int main()
{
    monthlyBudget monthly;  //Declares structure data type of monthlyBudget in main
    monthlySpent spent;     //Declares structure data type of monthlySpent in main
    monthlySpent *stdPtr2 = nullptr;    //Declares a pointer to the data structure monthlySpent
    monthlyBudget *stdPtr = nullptr;    //Declares a pointer to the data structure monthlyBudget
    stdPtr = &monthly;  //Pointer declared to show the value of monthlyBudget
    stdPtr2 = &spent;   //Pointer declared to show the value of monthlySpent

    //string months;

    showData(stdPtr);   //Function call with one argument

    getExpenses(stdPtr2);   //Function call with one argument

    compareExpenses(stdPtr, stdPtr2);   //Function call with two arguments

    return 0;
}

//List function definitions below

//******************* Function Definition *******************
//*This function is designed to show the monthly budget of  *
//*the year 2020 by using the structure data types and its  *
//*local variables with cout statements to represent the    *
//*integers within the data set                             *
//***********************************************************
void showData(/*inout*/monthlyBudget *m)
//Pre:
//This function is going to use the local double variable of total
//and its structure variables to display the monthly budget for 2020

//Post:
//The function successfully displays the contents in the variables
//with the use of a cout statement
{
    //Local double variable that stores the total of all the items combined
    double total;

        //Prompt that shows the user what they are looking at
        cout << "Here is your monthly budget for YEAR 2020:\n" << endl;

        cout << "Housing " << setw(9) << "$" << m->housing << endl;
        cout << "Utilities " << setw(7) << "$" << m->utilities << endl;
        cout << "Household " << setw(7) << "$" << m->houseHoldExpenses << endl;
        cout << "Transportation " << setw(2) << "$" << m->transportation << endl;
        cout << "Food " << setw(12) << "$" << m->food << endl;
        cout << "Medical " << setw(9) << "$" << m->medical << endl;
        cout << "Insurance " << setw(7) << "$" << m->insurance << endl;
        cout << "Entertainment " << setw(3) << "$" << m->entertainment << endl;
        cout << "Clothing " << setw(8) << "$" << m->clothing << endl;
        cout << "Miscellaneous " << setw(3) << "$" << m->miscellaneous << endl;

        cout << "=================================================" << endl;

        //Total variable being declared with contents that add everything up together
        total = m->housing + m->utilities + m->houseHoldExpenses + m->transportation + m->food + m->medical + m->insurance + m->entertainment + m->clothing + m->miscellaneous;

        cout << "Total budgeted " << setw(2) << "$" << total << endl;   //Displays total amount of the items

        cout << "=================================================" << endl;

        cout << endl;   //Space
}

//******************* Function Definition *******************
//*This function is responsible for getting the expenses of *
//*the structure data type variables in monthlySpent and    *
//*then outputting them and also comparing the difference in*
//*another function later on.                               *
//***********************************************************
void getExpenses(/*inout*/monthlySpent *s)
//Pre:
//The user will be prompted to enter a month and then with the use
//of the integer variables in the data structure function they will be
//asked to enter individual values for the certain amount of expenses
//they will have, while also integrating input validation to make sure the
//user does not enter any negative numbers or special characters that would
//other wise crash the program later on

//Post:
//The function runs successfully and collects the values and
//month entered by the user so they can be displayed in the
//following function later on.
{
    //Prompts user to enter month
    cout << "Enter month of expenditure: ";
    cin >> s->months;

    cout << endl;   //Space

    cout << "Enter actual monthly expenditures for each budget category" << endl;

    cout << endl;

        //Prompts user to enter housing value
        cout << "Housing: " << setw(9) << "$";
        cin >> s->housing;

        //Input validation which triggers if user enters negative number or special character
        while(s->housing < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Housing: " << setw(8) << "$";
            cin >> s->housing;
        }


        //Prompts user to enter utilities value
        cout << "Utilities: " << setw(7) << "$";
        cin >> s->utilities;

        //Input validation if user enters neg or special characters
        while(s->utilities < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Utilities: " << setw(8) << "$";
            cin >> s->utilities;
        }


        //Prompts user to enter household value
        cout << "Household: " << setw(7) << "$";
        cin >> s->houseHoldExpenses;

        //Input validation if user enters neg or special characters
        while(s->houseHoldExpenses < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Household: " << setw(8) << "$";
            cin >> s->houseHoldExpenses;
        }


        //Prompts user to enter transportation value
        cout << "Transportation: " << setw(2) << "$";
        cin >> s->transportation;

        //Input validation if user enters neg or special characters
        while(s->transportation < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Transportation: " << setw(8) << "$";
            cin >> s->transportation;
        }

        //Prompts user to enter food value
        cout << "Food: " << setw(12) << "$";
        cin >> s->food;

        //Input validation if user enters neg or special characters
        while(s->food < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Food: " << setw(8) << "$";
            cin >> s->food;
        }


        //Prompts user to enter medical value
        cout << "Medical: " << setw(9) << "$";
        cin >> s->medical;

        //Input validation if user enters neg or special characters
        while(s->medical < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Medical: " << setw(8) << "$";
            cin >> s->medical;
        }


        //Prompts user to enter insurance value
        cout << "Insurance: " << setw(7) << "$";
        cin >> s->insurance;

        //Input validation if user enters neg or special characters
        while(s->insurance < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Insurance: " << setw(8) << "$";
            cin >> s->insurance;
        }

        //Prompts user to enter entertainment value
        cout << "Entertainment: " << setw(3) << "$";
        cin >> s->entertainment;

        //Input validation if user enters neg or special characters
        while(s->entertainment < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Entertainment: " << setw(8) << "$";
            cin >> s->entertainment;
        }

        //Prompts user to enter clothing value
        cout << "Clothing: " << setw(8) << "$";
        cin >> s->clothing;

        //Input validation if user enters neg or special characters
        while(s->clothing < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Clothing: " << setw(8) << "$";
            cin >> s->clothing;
        }

        //Prompts user to enter misc value
        cout << "Miscellaneous: " << setw(3) << "$";
        cin >> s->miscellaneous;

        //Input validation if user enters neg or special characters
        while(s->miscellaneous < 0 || !cin)
        {
            cin.clear();
            cin.ignore();

            cout << "ERROR: You must enter a positive number." << endl;

            cout << "Miscellaneous: " << setw(8) << "$";
            cin >> s->miscellaneous;
        }

        cout << endl;
}

//******************* Function Definition *******************
//*This function is designed to display the amount of money *
//*spent and the difference of the amount budgeted to the   *
//*amount that is spent within a month of the year 2020     *
//*it shows data structure processing within function decomp*
//***********************************************************
void compareExpenses(/*inout*/monthlyBudget *m,/*inout*/ monthlySpent *s)
//Pre:
//This function will use the data structure variables passed from
//the two strucs into the function then with the local float variables
//will be used to display all the previous data accordingly and the new
//totals

//Post:
//The function does as it is designed to do and the data is displayed
//successfully, where it shows the difference in the amount spent
//compared to the budget of the year, it also displays the correct totals
//of the original budget, the spent version, and the difference
{
    //Local float variables used to hold the values of the difference between strucs and totals of budget, spent, and difference
    float totalOriginal, totalEntered, totalDifference, difference1, difference2, difference3, difference4, difference5,
    difference6, difference7, difference8, difference9, difference10;



    //Prompts user the header of the data they are looking at
    cout << "               Budgeted" << "      Spent" << "     Difference" << endl;
    cout << "==================================================" << endl;

    //Diff variables and couts used to display data correctly
    difference1 = m->housing - s->housing;
    cout << "Housing " << setw(13) << setprecision(2) << fixed << m->housing << setw(12) << setprecision(2) << fixed << s->housing << setw(12) << setprecision(2) << fixed << difference1 << endl;
    difference2 = m->utilities - s->utilities;
    cout << "Utilities " << setw(11) << setprecision(2) << fixed << m->utilities << setw(12) << setprecision(2) << fixed << s->utilities << setw(12) << setprecision(2) << fixed << difference2 << endl;
    difference3 = m->houseHoldExpenses - s->houseHoldExpenses;
    cout << "Household " << setw(10) << setprecision(2) << fixed << m->houseHoldExpenses << setw(13) << setprecision(2) << fixed << s->houseHoldExpenses << setw(12) << setprecision(2) << fixed << difference3 << endl;
    difference4 = m->transportation - s->transportation;
    cout << "Transportation "<< setw(5) << setprecision(2) << fixed << m->transportation << setw(13) << setprecision(2) << fixed << s->transportation << setw(12) << setprecision(2) << fixed << difference4 << endl;
    difference5 = m->food - s->food;
    cout << "Food " << setw(16) << setprecision(2) << fixed << m->food << setw(12) << setprecision(2) << fixed << s->food << setw(12) << setprecision(2) << fixed << difference5 << endl;
    difference6 = m->medical - s->medical;
    cout << "Medical " << setw(12) << setprecision(2) << fixed << m->medical << setw(13) << setprecision(2) << fixed << s->medical << setw(12) << setprecision(2) << fixed << difference6 << endl;
    difference7 = m->insurance - s->insurance;
    cout << "Insurance" << setw(12) << setprecision(2) << fixed << m->insurance << setw(12) << setprecision(2) << fixed << s->insurance << setw(12) << setprecision(2) << fixed << difference7 << endl;
    difference8 = m->entertainment - s->entertainment;
    cout << "Entertainment " << setw(7) << m->entertainment << setw(12) << setprecision(2) << fixed << s->entertainment << setw(12) << setprecision(2) << fixed << difference8 << endl;
    difference9 = m->clothing - s->clothing;
    cout << "Clothing " << setw(11) << setprecision(2) << fixed << m->clothing << setw(13) << s->clothing << setw(12) << setprecision(2) << fixed << difference9 << endl;
    difference10 = m->miscellaneous - s->miscellaneous;
    cout << "Miscellaneous " << setw(6) << setprecision(2) << fixed << m->miscellaneous << setw(13) << setprecision(2) << fixed << s->miscellaneous << setw(12) << setprecision(2) << fixed << difference10 << endl;

    //Local variables redeclared to output correct information
    totalOriginal =  m->housing + m->utilities + m->houseHoldExpenses + m->transportation + m->food + m->medical + m->insurance + m->entertainment + m->clothing + m->miscellaneous;
    totalEntered =  s->housing + s->utilities + s->houseHoldExpenses + s->transportation + s->food + s->medical + s->insurance + s->entertainment + s->clothing + s->miscellaneous;
    totalDifference = difference10 + difference9 + difference8 + difference7 + difference6 + difference6 + difference5 + difference4 + difference3 + difference2 + difference1;

    //Displays total of different categories
    cout << "=================================================" << endl;
    cout << "Total " << setw(15) << setprecision(2) << fixed << totalOriginal << setw(13) << setprecision(2) << fixed << totalEntered << setw(11) << setprecision(2) << fixed << totalDifference << endl;
    cout << "=================================================\n" << endl;

    //Prompts user if they were under or over
    if(totalDifference > 0)
        cout << "Congratulations! You were $" << totalDifference << " under budget in " << s->months << " 2020." << endl;
    else
        cout << "Unfortunately! You were $" << totalDifference << " over budget in " << s->months << " 2020." << endl;

}

/* OUTPUT WHEN RAN:
Here is your monthly budget for YEAR 2020:

Housing         $580
Utilities       $150
Household       $65
Transportation  $50
Food            $250
Medical         $30
Insurance       $100
Entertainment   $150
Clothing        $75
Miscellaneous   $50
=================================================
Total budgeted  $1500
=================================================

Enter month of expenditure: March

Enter actual monthly expenditures for each budget category

Housing:         $580
Utilities:       $130
Household:       $50
Transportation:  $50
Food:            $230
Medical:         $30
Insurance:       $100
Entertainment:   $120
Clothing:        $-10
ERROR: You must enter a positive number.
Clothing:        $100
Miscellaneous:   $30

               Budgeted      Spent     Difference
==================================================
Housing        580.00      580.00        0.00
Utilities      150.00      130.00       20.00
Household      65.00        50.00       15.00
Transportation 50.00        50.00        0.00
Food           250.00      230.00       20.00
Medical        30.00        30.00        0.00
Insurance      100.00      100.00        0.00
Entertainment  150.00      120.00       30.00
Clothing       75.00       100.00      -25.00
Miscellaneous  50.00        30.00       20.00
=================================================
Total         1500.00      1420.00      80.00
=================================================

Congratulations! You were $80.00 under budget in March 2020.

Process returned 0 (0x0)   execution time : 21.026 s
Press any key to continue.

*/

/*
Name: Brittany Kennedy
Date: 10/28/2025
Section: ITCS 2530 H0801 2025FA - C++ Programming 1

Week03_Programming_Assignment_Brittany_Kennedy.cpp:
********************Vegetarian Nutrition for Weightlifting*********************
Program to help user figure out their suggested daily and per meal macros (protein/carbs/fats).
The percentages used in the macros target calculations are geared toward vegetarians that weightlift.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// **********************Define constants for calculations*********************

// Macro ratios as percentages of daily calories: 30% protein, 40% carbs, 30% fats
const double PROTEIN_PERCENT = 0.30;
const double CARB_PERCENT = 0.40;
const double FAT_PERCENT = 0.30;

// Calories per gram for each macro
const int CALORIES_PER_GRAM_PROTEIN = 4;
const int CALORIES_PER_GRAM_CARBS = 4;
const int CALORIES_PER_GRAM_FAT = 9;

// Number of days for weekly calculations
const int NUMBER_OF_DAYS = 7;

// Activity thresholds (hours per week)
const double ACTIVITY_HIGH = 5.0;
const double ACTIVITY_MEDIUM = 3.0;
const double ACTIVITY_LOW = 0.0; // anything below medium

// Calorie thresholds (per day)
const int CAL_HIGH = 2500;
const int CAL_MEDIUM = 2000;
const int CAL_LOW = 1800;
const int CAL_EXCESS = 2200;

// Meal frequency thresholds (per day)
const int MEALS_PER_DAY_HIGH = 6;
const int MEALS_PER_DAY_MEDIUM = 4;
const int MEALS_PER_DAY_LOW = 2;

// Convert to weekly meals
const int MEALS_PER_WEEK_HIGH = MEALS_PER_DAY_HIGH * NUMBER_OF_DAYS;
const int MEALS_PER_WEEK_MEDIUM = MEALS_PER_DAY_MEDIUM * NUMBER_OF_DAYS;
const int MEALS_PER_WEEK_LOW = MEALS_PER_DAY_LOW * NUMBER_OF_DAYS;

// ****************************************************************************


int main()
{
    // **************************Variables************************************* 
    ofstream outFile;  // Declare file stream variable for output report

    string name;
    string favoriteProtein;
    int dailyTotalCalories = 0;
    int weeklyTotalCalories = 0;
    int mealsPerWeek = 0;
    int mealsPerDay = 0;
    double weeklyWorkoutHours = 0;
    int menuChoice = 0;

    int dailyProteinCalories = 0;
    int dailyCarbCalories = 0;
    int dailyFatCalories = 0;
    int weeklyProteinCalories = 0;
    int weeklyCarbCalories = 0;
    int weeklyFatCalories = 0;

    int dailyGramsProtein = 0;
    int dailyGramsCarbs = 0;
    int dailyGramsFats = 0;
    int weeklyGramsProtein = 0;
    int weeklyGramsCarbs = 0;
    int weeklyGramsFats = 0;

    int proteinPerMeal = 0;
    int carbsPerMeal = 0;
    int fatsPerMeal = 0;


    // ***********************Introduction*************************************
    cout << setfill('*') << setw(75) << '*' << endl;
    cout << setfill(' ');
    cout << left << setw(5) << " "
        << " Welcome to the Vegetarian Nutrition for Weightlifters Program! "
        << right << setw(5) << " " << endl;
    cout << setfill('*') << setw(75) << '*' << endl;
    cout << "\nLet's learn more about you so we can figure out what your macros should be!\n\n";
    cout << endl;


    // ************************User Input**************************************
    // Get user's name
    cout << "What is your name? ";
    getline(cin, name);
    cout << endl;

    // Get user's favorite protein source
    cout << "Hi " << name << "!\n\n";
    cout << "What is your favorite vegetarian protein source? ";
    getline(cin, favoriteProtein);
    cout << "Great choice!\n\n";

    // Ask for desired daily calorie target
    // Set default value if input is invalid or negative
    cout << "How many calories are you targeting each day? ";
    cin >> dailyTotalCalories;
    if (cin.fail() || dailyTotalCalories < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "That is not a valid number. Defaulting to 2000 calories.\n\n";
        dailyTotalCalories = 2000;
    }

    // Get how many meals per day the user eats
    // Set default value if input is invalid or negative
    cout << "\nHow many meals do you eat per day? ";
    cin >> mealsPerDay;
    if (cin.fail() || mealsPerDay < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "That is not a valid number. Defaulting to 3 meals.\n\n";
        mealsPerDay = 3;
    }

    // Get how many hours per week the user weightlifts
    // Set default value if input is invalid or negative
    cout << "\nLast question! How many hours per week do you weightlift? ";
    cin >> weeklyWorkoutHours;
    cout << endl;
    if (cin.fail() || weeklyWorkoutHours < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "That is not a valid number. Defaulting to 3 hours per week.\n\n";
        weeklyWorkoutHours = 3;
    }
    else
    {
        cin.ignore(1000, '\n');   // Remove leftover newline if input was valid
    }


    // ****************************Calculations***************************************
    ///////////////////Daily and Per Meal Calculations\\\\\\\\\\\\\\\\\\\\\\\\
    // Calculate user's daily macros using defined macro ratios
    dailyProteinCalories = static_cast<int>(dailyTotalCalories * PROTEIN_PERCENT);
    dailyCarbCalories = static_cast<int>(dailyTotalCalories * CARB_PERCENT);
    dailyFatCalories = static_cast<int>(dailyTotalCalories * FAT_PERCENT);

    // Convert calories to grams for daily targets
    dailyGramsProtein = dailyProteinCalories / CALORIES_PER_GRAM_PROTEIN;
    dailyGramsCarbs = dailyCarbCalories / CALORIES_PER_GRAM_CARBS;
    dailyGramsFats = dailyFatCalories / CALORIES_PER_GRAM_FAT;

    // Calculate macro targets per meal
    proteinPerMeal = dailyGramsProtein / mealsPerDay;
    carbsPerMeal = dailyGramsCarbs / mealsPerDay;
    fatsPerMeal = dailyGramsFats / mealsPerDay;

    /////////////////////////Weekly Calculations\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    // Calculate weekly calories and meals
    weeklyTotalCalories = dailyTotalCalories * NUMBER_OF_DAYS;
    mealsPerWeek = mealsPerDay * NUMBER_OF_DAYS;

    // Calculate user's weekly macros using using daily macro ratios
    weeklyProteinCalories = dailyProteinCalories * NUMBER_OF_DAYS;
    weeklyCarbCalories = dailyCarbCalories * NUMBER_OF_DAYS;
    weeklyFatCalories = dailyFatCalories * NUMBER_OF_DAYS;

    // Convert calories to grams for weekly targets
    weeklyGramsProtein = weeklyProteinCalories / CALORIES_PER_GRAM_PROTEIN;
    weeklyGramsCarbs = weeklyCarbCalories / CALORIES_PER_GRAM_CARBS;
    weeklyGramsFats = weeklyFatCalories / CALORIES_PER_GRAM_FAT;


    // ***************************Menu**********************************************
    // User menu implemented with switch
    cout << setfill('*') << setw(75) << '*' << endl;
    cout << "Now that I have you information - what would you like to do next:\n\n";
    cout << "MAIN MENU: \n";
    cout << "1. View Suggested Daily Macros\n";
    cout << "2. Report of Suggested Daily and Weekly Macros\n";
    cout << "3. Check Your Nutrition and Unlock a Free Recipe!\n";
    cout << "4. Exit Program\n\n";
    cout << "Enter your choice (1-4): ";
    cin >> menuChoice;
    cout << endl;

    switch (menuChoice)
    {
    case 1:
        cout << setfill('*') << setw(75) << '*' << endl;
        cout << "You chose to view your suggested daily macros!\n\n";

        // Display input and daily macros
        cout << "Here is the information you provided:\n";
        cout << left << setw(50) << setfill('.') << "Favorite protein source: " << right << favoriteProtein << endl;
        cout << left << setw(50) << setfill('.') << "Daily calorie target: " << right << dailyTotalCalories << endl;
        cout << left << setw(50) << setfill('.') << "Meals per day: " << right << mealsPerDay << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << left << setw(50) << setfill('.') << "Weekly workout hours: " << right << weeklyWorkoutHours << endl;

        cout << "\nSuggested daily macros:\n";
        cout << left << setw(50) << setfill('.') << "Protein: " << right << dailyGramsProtein << " grams (" << dailyProteinCalories << " cal)\n";
        cout << left << setw(50) << setfill('.') << "Carbs: " << right << dailyGramsCarbs << " grams (" << dailyCarbCalories << " cal)\n";
        cout << left << setw(50) << setfill('.') << "Fats: " << right << dailyGramsFats << " grams (" << dailyFatCalories << " cal)\n\n";

        cout << "Per meal macro targets:\n";
        cout << left << setw(50) << setfill('.') << "Protein grams per meal: " << right << proteinPerMeal << endl;
        cout << left << setw(50) << setfill('.') << "Carbs grams per meal:   " << right << carbsPerMeal << endl;
        cout << left << setw(50) << setfill('.') << "Fats grams per meal:    " << right << fatsPerMeal << endl;

        cout << setfill('*') << setw(75) << '*' << endl;
        cout << "Keep fueling with " << favoriteProtein << " to hit " << dailyGramsProtein << " grams of protein!\n";
        cout << "Remember your " << weeklyWorkoutHours << " hours of weightlifting per week...\n";
        cout << "Keep lifting heavy, " << name << "!\n\n";
        break;

    case 2:
        cout << setfill('*') << setw(75) << '*' << endl;
        cout << "You chose to generate a report of your suggested daily and weekly macros!\n";
        cout << "Open 'report.txt' to view, save, or print it.\n\n";
        cout << setfill('*') << setw(75) << '*' << endl;

        outFile.open("report.txt");

        // Report header
        outFile << setfill('*') << setw(75) << '*' << endl;
        outFile << "Information you provided:\n";
        outFile << left << setw(50) << setfill('.') << "Favorite protein source: " << right << favoriteProtein << endl;
        outFile << left << setw(50) << setfill('.') << "Daily calorie target: " << right << dailyTotalCalories << endl;
        outFile << left << setw(50) << setfill('.') << "Weekly calorie target: " << right << weeklyTotalCalories << endl;
        outFile << left << setw(50) << setfill('.') << "Meals per day: " << right << mealsPerDay << endl;
        outFile << fixed << showpoint << setprecision(2);
        outFile << left << setw(50) << setfill('.') << "Weekly workout hours: " << right << weeklyWorkoutHours << endl;

        // Weekly macros
        outFile << "\nSuggested weekly macros:\n";
        outFile << left << setw(50) << setfill('.') << "Protein: " << right << weeklyGramsProtein << " grams (" << weeklyProteinCalories << " cal)\n";
        outFile << left << setw(50) << setfill('.') << "Carbs: " << right << weeklyGramsCarbs << " grams (" << weeklyCarbCalories << " cal)\n";
        outFile << left << setw(50) << setfill('.') << "Fats: " << right << weeklyGramsFats << " grams (" << weeklyFatCalories << " cal)\n\n";

        // Daily macros
        outFile << "Suggested daily macros:\n";
        outFile << left << setw(50) << setfill('.') << "Protein: " << right << dailyGramsProtein << " grams (" << dailyProteinCalories << " cal)\n";
        outFile << left << setw(50) << setfill('.') << "Carbs: " << right << dailyGramsCarbs << " grams (" << dailyCarbCalories << " cal)\n";
        outFile << left << setw(50) << setfill('.') << "Fats: " << right << dailyGramsFats << " grams (" << dailyFatCalories << " cal)\n\n";

        // Per meal
        outFile << "Per meal macro targets:\n";
        outFile << left << setw(50) << setfill('.') << "Protein grams per meal: " << right << proteinPerMeal << endl;
        outFile << left << setw(50) << setfill('.') << "Carbs grams per meal:   " << right << carbsPerMeal << endl;
        outFile << left << setw(50) << setfill('.') << "Fats grams per meal:    " << right << fatsPerMeal << endl;

        outFile << setfill('*') << setw(75) << '*' << endl;
        outFile << "Keep fueling with " << favoriteProtein << " to hit " << dailyGramsProtein << " grams of protein!\n";
        outFile << "Remember your " << weeklyWorkoutHours << " hours of weightlifting per week...\n";
        outFile << "Keep lifting heavy, " << name << "!\n\n";

        outFile.close();
        break;

    case 3:
        cout << setfill('*') << setw(75) << '*' << endl;
        cout << "Checking your calorie intake vs activity level...\n\n";

        // Calories vs activity
        if (weeklyWorkoutHours >= ACTIVITY_HIGH && dailyTotalCalories >= CAL_HIGH)
            cout << "Your intake is sufficient for a high activity week. Keep it up!\n\n";
        else if (weeklyWorkoutHours >= ACTIVITY_MEDIUM && dailyTotalCalories >= CAL_MEDIUM)
            cout << "Your intake is decent for your activity level, but you could increase protein slightly.\n\n";
        else if (weeklyWorkoutHours < ACTIVITY_MEDIUM && dailyTotalCalories < CAL_LOW)
            cout << "You might be under fueling. Consider adding extra calories per day.\n\n";
        else if (weeklyWorkoutHours < ACTIVITY_MEDIUM && dailyTotalCalories > CAL_EXCESS)
            cout << "You may be eating more than your activity requires. Consider slightly reducing calories per day.\n\n";
        else
            cout << "Your calorie intake seems balanced for your activity level.\n\n";

        // Meals vs activity
        if (mealsPerWeek >= MEALS_PER_WEEK_MEDIUM && mealsPerWeek <= MEALS_PER_WEEK_HIGH && weeklyWorkoutHours >= ACTIVITY_HIGH)
            cout << "Excellent meal frequency for muscle recovery! Try the smoothie below!\n\n";
        else if (mealsPerWeek < MEALS_PER_WEEK_MEDIUM && weeklyWorkoutHours >= ACTIVITY_MEDIUM)
            cout << "Consider eating more often to support your training. Try the smoothie below!\n\n";
        else if (mealsPerWeek > MEALS_PER_WEEK_HIGH)
            cout << "You might be eating more than necessary — ensure portion sizes are balanced. Try the smoothie below!\n\n";
        else
            cout << "Your meal frequency seems appropriate for your activity level. Try the smoothie below!\n\n";

        cout << "Oatmeal Smoothie Recipe:\n\n- 1/4 cup rolled oats\n- 2 tbsp cocoa powder\n- 1/4 cup protein powder\n"
             << "- 1 tbsp maple syrup\n- 1 tbsp chia seeds\n- 1 tbsp peanut butter\n- 3/4 cup almond milk\n\n";
        cout << "Instructions: Blend all ingredients until smooth.\n\nProtein: 30g | Carbs: 37g | Fat: 13g\n\n";
        cout << setfill('*') << setw(75) << '*' << endl << endl;
        break;

    case 4:
        cout << "Have a great day!\n";
        cout << "Stay strong and keep fueling right, " << name << "!\n";
        cout << setfill('*') << setw(75) << '*' << endl;
        break;

    default:
        cout << "That is not a valid choice, but thank you for using the program!\n";
        cout << "Stay strong and keep fueling right, " << name << "!\n";
        cout << setfill('*') << setw(75) << '*' << endl;
        break;
    }


    return 0;
}
// *******************Vegetarian Nutrition for Weightlifting*******************

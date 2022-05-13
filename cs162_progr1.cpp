//****************************************************
// Name: Saimon Asghedom
// Class: Cs162 
// Darw: 10/13/20
// Purpose: This program will help you organize your
// time to finish your programming assignment 
// on time.
//**************************************************

#include <iostream>

using namespace std;

int main()
{
    int progrHrs;           //to store the number of hours needed to program
    int daysLeft;           //to store the number of days left before the due date
    int totalTime;          //to store the total time left until the due date
    int workTime;           //to store the time spent working each day
    int personalTime;       //to store the time spent on personal activities
    int leisureTime;        //to store the time spent on leisure activities
    int studyTime;          //to store the time spent studing
    int other;              //to store the time spent on other activities
    char response;           //to store the response of the user
    int availableTime;      //to store the total time remaining after other activities

//to allow the user to try again if they want
    do
    {
//let the user know to enter int value
       cout << "************** PLEASE ENTER WHOLE NUMBERS.(i.e. 10, 3) ********** " << endl;
       cout << "Please enter the number of total hours you expect to need to program: ";
       cin >> progrHrs;
       cout << endl;
       cout << "Please enter the number of days until the program is due: ";
       cin >> daysLeft;
       cout << endl;

//echo the input
       cout << "The number of hours you expect to need to program: " << progrHrs << "hrs" <<  endl;
       cout << "The number of days until the program is due: " << daysLeft << " days" << endl;

//output the time they have each day based on the input
       cout << "Based on the numbers you've entered you need " << progrHrs/daysLeft <<
	       "hrs and " << (((progrHrs%daysLeft) * 60)/ daysLeft) << "min each day to finish your"
               " programing\nassignment on time. " << endl;

//to find the total time we have until the due date
       totalTime = daysLeft * 24;

//to check and let the user try again in case they enter more hours that 24 hrs in a day
       do
       {
//let the user know to enter an int value
	  cout << "***************  PLEASE ENTER WHOLE NUMBERS.( i.e. 5, 10) ********** " << endl;
	  cout << "Please enter the number of hours on average per day you are not available: ";
          cin >> workTime;
	  cout  << endl;
	  cout << "Please entert the number of personal hours on average per day: ";
	  cin >> personalTime;
	  cout  << endl;
	  cout << "please enter the number of hours on average per day you spend on leisure: ";
	  cin >> leisureTime;
	  cout << endl;
	  cout << "Please enter the number of hours on average per day you spend on studying: ";
	  cin >> studyTime;
	  cout << endl;

//prompt the user if they want to enter more activities
	  cout << "Do you spend time on other activities not included above(Y or N): ";
	  cin >> response;
	  cout << endl;

//execute either statement depending on the user's input to variable response
	  if (response == 'Y' || response == 'y')
	  {
//prompt the user to enter the time spent on other activities
	    cout << "enter the time spend on average on other activities not mentioned above: ";
	    cin >> other;
	    cout << endl;

//echo the input
	    cout << "You've entered: " << endl;
	    cout << "Hours not available per day: " << workTime << "hrs" << endl;
	    cout << "Personal hours per day: " << personalTime << "hrs" << endl;
	    cout << "Leisure time per day: " << leisureTime << "hrs" << endl;
	    cout << "Study time per day: " << studyTime << "hrs" << endl;
	    cout << "Other activities per day: " << other << "hrs" << endl;
	  }
	  else if (response == 'N' || response == 'n')
	  {
//initial other to 0 if no there no other activities
	    other = 0;
//echo input
	   cout << "You've entered: " << endl;
	   cout << "Hours not available per day: " << workTime << "hrs" << endl;
	   cout << "personal hours per day: " << personalTime << "hrs" << endl;
	   cout << "Leisure time per day: " <<  leisureTime << "hrs" << endl;
	   cout << "Study time per day: " << studyTime << "hrs" << endl;
	  }

//availableTime to store the remaining time after all activities
	  availableTime = totalTime - ((workTime + personalTime + leisureTime + studyTime + other) * daysLeft);

//check guard and print error if the user enter more that 24hr in a day
	  if (availableTime < 0)
	   cout << "ERROR: The time you've entered for the given day is beyond 24hrs!\n"
		   "Please try again. " << endl;

       } while (availableTime < 0);

//print if thery don't have any time available after all their activities
       if (availableTime == 0)
	cout << "You don't have any time left on the " << daysLeft << " days you've entered.\n "
		"Please plan accordingly. " << endl;

//print if they have time available
       else if (availableTime > 0)
       {
//print if they have less time than they originally needed
	if (availableTime < progrHrs)
	  cout << "After all your activities, you have " << availableTime << "hrs total time and "
	       << availableTime/daysLeft << "hrs and " << ((availableTime%daysLeft) * 60)/daysLeft <<
		  "min each day for your programing assignment. \nYou have " << progrHrs - availableTime <<
 		  "hrs less than the time you need, plan accordingly. " <<  endl;

//print if they have more time than they originally needed
	else if (availableTime > progrHrs)
	  cout << "After all your activities, you have " << availableTime << "hrs total time and "
	       << availableTime/daysLeft << "hrs and " << ((availableTime%daysLeft) * 60)/daysLeft <<
	          "min each day for your programing assignment. \nYou have " << availableTime - progrHrs <<
		  "hrs Extra time in total. " << endl;

//print if they have the exact time they needed
	else
	  cout << "After all your activities, you have the time you requested. You need\n to program "
	       << availableTime/daysLeft << "hrs and " << ((availableTime%daysLeft) * 60)/daysLeft <<
	          "min each day to finish your assignment on time." << endl;
       }

//prompt the user if they want to try again
      cout << "If you want to try again enter \'Y\' otherwise to exit enter \'N\': ";
      cin >> response;
      cout << endl;
     } while (response != 'n' && response != 'N');

     cout << "Thank you for using our application. " << endl;

return 0;

}

///*
Created by John Akujobi
On the 19th of November, 2022

A hospital supply company wants to market a program to assist with the calculation of intravenous rates.
Design and implement a program that interacts with the user as follows: 

INTRAVENOUS RATE ASSISTANT 
Enter the number of the problem you wish to solve. 
 GIVEN A MEDICAL ORDER IN CALCULATE RATE IN 
(1) ml/hr & tubing drop factor drops / min 
(2) 1 L for n hr ml / hr 
(3) mg/kg/hr & concentration in mg/ml ml / hr 
(4) units/hr & concentration in units/ml ml / hr 
(5) QUIT 

Problem> 1 
Enter rate in ml/hr=> 150 
Enter tubing's drop factor(drops/ml)=> 15 
The drop rate per minute is 38.
//150* 15/60
rate_ml_per_hr * tubing_drop_factor_drops_per_min /60

Enter the number of the problem you wish to solve. 
 GIVEN A MEDICAL ORDER IN CALCULATE RATE IN 
(1) ml/hr & tubing drop factor drops / min 
(2) 1 L for n hr ml / hr 
(3) mg/kg/hr & concentration in mg/ml ml / hr 
(4) units/hr & concentration in units/ml ml / hr 
(5) QUIT 
Problem=> 2 
Enter number of hours=> 8 
The rate in milliliters per hour is 125. 
//The calculation is 1000/hr

Enter the number of the problem you wish to solve. 
 GIVEN A MEDICAL ORDER IN CALCULATE RATE IN 
(1) ml/hr & tubing drop factor drops / min 
(2) 1 L for n hr ml / hr 
(3) mg/kg/hr & concentration in mg/ml ml / hr 
(4) units/hr & concentration in units/ml ml / hr 
(5) QUIT 
Problem=> 3 
Enter rate in mg/kg/hr=> 0.6 
Enter patient weight in kg=> 70 
Enter concentration in mg/ml=> 1 
The rate in milliliters per hour is 42. 
// 70 * 0.6 / 1

Enter the number of the problem you wish to solve. 
 GIVEN A MEDICAL ORDER IN CALCULATE RATE IN 
(1) ml/hr & tubing drop factor drops / min 
(2) 1 L for n hr ml / hr 
(3) mg/kg/hr & concentration in mg/ml ml / hr 
(4) units/hr & concentration in units/ml ml / hr 
(5) QUIT 
Problem=> 4 
Enter rate in units/hr=> 1000 
Enter concentration in units/ml=> 25 
The rate in milliliters per hour is 40. 
//1000 / 40

Enter the number of the problem you wish to solve. 
 GIVEN A MEDICAL ORDER IN CALCULATE RATE IN 
(1) ml/hr & tubing drop factor drops / min 
(2) 1 L for n hr ml / hr 
(3) mg/kg/hr & concentration in mg/ml ml / hr 
(4) units/hr & concentration in units/ml ml / hr 
(5) QUIT

Problem=> 5 


Implement the following functions: 

print_Menu ();
	- Prints the user menu
  
//Definition
void print_Menu()
{
  //This function prints the user menu to the terminal
  printf("\n\n;
  printf("----------------------MENU----------------------\n");
  printf(" GIVEN A MEDICAL ORDER IN CALCULATE RATE IN \n");
  printf("(1) OPTION 1 \n");
  printf("    [ml/hr & tubing drop factor drops/min] \n");
  printf("    [calculates drops/min] \n");
  printf("(2) OPTION 2 \n");
  printf("    [1L for X hrs] \n");
  printf("(3) OPTION 3 \n");
  printf("    [mg/kg/hr & concentration in mg/ml] \n");
  printf("(4) OPTION 4")
  printf("    [Units/hr & concentration in units/ml] \n");
  printf("(5) QUIT \n\n;
  printf("\n\n;
}



get_problem ();
	- Displays the user menu, then inputs
  - returns as the function value the problem number selected. 
  
//Definition
int get_problem ()
{
	//declaring the local variable to represent the choice picked
	int option;
  
  //prints the user menu
  print_Menu();
  
  //Prompt the user for their choice
	printf("Enter the option you want to solve (1 - 5) --->:");
  scanf("%d" option);
  printf("\n\n;");
  
  return option;
}
  


int main ();
	- Takes in the problem number selected
  - and uses switch statements to pick then call the respective function
//
int main ()
{
	//Declare the variables
  int drop_rate_per_minute = 0;
  
  int ml_per_hr = 0;
  
  float rate_ml_per_hr;
  
  float tubing_drop_factor_drops_per_min;
  
  float number_of_hours;
  
  float rate_mg_per_kg_per_hr;
  
  float patient_weight_kg;
  
  float conc_mg_per_ml;
  
  float rate_units_per_hr;
  
  float conc_units_per_ml;
  
  
	print_Welcome ();
  
  do
  {
  	option = get_problem ();
    
    //Checks for invalid input
    if (option < 1 || option > 5)
    {
    	//Do an error check and informs the user
      //And repeat until there is a valid 
      while (option < 1 || option > 5)
      {
        printf("\nOops! Invalid Option");
        printf("\nPlease type in a number between 1 - 5 --->:");
        scanf("%d", &option);
        printf("\n");
      }
    }
    
    //checks if the user picked the first option
    else if (option == 1)
    {
      //Calls get_rate_drop_factor_OP1 to get the required input from the user
      get_rate_drop_factor_OP1 (&rate_ml_per_hr, &tubing_drop_factor_drops_per_min);
			
      //Calls OP1_fig_drops_min to calculat drop_rate_per_minute
    	drop_rate_per_minute = OP1_fig_drops_min (&rate_ml_per_hr, &tubing_drop_factor_drops_per_min);
      
      //prints the result
    	printf ("The drop rate per minute is %d.\n\n", drop_rate_per_minute);
    }
    
    else if (option == 5)
    {
    	printf("Have a good day!\n");
      exit (0);
    }
    
    else
    {
    	//This switch statements will process the other choices
      switch (option)
      {
        case 2:
          //Calls # to get the required input from the user
          
          //Calls # to calculate ml_per_hr
          ml_per_hr = OP2_fig_ml_hr (&number_of_hours);
          break;

        case 3
          //
          ml_per_hr = OP3_by_weight (&rate_mg_per_kg_per_hr, &patient_weight_kg, &conc_mg_per_ml);

          break;

        case 4
          //
          ml_per_hr = OP4_by_units (&rate_units_per_hr, &conc_units_per_ml);
          break;
      }
      //After the switch case is executed, the result is printed
      printf("The rate in millimeters per hour is %d", ml_per_hr);
    }
    
  
  } while (option != 5)
  
  return 0;
}

 

print_Welcome ();
	- Prints a welcome statement
  - Tells the user the purpose of the program
  
void print_Welcome ()
{
	printf("Welcome to the\nINTRAVENOUS RATE ASSISTANT\n");
  printf("This program would help you calculate the rate in\n");
  printf("- Milliliters per hour\n");
  printf("- And Drops per Minute\n");
  printf("\n");
}



get_rate_drop_factor_OP1 (&rate_ml_per_hr, &tubing_drop_factor_drops_per_min);
	- Prompts the user to enter the data required for problem 1,
  - and sends this data back to the calling module via output parameters.
//Definition
void get_rate_drop_factor_OP1 (float *rate_ml_per_hr, float *tubing_drop_factor_drops_per_min)
{
  //Informs the user about the Option
  printf("OPTION 1\n");
  printf("This calculates the drop per minute\n");
  
  //Prompts the user for rate_ml_per_hr
  printf("Type in the rate in millimeter per hour --->:");
  scanf("%f", rate_ml_per_hr);
  printf("\n;");

  //Prompts the user for tubing_drop_factor_drops_per_min
  printf("Type in the tubing drop factor in drops per minute --->:");
  scanff("%f", tubing_drop_factor_drops_per_min);
	printf("\n;");
	
  return;
}



get_number_of_hours_OP2 (&number_of_hours);
	- Prompts the user for the number of hours
  - and sends this data back to the calling module via output parameters.
           
//Definition
void get_number_of_hours_OP2 (float *number_of_hours)
{
  //Informs the user about the Option
  printf("OPTION 2\n");
  printf("Using the number of hours that 1Litre will be consumed,\n");
  printf("Then calculates the rate in millimeters per hour\n");

  
  //Prompts the user for number_of_hours
  printf("Type in the number_of_hours --->:");
  scanf("%f", number_of_hours);
  printf("\n;");
	
  return;
}

           
  
get_kg_rate_conc_OP3 (&rate_mg_per_kg_per_hr, &patient_weight_kg, conc_mg_per_ml);
	- Prompts the user to enter the data required for problem 3,
  - and sends this data back to the calling module via output parameters. 
           
//Definition
void get_patient_weight_OP3 (float *rate_mg_per_kg_per_hr, float *patient_weight_kg, float *conc_mg_per_ml)
{
  //Informs the user about the Option
  printf("OPTION 3\n");
  printf("Using the number of hours that 1Litre will be consumed,\n");
  printf("Then calculates the rate in millimeters per hour\n\n");

  //Prompts the user for rate_mg_per_kg_per_hr
  printf("Type in the rate in millimeter per hour --->:");
  scanf("%f", rate_mg_per_kg_per_hr);
  printf("\n;");
  
  //Prompts the user for patient_weight_kg
  printf("Type in the rate in patient_weight_kg --->:");
  scanf("%f", patient_weight_kg);
  printf("\n;");

  //Prompts the user for conc_mg_per_ml
  printf("Type in the tubing drop factor in conc_mg_per_ml --->:");
  scanff("%f", conc_mg_per_ml);
	printf("\n;");
	
  return;
}



get_units_conc_OP4(&rate_units_per_hr, &conc_units_per_ml)
	- Prompts the user to enter the data required for problem 4,
  - and sends this data back to the calling module via output parameters. 
//Definition
void get_units_conc_OP4 (float *rate_units_per_hr, float *conc_units_per_ml)
{
  //Informs the user about the Option
  printf("OPTION 4\n");
  printf("Using the rate in units per hour and concentration in units per milliliter,\n");
  printf("Then calculates the rate in millimeters per hour\n\n");

  //Prompts the user for rate_units_per_hr
  printf("Type in the rate in units per hour --->:");
  scanf("%f", rate_units_per_hr);
  printf("\n;");
  
  //Prompts the user for conc_units_per_ml
  printf("Now, type in the concentration in units per milliliter --->:");
  scanf("%f", conc_units_per_ml);
  printf("\n;");

  return;
}

           
int rounding (number);
	-This function rounds up the float to the nearest whole number
  - and returns it as an integer
  
int rounding (float number)
{
   return (int) (number < 0 ? number - 0.5 : number + 0.5);
}



OP1_fig_drops_min (&rate_ml_per_hr, &tubing_drop_factor_drops_per_min)
	- Takes rate and drop factor as input parameters
  and returns drops/min (rounded to nearest whole drop) as function value.
  
\\Definition
int OP1_fig_drops_min (float *rate_ml_per_hr, float *tubing_drop_factor_drops_per_min)
{
  //Declares drop_rate_per_minute, then calculates it
	float drop_rate_per_minute = 	(*rate_ml_per_hr) * (*tubing_drop_factor_drops_per_min /60.0);
  
  //returns a rounded ml_per_hr
	return rounding (drop_rate_per_minute);
}



OP2_fig_ml_hr (&number_of_hours);
	- Takes as an input parameter the number of hours over which one liter is to be delivered
  - and returns ml/hr (rounded) as function value. 
//Function Definition
int OP2_fig_ml_hr (float *number_of_hours)
{
   //calculating ml_per_hr
  float ml_per_hr = 1000 / (*number_of_hours);
  
  //returns a rounded ml_per_hr
  return rounding (ml_per_hr);
}



OP3_by_weight (&rate_mg_per_kg_per_hr, &patient_weight_kg, &conc_mg_per_ml);
	- Takes as input parameters rate in mg/kg/hr, patient weight in kg, 
	- and concentration of drug in mg/ml
  - and returns ml/hr (rounded) as function value. 
//Function Definition
int OP3_by_weight (float *rate_mg_per_kg_per_hr, float *patient_weight_kg, float *conc_mg_per_ml)
{
	float ml_per_hr =  ( (*rate_mg_kg_hr) * (*patient_weight_kg) ) / (*drug_conc_mg_ml);
  
  //returns a rounded ml_per_hr
	return rounding (ml_per_hr);
}



OP4_by_units (&rate_units_per_hr, &conc_units_per_ml);
	- Takes as input parameters rate in units/hr and concentration in units/ml,
  and returns ml/hr (rounded) as function value. 
//Definition
int OP4_by_units (float *rate_units_per_hr, float *conc_units_per_ml)
{
  //defines ml_per_hr then calculates it
	float ml_per_hr =  ( (*rate_units_per_hr) / (*conc_units_per_ml) );
  
  //returns a rounded ml_per_hr
	return rounding (ml_per_hr);
}


  
( Hint: Use a sentinel-controlled loop. Call get_problem once before the loop 
to initialize the problem number and once again at the end of the loop body to 
update it.)
*/

//Code

#include <stdio.h>
#include <stdlib.h>
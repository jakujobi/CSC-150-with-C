/*
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void print_Welcome ();
	//- Prints a welcome statement
  //- Tells the user the purpose of the program
	//Called by
	//print_Welcome ();
void print_Welcome ()
{
	printf("Welcome to the\nINTRAVENOUS RATE ASSISTANT\n");
  printf("This program would help you calculate the rate in\n");
  printf("- Milliliters per hour\n");
  printf("- And Drops per Minute\n");
  printf("\n");
}



void print_Menu ();
	//- Prints the user menu
	//Called by
	//print_Menu ();
void print_Menu()
{
  //This function prints the user menu to the terminal
  printf("\n----------------------MENU----------------------\n");
  printf(" GIVEN A MEDICAL ORDER IN CALCULATE RATE IN \n");
  printf("(1) OPTION 1 \n");
  printf("    [ml/hr & tubing drop factor drops/min] \n");
  printf("    [calculates drops/min] \n");
  printf("(2) OPTION 2 \n");
  printf("    [1L for X hrs] \n");
  printf("(3) OPTION 3 \n");
  printf("    [mg/kg/hr & concentration in mg/ml] \n");
  printf("(4) OPTION 4\n");
  printf("    [Units/hr & concentration in units/ml] \n");
  printf("(5) QUIT \n\n");
  printf("\n\n");
}
         
         

int get_problem ();
	//- Displays the user menu, then inputs
  //- returns as the function value the problem number selected.
	//Called by
	//get_problem ();
//Definition
int get_problem ()
{
	//declaring the local variable to represent the choice picked
	int option;
  
  //prints the user menu
  print_Menu();
  
  //Prompt the user for their choice
	printf("Enter the option you want to solve (1 - 5) --->:");
  scanf("%d",&option);
  printf("\n\n\n");
  
  return option;
}

         
         
void get_rate_drop_factor_OP1 (float *rate_ml_per_hr, float *tubing_drop_factor_drops_per_min);
	//- Prompts the user to enter the data required for Option 1,
  //- and sends this data back to the calling module via output parameters.
	//Called by
	//get_rate_drop_factor_OP1 (&rate_ml_per_hr, &tubing_drop_factor_drops_per_min);  
//Definition
void get_rate_drop_factor_OP1 (float *rate_ml_per_hr, float *tubing_drop_factor_drops_per_min)
{
  //Informs the user about the Option
  printf("OPTION 1\n");
  printf("This calculates the drop per minute\n");
  
  //Prompts the user for rate_ml_per_hr
  printf("Type in the rate in millimeter per hour --->:");
  scanf("%f", rate_ml_per_hr);
  printf("\n");

  //Prompts the user for tubing_drop_factor_drops_per_min
  printf("Type in the tubing drop factor in drops per minute --->:");
  scanf("%f", tubing_drop_factor_drops_per_min);
	printf("\n");
	
  return;
}
         
         

void get_number_of_hours_OP2 (float *number_of_hours); 
	//- Prompts the user for the number of hours for option 2
  //- and sends this data back to the calling module via output parameters.
	//Called by
	//get_number_of_hours_OP2 (&number_of_hours);
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
  printf("\n");
	
  return;
}
         



void get_patient_weight_OP3 (float *rate_mg_per_kg_per_hr, float *patient_weight_kg, float *conc_mg_per_ml);
	//- Prompts the user to enter the data required for Option 3,
  //- and sends this data back to the calling module via output parameters.
	//Called by
	//get_kg_rate_conc_OP3 (&rate_mg_per_kg_per_hr, &patient_weight_kg, conc_mg_per_ml);
         
void get_patient_weight_OP3 (float *rate_mg_per_kg_per_hr, float *patient_weight_kg, float *conc_mg_per_ml)
{
  //Informs the user about the Option
  printf("OPTION 3\n");
  printf("Using the number of hours that 1Litre will be consumed,\n");
  printf("Then calculates the rate in millimeters per hour\n\n");

  //Prompts the user for rate_mg_per_kg_per_hr
  printf("Type in the rate in millimeter per hour --->:");
  scanf("%f", rate_mg_per_kg_per_hr);
  printf("\n");
  
  //Prompts the user for patient_weight_kg
  printf("Type in the rate in patient_weight_kg --->:");
  scanf("%f", patient_weight_kg);
  printf("\n");

  //Prompts the user for conc_mg_per_ml
  printf("Type in the tubing drop factor in conc_mg_per_ml --->:");
  scanf("%f", conc_mg_per_ml);
	printf("\n");
	
  return;
}
         
         

void get_units_conc_OP4 (float *rate_units_per_hr, float *conc_units_per_ml);
	//- Prompts the user to enter the data required for Option 4,
  //- and sends this data back to the calling module via output parameters. 
	//Called by
	//get_units_conc_OP4(&rate_units_per_hr, &conc_units_per_ml);
void get_units_conc_OP4 (float *rate_units_per_hr, float *conc_units_per_ml)
{
  //Informs the user about the Option
  printf("OPTION 4\n");
  printf("Using the rate in units per hour and concentration in units per milliliter,\n");
  printf("Then calculates the rate in millimeters per hour\n\n");

  //Prompts the user for rate_units_per_hr
  printf("Type in the rate in units per hour --->:");
  scanf("%f", rate_units_per_hr);
  printf("\n");
  
  //Prompts the user for conc_units_per_ml
  printf("Now, type in the concentration in units per milliliter --->:");
  scanf("%f", conc_units_per_ml);
  printf("\n");

  return;
}
         
         
         
         
int rounding (float number);
	//-This function rounds up the float to the nearest whole number
  //- and returns it as an integer
	//Called by
	//rounding (number);
int rounding (float number)
{
   return (int) (number < 0 ? number - 0.5 : number + 0.5);
}
         

int OP1_fig_drops_min (float *rate_ml_per_hr, float *tubing_drop_factor_drops_per_min);
	//- Takes rate and drop factor as input parameters
  //- and returns drops/min (rounded to nearest whole drop) as function value.
	//Called by
	//OP1_fig_drops_min (&rate_ml_per_hr, &tubing_drop_factor_drops_per_min);      
//Definition
int OP1_fig_drops_min (float *rate_ml_per_hr, float *tubing_drop_factor_drops_per_min)
{
  //Declares drop_rate_per_minute, then calculates it
	float drop_rate_per_minute = 	(*rate_ml_per_hr) * (*tubing_drop_factor_drops_per_min /60.0);
  
  //returns a rounded ml_per_hr
	return rounding (drop_rate_per_minute);
}
         
         

int OP2_fig_ml_hr (float *number_of_hours);
	//- Takes as an input parameter the number of hours over which one liter is to be delivered
  //- and returns ml/hr (rounded) as function value.
	//Called by
	//OP2_fig_ml_hr (&number_of_hours);
//Function Definition
int OP2_fig_ml_hr (float *number_of_hours)
{
   //calculating ml_per_hr
  float ml_per_hr = 1000.0 / (*number_of_hours);
  
  //returns a rounded ml_per_hr
  return rounding (ml_per_hr);
}

         
  
  
int OP3_by_weight (float *rate_mg_per_kg_per_hr, float *patient_weight_kg, float *conc_mg_per_ml);
	//- Takes as input parameters rate in mg/kg/hr, patient weight in kg, 
	//- and concentration of drug in mg/ml
  //- and returns ml/hr (rounded) as function value. 
  //Called by
  //OP3_by_weight (&rate_mg_per_kg_per_hr, &patient_weight_kg, &conc_mg_per_ml);
//Function Definition
int OP3_by_weight (float *rate_mg_per_kg_per_hr, float *patient_weight_kg, float *conc_mg_per_ml)
{
	float ml_per_hr =  ( (*rate_mg_per_kg_per_hr) * (*patient_weight_kg) ) / (*conc_mg_per_ml);
  
  //returns a rounded ml_per_hr
	return rounding (ml_per_hr);
}
         
         
 
int OP4_by_units (float *rate_units_per_hr, float *conc_units_per_ml);
	//- Takes as input parameters rate in units/hr and concentration in units/ml,
  //and returns ml/hr (rounded) as function value.
	//Called by
	//OP4_by_units (&rate_units_per_hr, &conc_units_per_ml);
//Definition       
int OP4_by_units (float *rate_units_per_hr, float *conc_units_per_ml)
{
  //defines ml_per_hr then calculates it
	float ml_per_hr =  ( (*rate_units_per_hr) / (*conc_units_per_ml) );
  
  //returns a rounded ml_per_hr
	return rounding (ml_per_hr);
}




int main ()
{
	//Declare the variables
  
  int drop_rate_per_minute = 0; //This is the result from Option 1
  
  int ml_per_hr = 0; //The result from Options 2 to 4
  
  int option; //represents the choice the user picks from the menu
  
  float rate_ml_per_hr; //used as an input in get_rate_drop_factor_OP1 and OP1_fig_drops_min
  
  float tubing_drop_factor_drops_per_min; //used as an input in get_rate_drop_factor_OP1 and OP1_fig_drops_min
  
  float number_of_hours; //used as an input in get_number_of_hours_OP2 and OP2_fig_ml_hr
  
  float rate_mg_per_kg_per_hr; //used as an input in get_patient_weight_OP3 and OP3_by_weight
  
  float patient_weight_kg; //used as an input in get_patient_weight_OP3 and OP3_by_weight
  
  float conc_mg_per_ml; //used as an input in get_patient_weight_OP3 and OP3_by_weight
  
  float rate_units_per_hr; //used as an input in get_units_conc_OP4 and OP4_by_units
  
  float conc_units_per_ml; //used as an input in get_units_conc_OP4 and OP4_by_units
 
  
  //Prints the Welcome message
	print_Welcome ();
  
  //This do-while loop lets the program to repeat
  do
  {
    //calls get_problem(); to prompt the user for a choice
    //Then assigns the choice to the variable option
  	option = get_problem ();
    
    //Checks for invalid input
    if (option < 1 || option > 5)
    {
    	//Do an error check and informs the user
      //And repeat until there is a valid 
      while (option < 1 || option > 5)
      {
        //Prints an error message
        printf("\nOops! Invalid Option");
        
        //Asks user to type in a valid choice
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
    
    //executes if the option is 5 which represents quit or exit in the user menu
    else if (option == 5) 
    {
      //Prints a goodbye message
    	printf("Have a good day!\n");
      
      //Exits the program
      exit (0);
    }
    
    else
    {
    	//This switch statements will process the other choices
      switch (option)
      {
        case 2:
          //Calls # to get the required input from the user
          get_number_of_hours_OP2 (&number_of_hours);
          
          //Calls # to calculate ml_per_hr
          ml_per_hr = OP2_fig_ml_hr (&number_of_hours);
          break;

        case 3:
          //Calls # to get the required input from the user
          get_patient_weight_OP3 (&rate_mg_per_kg_per_hr, &patient_weight_kg, &conc_mg_per_ml);
          
          //Calls # to calculate ml_per_hr
          ml_per_hr = OP3_by_weight (&rate_mg_per_kg_per_hr, &patient_weight_kg, &conc_mg_per_ml);

          break;

        case 4:
          //Calls # to get the required input from the user
          get_units_conc_OP4 (&rate_units_per_hr, &conc_units_per_ml);
          
          //Calls # to calculate ml_per_hr
          ml_per_hr = OP4_by_units (&rate_units_per_hr, &conc_units_per_ml);
          break;
      }
      //After the switch case is executed, the result is printed
      printf("The rate in millimeters per hour is %d", ml_per_hr);
    }
    
  
  } while (option != 5); //Does not repeat if the choice is 5 which represents quit or exit in the user menu
  
  return (0);
}
        

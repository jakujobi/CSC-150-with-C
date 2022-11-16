/*	Create a grades file for transmission to Registrar.
	   Written by:
	   Date:
*/
#include <stdio.h>

//	Function Declarations
int getStu     (FILE* spStu,
                int* stuID, int*  exam1,
                int*  exam2, int* final);
int writeStu   (FILE* spGrades,
                int   stuID, int   avrg,  char grade);
void calcGrade (int   exam1, int   exam2, int  final,
                int*  avrg,  char* grade);

int main (void)
{
//	Local Declarations
	FILE* spStu;
	FILE* spGrades;

	int stuID;
	int exam1;
	int exam2;
	int final;
	int avrg;

	char grade;

//	Statements
	printf("Begin student grading\n");
	if (!(spStu = fopen ("stu_grades.txt", "r")))
	   {
	    printf("\aError opening student file\n");
	    return 100;
	   } // if open input

	if (!(spGrades = fopen ("P07-06Gr.DAT", "w")))
	   {
	    printf("\aError opening grades file\n");
	    return 102;
	   } // if open output

	while (getStu (spStu, &stuID, &exam1, &exam2, &final))
	   {
	    calcGrade (exam1, exam2, final, &avrg, &grade);
	    writeStu  (spGrades, stuID, avrg, grade);
	   } // while

	fclose (spStu);
	fclose (spGrades);

	printf("End student grading\n");
	return 0;
}	// main


/* ======================== getStu =======================
	Reads data from student file.
	   Pre   spStu is an open file.
	         stuID, exam1, exam2, final pass by address
	   Post  reads student ID and exam scores
	         if data read   --returns 1
	         if EOF or error--returns 0
*/
int getStu (FILE* spStu, int* stuID, int* exam1,
            int*  exam2, int* final)
{
//	Local Declarations
	int ioResult;

//	Statements
	ioResult = fscanf(spStu, "%d%d%d%d", stuID, exam1, exam2, final);
	if (ioResult == EOF)
	    return 0;
	else if (ioResult != 4)
	   {
	    printf("\aError reading data\n");
	    return 0;
	   } // if
	else
	   return 1;
}	// getStu

/*	==================== calcGrade ===================
	Determine student grade based on absolute scale.
	   Pre   exam1, exam2, and final contain scores
	         avrg and grade are addresses of variables
	   Post  Average and grade copied to addresses
*/
void calcGrade (int  exam1, int   exam2, int final, int* avrg,  char* grade)
{
//	Statements
	*avrg = (exam1 + exam2 + final) / 3;
	if (*avrg >= 90)
	   *grade = 'A';
	else if (*avrg >= 80)
	   *grade = 'B';
	else if (*avrg >= 70)
	   *grade = 'C';
	else if (*avrg >= 60)
	   *grade = 'D';
	else
	   *grade = 'F';
	return;
}	// calcGrade

/*	===================== writeStu ====================
	Writes student grade data to output file.
	   Pre   spGrades is an open file
	         stuID, avrg, and grade have values to write
	   Post  Data written to file
*/
int writeStu  (FILE* spGrades, int  stuID,
               int   avrg,     char grade)
{
//	Statements
	fprintf(spGrades, "%04d %d %c\n",
	                   stuID, avrg, grade);
	return 0;
}	// writeStu

/*	Results:
Begin student grading
End student grading

Input--------
0090 90 90 90
0089 88 90 89
0081 80 82 81
0079 79 79 79
0070 70 70 70
0069 69 69 69
0060 60 60 60
0059 59 59 59

Output----
0090 90 A \n
0089 89 B \n
0081 81 B \n
0079 79 C \n
0070 70 C \n
0069 69 D \n
0060 60 D \n
0059 59 F \n
*/

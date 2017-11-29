 /**
 *Joshua Whiteford
 *20/11/2017
 *main.c
 *Coordinate Conversion
 */



/**< preprocessor directives */
#include <iostream>
#include <stdio.h>
#include <tgmath.h>
#include <math.h>

using namespace std;
/**< Starting all of the functions */
void cartesian(double *r_ptr, double *ang_ptr);
void polar(double *r_ptr, double *ang_ptr);
/**< Starting the main function */
int main()
{
    /**< Variable Decliration */
    char input;
    double  radx = 0, angy = 0 ;
    double *r_ptr, *ang_ptr;

    /**< Introducing the User to the program */
    cout << "\t\tCoordinate Conversion!" << endl << "This application will convert from polar to Cartesian and back!" << endl;

    /**< Setting out pointers to the address of radx & angy */
    r_ptr = &radx;
    ang_ptr = &angy;

    /**< Sending the program into a loop until the user enters some value */
     do
    {
        /**< Displaying the Different tasks this program can do */
        cout << "Please Select one of the following Keys depending upon which conversion you wish to do!"<< endl;
        cout << " Press 'p' to select:\tCartesian to Polar conversion" << endl;
        cout << " Press 'c' to select:\tPolar to Cartesian conversion " << endl;
        cout << "\tPress 'q' to Quit ";

        fflush(stdin);
        /**< Getting the User to input a character */
        cin >> input;

        /**< Checxking if the Inputted character is equal to any of the following cases */
        switch (input)
        {
             case 'p' :
                        /**< Asking the user to prepare to enter values in  */
                        cout << "Prepare too enter two Values for the polar cordinates you wish to convert! ";

                        /**< Seding the program to the Another function */
                        polar(r_ptr, ang_ptr);

                        /**< Displaying the Result to the User */
                        cout << "The Magnitude of the Angle is: " << radx << endl;
                        cout << "The angle is: " << angy << endl;

                        /**< Ending this part of the switch Case */
                        break;

            case 'c' :
                        /**< Asking the User to Prepare to enter values in */
                        cout << "Prepare too enter two Values for the Cartesian cordinates you wish to convert " ;

                        /**< Sending the program to Another Function */
                        cartesian(r_ptr, ang_ptr);

                        /**< Dislpaying the Result to the user */
                        cout << "The X Cordinate is: " << radx << endl;
                        cout << "The Y Cordinate is: " << angy << endl;

                        /**< Ending this part of the Switch Case */
                        break;

            case 'q' :
                        /**< Thanking & saying goodbye to the User */
                        cout << "Tank you and GoodBye..." << endl;

                        /**< Ending this part of the Switch case */
                        break;

            default :
                        /**< Asking the User to try to select the case they want again */
                        cout << "\t\tPlease Try that again!" << endl;

                        /**< Ending this part of the Switch Case */
                        break;
        }
    }
    /**< Causing the Program to loop with the input is not equal to 'q' */
    while (input != 'q');

    /**< Ending the pregram */
    return 0;
}

/**< Polar to Cartesian convertion function */
void cartesian(double *r_ptr, double *ang_ptr)
{
    /**< Variable Decliration */
    double num1 = 0, num2 =0, num3 = 0, num4 =0;

        /**< Asking the user to enter a value in for R and declaring num1 to be equal to it  */
        cout <<endl << "Enter a value for R :";
        cin >> num1;

        /**< Asking the user to enter a value in for the angle and declaring num2 to be equal to it  */
        cout << endl << "Enter the Angle ";
        cin >> num2;

        /**< Doing equations to calcualte x & y */
        num3 = num1 *cos((num2*M_PI)/180);
        num4 = num1 * sin((num2*M_PI)/180);

        /**< Declaring the ptr's to be equal to our calculated values, which in turn sets the value of the address the ptr's are pointing to to be equal to num1 & num2 */
        *r_ptr = num3;
        *ang_ptr = num4;
}


void polar(double *r_ptr, double *ang_ptr)
{
    /**< Variable Decliration */
    double num1 = 0, num2 =0;
    float angle , rad;

        /**< Asking the user to enter the X & Y Cordinates */
        cout << endl << "Enter the X Cordinate:";
        cin >> num1;
        cout << endl << "Enter the Y Cordinate";
        cin >> num2;

    /**< Doing equations to calcualte rad & angle */
    rad = sqrt((num1*num1)+(num2*num2));
    angle =  180 * (atan2(num2,num1))/M_PI;

    /**< Declaring the ptr's to be equal to our calculated values, which in turn sets the value of the address the ptr's are pointing to to be equal to num1 & num2 */
    *r_ptr = rad;
    *ang_ptr = angle;
}


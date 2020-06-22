import java.util.Scanner;
import java.lang.*;

public class rationalArithmetic {
	/*Recursively finds the greatest common denominator between two numbers (where num1 >= num2).
	If both numbers are the same, then it returns itself. Otherwise, it will recursively loop until num2 = 0
	Uses Euclidean Algorithm to find the gcd
	*/
	public static long gcd(long num1, long num2) {
		if(num1 == num2)
			return num1;

		if(num2 == 0)
			return num1;

		return gcd(num2, num1 % num2);
	}

	public static void main(String[] args) {
		//Initiallizing scanner
		Scanner input = new Scanner(System.in);

		//Stores the number total inputs passed into the program. This is not used anywhere
		int numberOfInputs = Integer.parseInt(input.nextLine());

		//While-loop that that continues until there are no more inputs (or End-of-File)
		while(input.hasNextLine()) {
			//Takes one line of input, splits it along the " " delimiter and stores it in the array
			String[] inputs = input.nextLine().split(" ");

			//Stores the numerator and denominator of the first fraction
			long num1 = Long.parseLong(inputs[0]), den1 = Long.parseLong(inputs[1]);

			//Stores the operation used between the two fractions
			String operation = inputs[2];

			//Stores the numerator and denominator of the second fraction
			long num2 = Long.parseLong(inputs[3]), den2 = Long.parseLong(inputs[4]);

			/*Initiallzing variables to store what the numerator and denominator will be after performing the operation. 
			  The divisor is used to reduce the resultant numerator and denominator by their greatest common denominator
			 */
			long resultNum, resultDen, divisor;

			//Switch-statement 
			switch(operation) {
				case "+":
					//Multiplies the numerator of fraction one with the denominator of fraction two
					num1 = num1 * den2;

					//Multiplies the numerator of fraction two with the denominator of fraction one
					num2 = num2 * den1;

					//Adds the two previosuly calculated numerators together
					resultNum = num1 + num2;

					//Multiplies the denominators of the two fractions together
					resultDen = den1 * den2;
					break;
				case "-":
					//Multiplies the numerator of fraction one with the denominator of fraction two
					num1 = num1 * den2;

					//Multiplies the numerator of fraction two with the denominator of fraction one
					num2 = num2 * den1;

					//Subtracts the two previosuly calculated numerators together
					resultNum = num1 - num2;

					//Multiplies the denominators of the two fractions together
					resultDen = den1 * den2;
					break;
				case "*":
					//Multiplies the numerators of the two fractions together
					resultNum = num1 * num2;

					//Multiplies the denominators of the two fractions together
					resultDen = den1 * den2;
					break;
				case "/":
					//Multiplies the numerator of fraction one with the denominator of fraction two
					resultNum = num1 * den2;

					//Multiplies the numerator of fraction two with the denominator of fraction one
					resultDen = den1 * num2;
					break;
				default:
					//Exits the program if an input not specified in the switch is given
					return;
			};

			//If-else statement to determine which number to pass as the first parameter to the function. If the numerator is bigger, then it is passes first. Otherwise, the denominator is passed first.
			if(resultNum > resultDen)
				divisor = gcd(Math.abs(resultNum), Math.abs(resultDen));
			else
				divisor = gcd(Math.abs(resultDen), Math.abs(resultNum));

			//Divides both numbers by the gcd
			resultNum = resultNum/divisor;
			resultDen = resultDen/divisor;

			/*Checks if the denominator is 0. If it is, then it mulitplies -1 to both numbers
			  This is for the situations where the numerator is positive while the denominator is negative, then it moves the sign to numerator
			  It also (as a consequence) remove the sign from both numbers if they are both negative
			*/
			if(resultDen < 0) {
				resultDen = resultDen * -1;
				resultNum = resultNum * -1;
			}

			//Outputs to terminal
			System.out.println(resultNum + " / " + resultDen);
		}
	}
}
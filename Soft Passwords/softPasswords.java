import java.util.*;
import java.lang.*;

public class softPasswords {
	/*Checks if both strings are exactly the same by using the String class .equals() method. 
	  Returns true if both strings are exactly the same. Otherwise, it returns false.
	*/
	public static boolean identicalStrings(String password1, String password2) {
		return password1.equals(password2);
	}

	/*Checks if password1 is similar to password2 by being the same string but with a digit prepended or appended to it.
	  Returns true if either condition is meet. Otherwise, it returns false.
	*/
	public static boolean appendNumberString(String password1, String password2) {
		//Checks if password1 is the same as password2 after removing the first character (checks for the condition in which a digit is prepended to it)
		if(identicalStrings(password1.substring(1), password2)) {
			//For-loop to check if the first character is a digit. If it is, then the method returns true.
			for(int number = 0; number < 10; number++)
				if(password1.substring(0, 1).equals(Integer.toString(number)))
					return true;
		}

		//Checks if password1 is the same as password2 after removing the last character (checks for the condition in which a digit is appended to it)
		if(identicalStrings(password1.substring(0, password1.length() - 1), password2)) {
			//For-loop to check if the last character is a digit. If it is, then the method returns true.
			for(int number = 0; number < 10; number++) 
				if(password1.substring(password1.length() - 1).equals(Integer.toString(number)))
					return true;
		}

		return false;
	}

	/*Helper method for reverseCaseString(). It takes the ASCII array defined in that method and the value it wants to compare in the array. It is used to determine if that ASCII value for the character is a number.
	  Returns true if the value is in the array. Otherwise, it returns false.
	*/
	public static boolean iterateThroughPrimitiveArray(int[] array, int value) {
		for(int x : array)
			if(x == value)
				return true;

		return false;
	}

	/*Checks if all the letters in password2 are the same and the reverse case of password1.
	  Returns true if the condition is meet. Otherwise, it returns false. 
	*/
	public static boolean reverseCaseString(String password1, String password2) {
		/*Checks if both strings are fundamentally the same. 
		  If true, then it continues through the rest of function. Otherwise, it exits the method and returns false.*/
		if(!password1.equalsIgnoreCase(password2))
			return false;

		//Array that holds the ASCII values for the digits 0-9
		int[] numberAscii = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

		//For-loop that extracts the character from each string at an index value to compare with each other 
		for(int index = 0; index < password1.length(); index++) {
			//Stores the character from the input strins at index
			char c1 = password1.charAt(index), c2 = password2.charAt(index);

			//Converts the character to its ASCII value
			int ascii1 = (int) c1, ascii2 = (int) c2;

			/*If-statement for two cases when the characters at index are the same: 
				Case 1: If both characters are numbers, then it skips the current iteration it is on and goes to the next one
				Case 2: If both characters are the same letter and the same case (meaning upper-case or lower-case), then exits the method and returns false to the function
			*/
			if(ascii1 == ascii2) {
				if(iterateThroughPrimitiveArray(numberAscii, ascii1)) 
					continue;
				else 
					return false;
			}
		}

		return true;
	}

	/*
	Function that compiles the different conditions into one function. If one of the functinos return true, then this function returns true. Otherwise, it returns false
	*/
	public static boolean checkConditions(String password1, String password2) {
		return identicalStrings(password1, password2) || appendNumberString(password1, password2) || reverseCaseString(password1, password2);
	}

	public static void main(String[] args) {
		//Used to get input from command line
		Scanner input = new Scanner(System.in);

		//Variables used to store the two inputs; password1 is string S and password2 is string P
		String password1 = input.nextLine();
		String password2 = input.nextLine();

		//Closing scanner
		input.close();

		//If-statement to output a result after a test; if the strings pass one of the conditions, it returns true and outputs "Yes"; otherwise, it outputs "No".
		if(checkConditions(password1, password2))
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
import java.lang.String;
import java.lang.Character;
import java.lang.Integer;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Hashtable;

public class anagramcounting {
	//Recursively calculates the factorial of a number
	public static BigInteger factorial(BigInteger number) {
		if(number.equals(BigInteger.ONE) || number.equals(BigInteger.ZERO))
			return BigInteger.ONE;

		return number.multiply(factorial(number.subtract(BigInteger.ONE)));
	}

	//Calculates the number of possible anagrams for a given string. 
	//This uses the multinomial theorem for counting, where it takes the total number of possible combinations and divides it with the product of the factorial of each character's frequency
	public static BigInteger multinomialTheorem(Hashtable<Character, Integer> characterFrequency, int numberOfCharacters) {
		/* Initializing variables, 
		 * numerator, stores the total number of possible combinations, based on the total number of characters in the string
		 * denominator, stores the result after taking the factorial of the frequency of a certain character and multiplying it with the current value stored here
		 */
		BigInteger numerator = factorial(BigInteger.valueOf(numberOfCharacters)), denominator = BigInteger.ONE;

		//Goes through each value stored in the table
		for(Integer x : characterFrequency.values())
			//Calculates the factorial and stores it in this variable
			denominator = denominator.multiply(factorial(BigInteger.valueOf(x)));

		//Returns the result of the multinomial theorem
		return numerator.divide(denominator);
	}

	public static void main(String[] args) {
		//Initializing input stream
		Scanner scan = new Scanner(System.in);

		/* Initializing variables, 
		 * str, used to store the current string to consider
		 * ch, used to store the extracted character found at a current index
		 */
		String str = null;
		Character ch = null;

		//Initializing collection, used to keep track of the frequency of each character in str
		Hashtable<Character, Integer> characterFrequency = new Hashtable<Character, Integer>();

		//Is used to determine if the multinomial theorem is needed
		boolean uniqueLetters = true;

		while(scan.hasNextLine()) {
			str = scan.nextLine();

			for(int index = 0; index < str.length(); index++) {
				//Stores the character
				ch = str.charAt(index);

				//Either increments the current value by 1 or inserts a new pair into the table
				characterFrequency.put(ch, characterFrequency.getOrDefault(ch, 0) + 1);

				//Checks if the string has a unique set of characters
				if(uniqueLetters && characterFrequency.get(ch) > 1)
					uniqueLetters = false;
			}

			//If str contains all unique characters, then it just calculates the factorial of the length of the string. Otherwise, it applies the multinomial theorem
			if(uniqueLetters)
				System.out.println(factorial(BigInteger.valueOf(str.length())));
			else
				System.out.println(multinomialTheorem(characterFrequency, str.length()));

			//Clearing table for next input
			characterFrequency.clear();
		}

		//Closing input stream
		scan.close();
	}
}
import java.util.Scanner;
import java.lang.String;

public class spellingbee {
	//Checks if the given word is valid to use, given the conditions outlined in the prompt
	public static Boolean isValid(String word, String givenLetters) {
		//Initializing variable, used to determine if word contains the specified starting letter (which is stored as the first character in givenLetters)
		boolean containsSpecifcCharacter = false;

		//Storing the required letter every word need to contain
		char startingLetter = givenLetters.charAt(0);

		//First, checks if the word meets the minimum size
		if(word.length() < 4)
			return false;

		//Converting the word into a character array, so that it can be traversed
		char[] wd = word.toCharArray();

		//Iterating through all of the characters in wd
		for(char c : wd) {
			//Checks if the character is one of seven stored in givenLetters
			if(givenLetters.indexOf(c) == -1)
				return false;

			//Checks if the word contains the specified letter. If it does, it changes containsSpecifcCharacter to true
			if(!containsSpecifcCharacter && c == startingLetter)
				containsSpecifcCharacter = true;
		}

		return containsSpecifcCharacter;
	}

	public static void main(String args[]) {
		//Initializing input stream
		Scanner scan = new Scanner(System.in);

		/* Initializing variables
		 *
		 * word, contains the word that needs to be verified if it is valid to use, given the conditions
		 * givenLetters, contains the approved letters to use in a word 
		 * dictionarySize, contains the number of inputs in the test case
		 */
		String givenLetters = scan.nextLine(), word;
		int inputSize = Integer.valueOf(scan.nextLine());

		//Goes through all of the given inputs in a test case
		for(int i = 0; i < inputSize; i++) {
			//Storing a given word
			word = scan.nextLine();

			//Checks if the word is valid to use in the competition. Outputs it if it is
			if(isValid(word, givenLetters))
				System.out.println(word);
		}

		//Closing input stream
		scan.close();
	}
}
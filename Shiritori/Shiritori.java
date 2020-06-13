import java.util.HashSet;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Shiritori {
	public static void main(String[] args) {
		//Initiallizing Input stream
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in)); 

		//Initiallizing Set to hold previous results
		HashSet<String> gameHistory = new HashSet<String>();

		//A try-catch block (must be implemented when using BufferedReader)
		try {
			//Stores the total number of words/turns in the game
			int numberOfInputs = Integer.parseInt(input.readLine());

			//Stores the first word used in the game; initiallizes the second variable to store the most recent word used in the game
			String word = input.readLine(), previousWord;

			//Adding word to set
			gameHistory.add(word);

			//For-loop that iterates from turn 2 to the last turn in the game (inclusive) 
			for(int turn = 2; turn <= numberOfInputs; turn++) {
				//Stores the most recent word used
				previousWord = word;

				//Stores the next word used
				word = input.readLine();

				/*Checks if the word is already in the set. If it's not, then it is added; Otherwise, it checks which player lost
				  If it is an even turn number, then player two lost; otherwise player one lost. It then exits the program.
				*/
				if(!gameHistory.add(word)) {
					System.out.println(turn % 2 == 0 ? "Player 2 lost" : "Player 1 lost");
					return;
				}

				/*Checks if the the first letter of word is equal to the last letter of the previous word; If they are not equal, then it checks which player lost
				  If it is an even turn number, then player two lost; otherwise player one lost. It then exits the program.
				*/
				if(!word.substring(0, 1).equals(previousWord.substring(previousWord.length() - 1))) {
					System.out.println(turn % 2 == 0 ? "Player 2 lost" : "Player 1 lost");
					return;
				}
			}
		}catch(Exception e) {
			//If there is an error while executing, it outputs it to the terminal and exits
			e.printStackTrace();
		}

		//CLosing input stream
		input.close();

		//If it does not find any rule violations, then it outputs the following phrase
		System.out.println("Fair Game");
	}
}
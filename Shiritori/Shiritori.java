import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Shiritori {
	public static void main(String[] args) {
		//Scanner input = new Scanner(System.in);
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in)); 
		ArrayList<String> gameHistory = new ArrayList<String>();

		try {
			int numberOfInputs = Integer.parseInt(input.readLine());
			gameHistory.add(input.readLine());

			for(int turn = 2; turn <= numberOfInputs; turn++) {
				String word = input.readLine();
				String previousWord = gameHistory.get(turn - 2);

				if(gameHistory.contains(word)) {
					System.out.println(turn % 2 == 0 ? "Player 2 lost" : "Player 1 lost");
					return;
				}

				if(!word.substring(0, 1).equals(previousWord.substring(previousWord.length() - 1))) {
					System.out.println(turn % 2 == 0 ? "Player 2 lost" : "Player 1 lost");
					return;
				}

				gameHistory.add(word);
			}
		}catch(Exception e) {
			e.printStackTrace();
		}

		System.out.println("Fair Game");
	}
}
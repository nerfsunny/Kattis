import java.util.*;
import java.lang.*;
import java.io.*;

public class piglatin {
	public static void main(String[] args) {
		//Initializing IO Stream
		BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));

		//Initializing variable. Used to store translated string
		StringBuilder pigLatin = new StringBuilder();

		//Initializing collection. Stores variables
		TreeSet<Character> vowels = new TreeSet<Character>();

		//Storing vowels
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');
		vowels.add('y');

		//Initializing variable. Used to store input line
		String line;

		//Try-catch required for using BufferedReader
		try {
			//While-loop that continues reading lines from input until there are no more lines left
			while((line = scan.readLine()) != null) {
				//For-loop that iterates through each word in line
				for(String word : line.split(" ")) {
					//Checks if the first character in word is a vowel. If it is, then it appends it and required suffix to pigLatin
					if(vowels.contains(word.charAt(0))) 
						pigLatin.append(word + "yay ");
					else {
						//Initializing varibale. Used to store the index of the first instance of a vowel in word
						int index = 0;

						//For-loop that iterates through word until it finds a first instance of a vowel. Once it finds it, it stores it index and breaks the loop
						for(int i = 0; i < word.length(); i++) 
							if(vowels.contains(word.charAt(i))) {
								index = i;
								break;
							}

						//Appends subsections of word and the required suffix to pigLatin
						pigLatin.append(word.substring(index) + word.substring(0, index) + "ay ");
					}
				}

				//Trimming pigLatin of white space and outputs it
				System.out.println(pigLatin.substring(0, pigLatin.length() - 1));

				//Clearing pigLatin
				pigLatin.setLength(0);
			}

			//Closing stream
			scan.close();			
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
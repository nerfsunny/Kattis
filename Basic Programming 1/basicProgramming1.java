import java.util.*;
import java.lang.*;
import java.math.BigInteger;

public class basicProgramming1 {
	/*Takes Scanner object as input. Scanner is used to read the input of the first two numbers
	  Checks whether the first number is greater than, less than or equal to the second number
	*/
	public static String case2(Scanner input) {
		//Initializing variables. Storing the first two inputs
		int num1 = input.nextInt(), num2 = input.nextInt();

		//If-else statement block that checks if num1 is either greater than, less than or equal to num2. Returns phrase accordingly
		if(num1 > num2)
			return "Bigger";
		else if(num1 < num2)
			return "Smaller";
		else
			return "Equal";
	}

	/*Takes Scanner object as input. Scanner is used to read the input of the first three numbers
	  Returns the median number between the three numbers
	*/
	public static int case3(Scanner input) {
		//Initializing variable. Allocating size of contianer to known number of inputs
		ArrayList<Integer> list = new ArrayList<Integer>(3);

		//For-loop that stores the first three inputs into the ArrayList
		for(int i = 0; i < 3; i++) 
			list.add(input.nextInt());

		//Sorts the ArrayList in ascending order
		Collections.sort(list);

		//Returns the number found at index 1 of the ArrayList
		return list.get(1);
	}

	/*Takes Scanner object and int. Scanner is used to read input and arraySize is the number of inputs
      Iterates through all of the inputs and returns the sum of all numbers
	*/
	public static BigInteger case4(Scanner input, int arraySize) {
		//Initializing variables. sum is used to hold the total sum of all numbers
		BigInteger sum = BigInteger.ZERO;

		//For-loop that iterates through all of the inputs
		for(int i = 0; i < arraySize; i++)
			//Adds input to sum
			sum = sum.add(BigInteger.valueOf(input.nextInt()));

		//Returning sum
		return sum;
	}

	/*Takes Scanner object and int. Scanner is used to read input and arraySize is the number of inputs
      Iterates through all of the inputs and returns the sum of all even numbers
	*/
	public static BigInteger case5(Scanner input, int arraySize) {
		//Initializing variables. sum is used to hold the total sum of all even numbers, num is used to store the input
		BigInteger sum = BigInteger.ZERO;
		int num;

		//For-loop that iterates through all of the inputs
		for(int i = 0; i < arraySize; i++) {
			//Stores input
			num = input.nextInt();

			//Checks if num is an even number
			if(num % 2 == 0)
				//Adds num to sum
				sum = sum.add(BigInteger.valueOf(num));
		}

		//Returning sum
		return sum;
	}

	/*Takes Scanner object and int. Scanner is used to read input and arraySize is the number of inputs
	  Iterates through all of the inputs, converts the number into its char equivalent (range being a-z lowercase) and appends it to a String
	  Returns final constructed String
	*/
	public static void case6(Scanner input, int arraySize) {
		//Initializing variables. result is StringBuilder object that has size allocated for arraySize, num is used to store the input, and letter stores the ASCII number of its char equivalent
		StringBuilder result = new StringBuilder(arraySize);
		int num, letter;

		//For-loop that iterates through all of the inputs
		for(int i = 0; i < arraySize; i++) {
			//Stores input
			num = input.nextInt();

			//Caluclates the modulo of num and 26, then adds it to 97. This num represents the ASCII number of a character
			letter = 97 + (num % 26);

			//Casts letter to char and appends it to result
			result.append((char) letter);
		}

		//Outputs fully constructed string
		System.out.println(result);
	}

	/*Takes Scanner object and int. Scanner is used to read input and arraySize is the number of inputs
	  Uses values stored in container to jump to different indexes in the container. While looping, it checks if it falls in 1 of 3 conditions:
	  	1. If the index is at the last index of the container, it returns Done.
	  	2. if the loop seems that it will go on forever, it returns Cyclic
	  	3. If the index is a value greater than the size of the container, it returns Out
	*/
	public static String case7(Scanner input, int arraySize) {
		//Initializing variable. Allocates size of array to arraySize
		int[] numArray = new int[arraySize];

		//For-loop that populates numArray
		for(int i = 0; i < arraySize; i++)
			numArray[i] = input.nextInt();

		//Storing the starting point of the loop
		int arrayIndex = numArray[0];

		//Initializing HashSet. Used to determine if the loop will enter a cycle or not
		HashSet<Integer> numSet = new HashSet<Integer>();

		//Adding arrayIndex of numSet
		numSet.add(arrayIndex);

		//While-loop that continues while the arrayIndex is less than numArray.length
		while(arrayIndex < numArray.length) {
			//Checks if the arrayIndex is equal to the last index of numArray. If it is, then it returns Done
			if(arrayIndex == numArray.length - 1) 
				return "Done";

			//Stores new arrayIndex value as the value stored at the index (old) arrayIndex
			arrayIndex = numArray[arrayIndex];

			//Adds arrayIndex into numSet. If the number is already present in numSet, then it returns Cyclic
			if(!numSet.add(arrayIndex)) 
				return "Cyclic";
		}

		//Returns Out if it exits the loop
		return "Out";
	}

	public static void main(String[] args) {
		//Initializing Scanner
		Scanner input = new Scanner(System.in);

		//Stores the first two numbers in the first line of the input. arraySize stores the number of inputs on the second line, state stores what method to call
		int arraySize = input.nextInt(), state = input.nextInt();

		//Moves cursor to the next line
		input.nextLine();

		//Switch-statement that calls the method the matches state
		switch(state) {
			case 1:
				System.out.println("7");
				break;
			case 2:
				System.out.println(case2(input));
				break;
			case 3:
				System.out.println(case3(input));
				break;
			case 4:
				System.out.println(case4(input, arraySize));
				break;
			case 5:
				System.out.println(case5(input, arraySize));
				break;
			case 6:
				case6(input, arraySize);
				break;
			case 7:
				System.out.println(case7(input, arraySize));
				break;
			default:
				return;
		};

		//Closing Scanner
		input.close();
	}
}
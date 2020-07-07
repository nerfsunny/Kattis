import java.util.*;
import java.lang.*;

public class basicProgramming2 {
	/* Takes Scanner object as input and size to allocate HashSet container. Populates HashSet with numbers from second line in the input
	   Iterates through all numbers in HashSet, calculates the difference between number x and 7777
	   If the HashSet contains the result of that difference, then it returns "Yes"
	   If no value in the HashSet has a completment value such that their sum is 7777, it returns "No"
	*/
	public static String case1(Scanner scan, int size) {
		//Initializing HashSet and allocating for size
		HashSet<Integer> hashNumbers = new HashSet<Integer>(size);

		//Populating HashSet
		while(scan.hasNextInt())
			hashNumbers.add(scan.nextInt());

		//Iterating through all numbers in HashSet
		for(Integer x : hashNumbers) {
			//Calculating compliment value of x
			Integer y = 7777 - x;

			//Checking if the complement value is in the HashSet; Returns true if found and outputs "Yes"
			if(x != y && hashNumbers.contains(y)) 
				return "Yes";
		}

		//Returns "No" if it can't find any pair that sums to 7777
		return "No";
	}

	/* Takes Scanner object as input and size to allocate HashSet container. Populates HashSet with numbers from second line in the input
	   While populating the HashSet, if inserts a value that already exists in the HashSet, it returns "Contains Duplicate"
	   If all of the inputs are unique, it returns "Unique" 
	*/
	public static String case2(Scanner scan, int size) {
		//Initializing HashSet and allocating for size
		HashSet<Integer> hashNumbers = new HashSet<Integer>(size);

		//Populating HashSet
		while(scan.hasNextInt()) 
			//If scan.nextInt() is a value that already exists in HashSet, it returns true and outputs "Contains duplicate"
			if(!hashNumbers.add(scan.nextInt())) 
				return "Contains duplicate";

		//If all numbers inserted in the HashSet are unique, it returns "Unique"
		return "Unique";
	}

	/* Takes Scanner object as input and size for number of elements in the input. Populates TreeMap with numbers from the second line in the input
	   TreeMap stores the number of instances a certain number appears in the input (with the number as key and number of instances as value)
	   If the number of instances of a certain number is strictly greater than half of the input size and has the most instances compared to other numbers, that value is outputted
	   Otherwise, it outputs -1 
	*/
	public static void case3(Scanner scan, int size) {
		//Initializing TreeMap
		TreeMap<Integer, Integer> table = new TreeMap<Integer, Integer>();

		//While-loop that populates TreeMap
		while(scan.hasNextInt()) {
			//Storing input
			int key = scan.nextInt();

			//If-statement that checks if it already contains key. If it does, it increments the value at key; otherwise, it adds a new key with value 1
			if(table.containsKey(key)) {
				//Storing value of key in temp variable and incrementing by 1
				int value = table.get(key).intValue() + 1;

				//Updating key with new value
				table.put(key, value);
			}else
				//Storing new key with value 1
				table.put(key, 1);
		}

		/*Initializing variables. resultKey has an initial value of -1 in the event that there is no key that has more instances > size/2
		  compareValue stores the value of size/2
		*/
		int resultKey = -1, compareValue = size/2;

		//For-loop that iterates through all entries in table
		for(Map.Entry<Integer, Integer> map : table.entrySet())
			//If-statement that checks if value of key is strictly greater than compareValue. If it is, it stores the key in resultKey
			if(map.getValue() > compareValue)
				resultKey = map.getKey();

		//Outputs value of resultKey
		System.out.println(resultKey);
	}

	/* Takes Scanner object as input and size to allocate ArrayList container. Populates ArrayList with numbers from the second line in the input
	   Once it populates the ArrayList, it is sorted in ascending order
	   If the ArrayList size/2 is odd, it outputs the median value at size/2
	   If the ArrayList size/2 is even, it outputs the median values at (size/2 - 1) and (size/2)
	*/
	public static void case4(Scanner scan, int size) {
		//Initializing ArrayList and allocating for size
		ArrayList<Integer> numArray = new ArrayList<Integer>(size);

		//While-loop that populates ArrayList
		while(scan.hasNextInt())
			numArray.add(scan.nextInt());

		//Sorts ArrayList in ascending order
		Collections.sort(numArray);

		//If size % 2 is 0, it executes the else statement. If size % 2 is 1, it executes the first statement
		if(size % 2 == 1)
			System.out.println(numArray.get(size/2));
		else
			System.out.println(numArray.get(size/2 - 1) + " " + numArray.get(size/2));
	}

	/* Takes Scanner object as input. Populates TreeMap with numbers from second line in the input
	   If the number is in the range [100, 999] inclusive, it is stored in the TreeMap with a count of 1
	   If there are more than one instance of the number and it already exists in TreeMap, it increments the count by 1
	   Once it has taken all of the inputs, it builds the string (in ascending order) to output the result
	*/
	public static void case5(Scanner scan) {
		//Initializing TreeMap
		TreeMap<Integer, Integer> treeNumbers = new TreeMap<Integer, Integer>();

		//While-loop that goes through all of the inputs
		while(scan.hasNextInt()) {
			//Storing input in temp variable
			int num = scan.nextInt();

			//Checks if num is in the range of [100, 999]
			if(num >= 100 && num <= 999) {
				//Checks if treeNumbers already contains num as a key
				if(treeNumbers.containsKey(num)) {
					//Stores value of key num in temp variable and incremenets by 1
					int count = treeNumbers.get(num) + 1;

					//Overrides value of key num with count
					treeNumbers.put(num, count);
				}else
					//Stores key num and value 1
					treeNumbers.put(num, 1);
			}
		}

		//Initializing StringBuilder object
		StringBuilder output = new StringBuilder();

		//For-loop that iterates through all entries in treeNumbers
		for(Map.Entry<Integer, Integer> map : treeNumbers.entrySet()) {
			//Checks if there was more than one instance of num (if the value of key num is greater than 1)
			if(map.getValue() > 1)
				//For-loop that appends key num to output i times
				for(int i = 0; i < map.getValue(); i++)
					output.append(map.getKey() + " ");
			else
				//Appends key num to output
				output.append(map.getKey() + " ");
		}

		//Trims all trailing whitespace in string
		output.setLength(output.length() - 1);

		//Outputs String
		System.out.println(output);
	}

	public static void main(String[] args) {
		//Initializing IO 
		Scanner scan = new Scanner(System.in);

		//Initializing variables; size is the number of numbers on the second line, state stores which method to call
		int size = scan.nextInt(), state = scan.nextInt();

		//Moves cursor to the next line
		scan.nextLine();

		//Switch-statement that calls a certain method based on the state number; In the unlikelihood that a number is given and it is defined as a case, it exits the program
		switch(state) {
			case 1:
				System.out.println(case1(scan, size));
				break;
			case 2:
				System.out.println(case2(scan, size));
				break;
			case 3:
				case3(scan, size);
				break;
			case 4:
				case4(scan, size);
				break;
			case 5:
				case5(scan);
				break;
			default:
				return;
		};

		//Closing input
		scan.close();
	}
}
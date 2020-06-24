import java.util.*;
import java.lang.*;

public class basicProgramming1 {
	public static String case2(Scanner input) {
		int num1 = input.nextInt(), num2 = input.nextInt();

		if(num1 > num2)
			return "Bigger";
		else if(num1 < num2)
			return "Smaller";
		else
			return "Equal";
	}

	public static int case3(Scanner input) {
		int num1 = input.nextInt(), num2 = input.nextInt(), num3 = input.nextInt();

		if(num1 >= num2 && num1 <= num3)
			return num1;
		else if(num2 >= num1 && num2 <= num3)
			return num2;
		else
			return num3;
	}

	public static int case4(Scanner input) {
		int sum = 0;

		while(input.hasNextInt())
			sum += input.nextInt();

		return sum;
	}

	public static int case5(Scanner input, int arraySize) {
		int sum = 0;

		for(int i = 0; i < arraySize; i++) {
			int num = input.nextInt();

			if(num % 2 == 0)
				sum += num;
		}

		return sum;
	}

	public static String case6(Scanner input, int arraySize) {
		String result = "";

		for(int i = 0; i < arraySize; i++) {
			int num = input.nextInt();
			int letter = 97 + (num % 26);
			result += (char) letter;
		}

		return result;
	}

	public static void case7(Scanner input, int arraySize) {
		int[] numArray = new int[arraySize];

		for(int i = 0; i < arraySize; i++)
			numArray[i] = input.nextInt();

		int arrayIndex = numArray[0];
		HashSet<Integer> numSet = new HashSet<Integer>();
		numSet.add(arrayIndex);

		while(arrayIndex < numArray.length) {
			if(arrayIndex == numArray.length - 1) {
				System.out.println("Done");
				break;
			}

			arrayIndex = numArray[arrayIndex];

			if(!numSet.add(arrayIndex)) {
				System.out.println("Cyclic");
				break;
			}
		}

		if(arrayIndex >= numArray.length)
			System.out.println("Out");
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int arraySize = input.nextInt();
		int state = input.nextInt();

		input.nextLine();

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
				System.out.println(case4(input));
				break;
			case 5:
				System.out.println(case5(input, arraySize));
				break;
			case 6:
				System.out.println(case6(input, arraySize));
				break;
			case 7:
				case7(input, arraySize);
				break;
			default:
				return;
		};

		input.close();
	}
}
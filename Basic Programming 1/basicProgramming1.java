import java.util.*;
import java.lang.*;

public class basicProgramming1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int arraySize = input.nextInt();
		int state = input.nextInt();

		input.nextLine();

		int numArray[] = new int[arraySize];

		for(int index = 0; index < arraySize; index++)
			numArray[index] = input.nextInt();

		switch(state) {
			case 1:
				System.out.println("7");
				break;
			case 2:
				if(numArray[0] > numArray[1])
					System.out.println("Bigger");
				else if (numArray[0] == numArray[1])
					System.out.println("Equal");
				else
					System.out.println("Smaller");
				break;
			case 3:
				if(numArray[0] > numArray[1] && numArray[0] < numArray[2])
					System.out.println(numArray[0]);
				else if(numArray[1] > numArray[0] && numArray[1] < numArray[2])
					System.out.println(numArray[1]);
				else
					System.out.println(numArray[2]);
				break;
			case 4:
				int sum = 0;

				for(int i : numArray)
					sum += i;

				System.out.println(sum);
				break;
			case 5:
				int evenSum = 0;

				for(int i : numArray)
					if(i % 2 == 0)
						evenSum += i;

				System.out.println(evenSum);
				break;
			case 6:
				String result = "";

				for(int i : numArray) {
					int letter = 97 + (i % 26);
					result += (char) letter;
				}

				System.out.println(result);
				break;
			case 7:
				int arrayIndex = numArray[0];
				HashSet<Integer> numSet = new HashSet<Integer>();
				numSet.add(new Integer(arrayIndex));

				while(arrayIndex < numArray.length) {
					if(arrayIndex == numArray.length - 1) {
						System.out.println("Done");
						break;
					}

					arrayIndex = numArray[arrayIndex];

					if(!numSet.add(new Integer(arrayIndex))) {
						System.out.println("Cyclic");
						break;
					}
				}

				if(arrayIndex >= numArray.length)
					System.out.println("Out");

				break;
			default:
				return;
		};
	}
}
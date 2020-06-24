import java.util.*;
import java.lang.*;

public class basicProgramming2 {
	public static String case1(Scanner scan) {
		HashSet<Integer> hashNumbers = new HashSet<Integer>();

		while(scan.hasNextInt())
			hashNumbers.add(scan.nextInt());

		for(Integer x : hashNumbers) {
			Integer y = 7777 - x;

			if(x != y && hashNumbers.contains(y)) 
				return "Yes";
		}

		return "No";
	}

	public static String case2(Scanner scan) {
		HashSet<Integer> hashNumbers = new HashSet<Integer>();

		while(scan.hasNextInt()) 
			if(!hashNumbers.add(scan.nextInt())) 
				return "Contains duplicate";

		return "Unique";
	}

	public static void case3(Scanner scan, int arraySize) {
		HashMap<Integer, Integer> table = new HashMap<Integer, Integer>();

		while(scan.hasNextInt()) {
			int key = scan.nextInt();

			if(table.containsKey(key)) {
				int value = table.get(key).intValue();
				table.put(key, value + 1);
			}else
				table.put(key, 1);
		}

		int resultKey = -1, compareValue = arraySize/2;

		for(Map.Entry<Integer, Integer> map : table.entrySet())
			if(map.getValue() > compareValue && map.getKey() > resultKey)
				resultKey = map.getKey();

		System.out.println(resultKey);
	}

	public static void case4(Scanner scan, int arraySize) {
		ArrayList<Integer> numArray = new ArrayList<Integer>(arraySize);

		while(scan.hasNextInt())
			numArray.add(scan.nextInt());

		Collections.sort(numArray);

		if(arraySize % 2 == 1)
			System.out.println(numArray.get(arraySize/2));
		else
			System.out.println(numArray.get(arraySize/2 - 1) + " " + numArray.get(arraySize/2));
	}

	public static void case5(Scanner scan) {
		TreeSet<Integer> treeNumbers = new TreeSet<Integer>();

		while(scan.hasNextInt()) {
			int num = scan.nextInt();

			if(num >= 100 && num <= 999)
				treeNumbers.add(num);
		}

		scan.close();

		String output = "";
		for(Integer x : treeNumbers)
			output += x + " ";

		System.out.println(output.trim());
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int arraySize = scan.nextInt();
		int state = scan.nextInt();

		//Moves cursor to the next line
		scan.nextLine();

		switch(state) {
			case 1:
				System.out.println(case1(scan));
				break;
			case 2:
				System.out.println(case2(scan));
				break;
			case 3:
				case3(scan, arraySize);
				break;
			case 4:
				case4(scan, arraySize);
				break;
			case 5:
				case5(scan);
				break;
			default:
				return;
		};

		scan.close();
	}
}
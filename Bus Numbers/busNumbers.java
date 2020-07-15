import java.lang.*;
import java.util.*;

public class busNumbers {
	public static void main(String[] args) {
		//Initializing variables. scan is used to read inputs, numberOfInputs is the the amount of numbers to store in busNumbers
		Scanner scan = new Scanner(System.in);
		int numberOfInputs = scan.nextInt();

		//Initializing ArrayLists. busNumbers store the inputs, interval is used to store a subset of numbers increase by 1
		ArrayList<Integer> busNumbers = new ArrayList<Integer>(numberOfInputs);
		ArrayList<Integer> interval = new ArrayList<Integer>();

		//Storing numbers in busNumbers
		while(scan.hasNextInt())
			busNumbers.add(scan.nextInt());

		//Sorting busNumbers in ascending order
		Collections.sort(busNumbers);

		//Closing Scanner
		scan.close();

		//Initializing StringBuilder
		StringBuilder output = new StringBuilder();

		//Storing the first number interval
		interval.add(busNumbers.get(0));

		//For-loop that iterates through busNumbers from index [1, size of busNumbers]
		for(int i = 1; i <= busNumbers.size(); i++) {
			//Special case for when the loop reaches the index after last in busNumbers. This gets the last number(s) from the loop and appends it to output
			if(i == busNumbers.size()) {
				/*If-else statement block:
					1. If the last number in busNumber did not fit in an interval that came before it, then it is appended to output
					2. If the last two numbers in busNumber have a difference of 1 and did not fit in an interval that came before it, then they are both appended to output
					3. If the last set of numbers in busNumbers form an interval, then the interval is appeneded to output
				*/
				if(interval.size() == 1) 
					output.append(interval.get(0).intValue() + " ");
				else if(interval.size() == 2) {
					output.append(interval.get(0).intValue() + " " + interval.get(1).intValue() + " ");
					interval.clear();
				}else {
					output.append(interval.get(0).intValue() + "-" + interval.get(interval.size() - 1) + " ");
					interval.clear();
				}
			}else {
					//If the difference between the number at index and the last number in interval, then the number is added to interval and the loop goes to the next number
					if((busNumbers.get(i) - interval.get(interval.size() - 1)) == 1) {
					interval.add(busNumbers.get(i));
					continue;
					}

					/*If-else statement blocks that executes when the number at i does not fit with the numbers in interval:
						1. If the number at index + 1 is not +1 of the number at index, then the number at index is appended to output and index + 1 is stored in interval[0]
						2. If the number at index + 1 is not +1 of the two previous numbers, the the two numbers are separately appended to output, interval is cleared and index + 1 is stored in interval[0]
						3. If the number at index + 1 does not fit in the numbers in interval, then the first and last number of interval is appended to output, interval is cleared and index + 1 is stored in interval[0]
					*/
					if(interval.size() == 1) {
						output.append(interval.get(0).intValue() + " ");
						interval.set(0, busNumbers.get(i));
					}else if(interval.size() == 2) {
						output.append(interval.get(0).intValue() + " " + interval.get(1).intValue() + " ");
						interval.clear();
						interval.add(busNumbers.get(i));
					}else {
						output.append(interval.get(0).intValue() + "-" + interval.get(interval.size() - 1) + " ");
						interval.clear();
						interval.add(busNumbers.get(i));
					}
			}
		}

		//Removing trailing whitespace
		output.setLength(output.length() - 1);

		//Outputting result
		System.out.println(output);
	}
}
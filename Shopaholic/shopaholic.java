import java.util.*;
import java.lang.*;

public class shopaholic {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numberOfInputs = scan.nextInt();

		ArrayList<Integer> prices = new ArrayList<Integer>(numberOfInputs);

		for(int i = 0; i < numberOfInputs; i++)
			prices.add(scan.nextInt());

		scan.close();
		Collections.sort(prices);

		Integer sum = 0;

		if(prices.size() % 3 == 0) {
			for(int i = 0; i < prices.size(); i += 3)
				sum += prices.get(i);
		}else {
			int difference = prices.size() % 3;

			for(int i = 0; i < prices.size() - difference; i += 3)
				sum += prices.get(i);
		}

		System.out.println(sum);
	}
}
import java.lang.*;
import java.util.*;
import java.math.*;

public class catalan {
	public static BigInteger calculateFactorial(int number) {
		BigInteger value = BigInteger.ONE;

		for(int i = 2; i <= number; i++)
			value = value.multiply(BigInteger.valueOf(i));

		return value;
	}

	public static BigInteger calculateCatalanNumber(int number) {
		BigInteger denominator = calculateFactorial(number).multiply(calculateFactorial(number + 1));
		BigInteger numerator = calculateFactorial(number * 2);

		return numerator.divide(denominator);
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int number, numberOfInputs = scan.nextInt();
		HashMap<Integer, BigInteger> factorials = new HashMap<Integer, BigInteger>();
		BigInteger factorialNumber;

		while(scan.hasNextInt()) {
			number = scan.nextInt();
			factorialNumber = calculateCatalanNumber(number);
			factorials.put(number, factorialNumber);

			System.out.println(factorialNumber);
		}
	}
}
import java.util.*;
import java.math.*;

public class smallestmultiple {
    //Recursive method that returns the gcd of two numbers
    public static BigInteger gcd(BigInteger num1, BigInteger num2) {
        //If both objects are the same value, it returns num1
        if(num1.equals(num2))
            return num1;

        //If num2 is equal to zero, it returns num1
        if(num2.equals(BigInteger.ZERO))
            return num1;

        //Passes num2 and the modulo of num1 and num2 back into gcd
        return gcd(num2, num1.mod(num2));
    }

    //Method that returns the lcm of two numbers
    public static BigInteger lcm(BigInteger num1, BigInteger num2) {
        //Formula that calculates the lcm of two numbers. First multiply num1 and num2. Then, divide this value by the gcd of num1 and num2
        return num1.multiply(num2).divide(gcd(num2, num1));
    }
    public static void main(String[] args) {
        //Initializing IO Object
        Scanner scan = new Scanner(System.in);

        //Initializing Object to store input
        String line;

        //Initializing container
        ArrayList<BigInteger> nums = new ArrayList<BigInteger>();

        //While-loop that iterates through all lines in the input
        while(scan.hasNextLine()) {
            //Stores line
            line = scan.nextLine();

            //Splits line into String[] array and iterates through all elements
            for(String x : line.split(" "))
                //Constructs BigInteger object and stores it in nums
                nums.add(new BigInteger(x));

            //Sorts nums from least to greatest
            Collections.sort(nums);

            //Stores the first element in nums as lcmNum, initializes num2
            BigInteger lcmNum = nums.get(0), num2;
            
            //For-loop that iterates through all elements indexed from 1 to nums size - 1
            for(int i = 1; i < nums.size(); i++) {
                //Stores BigInteger found at index i
                num2 = nums.get(i);

                //Stores the lcm of lcmNum and num2
                lcmNum = lcm(lcmNum, num2);
            }

            //Prints out the lcm
            System.out.println(lcmNum);

            //Clearing ArrayList
            nums.clear();
        }

        //Closing scanner
        scan.close();
    }
}
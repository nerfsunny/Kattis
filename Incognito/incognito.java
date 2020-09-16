import java.lang.*;
import java.util.*;

public class incognito {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int numberOfTestCases = scan.nextInt();
        HashMap<String, ArrayList<String>> attributes = new HashMap<String, ArrayList<String>>();

        for(int i = 0; i < numberOfTestCases; i++) {
            int numberOfAttributes = scan.nextInt();

            for(int j = 0; j < numberOfAttributes; j++) {
                String attribute = scan.next(), type = scan.next();

                if(attributes.containsKey(type))
                    attributes.get(type).add(attribute);
                else {
                    attributes.put(type, new ArrayList<String>());
                    attributes.get(type).add(attribute);
                }
            }

            int totalCombination = 0;

            for(ArrayList<String> x : attributes.values())
                totalCombination += x.size();

            if(attributes.keySet().size() != 1) {
                System.out.println("Hello");
            }else
                System.out.println(totalCombination);
            
            attributes.clear();
        }

        scan.close();
    }
}
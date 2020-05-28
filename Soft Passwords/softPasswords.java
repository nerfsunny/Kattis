import java.util.*;
import java.lang.*;

public class softPasswords {
	public static boolean identicalStrings(String password1, String password2) {
		return password1.equals(password2);
	}

	public static boolean appendNumberString(String password1, String password2) {
		if(identicalStrings(password1, password2.substring(1))) {
			for(int number = 0; number < 10; number++) {
				if(password2.substring(0, 1).equals(Integer.toString(number)))
					return true;
			}
		}

		if(identicalStrings(password1, password2.substring(0, password2.length() - 1))) {
			for(int number = 0; number < 10; number++) {
				if(password2.substring(password2.length() - 1).equals(Integer.toString(number)))
					return true;
			}
		}

		return false;
	}

	public static boolean reverseCaseString(String password1, String password2) {
		if(!password1.equalsIgnoreCase(password2))
			return false;

		int[] numberAscii = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

		for(int index = 0; index < password1.length(); index++) {
			char c1 = password1.charAt(index), c2 = password2.charAt(index);
			int ascii1 = (int) c1, ascii2 = (int) c2;

			if(ascii1 == ascii2) {
				if(Arrays.asList(numberAscii).contains(ascii1))
					continue;
				else
					return false;
			}

		}

		return true;
	}

	public static boolean checkConditions(String password1, String password2) {
		return identicalStrings(password1, password2) || appendNumberString(password1, password2) || reverseCaseString(password1, password2);
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		String password1 = input.nextLine();
		String password2 = input.nextLine();

		input.close();

		//System.out.println(password1 + " " + password2);
		if(checkConditions(password1, password2))
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
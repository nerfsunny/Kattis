import java.util.*;
import java.lang.*;
import java.io.*;

public class aPlusB {
	public static int numberOfInstances(int[] array, int value) {
		int count = 0;

		for(int i : array)
			if(i == value)
				count++;

		return count;
	}

	public static boolean containsValue(ArrayList<tripleIndices> list, tripleIndices triplet) {
		for(tripleIndices trip : list)
			if(trip.equals(triplet))
				return true;

		return false;
	}

	public static void main(String[] args) {
		int[] valueSet = null;
		String[] tempValueSet = null;
		int inputSize = 0;
		ArrayList<tripleIndices> list = new ArrayList<tripleIndices>();
		tripleIndices triplet;

		try{
			File inputFile = new File(args[0]);
			Scanner read = new Scanner(inputFile);

			inputSize = Integer.parseInt(read.nextLine());
			tempValueSet = read.nextLine().split(" ");

			read.close();			
		}catch(FileNotFoundException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}

		valueSet = new int[inputSize];

		for(int i = 0; i < inputSize; i++)
			valueSet[i] = Integer.parseInt(tempValueSet[i]);

		boolean condition = false;

		for(int i : valueSet) {
			for(int j : valueSet) {
				condition = false;
				int k = i + j;

				for(int x : valueSet)
					if(x == k)
						condition = true;

				if( condition ) {
					if(i == j && !(numberOfInstances(valueSet, j) > 1)) 
						continue;

					triplet = new tripleIndices(i, j, k);

					if(!containsValue(list, triplet)) 
						list.add(triplet);
				}
			}
		}

		System.out.println(list.size());
	}
}

class tripleIndices {
	private int i, j, k;

	//Empty constructor
	public tripleIndices() {

	}

	public tripleIndices(int i, int j, int k) {
		this.i = i;
		this.j = j;
		this.k = k;
	}

	public int getI() {
		return i;
	}

	public int getJ() {
		return j;
	}

	public int getK() {
		return k;
	}

	@Override
	public boolean equals(Object obj) {
		if(obj == null)
			return false;

		if(!(obj instanceof tripleIndices))
			return false;

		tripleIndices trip = (tripleIndices) obj;

		return this.i == trip.getI() && this.j == trip.getJ() && this.k == trip.getK();
	}

	@Override
	public String toString() {
		return Integer.toString(i) + " " + Integer.toString(j) + " " + Integer.toString(k);
	}
}
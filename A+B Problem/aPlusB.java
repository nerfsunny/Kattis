import java.util.*;
import java.lang.*;
import java.io.*;

public class aPlusB {
	/*
	Checks the array to determine how many instances it has of the passed value. After traversing the array, it returns the count. 
	If the array does not contain any instance of the value, then it returns 0.
	*/
	public static int numberOfInstances(long[] array, long value) {
		int count = 0;

		for(long i : array)
			if(i == value)
				count++;

		return count;
	}

	/*
	Checks the ArrayList to determine if it already contains a copy of a tripleIndices object. It uses the object's equals method to determine they are equal or not. 
	If the ArrayList already contains a copy of the object, then it returns true. Otherwise, it returns false.
	*/
	public static boolean containsValue(ArrayList<tripleIndices> list, tripleIndices triplet) {
		for(tripleIndices trip : list)
			if(trip.equals(triplet))
				return true;

		return false;
	}

	public static void main(String[] args) {
		long[] valueSet = null;
		int inputSize = 0;
		ArrayList<tripleIndices> list = new ArrayList<tripleIndices>();
		tripleIndices triplet;

		Scanner read = new Scanner(System.in);

		inputSize = read.nextInt();

		valueSet = new long[inputSize];
		int index = 0;

		while(read.hasNextLong() && index < inputSize) {
			valueSet[index] = read.nextLong();
			index++;
		}

		read.close();

		boolean condition = false;

		for(long i : valueSet) {
			for(long j : valueSet) {
				condition = false;
				long k = i + j;

				for(long x : valueSet)
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
	private long i, j, k;

	//Empty constructor
	public tripleIndices() {

	}

	public tripleIndices(long i, long j, long k) {
		this.i = i;
		this.j = j;
		this.k = k;
	}

	public long getI() {
		return i;
	}

	public long getJ() {
		return j;
	}

	public long getK() {
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
		return Long.toString(i) + " " + Long.toString(j) + " " + Long.toString(k);
	}
}
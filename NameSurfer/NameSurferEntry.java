
/*
 * File: NameSurferEntry.java
 * --------------------------
 * This class represents a single entry in the database.  Each
 * NameSurferEntry contains a name and a list giving the popularity
 * of that name for each decade stretching back to 1900.
 */

import acm.util.*;

import java.io.BufferedReader;
import java.util.*;

public class NameSurferEntry implements NameSurferConstants {

	// array to store 11 ranks for each entry object
	private int[] ranks = new int[11];
	// Stroes name
	private String name;

	/* Constructor: NameSurferEntry(line) */
	/**
	 * Creates a new NameSurferEntry from a data line as it appears in the data
	 * file. Each line begins with the name, which is followed by integers giving
	 * the rank of that name for each decade.
	 */
	public NameSurferEntry(String line) {
		// You fill this in //

		int firstSpaceIndex = line.indexOf(" ");

		name = line.substring(0, firstSpaceIndex);

		// String which contains ranks
		String ranksString = line.substring(firstSpaceIndex + 1);// TODO +1

		StringTokenizer tokenizer = new StringTokenizer(ranksString);

		for (int i = 0; i < NDECADES; i++) {
			String currentToken = tokenizer.nextToken();
			ranks[i] = Integer.parseInt(currentToken);
		}

	}

	/* Method: getName() */
	/**
	 * Returns the name associated with this entry.
	 */
	public String getName() {
		return name;
	}

	/* Method: getRank(decade) */
	/**
	 * Returns the rank associated with an entry for a particular decade. The decade
	 * value is an integer indicating how many decades have passed since the first
	 * year in the database, which is given by the constant START_DECADE. If a name
	 * does not appear in a decade, the rank value is 0.
	 */
	public int getRank(int decade) {
		return ranks[decade];
	}

	/* Method: toString() */
	/**
	 * Returns a string that makes it easy to see the value of a NameSurferEntry.
	 */
	public String toString() {
		String entryString = "";
		entryString = name + " [";
		for (int i = 0; i < NDECADES - 1; i++) {
			entryString = entryString + ranks[i] + " ";
		}
		// last decades rank
		entryString = entryString + ranks[NDECADES - 1];
		entryString = entryString + "]";

		return entryString;

	}
}

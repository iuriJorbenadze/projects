
/*
 * File: HangmanLexicon.java
 * -------------------------
 * This file contains a stub implementation of the HangmanLexicon
 * class that you will reimplement for Part III of the assignment.
 */

import java.io.BufferedReader;
import java.util.ArrayList;

import acm.util.*;
import acmx.export.java.io.FileReader;

public class HangmanLexicon {

	private ArrayList<String> secretWordsList = new ArrayList<String>();

	// This is the HangmanLexicon constructor
	public HangmanLexicon() {
		try {
			BufferedReader bufReader = new BufferedReader(new FileReader("HangmanLexicon.txt"));
			while (true) {
				String currentLine = bufReader.readLine();
				if (currentLine == null) {
					break;
				}
				secretWordsList.add(currentLine);

			}
			bufReader.close();

		} catch (Exception e) {
			throw new ErrorException(e);
		}

	}

	/** Returns the number of words in the lexicon. */
	public int getWordCount() {
		return secretWordsList.size();
	}

	/** Returns the word at the specified index. */
	public String getWord(int index) {

		return secretWordsList.get(index);

	};

}


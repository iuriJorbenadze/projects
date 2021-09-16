import java.io.BufferedReader;
import java.util.ArrayList;

import acm.util.ErrorException;
import acmx.export.java.io.FileReader;
import javafx.scene.input.TouchPoint;

/*
 * File: NameSurferDataBase.java
 * -----------------------------
 * This class keeps track of the complete database of names.
 * The constructor reads in the database from a file, and
 * the only public method makes it possible to look up a
 * name and get back the corresponding NameSurferEntry.
 * Names are matched independent of case, so that "Eric"
 * and "ERIC" are the same names.
 */

public class NameSurferDataBase implements NameSurferConstants {

	private ArrayList<String> dataBase = new ArrayList<String>();

	/* Constructor: NameSurferDataBase(filename) */
	/**
	 * Creates a new NameSurferDataBase and initializes it using the data in the
	 * specified file. The constructor throws an error exception if the requested
	 * file does not exist or if an error occurs as the file is being read.
	 */
	//bufReader reads file line by line and saves each line into the dataBase ArrayList
	public NameSurferDataBase(String filename) {
		try {
			BufferedReader bufReader = new BufferedReader(new FileReader(NAMES_DATA_FILE));
			while (true) {
				String currentLine = bufReader.readLine();
				if (currentLine == null) {
					break;
				}
				dataBase.add(currentLine);
			}
			bufReader.close();

		} catch (Exception e) {
			throw new ErrorException(e);
		}

	}

	/* Method: findEntry(name) */
	/**
	 * Returns the NameSurferEntry associated with this name, if one exists. If the
	 * name does not appear in the database, this method returns null.
	 */
	public NameSurferEntry findEntry(String name) {
		
		String upperCasedName =  name.toUpperCase();
		//we make any entered names first letter become upper cased
		//so it will get same results on "sam" and "Sam"
		name = upperCasedName.charAt(0) + name.substring(1);
		
		//looks for entered name in dataBase and returns entry object if is present
		for (int i = 0; i < dataBase.size(); i++) {

			String currentLine = dataBase.get(i);
			String nameFromDataBase = currentLine.substring(0, currentLine.indexOf(" "));

			if (nameFromDataBase.equals(name)) {
				NameSurferEntry entryObj = new NameSurferEntry(currentLine);
				return entryObj;
			}

		}
		//if entered name is not in dataBase returns null
		return null;
	}
}

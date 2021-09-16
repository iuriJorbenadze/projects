
/*
 * File: NameSurferGraph.java
 * ---------------------------
 * This class represents the canvas on which the graph of
 * names is drawn. This class is responsible for updating
 * (redrawing) the graphs whenever the list of entries changes or the window is resized.
 */

import acm.graphics.*;
import java.awt.event.*;
import java.util.*;
import java.awt.*;

public class NameSurferGraph_extension extends GCanvas implements NameSurferConstants, ComponentListener {

	private ArrayList<NameSurferEntry> entryObjects = new ArrayList<NameSurferEntry>();

	private static final Color DEFAULT_COLOR = Color.BLACK;
	private static final double sepBetweenLabelAndStartingCord = 1.5;


	
	/**
	 * Creates a new NameSurferGraph object that displays the data.
	 */
	public NameSurferGraph_extension() {
		addComponentListener(this);
		// You fill in the rest //

	}

	/**
	 * Clears the list of name surfer entries stored inside this class.
	 */
	public void clear() {
		entryObjects.clear();

		update();

	}

	/* Method: addEntry(entry) */
	/**
	 * Adds a new NameSurferEntry to the list of entries on the display. Note that
	 * this method does not actually draw the graph, but simply stores the entry;
	 * the graph is drawn by calling update.
	 */
	public void addEntry(NameSurferEntry entry) {

		if (!contains(entry)) {
			entryObjects.add(entry);

			System.out.println(entryObjects.toString());
			// System.out.println(entry);
			update();

		}
	}

	/**
	 * Updates the display image by deleting all the graphical objects from the
	 * canvas and then reassembling the display according to the list of entries.
	 * Your application must call update after calling either clear or addEntry;
	 * update is also called whenever the size of the canvas changes.
	 */
	public void update() {
		removeAll();
		addStructure();
		addEntriesFromList();

		
	}

	
	// adds background structure: grid and decades
	private void addStructure() {
		addVerticalLines();
		addHorizontalLines();
		addDecades();
	}

	// creates and adds line at given coordinates with certain color
	private void addLine(double x0, double y0, double x1, double y1, Color color) {
		GLine line = new GLine(x0, y0, x1, y1);
		line.setColor(color);
		add(line);
	}

	// creates 11 vertical lines each separated by same distance
	// which is calculated and given in marginBetweenLines
	private void addVerticalLines() {
		double marginBetweenLines = getWidth() / (double) NDECADES;

		for (int i = 0; i < NDECADES; i++) {
			addLine(marginBetweenLines * i, 0, marginBetweenLines * i, getHeight(), DEFAULT_COLOR);
		}

	}

	// adds two horizontal line one at the top and second at the bottom
	private void addHorizontalLines() {

		addLine(0, GRAPH_MARGIN_SIZE, getWidth(), GRAPH_MARGIN_SIZE, DEFAULT_COLOR);
		addLine(0, getHeight() - GRAPH_MARGIN_SIZE, getWidth(), getHeight() - GRAPH_MARGIN_SIZE, DEFAULT_COLOR);
	}

	// adds 11 GLabels with decades written in them
	private void addDecades() {

		double marginBetweenLines = getWidth() / (double) NDECADES;

		for (int i = 0; i < NDECADES; i++) {
			String decadeText = "" + (1900 + 10 * i);
			addLabel(decadeText, marginBetweenLines * i);
		}
	}

	// adds decade label with given text and x cord
	private void addLabel(String text, double x0) {

		GLabel label = new GLabel(text);
		double labelY = getHeight() - label.getDescent();
		add(label, x0 + 3, labelY);
	}

	// this method will add each entry, which is present
	// in entryObjects ArrayList, on the graph
	private void addEntriesFromList() {

		for (int i = 0; i < entryObjects.size(); i++) {
			Color color = defineCollor(i);

			addCurrentEntriesStatistic(entryObjects.get(i), color);

		}

	}

	// decades count from 0th to 10th total 11 decades

	// creates and adds 11 lines by given ranks and name and color
	private void addCurrentEntriesStatistic(NameSurferEntry nameSurferEntry, Color color) {

		double marginBetweenLines = getWidth() / (double) NDECADES;
		double linesHorisontalAxisSize = ((double) getHeight() - 2.0 * GRAPH_MARGIN_SIZE) / (double) MAX_RANK;

		String enrtyName = nameSurferEntry.getName();

		for (int i = 0; i < NDECADES - 1; i++) {
			// i will be current decades number
			// starts from 0th decade and ends with 10th decade

			int currentDecadesRank = nameSurferEntry.getRank(i);

			int nextDecadesRank = -1;
			double lineStaringYCord;
			double lineEndingYCord;

			if (i + 1 < 11) {
				nextDecadesRank = nameSurferEntry.getRank(i + 1);
			}

			lineStaringYCord = defineLineStaringYCord(currentDecadesRank, linesHorisontalAxisSize);
			lineEndingYCord = definelineEndingYCord(nextDecadesRank, linesHorisontalAxisSize);

			addLine(marginBetweenLines * i, lineStaringYCord, marginBetweenLines * (i + 1), lineEndingYCord, color);

			addNameLabel(enrtyName, currentDecadesRank, marginBetweenLines * i, lineStaringYCord, color);

		}
		// displays last decades ranks label
		double lastLabelYCord = defineLineStaringYCord(nameSurferEntry.getRank(10), linesHorisontalAxisSize);
		addNameLabel(enrtyName, nameSurferEntry.getRank(10), marginBetweenLines * 10, lastLabelYCord, color);
	}

	// this method adds nameLabel by given name rank , coordinates and color
	// and if rank was 0 then on graph it will be shown as "*"
	private void addNameLabel(String name, int rank, double x0, double y0, Color color) {
		GLabel label;

		if (rank == 0) {
			label = new GLabel(name + " " + "*");
		} else {
			label = new GLabel(name + " " + rank);
		}
		label.setColor(color);
		add(label, x0 + sepBetweenLabelAndStartingCord, y0 - sepBetweenLabelAndStartingCord);

	}

	// defines starting coordinate for line or label (label is added on lines
	// coordinate with small separation of 4 pixels) by currentDecades rank and
	// linesHorisontalAxis length
	// if rank was 0 cord will be at the bottom
	private double defineLineStaringYCord(int currentDecadesRank, double linesHorisontalAxisSize) {
		double lineStaringYCord;

		if (currentDecadesRank == 0) {
			lineStaringYCord = (double) getHeight() - GRAPH_MARGIN_SIZE; // bottom lineCord

		} else {
			lineStaringYCord = GRAPH_MARGIN_SIZE + (currentDecadesRank - 1) * linesHorisontalAxisSize;
		}

		return lineStaringYCord;
	}

	// is exactly the same method but for better understanding is written again
	private double definelineEndingYCord(int nextDecadesRank, double linesHorisontalAxisSize) {

		double lineEndingYCord;
		if (nextDecadesRank == 0) {
			lineEndingYCord = (double) getHeight() - GRAPH_MARGIN_SIZE;
		} else {
			lineEndingYCord = GRAPH_MARGIN_SIZE + (nextDecadesRank - 1) * linesHorisontalAxisSize;
		}

		return lineEndingYCord;
	}

	// checks if entryObjects contains entry
	private boolean contains(NameSurferEntry entry) {

		boolean contains = false;
		for (int i = 0; i < entryObjects.size(); i++) {
			if ((entryObjects.get(i).toString()).equals(entry.toString())) {
				contains = true;
			}
		}
		return contains;

	}

	// method receives ints which start from 0
	// to be more easily understandable
	// we add +1 to entered int so we can count them like this
	// 1st 2nd 3rd ...
	// and not like this 0th...
	private Color defineCollor(int numberOfEnteredEntry) {
		// 1st entered 5th entered, 9th entered... will be black
		if ((numberOfEnteredEntry + 1) % 4 == 1) {
			return Color.BLACK;
			// 2nd 6th 10th... will be red
		}
		if ((numberOfEnteredEntry + 1) % 4 == 2) {
			return Color.RED;
			// 3rd 7th 11th ... will be blue
		}
		if ((numberOfEnteredEntry + 1) % 4 == 3) {
			return Color.BLUE;
			// 4th 8th 12th... will be yellow
		} else {
			return Color.CYAN; // TODO yellow
		}

	}

	// extension

	//this method deletes entry from entryObjects
	public void Delete(NameSurferEntry enrtyWishedToDelete) {
		int indexOfEnrtyWishedToDelete = indexOfEntry(enrtyWishedToDelete);
		
		if (contains(enrtyWishedToDelete)) {
			entryObjects.remove(indexOfEnrtyWishedToDelete);
		}
		System.out.println(entryObjects);  

		update();

	}

	private int indexOfEntry(NameSurferEntry entry) {
		int index = -1;
		
		for (int i = 0; i < entryObjects.size(); i++) {
			if ((entryObjects.get(i).toString()).equals(entry.toString())) {
				
				return i;
			}
		}
		// return contains;
		return index;
	}
	
	
	

	
	

	/* Implementation of the ComponentListener interface */
	public void componentHidden(ComponentEvent e) {
	}

	public void componentMoved(ComponentEvent e) {
	}

	public void componentResized(ComponentEvent e) {
		update();
	}

	public void componentShown(ComponentEvent e) {
	}
}

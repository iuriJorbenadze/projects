
/*
 * File: NameSurfer.java
 * ---------------------
 * When it is finished, this program will implements the viewer for
 * the baby-name database described in the assignment handout.
 */

import acm.graphics.GCanvas;
import acm.program.*;
import java.awt.event.*;
import javax.swing.*;

public class NameSurfer_exstension extends Program implements NameSurferConstants {

	private JLabel Name;
	private JTextField textField;
	private JButton Graph;
	private JButton Clear;

	private NameSurferDataBase dataBase = new NameSurferDataBase(NAMES_DATA_FILE);

	private NameSurferGraph_extension graph;

	
	
	/** extension */
	
	private JButton Delete;
	private static final int NEW_APLICATION_WIDTH = 1200;
	private static final int NEW_APLICATION_HEIGHT = 600;
	
	private secondCanvas barChartCanvas ;
	


	/* Method: init() */
	/**
	 * This method has the responsibility for reading in the data base and
	 * initializing the interactors at the bottom of the window.
	 */
	public void init() {
		// You fill this in, along with any helper methods //
		
		setSize(NEW_APLICATION_WIDTH,NEW_APLICATION_HEIGHT);
		
		Name = new JLabel("Name");
		textField = new JTextField(10);
		textField.addActionListener(this);
		Graph = new JButton("Graph");
		Graph.addActionListener(this);
		Clear = new JButton("Clear");
		Clear.addActionListener(this);

		add(Name, SOUTH);
		add(textField, SOUTH);
		add(Graph, SOUTH);
		add(Clear, SOUTH);

		graph = new NameSurferGraph_extension();
		add(graph);

		Delete = new JButton("Delete");
		Delete.addActionListener(this);

		add(Delete, SOUTH);
			
		barChartCanvas = new secondCanvas();
		add(barChartCanvas);
		
	}

	/* Method: actionPerformed(e) */
	/**
	 * This class is responsible for detecting when the buttons are clicked, so you
	 * will have to define a method to respond to button actions.
	 */
	public void actionPerformed(ActionEvent e) {

		// if graph was clicked or enter was pressed on textField
		//
		if (e.getSource() == textField || e.getSource() == Graph) {
			if (!textField.getText().equals("")) {

				NameSurferEntry enrty = dataBase.findEntry(textField.getText()); // find entry returns null if object
																					// not present

				// if entry is null method will not do anyting
				// just empties textField
				if (enrty != null) {
					graph.addEntry(enrty);

					
					barChartCanvas.addEntry(enrty);
				}
				textField.setText("");
			}
		} else if (e.getSource() == Clear) {
			// clears all statistics from graph and updates in clear method so it can be
			// seen
			graph.clear();
			
			
			barChartCanvas.clear();
			
			
		}

		// extension
		//if delete button is pressed and textField is not empty
		//deletes entry and sets textField to empty
		else if (e.getSource() == Delete) {
			// clears entered names statistics from graph and updates in delete method so it
			// can be seen
			if (!textField.getText().equals("")) {
				NameSurferEntry enrty = dataBase.findEntry(textField.getText());// find entry returns null if object
																				// not present
				if (enrty != null) {
					graph.Delete(enrty);
					
					
					
					barChartCanvas.Delete(enrty);
				}
				textField.setText("");
			}
		}

	}
}


/*
 * File: NameSurfer.java
 * ---------------------
 * When it is finished, this program will implements the viewer for
 * the baby-name database described in the assignment handout.
 */

import acm.program.*;
import java.awt.event.*;
import javax.swing.*;

public class NameSurfer extends Program implements NameSurferConstants {

	private JLabel Name;
	private JTextField textField;
	private JButton Graph;
	private JButton Clear;

	private NameSurferDataBase dataBase = new NameSurferDataBase(NAMES_DATA_FILE);

	private NameSurferGraph graph;

	/* Method: init() */
	/**
	 * This method has the responsibility for reading in the data base and
	 * initializing the interactors at the bottom of the window.
	 */
	public void init() {
		// You fill this in, along with any helper methods //

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

		graph = new NameSurferGraph();
		add(graph);

	}

	/* Method: actionPerformed(e) */
	/**
	 * This class is responsible for detecting when the buttons are clicked, so you
	 * will have to define a method to respond to button actions.
	 */
	public void actionPerformed(ActionEvent e) {
		
		//if graph was clicked or enter was pressed on textField
		//
		if (e.getSource() == textField || e.getSource() == Graph) {
			if (!textField.getText().equals("")) {
				

				NameSurferEntry enrty = dataBase.findEntry(textField.getText()); // find entry returns null if object
																					// not present
			
				//if entry is null method will not do anyting
				//just empties textField
				if (enrty != null) {
					graph.addEntry(enrty); 
				
				}
				textField.setText("");
			}
		} else if (e.getSource() == Clear) {
			//clears all statistics from graph and updates in clear method so it can be seen
			graph.clear();
		
		}

	}
}

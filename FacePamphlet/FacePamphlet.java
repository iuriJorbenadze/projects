
/* 
 * File: FacePamphlet.java
 * -----------------------
 * When it is finished, this program will implement a basic social network
 * management system.
 */

import acm.program.*;
import acm.graphics.*;
import acm.util.*;
import java.awt.event.*;
import java.util.Iterator;

import javax.swing.*;

public class FacePamphlet extends Program // TODO change back to program
		implements FacePamphletConstants {

	private JLabel NameLabel;
	private JTextField NameTextField;
	private JButton AddButton;
	private JButton DeleteButton;
	private JButton LookupButton;

	private JTextField ChangeStatutsTF;
	private JButton ChangeStatutsButton;

	private JTextField ChangePictureTF;
	private JButton ChangePictureButton;

	private JTextField addFriendTF;
	private JButton addFriendButon;

	// current user from whichs perspective we are interacting
	private FacePamphletProfile currentProfile;

	private FacePamphletDatabase profileDataBase = new FacePamphletDatabase();

	private FacePamphletCanvas canvas;

	/**
	 * This method has the responsibility for initializing the interactors in the
	 * application, and taking care of any other initialization that needs to be
	 * performed.
	 */
	public void init() {
		// You fill this in

		addUI();

		canvas = new FacePamphletCanvas();
		add(canvas);

	}

	/**
	 * This class is responsible for detecting when the buttons are clicked or
	 * interactors are used, so you will have to add code to respond to these
	 * actions.
	 */
	public void actionPerformed(ActionEvent e) {
		// You fill this in as well as add any additional methods

		if (e.getSource() == AddButton) {
			if (!NameTextField.getText().equals("")) {

				createProfile();
				NameTextField.setText("");

			}

		} else if (e.getSource() == DeleteButton) {
			if (!NameTextField.getText().equals("")) {

				deleteProfile();
				NameTextField.setText("");
			}
		} else if (e.getSource() == LookupButton) {
			if (!NameTextField.getText().equals("")) {

				lookupProfile();
				NameTextField.setText("");

			}

		} else if (e.getSource() == ChangeStatutsButton || e.getSource() == ChangeStatutsTF) {
			if (!ChangeStatutsTF.getText().equals("")) {

				changeStatus();
				ChangeStatutsTF.setText("");
			}

		} else if (e.getSource() == ChangePictureButton || e.getSource() == ChangePictureTF) {
			if (!ChangePictureTF.getText().equals("")) {

				changePicture();
				ChangePictureTF.setText("");

			}
		} else if (e.getSource() == addFriendButon || e.getSource() == addFriendTF) {

			if (!addFriendTF.getText().equals("")) {

				checkCurrentProfileState();
				addFriendTF.setText("");

			}
		}

	}

	private void addUI() {
		createNameInteractors();
		createAddButton();
		createDeleteButton();
		createLookupButton();
		createChangeStatusInteractors();
		add(new JLabel(EMPTY_LABEL_TEXT), WEST);
		createChangePictureInteractors();
		add(new JLabel(EMPTY_LABEL_TEXT), WEST);
		createAddFriendInteractors();

	}

	private void createNameInteractors() {
		NameLabel = new JLabel("Name");
		add(NameLabel, NORTH);

		NameTextField = new JTextField(TEXT_FIELD_SIZE);
		NameTextField.addActionListener(this);
		add(NameTextField, NORTH);
	}

	private void createAddButton() {
		AddButton = new JButton("Add");
		AddButton.addActionListener(this);
		add(AddButton, NORTH);
	}

	private void createDeleteButton() {
		DeleteButton = new JButton("Delete");
		DeleteButton.addActionListener(this);
		add(DeleteButton, NORTH);
	}

	private void createLookupButton() {
		LookupButton = new JButton("Lookup");
		LookupButton.addActionListener(this);
		add(LookupButton, NORTH);
	}

	private void createChangeStatusInteractors() {
		ChangeStatutsTF = new JTextField(TEXT_FIELD_SIZE);
		ChangeStatutsTF.addActionListener(this);
		add(ChangeStatutsTF, WEST);
		ChangeStatutsButton = new JButton("Change Status");
		ChangeStatutsButton.addActionListener(this);
		add(ChangeStatutsButton, WEST);
	}

	private void createChangePictureInteractors() {
		ChangePictureTF = new JTextField(TEXT_FIELD_SIZE);
		ChangePictureTF.addActionListener(this);
		add(ChangePictureTF, WEST);
		ChangePictureButton = new JButton("Change Picture");
		ChangePictureButton.addActionListener(this);
		add(ChangePictureButton, WEST);
	}

	private void createAddFriendInteractors() {
		addFriendTF = new JTextField(TEXT_FIELD_SIZE);
		addFriendTF.addActionListener(this);
		add(addFriendTF, WEST);
		addFriendButon = new JButton("Add Friend");
		addFriendButon.addActionListener(this);
		add(addFriendButon, WEST);
	}

	// creates profile if one does not already exist
	// if already exists displays msg and profile
	private void createProfile() {

		if (!profileDataBase.containsProfile(NameTextField.getText())) {

			currentProfile = new FacePamphletProfile(NameTextField.getText());

			profileDataBase.addProfile(currentProfile);

			canvas.displayProfile(currentProfile);
			canvas.showMessage("New profile created");

		} else {
			currentProfile = profileDataBase.getProfile(NameTextField.getText());

			canvas.displayProfile(currentProfile);
			canvas.showMessage("This profile with the name " + currentProfile.getName() + "  already exists: ");

		}

	}

	// deletes profile, clears screen and sets current profile to null
	// if profile does not exist displays certain msg
	private void deleteProfile() {
		if (!profileDataBase.containsProfile(NameTextField.getText())) {
			canvas.showMessage("This profile does not exist");

		} else {
			String profWishedToDelete = NameTextField.getText();

			profileDataBase.deleteProfile(profWishedToDelete);

			currentProfile = null;

			canvas.removeAll();

			canvas.showMessage("Profile of " + profWishedToDelete + " deleted ");

		}
	}

	// lookups for profile and displays it on screen
	// if profile does not exist displays certain msg and sets
	// current profile to null
	private void lookupProfile() {
		String profWishedToLookup = NameTextField.getText();

		if (profileDataBase.containsProfile(profWishedToLookup)) {

			FacePamphletProfile lookupedProf = profileDataBase.getProfile(profWishedToLookup);
			currentProfile = lookupedProf;

			canvas.displayProfile(currentProfile);
			canvas.showMessage("Displaying: " + profWishedToLookup);

		} else {
			canvas.removeAll();
			canvas.showMessage("Profile with name " + profWishedToLookup + " does not exist");
			currentProfile = null;

		}
	}

	// changes status and displays updated profile and displays certain msg
	// if profile is not selected (current profile is null) displays certain msg
	private void changeStatus() {
		if (currentProfile != null) {

			currentProfile.setStatus(ChangeStatutsTF.getText());

			canvas.displayProfile(currentProfile);
			canvas.showMessage("Status updated to: " + ChangeStatutsTF.getText());

		} else {

			// canvas.removeAll();
			canvas.showMessage("Please select a profile to change status");
		}
	}

	// changes picture and displays certain msg
	// if profile is not selected (current profile is null) displays certain msg
	// if file was not found also displays certain msg
	private void changePicture() {
		if (currentProfile != null) {

			GImage image = null;
			String filename = ChangePictureTF.getText();

			try {
				image = new GImage(filename);

				currentProfile.setImage(image);

				canvas.displayProfile(currentProfile);
				canvas.showMessage("Picture updated");

			} catch (ErrorException ex) {
				// Code that is executed if the filename cannot be opened.
				canvas.showMessage("Unable to open an image file: " + ChangePictureTF.getText());
				image = null;
			}

		} else {
			canvas.showMessage("Please select a profile to change picture");
		}
	}

	// checks current profiles state
	// if it is null displays certain msg
	// if is not null adds friend
	private void checkCurrentProfileState() {

		if (currentProfile != null) {

			addFriendToProfile();

		} else {
			canvas.showMessage("Please select a profile to add friend");
		}
	}

	// adds friend to profile
	// if already are friends displays certain msg
	// if is trying to add himself displays msg
	// if friend wished to add does not exist displays certain msg
	private void addFriendToProfile() {
		String friendToAddStr = addFriendTF.getText();
		String currentUser = currentProfile.getName();

		if (profileDataBase.getProfile(friendToAddStr) != null && !currentUser.equals(friendToAddStr)) {

			FacePamphletProfile friendToAddObj = profileDataBase.getProfile(friendToAddStr);

			if (currentProfile.addFriend(friendToAddStr)) {
				friendToAddObj.addFriend(currentUser);

				canvas.displayProfile(currentProfile);
				canvas.showMessage(friendToAddStr + " added as a friend");

			} else {
				canvas.showMessage(currentUser + " already has " + friendToAddStr + " as a friend.");
			}

		} else if (currentUser.equals(friendToAddStr)) {
			canvas.showMessage("You can't add yourself to friends. Go get friends!");
		} else {
			canvas.showMessage(friendToAddStr + " does not exist");
		}
	}

}

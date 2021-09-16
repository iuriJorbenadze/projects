
/*
 * File: FacePamphletCanvas.java
 * -----------------------------
 * This class represents the canvas on which the profiles in the social
 * network are displayed.  NOTE: This class does NOT need to update the
 * display when the window is resized.
 */

import acm.graphics.*;
import javafx.scene.effect.BlurType;

import java.awt.*;
import java.util.*;

public class FacePamphletCanvas extends GCanvas implements FacePamphletConstants {

	private GLabel currentMessage;
	private GLabel nameLbl;
	private GImage image;
	private GLabel statusLbl;

	private GLabel friendsLbl;

	private static final double MARGIN_BETWEEN_FRIENDS = 15;

	/**
	 * Constructor This method takes care of any initialization needed for the
	 * display
	 */
	public FacePamphletCanvas() {
		// You fill this in
		currentMessage = new GLabel("Welcome!!!");
		currentMessage.setFont(MESSAGE_FONT);

		nameLbl = new GLabel("");

		image = new GImage(""); 
		statusLbl = new GLabel("");

		friendsLbl = new GLabel("Friends:");
	}

	/**
	 * This method displays a message string near the bottom of the canvas. Every
	 * time this method is called, the previously displayed message (if any) is
	 * replaced by the new message text passed in.
	 */
	public void showMessage(String msg) {
		// You fill this in

		currentMessage.setLabel(msg);

		// System.out.println(getWidth());
		// System.out.println(getHeight());

		double labelX = ((getWidth() - currentMessage.getWidth()) / 2);
		double labelY = getHeight() - BOTTOM_MESSAGE_MARGIN;

		// currentMessage.setLocation(labelX, labelY);

		add(currentMessage, labelX, labelY);
	}

	/**
	 * This method displays the given profile on the canvas. The canvas is first
	 * cleared of all existing items (including messages displayed near the bottom
	 * of the screen) and then the given profile is displayed. The profile display
	 * includes the name of the user from the profile, the corresponding image (or
	 * an indication that an image does not exist), the status of the user, and a
	 * list of the user's friends in the social network.
	 */
	public void displayProfile(FacePamphletProfile profile) {
		// You fill this in

		removeAll();

		displayName(profile);

		displayImage(profile);

		displayStatus(profile);
		
		displayListOfFriends(profile);
	}

	private void displayName(FacePamphletProfile profile) {
		nameLbl.setLabel(profile.getName());

		nameLbl.setFont(PROFILE_NAME_FONT);
		nameLbl.setColor(Color.BLUE);
		add(nameLbl);

		nameLbl.setLocation(LEFT_MARGIN, TOP_MARGIN + nameLbl.getAscent());

	}

	private void displayImage(FacePamphletProfile profile) {
		if (profile.getImage() != null) {
			image = profile.getImage();
			image.setSize(IMAGE_WIDTH, IMAGE_HEIGHT);
			image.setLocation(LEFT_MARGIN, nameLbl.getY() + IMAGE_MARGIN);
			add(image);
		} else {

			GRect frame = new GRect(IMAGE_WIDTH, IMAGE_HEIGHT);
			add(frame, LEFT_MARGIN, nameLbl.getY() + IMAGE_MARGIN);

			GLabel noImgLbl = new GLabel("No Image");
			noImgLbl.setFont(PROFILE_IMAGE_FONT);
			add(noImgLbl, frame.getX() + IMAGE_WIDTH / 2 - noImgLbl.getWidth() / 2,
					frame.getY() + IMAGE_HEIGHT / 2 - noImgLbl.getDescent() + noImgLbl.getHeight() / 2);
		}
	}

	private void displayStatus(FacePamphletProfile profile) {
		if (!profile.getStatus().equals("")) {

			statusLbl.setLabel(profile.getName() + " is " + profile.getStatus());
			statusLbl.setFont(PROFILE_STATUS_FONT);
			add(statusLbl, LEFT_MARGIN, TOP_MARGIN + nameLbl.getHeight() + IMAGE_MARGIN + IMAGE_HEIGHT + STATUS_MARGIN);

		} else {
			GLabel noStatusLbl = new GLabel("No current status");
			noStatusLbl.setFont(PROFILE_STATUS_FONT);
			add(noStatusLbl, LEFT_MARGIN,
					TOP_MARGIN + nameLbl.getHeight() + IMAGE_MARGIN + IMAGE_HEIGHT + STATUS_MARGIN);

		}
	}
	
	private void displayListOfFriends(FacePamphletProfile profile) {

		friendsLbl.setFont(PROFILE_FRIEND_LABEL_FONT);
		add(friendsLbl, getWidth() / 2, nameLbl.getY() + IMAGE_MARGIN);

		Iterator<String> listOfFrineds = profile.getFriends();
		double friendCord = friendsLbl.getY() + MARGIN_BETWEEN_FRIENDS;
		while (listOfFrineds.hasNext()) {
			GLabel friendLbl = new GLabel(listOfFrineds.next());
			friendLbl.setFont(PROFILE_FRIEND_FONT);
			add(friendLbl, getWidth() / 2, friendCord);
			friendCord += MARGIN_BETWEEN_FRIENDS;
		}
	}
	

}

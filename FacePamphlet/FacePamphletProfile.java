
/*
 * File: FacePamphletProfile.java
 * ------------------------------
 * This class keeps track of all the information for one profile
 * in the FacePamphlet social network.  Each profile contains a
 * name, an image (which may not always be set), a status (what 
 * the person is currently doing, which may not always be set),
 * and a list of friends.
 */

import acm.graphics.*;
import java.util.*;

public class FacePamphletProfile implements FacePamphletConstants {

	private String Name;

	private GImage Image;

	private String Status;

	private ArrayList<String> listOfFriends;

	/**
	 * Constructor This method takes care of any initialization needed for the
	 * profile.
	 */
	public FacePamphletProfile(String name) {
		// You fill this in
		Name = name;
		listOfFriends = new ArrayList<String>();
	}

	/** This method returns the name associated with the profile. */
	public String getName() {
		// You fill this in. Currently always returns the empty string.
		return Name;
	}

	/**
	 * This method returns the image associated with the profile. If there is no
	 * image associated with the profile, the method returns null.
	 */
	public GImage getImage() {
		// You fill this in. Currently always returns null.
		return Image;
	}

	/** This method sets the image associated with the profile. */
	public void setImage(GImage image) {
		// You fill this in

		Image = image;
	}

	/**
	 * This method returns the status associated with the profile. If there is no
	 * status associated with the profile, the method returns the empty string ("").
	 */
	public String getStatus() {
		// You fill this in. Currently always returns the empty string.
		if(Status == null ) {
			return "";
		}
		return Status;
	}

	/** This method sets the status associated with the profile. */
	public void setStatus(String status) {
		// You fill this in
		Status = status;
	}

	/**
	 * This method adds the named friend to this profile's list of friends. It
	 * returns true if the friend's name was not already in the list of friends for
	 * this profile (and the name is added to the list). The method returns false if
	 * the given friend name was already in the list of friends for this profile (in
	 * which case, the given friend name is not added to the list of friends a
	 * second time.)
	 */
	public boolean addFriend(String friend) {
		// You fill this in. Currently always returns true.
		boolean contains = false;

		for (int i = 0; i < listOfFriends.size(); i++) {
			if (listOfFriends.get(i).equals(friend)) {
				contains = true;
			}
		}
		if (!contains) {
			listOfFriends.add(friend);
		}

		// returns true if do not contains
		return !contains;

	}

	/**
	 * This method removes the named friend from this profile's list of friends. It
	 * returns true if the friend's name was in the list of friends for this profile
	 * (and the name was removed from the list). The method returns false if the
	 * given friend name was not in the list of friends for this profile (in which
	 * case, the given friend name could not be removed.)
	 */
	public boolean removeFriend(String friend) {
		// You fill this in. Currently always returns false.

		boolean contains = false;

		for (int i = 0; i < listOfFriends.size(); i++) {
			if (listOfFriends.get(i).equals(friend)) {
				contains = true;
				listOfFriends.remove(friend);
				break;
			}
		}

		return contains;
	}

	/**
	 * This method returns an iterator over the list of friends associated with the
	 * profile.
	 */
	public Iterator<String> getFriends() {
		// You fill this in. Currently always returns null.

		Iterator<String> friendsIterator = listOfFriends.iterator();

		return friendsIterator;
	}

	/**
	 * This method returns a string representation of the profile. This string is of
	 * the form: "name (status): list of friends", where name and status are set
	 * accordingly and the list of friends is a comma separated list of the names of
	 * all of the friends in this profile.
	 * 
	 * For example, in a profile with name "Alice" whose status is "coding" and who
	 * has friends Don, Chelsea, and Bob, this method would return the string:
	 * "Alice (coding): Don, Chelsea, Bob"
	 */
	public String toString() {
		// You fill this in. Currently always returns the empty string.
		String profileStr = "";
		int listOfFriendsSize = listOfFriends.size();
		
		String statusStr = "";
		if (Status != null) {
			statusStr = Status;
		}
		
		profileStr = Name + " (" + statusStr + "): ";

		for (int i = 0; i < listOfFriendsSize - 1; i++) {
			profileStr += listOfFriends.get(i) + ", ";
		}
		// adds last friend from list to string
		if (listOfFriendsSize - 1 >= 0) {
			profileStr += listOfFriends.get(listOfFriendsSize - 1);
		}
		return profileStr;
	}

}

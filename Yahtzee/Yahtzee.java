
/*
 * File: Yahtzee.java
 * ------------------
 * This program will eventually play the Yahtzee game.
 */

import java.util.ArrayList;

import com.sun.xml.internal.bind.v2.runtime.unmarshaller.XsiNilLoader.Array;

import acm.io.*;
import acm.program.*;
import acm.util.*;

public class Yahtzee extends GraphicsProgram implements YahtzeeConstants {

	public static void main(String[] args) {
		new Yahtzee().start(args);
	}

	public void run() {
		IODialog dialog = getDialog();
		nPlayers = dialog.readInt("Enter number of players");
		// prevents from entering more than 4 players
		while (nPlayers > 4) {
			nPlayers = dialog.readInt("Enter number of players");
		}
		playerNames = new String[nPlayers];
		for (int i = 1; i <= nPlayers; i++) {
			playerNames[i - 1] = dialog.readLine("Enter name for player " + i);
		}
		display = new YahtzeeDisplay(getGCanvas(), playerNames);
		playGame();
	}

	private void playGame() {
		/* You fill this in */

		// create 17boxes with nPlayers number boxes inside of each
		scoreBox = new int[N_CATEGORIES][nPlayers];

		// set default value to -1
		for (int i = 0; i < N_CATEGORIES; i++) {
			for (int j = 0; j < nPlayers; j++) {
				scoreBox[i][j] = -1;
			}
		}

		// loop for switching turns
		for (int turnN = 0; turnN < N_SCORING_CATEGORIES; turnN++) {

			for (int playerNumberN = 1; playerNumberN < nPlayers + 1; playerNumberN++) {

				display.printMessage(playerNames[playerNumberN - 1] + "'s turn");

				rollNumber1(playerNumberN);
				rollNumber2and3();

				chooseCategory(playerNumberN);

				//
				displayCurrentScore(playerNumberN);
				//
			}
		}
		sumScores();
		determineWinner();
	}

	private void rollNumber1(int playerNumberN) {

		// playerNumberN-1 because we want to start from index 0
		display.printMessage(playerNames[playerNumberN - 1] + "'s turn! click (Roll Dice) button to roll the dice");

		display.waitForPlayerToClickRoll(playerNumberN);

		for (int diceIndex = 0; diceIndex < N_DICE; diceIndex++) {
			int randomN = rgen.nextInt(1, 6);
			dice[diceIndex] = randomN;
			// println(randomN);
		}
		// show results on screen
		display.displayDice(dice);

	}

	private void rollNumber2and3() {
		// for loop to do roll 2 times
		for (int i = 0; i < 2; i++) {
			display.printMessage("Select the dice you wish to re-roll and click (Roll Again)");
			display.waitForPlayerToSelectDice();

			reRollSelectedDices();

		}

	}

	// check for all 5 dices which ones were pressed again, so we re-roll that ones
	private void reRollSelectedDices() {

		for (int diceIndex = 0; diceIndex < N_DICE; diceIndex++) {
			if (display.isDieSelected(diceIndex)) {
				// roll again
				int randomN = rgen.nextInt(1, 6);
				dice[diceIndex] = randomN;
				// println(randomN);
			}
		}
		display.displayDice(dice);
	}

	// selects category, checks if category is empty, enters score in scoreBox array
	// and displays
	// on screen
	private void chooseCategory(int playerNumberN) {

		int category = -1;

		// until valid category is entered(chosen), player chooses category again
		while (true) {
			display.printMessage("select a category for this roll.");
			category = display.waitForPlayerToSelectCategory();

			if (isValidCategory(category, playerNumberN)) {
				enterCategoryScore(playerNumberN, category);//////////////////
				break;
			}

		}

	}

	private boolean isValidCategory(int category, int playerNumberN) {

		// category must not be equal to upper bonus, upper score, total and lower
		// score and also must be empty. so if it equals to them return false
		if (category != UPPER_BONUS && category != UPPER_SCORE && category != TOTAL && category != LOWER_SCORE
				&& scoreBox[category - 1][playerNumberN - 1] == -1) {////////// 0 iyo aq
			// category-1 and playerNumberN-1, because we need to start form index 0
			return true;
		}
		return false; /////////////////////////////////
	}

	// at each click on category, this method calculates how much score player
	// will get and method will enter score into scoreBox and show it on display
	private void enterCategoryScore(int playerNumberN, int category) {
		int currentScore = 0;

		// if clicked category is ones, twos.... or sixes
		if (category <= SIXES && category >= ONES) {/////////
			// check 5 times (each dice) if it matches category, and if it does, adds to
			// score
			for (int diceIndex = 0; diceIndex < N_DICE; diceIndex++) {
				if (dice[diceIndex] == category) {
					currentScore = currentScore + category;
				}
			}
		} else if (category == THREE_OF_A_KIND) {///////////
			if (checkRareCategory(category)) {
				for (int diceIndex = 0; diceIndex < N_DICE; diceIndex++) {
					// increase score by value of dice
					currentScore = currentScore + dice[diceIndex];
				}
			} else {
				currentScore = 0;
			}
		} else if (category == FOUR_OF_A_KIND) {///////////
			if (checkRareCategory(category)) {
				for (int diceIndex = 0; diceIndex < N_DICE; diceIndex++) {
					// increase score by value of dice
					currentScore = currentScore + dice[diceIndex];
				}
			} else {
				currentScore = 0;
			}
		} else if (category == FULL_HOUSE) {
			if (checkRareCategory(category)) {
				currentScore = 25;
			} else {
				currentScore = 0;
			}
		} else if (category == SMALL_STRAIGHT) {
			if (checkRareCategory(category)) {
				currentScore = 30;
			} else {
				currentScore = 0;
			}
		} else if (category == LARGE_STRAIGHT) {
			if (checkRareCategory(category)) {
				currentScore = 40;
			} else {
				currentScore = 0;
			}
		} else if (category == YAHTZEE) {
			if (checkRareCategory(category)) {
				currentScore = 50;
			} else {
				currentScore = 0;
			}
		} else if (category == CHANCE) {

			for (int diceIndex = 0; diceIndex < N_DICE; diceIndex++) {
				currentScore = currentScore + dice[diceIndex];
			}

		}

		display.updateScorecard(category, playerNumberN, currentScore);
		scoreBox[category - 1][playerNumberN - 1] = currentScore;
	}

	// method will check value of each dice and according to its value it will add
	// it to certain list
	private boolean checkRareCategory(int category) {

		// for example if we have 1 dice with value one and 4 dices with value 6
		// 1 will go to list n1 and 4 sixes will go to last list(listForSixes)
		ArrayList<Integer> listForOnes = new ArrayList<Integer>();
		ArrayList<Integer> listForTwos = new ArrayList<Integer>();
		ArrayList<Integer> listForThrees = new ArrayList<Integer>();
		ArrayList<Integer> listForFours = new ArrayList<Integer>();
		ArrayList<Integer> listForFives = new ArrayList<Integer>();
		ArrayList<Integer> listForSixes = new ArrayList<Integer>();

		// check each dice and add values at certain conditions
		for (int diceIndex = 0; diceIndex < N_DICE; diceIndex++) {
			if (dice[diceIndex] == 1) {
				listForOnes.add(1);
			} else if (dice[diceIndex] == 2) {
				listForTwos.add(1);
			} else if (dice[diceIndex] == 3) {
				listForThrees.add(1);
			} else if (dice[diceIndex] == 4) {
				listForFours.add(1);
			} else if (dice[diceIndex] == 5) {
				listForFives.add(1);
			} else if (dice[diceIndex] == 6) {
				listForSixes.add(1);
			}
		}

		if (category == THREE_OF_A_KIND) {
			// three of a kind which means more than 2 dices should match, min3
			if (listForOnes.size() <= 2 && listForTwos.size() <= 2 && listForThrees.size() <= 2
					&& listForFours.size() <= 2 && listForFives.size() <= 2 && listForSixes.size() <= 2) {
				return false;
			} else {
				return true;////////////////////////
			}
		} else if (category == FOUR_OF_A_KIND) {
			// in this case if size is not 4, 5 or 6 it returns false
			if (listForOnes.size() <= 3 && listForTwos.size() <= 3 && listForThrees.size() <= 3
					&& listForFours.size() <= 2 && listForFives.size() <= 3 && listForSixes.size() <= 3) {
				return false;
			} else {
				return true;/////////////////////
			}
		} else if (category == FULL_HOUSE) {
			// in full house we need 3of a kind and 2 of a kind
			if (listForOnes.size() == 3 || listForTwos.size() == 3 || listForThrees.size() == 3
					|| listForFours.size() == 3 || listForFives.size() == 3 || listForSixes.size() == 3) {

				// check if other part is 2of a kind
				if (listForOnes.size() == 2 || listForTwos.size() == 2 || listForThrees.size() == 2
						|| listForFours.size() == 2 || listForFives.size() == 2 || listForSixes.size() == 2) {
					return true;
				}
			}
		} else if (category == SMALL_STRAIGHT) {
			// small straight: 1;2;3;4; or 2;3;4;5 or 3;4;5;6
			// >=on each list because one of them will have more than 1 element in list
			// 1 2 3 4
			if (listForOnes.size() >= 1 && listForTwos.size() >= 1 && listForThrees.size() >= 1
					&& listForFours.size() >= 1) {
				return true;
				// 2 3 4 5
			} else if (listForFives.size() >= 1 && listForTwos.size() >= 1 && listForThrees.size() >= 1
					&& listForFours.size() >= 1) {
				return true;
				// 3 4 5 6
			} else if (listForFives.size() >= 1 && listForSixes.size() >= 1 && listForThrees.size() >= 1
					&& listForFours.size() >= 1) {
				return true;
			}
		} else if (category == LARGE_STRAIGHT) {
			// 1 2 3 4 5
			if (listForOnes.size() == 1 && listForTwos.size() == 1 && listForThrees.size() == 1
					&& listForFours.size() == 1 && listForFives.size() == 1) {
				return true;
				// 2 3 4 5 6
			} else if (listForTwos.size() == 1 && listForThrees.size() == 1 && listForFours.size() == 1
					&& listForFives.size() == 1 && listForSixes.size() == 1) {
				return true;
			}
			// 5 of a kind
		} else if (category == YAHTZEE) {
			if (listForOnes.size() == 5 || listForTwos.size() == 5 || listForThrees.size() == 5
					|| listForFours.size() == 5 || listForFives.size() == 5 || listForSixes.size() == 5) {
				return true;
			}
		} else if (category == CHANCE) {
			return true;
		}
		// returns false if its not rare combination(category)
		return false;
		// and in main method false goes to else statement which makes score =0;

	}

	// displays current players current score during game
	private void displayCurrentScore(int playerNumberN) {

		int matchCurrentScore = 0;

		for (int i = 0; i < N_CATEGORIES; i++) {
			if (scoreBox[i][playerNumberN - 1] >= 0) {
				matchCurrentScore = matchCurrentScore + scoreBox[i][playerNumberN - 1];
				display.updateScorecard(TOTAL, playerNumberN, matchCurrentScore);
			}

		}
	}

	// after game ends this method sums up upper scores, if
	// upper score will be greater than 63, bonus score will become 35
	// after it sums lower score
	// and at the end sums upper bonus and lower scores to find total and
	// enters all values on display
	private void sumScores() {
		for (int playerN = 1; playerN < nPlayers + 1; playerN++) {
			int upperScore = 0;
			// scoreBox's default value was -1 so now we set it to 0
			int upperBonus = 0;
			scoreBox[UPPER_BONUS - 1][playerN - 1] = upperBonus;

			for (int categoryIndex = 1; categoryIndex < UPPER_SCORE; categoryIndex++) {
				upperScore = upperScore + scoreBox[categoryIndex - 1][playerN - 1];
			}

			if (upperScore > 63) {
				upperBonus = 35;
				scoreBox[UPPER_BONUS - 1][playerN - 1] = upperBonus;
			}

			int lowerScore = 0;
			for (int categoryIndex = THREE_OF_A_KIND; categoryIndex < LOWER_SCORE; categoryIndex++) {
				lowerScore = lowerScore + scoreBox[categoryIndex - 1][playerN - 1];
			}

			int total = upperScore + lowerScore + upperBonus;

			// enter player number n's total score into score box
			// total score is on index total-1
			scoreBox[TOTAL - 1][playerN - 1] = total;

			// display all results on screen
			display.updateScorecard(UPPER_SCORE, playerN, upperScore);
			display.updateScorecard(UPPER_BONUS, playerN, upperBonus);
			display.updateScorecard(LOWER_SCORE, playerN, lowerScore);
			display.updateScorecard(TOTAL, playerN, total);
		}

	}

	private void determineWinner() {
		int highestScore = 0;
		int indexOfPlayerWithHighestScore = -1;
		for (int playerIndex = 0; playerIndex < nPlayers; playerIndex++) {
			if (scoreBox[TOTAL - 1][playerIndex] > highestScore) {
				highestScore = scoreBox[TOTAL - 1][playerIndex];
				indexOfPlayerWithHighestScore = playerIndex;
			}
		}
		display.printMessage("Congratulations, " + playerNames[indexOfPlayerWithHighestScore]
				+ ", you're the winner with a total score of " + highestScore);

	}

	/* Private instance variables */
	private int nPlayers;
	private String[] playerNames;
	private YahtzeeDisplay display;
	private RandomGenerator rgen = new RandomGenerator();

	private int[] dice = new int[N_DICE];

	private int[][] scoreBox;
}

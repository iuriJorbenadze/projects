
/*
 * File: Hangman.java
 * ------------------
 * This program will eventually play the Hangman game from
 * Assignment #4.
 */

import acm.graphics.*;
import acm.program.*;
import acm.util.*;

import java.awt.*;

public class Hangman extends ConsoleProgram {

	// word from list, which is unknown for player
	private String secretWord;

	// word which at start is "---" , but then fills with letters
	private String guessedWord;

	// the number of guesses player has
	private int guessesLeft = 8;

	private RandomGenerator rgen = RandomGenerator.getInstance();

	private HangmanLexicon hangmanListWords = new HangmanLexicon();

	private HangmanCanvas canvas;

	public void run() {
		/* You fill this in */
		SetupForHangman();

		canvas.reset();
		canvas.displayWord(guessedWord);
		playHangman();

	}

	private void SetupForHangman() {
		welcomeMsg();
		secretWord = chooseRandomWord(); // makes secret word which the method randomly chose from list.
		guessedWord = wordOfDashes();
		guessCounter();
	}

	private void welcomeMsg() {
		println("Welcome To Hangman!");
	}

	// method randomly chooses word from the list
	private String chooseRandomWord() {
		// random index for choosing word from list by index number
		int wordIndex = rgen.nextInt(0, hangmanListWords.getWordCount() - 1);

		String randomWord = "";

		randomWord = hangmanListWords.getWord(wordIndex);
		return randomWord;
	}

	// creates word without symbols(with "_")
	// number of dashes increase until is equal to number of letters
	private String wordOfDashes() {
		String result = "";
		int strLength = secretWord.length();
		for (int i = 0; i < strLength; i++) {
			result += "-";

		}
		println("The word now looks like this:" + result);
		return result;
	}

	// updates the number of guesses left
	private void guessCounter() {
		if (guessesLeft == 1) {
			println("You have only one guess left!");
		} else {
			println("You have " + guessesLeft + " guesses left!");
		}
	}

	private String enterLetter() {
		String enteredLetter = readLine("Your guess: ");

		// entered letter becomes uppercase, because lexicon has words in uppercase
		enteredLetter = enteredLetter.toUpperCase();
		return enteredLetter;
	}

	// pre method which makes sure letter (char) was entered (not number)
	private boolean rightInputGuess(String guess) {
		// prevents player entering more then 1 letter and digit
		if (guess.length() > 1) {
			println("Wrong Input");
			return false;
		} else if (Character.isDigit(guess.charAt(0))) {
			println("Wrong Input");
			return false;
		}
		return true;
	}

	private void playHangman() {

		/**
		 * we can keep guessing until we run out of guesses (guessesLeft) or until
		 * guessedWord uncovers (will not contain dashes "-" anymore)
		 * 
		 * each loop of while cycle receives letter from player, uppercases it, checks
		 * if letter is valid (must be letter, not number), checks if letter matches
		 * with letter from word and then checks we won or not
		 */
		while (guessesLeft > 0 && guessedWord.contains("-")) {

			String guess = enterLetter();
			while (!rightInputGuess(guess)) {
				guess = enterLetter();
			}

			// check if entered letter matches any letters from the secret word
			checkGuessLetter(guess);

			// if game has not finished yet
			if (!checkWinOrLoss()) {
				println("The word now looks like this:" + guessedWord);

				guessCounter();
				// game finished
			} else {
				break;
			}

		}

	}

	private void checkGuessLetter(String guess) {
		boolean guessWasRight = false;

		for (int i = 0; i < secretWord.length(); i++) {
			char charAtIndexi = secretWord.charAt(i);

			// right guess
			if (guess.charAt(0) == charAtIndexi) {
				// replace dash by letter using concatenation with left and righ parts of the
				// word
				guessedWord = guessedWord.substring(0, i) + guess.charAt(0) + guessedWord.substring(i + 1);

				guessWasRight = true;

			}

		}
		// after checking whole word if we have met guess letter in the word at least
		// once
		// guessWasRight becomes true so we print that guess was correct was correct, if
		// not we substract guessesLeft
		// by 1
		if (guessWasRight) {
			println("Your guess was correct.");
			
			// displays word (with guess letter) on canvas
			canvas.displayWord(guessedWord);
			
			// wrong guess
		} else {
			println("There are no " + guess + "'s in in the word.");
			guessesLeft--;
			
			//because players guess was incorrect hangman's parts get drawn
			canvas.noteIncorrectGuess(guess.charAt(0));

		}

	}

	// if game is finished returns true, if not returns false
	private boolean checkWinOrLoss() {
		// lose condition when you run out of guessing tries
		if (guessesLeft == 0) {
			println("You're completly hung.");
			println("The word was: " + secretWord);
			println("You lose.");
			return true;

			// condition when all letters are guessed and you win
		} else if (!guessedWord.contains("-")) {
			println("You guessed the word! " + secretWord);
			println("You win.");
			return true;
		}
		// game has not finished yet
		return false;
	}

	public void init() {
		canvas = new HangmanCanvas();
		add(canvas);
	}

}


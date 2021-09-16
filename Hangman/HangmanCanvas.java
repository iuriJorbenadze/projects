
/*
 * File: HangmanCanvas.java
 * ------------------------
 * This file keeps track of the Hangman display.
 */

import acm.graphics.*;

public class HangmanCanvas extends GCanvas {

	/* Constants for the simple version of the picture (in pixels) */
	private static final int SCAFFOLD_HEIGHT = 360;
	private static final int BEAM_LENGTH = 144;
	private static final int ROPE_LENGTH = 18;
	private static final int HEAD_RADIUS = 36;
	private static final int BODY_LENGTH = 144;
	private static final int ARM_OFFSET_FROM_HEAD = 28;
	private static final int UPPER_ARM_LENGTH = 72;
	private static final int LOWER_ARM_LENGTH = 44;
	private static final int HIP_WIDTH = 36;
	private static final int LEG_LENGTH = 108;
	private static final int FOOT_LENGTH = 28;

	private static final int NEW_WIDTH = 400;
	private static final int NEW_HEIGHT = 400;

	// x and y coordinates for scaffles lower cords, from which we start drawing
	private double startingX = NEW_WIDTH / 2 - BEAM_LENGTH;
	private double startingY = NEW_HEIGHT / 2 + SCAFFOLD_HEIGHT / 2;

	private double startingBodyX = startingX + BEAM_LENGTH;
	private double startingBodyY = startingY - SCAFFOLD_HEIGHT + ROPE_LENGTH;

	private GLabel wordDisplayLabel = null;

	private GLabel incorrectLettersLabel = null;
	private String incorrectGuessesOnCanvas = "";

	// incorrect guesses
	private int incGuessCounter = 0;

	/** Resets the display so that only the scaffold appears */
	public void reset() {
		removeAll();
		drawScaffold();

	}

	/**
	 * Updates the word on the screen to correspond to the current state of the
	 * game. The argument string shows what letters have been guessed so far;
	 * unguessed letters are indicated by hyphens.
	 */
	public void displayWord(String word) {

		// this statement removes old label so they do not add up over each other
		if (wordDisplayLabel != null) {
			remove(wordDisplayLabel);
		}
		wordDisplayLabel = new GLabel(word, startingX, startingY + 40);
		wordDisplayLabel.setFont("Sylfaen-30");

		add(wordDisplayLabel);
	}

	/**
	 * Updates the display to correspond to an incorrect guess by the user. Calling
	 * this method causes the next body part to appear on the scaffold and adds the
	 * letter to the list of incorrect guesses that appears at the bottom of the
	 * window.
	 */
	public void noteIncorrectGuess(char letter) {

		// this statement removes old label so they do not add up over each other
		if (incorrectLettersLabel != null) {
			remove(incorrectLettersLabel);
		}

		// string which will be at bottom of the screen fills with wrong guess Letters
		incorrectGuessesOnCanvas += letter;

		incGuessCounter++;
		buildBody();

		GLabel incorrectGuessesOnCanvasLabel = new GLabel(incorrectGuessesOnCanvas);
		incorrectGuessesOnCanvasLabel.setFont("Sylfaen-20");
		add(incorrectGuessesOnCanvasLabel, startingX, startingY + 80);

	}

	// method draws 3 GLines which form scaffold
	private void drawScaffold() {
		GLine scaffold = new GLine(startingX, startingY, startingX, startingY - SCAFFOLD_HEIGHT);
		GLine beam = new GLine(startingX, startingY - SCAFFOLD_HEIGHT, startingX + BEAM_LENGTH,
				startingY - SCAFFOLD_HEIGHT);
		GLine rope = new GLine(startingX + BEAM_LENGTH, startingY - SCAFFOLD_HEIGHT, startingX + BEAM_LENGTH,
				startingY - SCAFFOLD_HEIGHT + ROPE_LENGTH);
		add(scaffold);
		add(beam);
		add(rope);
	}

	// at each incGuessCounter number method adds specific part of body
	private void buildBody() {
		switch (incGuessCounter) {
		case 0:
			break;
		case 1:
			drawHead();
			break;
		case 2:
			drawBody();
			break;
		case 3:
			drawLeftArm();
			break;
		case 4:
			drawRightArm();
			break;
		case 5:
			drawLeftLeg();
			break;
		case 6:
			drawRightLeg();
			break;

		case 7:
			drawLeftFoot();
			break;
		case 8:
			drawRightFoot();
			break;
		default:
			break;

		}
	}

	
	// "Ah shit, here we go again."_GTA San Andreas
	
	//following methods create and add body parts of hangman
	
	private void drawHead() {
		GOval head = new GOval(startingBodyX - HEAD_RADIUS, startingBodyY, 2 * HEAD_RADIUS, 2 * HEAD_RADIUS);
		add(head);
	}

	private void drawBody() {
		GLine body = new GLine(startingBodyX, startingBodyY + 2 * HEAD_RADIUS, startingBodyX,
				startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH);
		add(body);
	}

	private void drawLeftArm() {
		GLine leftArm = new GLine(startingBodyX, startingBodyY + 2 * HEAD_RADIUS + ARM_OFFSET_FROM_HEAD,
				startingBodyX - UPPER_ARM_LENGTH, startingBodyY + 2 * HEAD_RADIUS + ARM_OFFSET_FROM_HEAD);
		GLine leftLowerArm = new GLine(startingBodyX - UPPER_ARM_LENGTH,
				startingBodyY + 2 * HEAD_RADIUS + ARM_OFFSET_FROM_HEAD, startingBodyX - UPPER_ARM_LENGTH,
				startingBodyY + 2 * HEAD_RADIUS + ARM_OFFSET_FROM_HEAD + LOWER_ARM_LENGTH);

		add(leftArm);
		add(leftLowerArm);
	}

	private void drawRightArm() {
		GLine rightArm = new GLine(startingBodyX, startingBodyY + 2 * HEAD_RADIUS + ARM_OFFSET_FROM_HEAD,
				startingBodyX + UPPER_ARM_LENGTH, startingBodyY + 2 * HEAD_RADIUS + ARM_OFFSET_FROM_HEAD);
		GLine rightLowerArm = new GLine(startingBodyX + UPPER_ARM_LENGTH,
				startingBodyY + 2 * HEAD_RADIUS + ARM_OFFSET_FROM_HEAD, startingBodyX + UPPER_ARM_LENGTH,
				startingBodyY + 2 * HEAD_RADIUS + ARM_OFFSET_FROM_HEAD + LOWER_ARM_LENGTH);

		add(rightArm);
		add(rightLowerArm);
	}

	private void drawLeftLeg() {
		GLine leftLeg = new GLine(startingBodyX, startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH,
				startingBodyX - HIP_WIDTH, startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH);
		GLine leftLowerLeg = new GLine(startingBodyX - HIP_WIDTH, startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH,
				startingBodyX - HIP_WIDTH, startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH + LEG_LENGTH);

		add(leftLeg);
		add(leftLowerLeg);
	}

	private void drawRightLeg() {
		GLine rightLeg = new GLine(startingBodyX, startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH,
				startingBodyX + HIP_WIDTH, startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH);
		GLine rightLowerLeg = new GLine(startingBodyX + HIP_WIDTH, startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH,
				startingBodyX + HIP_WIDTH, startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH + LEG_LENGTH);

		add(rightLeg);
		add(rightLowerLeg);
	}

	private void drawLeftFoot() {
		GLine leftFoot = new GLine(startingBodyX - HIP_WIDTH,
				startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH + LEG_LENGTH, startingBodyX - HIP_WIDTH - FOOT_LENGTH,
				startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH + LEG_LENGTH);

		add(leftFoot);
	}

	private void drawRightFoot() {
		GLine rightFoot = new GLine(startingBodyX + HIP_WIDTH,
				startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH + LEG_LENGTH, startingBodyX + HIP_WIDTH + FOOT_LENGTH,
				startingBodyY + 2 * HEAD_RADIUS + BODY_LENGTH + LEG_LENGTH);

		add(rightFoot);
	}

}


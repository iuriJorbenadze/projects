
/*
 * File: Breakout.java
 * -------------------
 * Name:
 * Section Leader:
 * 
 * This file will eventually implement the game of Breakout.
 */

import acm.graphics.*;
import acm.program.*;
import acm.util.*;

import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class Breakout extends GraphicsProgram {

	/** Width and height of application window in pixels */
	public static final int APPLICATION_WIDTH = 400;
	public static final int APPLICATION_HEIGHT = 600;

	/** Dimensions of game board (usually the same) */
	private static final int WIDTH = APPLICATION_WIDTH;
	private static final int HEIGHT = APPLICATION_HEIGHT;

	/** Dimensions of the paddle */
	private static final int PADDLE_WIDTH = 60;
	private static final int PADDLE_HEIGHT = 10;

	/** Offset of the paddle up from the bottom */
	private static final int PADDLE_Y_OFFSET = 30;

	/** Number of bricks per row */
	private static final int NBRICKS_PER_ROW = 10;

	/** Number of rows of bricks */
	private static final int NBRICK_ROWS = 10;

	/** Separation between bricks */
	private static final int BRICK_SEP = 4;

	/** Width of a brick */
	private static final int BRICK_WIDTH = (WIDTH - (NBRICKS_PER_ROW - 1) * BRICK_SEP) / NBRICKS_PER_ROW;

	/** Height of a brick */
	private static final int BRICK_HEIGHT = 8;

	/** Radius of the ball in pixels */
	private static final int BALL_RADIUS = 10;

	/** Offset of the top brick row from the top */
	private static final int BRICK_Y_OFFSET = 70;

	/** Number of turns */
	private static final int NTURNS = 3;

	private int gameLifes = NTURNS;

	// paddle settings
	private GRect paddle;
	private static final int PADDLE_X = APPLICATION_WIDTH / 2 - PADDLE_WIDTH / 2;
	private static final int PADDLE_Y = APPLICATION_HEIGHT - PADDLE_Y_OFFSET - PADDLE_HEIGHT;

	// ball settings
	private GOval ball = new GOval(2 * BALL_RADIUS, 2 * BALL_RADIUS);
	private double vx;
	private double vy = 3;
	private RandomGenerator rgen = RandomGenerator.getInstance();
	private int BALL_PAUSE = 20;

	// brick settings
	private GRect brick;

	// game score
	private int score = 0;
	// Winning score
	private static final int MAX_SCORE = NBRICK_ROWS * NBRICKS_PER_ROW;

	private int paddleHits = 0;

	AudioClip bounceClip = MediaTools.loadAudioClip("bounce.au");

	// reflected ball speed depending on which part of paddle it hits
	// if it hits centre part of paddle speed will be 1.5
	private double sidesReflectSpeed = 3;
	private double centreReflectSpeed = 1.5;

	/* Method: run() */
	/** Runs the Breakout program. */
	public void run() {
		addMouseListeners();
		setup();

		playGame();
		if (gameLifes == 0) {
			gameOver();
		} else {
			youWon();
		}
	}

	private void setup() {
		menu();
		// setSize(APPLICATION_WIDTH,APPLICATION_HEIGHT);
		addPicture();
		addBricks();
		addPaddle();
		addBall();
		clickToStart();
	}


	// starting menu with 2 glabels: game name and instruction
	private void menu() {
	
			setBackground(Color.LIGHT_GRAY);

			GLabel brakout = new GLabel("BREAKOUT");
			brakout.setFont("Times New Roman-40");
			brakout.setColor(Color.RED);
			double x = brakout.getWidth();
			double y = brakout.getAscent();
			add(brakout, (WIDTH - x) / 2, (HEIGHT - y) / 2);

			GLabel click = new GLabel("Click to launch the game");
			click.setFont("-BOLD-20");
			double x2 = click.getWidth();
			double y2 = click.getAscent();
			add(click, (WIDTH - x2) / 2, ((HEIGHT - y2) / 2) + (HEIGHT / 4));
			waitForClick();
			removeAll();
		
	}
	
	private void addPicture() {
		
		GImage image = new GImage("");
		add(image);
	}

	private void addBricks() {
		int rowStartingY = BRICK_Y_OFFSET;

		for (int rowN = 0; rowN < NBRICK_ROWS; rowN++) {

			Color currentColor = Color.red;
			// by using this if statements addRow method will receive different color
			// depending on row number
			// for 0th (first row is 0) and 1st rows color will be red, 2nd 3rd rows color
			// will be orange and so on
			if (rowN < 2) {
				currentColor = Color.red;
			} else if (rowN < 4) {
				currentColor = Color.orange;
			} else if (rowN < 4) {
				currentColor = Color.orange;
			} else if (rowN < 6) {
				currentColor = Color.yellow;
			} else if (rowN < 8) {
				currentColor = Color.green;
			} else if (rowN < 10) {
				currentColor = Color.cyan;
			}

			addRow(currentColor, rowStartingY + rowN * (BRICK_HEIGHT + BRICK_SEP));

		}
	}

	private void addRow(Color enteredColor, int rowY) {

		// width of total 10 bricks and 9 separations between them
		int totalWidthOfBricksInRow = BRICK_WIDTH * NBRICKS_PER_ROW + BRICK_SEP * (NBRICKS_PER_ROW - 1);

		// starting x coordinate for first brick in row
		int rowStartingX = (APPLICATION_WIDTH - totalWidthOfBricksInRow) / 2;

		// adds n bricks to given Y coordinate (which is changing as row number changes)
		for (int i = 0; i < NBRICKS_PER_ROW; i++) {
			brick = new GRect(BRICK_WIDTH, BRICK_HEIGHT);
			brick.setFilled(true);
			brick.setColor(enteredColor);
			add(brick, rowStartingX + i * (BRICK_WIDTH + BRICK_SEP), rowY);
		}
	}

	// add paddle to centre of aplication's lower part
	private void addPaddle() {
		paddle = new GRect(PADDLE_WIDTH, PADDLE_HEIGHT);
		paddle.setFilled(true);

		add(paddle, PADDLE_X, PADDLE_Y);
	}

	public void mouseMoved(MouseEvent e) {
		// move paddle if mouse is inside aplication bonds
		// because paddle's center is conected to mouseeft bond is half of paddles width
		// and
		// right bond is right walls - paddle width/2
		if (e.getX() <= WIDTH - PADDLE_WIDTH / 2 && e.getX() >= PADDLE_WIDTH / 2) {
			paddle.setLocation(e.getX() - PADDLE_WIDTH / 2, PADDLE_Y);
		}

	}

	// adds ball to application's centre
	private void addBall() {
		ball.setFilled(true);
		add(ball, (APPLICATION_WIDTH - BALL_RADIUS * 2) / 2, (APPLICATION_HEIGHT - BALL_RADIUS * 2) / 2);
	}

	// asks player to click after what game starts
	private void clickToStart() {
		GLabel clickToPlay = new GLabel("CLICK TO START!");
		clickToPlay.setFont("Times New Roman-30");
		double X = (APPLICATION_WIDTH - clickToPlay.getWidth()) / 2;
		double Y = (APPLICATION_HEIGHT - clickToPlay.getAscent()) * 3 / 4;
		add(clickToPlay, X, Y);
		waitForClick();
		remove(clickToPlay);
	}

	private void playGame() {
		// speed of ball towards x will be random number from 1 to 3 and then randomly
		// turned to positive or negative number
		// so ball moves randomly both to left or right when game starts

		setRandomDirectionOfBall();

		// While players still has game lifes
		// and have not reached max score yet (if he reaches max score that means he
		// destroyed all bricks)
		// game will go on
		while (gameLifes > 0 && score != MAX_SCORE) {
			ball.move(vx, vy);
			pause(BALL_PAUSE);

			reflectFromWall();

			GObject colider = getCollidingObject();

			// check if ball hit paddle and if is true reflect
			if (colider == paddle) {
				hitBallWithPaddle();

				stuckInPaddleCase(colider);

				paddleHits++;
				speedIncrease();
			}
			// check if ball hit brick, if true remove ball and reflect
			else if (colider != paddle && colider != null) {
				remove(colider);
				// after 1 destroyed brick score will get raised by 1
				score++;

				vy = -vy;
				bounceClip.play();
			}
		}
	}

	// this method will set random direction to ball at start of each try
	private double setRandomDirectionOfBall() {
		vx = rgen.nextDouble(1, 3);
		if (rgen.nextBoolean(0.5)) {
			vx = -vx;
		}
		return vx;
	}

	private void reflectFromWall() {
		Boolean leftWallContact = ball.getX() < 0;
		Boolean rightWallContact = ball.getX() + 2 * BALL_RADIUS > APPLICATION_WIDTH;
		Boolean topWallContact = ball.getY() < 0;
		Boolean bottomWallContact = ball.getY() + 2 * BALL_RADIUS > APPLICATION_HEIGHT;

		if (leftWallContact || rightWallContact) {
			vx = -vx;
			bounceClip.play();
		}
		if (topWallContact) {
			vy = -vy;
			bounceClip.play();
		}
		if (bottomWallContact) {

			gameLifes = gameLifes - 1;
			resetBallAndShowLifesLeft();

		}

	}

	// this method returns/gets object which is hit by ball
	private GObject getCollidingObject() {
		// top left corner of ball's box
		double ballCordX1 = ball.getX();
		double ballCordY1 = ball.getY();
		// top right
		double ballCordX2 = ballCordX1 + 2 * BALL_RADIUS;
		double ballCordY2 = ballCordY1;
		// bottom right
		double ballCordX3 = ballCordX1 + 2 * BALL_RADIUS;
		double ballCordY3 = ballCordY1 + 2 * BALL_RADIUS;
		// bottom left
		double ballCordX4 = ballCordX1;
		double ballCordY4 = ballCordY1 + 2 * BALL_RADIUS;

		// check each cordinate of ball, if 1 othe cords is touching object
		// this obejt will be returned
		// if there is no object null will be returned
		if (getElementAt(ballCordX1, ballCordY1) != null) {
			return getElementAt(ballCordX1, ballCordY1);

		} else if (getElementAt(ballCordX2, ballCordY2) != null) {
			return getElementAt(ballCordX2, ballCordY2);

		} else if (getElementAt(ballCordX3, ballCordY3) != null) {
			return getElementAt(ballCordX3, ballCordY3);

		} else if (getElementAt(ballCordX4, ballCordY4) != null) {
			return getElementAt(ballCordX4, ballCordY4);

		}
		return null;
	}

	// when ball hits paddle, ball will change its direction
	// depending on which part of paddle was hit by ball
	// ball will reflect differently
	private void hitBallWithPaddle() {
		double paddleMidpoint = paddle.getX() + PADDLE_WIDTH / 2;
		double ballCenterX = ball.getX() + BALL_RADIUS;

		// if ball hits left side of paddle (40% of paddles width from left) no matter
		// from which direction it came from,
		// it will start moving left
		if (ballCenterX < paddleMidpoint - PADDLE_WIDTH / 10) {
			if (vx >= 0) {
				vx = -sidesReflectSpeed;
			}
			vy = -vy;
			bounceClip.play();
		} else
		// if ball hits right side of paddle no matter from which direction it came
		// from,
		// it will start moving right
		if (ballCenterX > paddleMidpoint + PADDLE_WIDTH / 10) {
			if (vx <= 0) {
				vx = sidesReflectSpeed;
			}

			vy = -vy;
			bounceClip.play();
		} else
		// if ball hits middle part's RIGHT SIDE of paddle it will reflect more
		// vertically and no matter from which direction it came
		// it will reflect right
		if (paddleMidpoint <= ballCenterX && ballCenterX <= paddleMidpoint + PADDLE_WIDTH / 10) {
			if (vx < 0) {

				vx = centreReflectSpeed;////
			} else if (vx >= 0) {

				vx = centreReflectSpeed;
			}

			vy = -vy;
			bounceClip.play();

		} else
		// if ball hits middle part's LEFT SIDE of paddle it will reflect more
		// vertically and no matter from which direction it came
		// it will reflect left
		if (paddleMidpoint - PADDLE_WIDTH / 10 <= ballCenterX && ballCenterX <= paddleMidpoint) {
			if (vx < 0) {

				vx = -centreReflectSpeed;
			} else if (vx >= 0) {

				vx = -centreReflectSpeed;
			}

			vy = -vy;
			bounceClip.play();

		}
		//if paddle's centre was hit ball moves vertically up
		else if (paddleMidpoint == ballCenterX) {
			vx = 0;
			vy = -vy;
			bounceClip.play();
		}

	}

	// this method receives paddle object, if balls lower coordinate had
	// passed(gacda) paddles top coordinate
	// ball will be moved up, so it do not get stuck in paddle
	private void stuckInPaddleCase(GObject colider) {
		if (colider == paddle && (ball.getY() + (BALL_RADIUS * 2)) > (colider.getY())) {
			double overExtendY = ball.getY() + (BALL_RADIUS * 2) - paddle.getY();
			ball.move(0, -overExtendY);
		}
	}

	// this method will increase horizontal speed after every 7th hit with paddle
	// 7, 14,21, 28...
	private void speedIncrease() {
		if (paddleHits % 7 == 0) {
			sidesReflectSpeed = 2 * sidesReflectSpeed;
			centreReflectSpeed = 2 * centreReflectSpeed;
		}
	}

	// after bottom wall will be hit ball will be reset to middle of application,
	// player will be informed about how many game lifes he had left and
	// direction of ball will be randomised so ball starts with new random direction
	private void resetBallAndShowLifesLeft() {

		GLabel lifesLeftMsg = new GLabel("You have " + gameLifes + " lifes left");
		lifesLeftMsg.setFont("Times New Roman-25");
		double msgX = (APPLICATION_WIDTH - lifesLeftMsg.getWidth()) / 2;
		double msgY = (APPLICATION_HEIGHT - lifesLeftMsg.getAscent()) * 3 / 4;
		add(lifesLeftMsg, msgX, msgY);

		ball.setLocation((APPLICATION_WIDTH - BALL_RADIUS * 2) / 2, (APPLICATION_HEIGHT - BALL_RADIUS * 2) / 2);

		waitForClick();
		remove(lifesLeftMsg);

		// after ball has been reset to starting position, starting direction must be
		// randomised again
		setRandomDirectionOfBall();
	}

	// this method will happen if player runs out of lifes
	// and it will write game over 10 times on screen creating flashing text
	// animation
	private void gameOver() {
		for (int i = 0; i < 10; i++) {
			removeAll();
			pause(500);
			GLabel gameOver = new GLabel("GAME OVER");
			gameOver.setFont("Times New Roman-30");
			double gameOverW = gameOver.getWidth();
			double gameOverH = gameOver.getAscent();
			add(gameOver, (WIDTH - gameOverW) / 2, (HEIGHT - gameOverH) / 2);
			pause(500);
		}
	}

	// this method will happen if player destroys all brciks
	// and it will write you won 10 times on screen creating flashing text
	// animation
	private void youWon() {
		for (int i = 0; i < 10; i++) {
			removeAll();
			pause(500);
			GLabel victory = new GLabel("YOU WON!!!");
			victory.setFont("Times New Roman-30");
			double victoryW = victory.getWidth();
			double victoryH = victory.getAscent();
			add(victory, (WIDTH - victoryW) / 2, (HEIGHT - victoryH) / 2);
			pause(500);
		}
	}
}

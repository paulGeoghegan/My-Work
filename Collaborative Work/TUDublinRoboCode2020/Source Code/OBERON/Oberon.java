package Oberon;
import robocode.*;
import robocode.util.Utils;
import java.util.*;
import java.awt.Color;


/**
 * Oberon - Decision tree based melee (1v1) robot
 * <p>
 * Moves around the central grid within the borderzone, and uses it's decision tree to decide upon optimal strategies for combat
 *
 * @author Paul Geoghegan
 * @author Saul Burgess
 * @author Alan Byju
 */


public class Oberon extends Robot
{
	//imports rand and declairs variables
	Random rand = new Random();
	double x, y, h, rangeX, rangeY;
	byte scanDirection = -1;

	//declairs arrays that will dictate the grid that Oberon follows
	double[] goToX = new double[5], goToY = new double[5];

	//main
	public void run(){
		//sets colors for Oberon
		setAllColors(Color.green);

		//sets the area in the center of the arena that Oberon will stay within
		double rangeX = getBattleFieldWidth() - (getSentryBorderSize() * 2), rangeY = getBattleFieldHeight() - (getSentryBorderSize() * 2);

		//devides up the block in to small blocks that will form a grid
		rangeX = rangeY = rangeY / 5;

		//this loop creates the points that Oberon will use
		for(int i = 0 ; i < 5 ; i++)
		{

			//this saves the coardinates in the arrays which will be 5 points * 5 points for a total of 25 points
			goToX[i] = goToY[i] = rangeX / 4 + (rangeX * i) + getSentryBorderSize();

		} //end for

		//main loop
		while(true){

			//this checks if Oberon has finished moving
			if (getVelocity() < 1){

				x = goToX[rand.nextInt(5)] - getX();
				y = goToY[rand.nextInt(5)] - getY();

				//Turning is controlled by... liberal use of the inbuilt java trignometric functions. It calculates the desired heading by calculating the oppsite angle in a simulated triangle
				turnRight((Math.atan(Math.tan(Utils.normalRelativeAngleDegrees(Math.atan2(x, y) - getHeading() * 0.0174533)))) / 0.0174533);

				//Ahead is calculated via the same method as turning, just instead of the opposite angle, it is the opposite side
				ahead(Math.cos(Utils.normalRelativeAngleDegrees(Math.atan2(x, y) - getHeading() * 0.0174533)) * Math.hypot(x, y));

			}//End GetVelocity

			//this turns the radar
			turnRadarRight(360);

			//Triggers scan, this elminates a problem we had earlier onScannedRobot would cancel the current movement
			scan();

		}//End While
	}//End Run


	//when a robot is scanned by the radar this method will run
	public void onScannedRobot(ScannedRobotEvent ScannedRobotEvent)
	{

		//Checks if the enemy is outside the borderzone, if it is, don't fire at it
		if (ScannedRobotEvent.getDistance() < 200)
		{
			//this checks if the scanned robot is a sentry bot or not
			if(!ScannedRobotEvent.isSentryRobot())
			{

				//Calculates the values required for a firing solution to be calculated, also includes systems for converting import variables to radians
				double BodyRadians = getHeading() * 0.0174533, GunRadians = getGunHeading() * 0.0174533, BearingRadians = ScannedRobotEvent.getBearing() * 0.0174533, absoluteBearing = BodyRadians + BearingRadians;

				// This uses basic triganomitry to do a linear prediction of where the enemy will be and fires at that projected point
				turnGunRight((Utils.normalRelativeAngle(absoluteBearing - GunRadians + (ScannedRobotEvent.getVelocity() * Math.sin(BodyRadians - absoluteBearing) / 13.0))) / 0.0174533);
				fire(3.0);

			}//End sentry checker if

		}//End distance checker

	}//End scanned robot event/method


	//when Oberon hits another robot
	public void onHitRobot(HitRobotEvent e)
	{

		//reverses Oberon by 50 if it colides with another robot
		back(50);

		x = goToX[2] - getX();
		y = goToY[2] - getY();

		//Turning is controlled by... liberal use of the inbuilt java trignometric functions. It calculates the desired heading by calculating the oppsite angle in a simulated triangle
		turnRight((Math.atan(Math.tan(Utils.normalRelativeAngleDegrees(Math.atan2(x, y) - getHeading() * 0.0174533)))) / 0.0174533);

		//Ahead is calculated via the same method as turning, just instead of the opposite angle, it is the opposite side
		ahead(Math.cos(Utils.normalRelativeAngleDegrees(Math.atan2(x, y) - getHeading() * 0.0174533)) * Math.hypot(x, y));

	} //end on hit robot event/method

}//End Oberon

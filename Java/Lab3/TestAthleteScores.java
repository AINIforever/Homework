import  java.io.*;

/**
 * Test driver for class <code>AthleteScores</code>.
 *
 * @author  author name
 * @version  1.0.0
 */
public class TestAthleteScores  {

	/* Standard output stream */
	private static PrintWriter  stdOut = new  PrintWriter(System.out, true);

	/* Standard error stream */
	private static PrintWriter  stdErr = new  PrintWriter(System.err, true);

	/**
	 * Test driver for class <code>AthleteScores</code>.
	 *
	 * @param args  not used.
	 */
	public static void  main(String[] args)  {
		AthleteScores athlete1 = new AthleteScores("A" , 40 , 30 , 50);
		assertTrue("1: testing method getName()" , athlete1.getName() == "A");
		assertTrue("2: testing method getScoreOne()" , athlete1.getScoreOne() == 40);
		assertTrue("3: testing method getScoreTwo()" , athlete1.getScoreTwo() == 30);
		assertTrue("4: testing method getScoreThree()" , athlete1.getScoreThree() == 50);
		athlete1.setScoreOne(20);
		athlete1.setScoreTwo(40);
		athlete1.setScoreThree(30);
		assertTrue("5: testing method setScoreOne()" , athlete1.getScoreOne() == 20);
		assertTrue("6: testing method setScoreTwo()" , athlete1.getScoreTwo() == 40);
		assertTrue("7: testing method setScoreThree()" , athlete1.getScoreThree() == 30);
		AthleteScores athlete2 = new AthleteScores("B" , 30 , 40 , 50);
		assertTrue("8: testing method getMinimum" , athlete2.getMinimum() == 30 && athlete2.getScoreOne() == 30);
		athlete2 = new AthleteScores("Kobe" , 40 , 30 , 50);
		assertTrue("9: testing method getMinimum" , athlete2.getMinimum() == 30 && athlete2.getScoreTwo() == 30);
		athlete2 = new AthleteScores("Kobe" , 40 , 50 , 30);
		assertTrue("10: testing method getMinimum" , athlete2.getMinimum() == 30 && athlete2.getScoreThree() == 30);
		AthleteScores athlete3 = new AthleteScores("A" , 30 , 30 , 30);
		assertTrue("11: testing method equals()" , athlete3.equals(athlete1));
		assertTrue("12: testing method equals()" , !athlete2.equals(athlete1));
		TestAthleteScores athlete4 = new TestAthleteScores();
		assertTrue("13: testing method equals()" , !athlete4.equals(athlete1));
		
		String out1 = athlete1.getName() + "," + athlete1.getScoreOne() + "," + athlete1.getScoreTwo()+ "," + athlete1.getScoreThree();
		String out2 = athlete1.toString();
		assertTrue("14: testing method equals()" , out1.equals(out2));
		stdOut.println("done");
		/* PLACE YOUR CODE HERE */
	}

	/**
	 * Displays a message in the standard error stream if the value specified
	 * by parameter <code>condition<code> is <code>false</code>.
	 *
	 * @param message  the error message.
	 * @param condition  the test condition.
	 */
	public static void assertTrue(String message, boolean condition) {

		if (! condition) {
			stdErr.print("** Test failure ");
			stdErr.println(message);
		}
	}
}

import java.io.*;
import java.util.*;

public class SecondsCalculator {
	private static BufferedReader stdIn =
		new BufferedReader(new InputStreamReader(System.in));
	private static PrintWriter stdOut =
		new PrintWriter(System.out , true);
	private static PrintWriter stdErr =
		new PrintWriter(System.err , true);
		
	public static void main(String[] args) {
		//TODO write your own code here.
		String input;
		try{
			stdErr.print("time [hours:minutes:seconds]>");
			stdErr.flush();

			final String DELIM = ":";
			input = stdIn.readLine();
			StringTokenizer token = new StringTokenizer(input,DELIM);
			int count = token.countTokens();
			if(count!=3)
				stdErr.print("invalid input");

			int hour = Integer.parseInt(token.nextToken());
			int minute = Integer.parseInt(token.nextToken());
			int second = Integer.parseInt(token.nextToken());

			if(!(0<=hour && hour<=59 && minute>=0 && minute<=59 && second>=0 && second<= 59)){
				stdErr.print("invalid input");
			}

		}catch(NumberFormatException  nfe){
			stdErr.println(nfe);
		}
	}
}

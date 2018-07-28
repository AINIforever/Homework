import java.util.*;
import java.io.*;

/**
 * This class provides two file I/O methods for handling employee data.
 *
 * @author  author name
 * @version  1.0.0
 * @see  Employee
 */
public class  EmployeeFileIO {

	/**
	 * Creates an <code>ArrayList</code> of <code>Employee</code> objects
	 * from a file that contains employee data.
	 * <p>
	 * Every line in the specified file should contain three fields: ID, name,
	 * and salary of an employee in the following format: ID_name_salary
	 * </p>
	 *
	 * @param filename  the name of a file containing employee data.
	 * @return  an <code>ArrayList</code> of <code>Employee</code> objects.
	 * @throws FileNotFoundException  if the specified file does not exist.
	 * @throws IOException  if an I/O error occurs.
	 * @throws NoSuchElementException  if the data in the file is incomplete.
	 * @throws NumberFormatException  if the file contains invalid numbers.
	 */
	public static ArrayList<Employee> read(String filename)
		throws FileNotFoundException,
			IOException,
			NoSuchElementException,
			NumberFormatException  {


		/* PLACE YOUR CODE HERE */
		ArrayList<Employee> arrayList = new ArrayList<Employee>();  
        InputStream inputStream = new FileInputStream(filename);
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));  
        String str = "";  
    	while (true) {  
            str = bufferedReader.readLine();  
			if(str==null) 
				break;
			StringTokenizer stringTokenizer = new StringTokenizer(str, "_");    
			int id = Integer.parseInt(stringTokenizer.nextToken());
			String name = stringTokenizer.nextToken();
			double salary = Double.parseDouble(stringTokenizer.nextToken());
			arrayList.add(new Employee(id,name,salary));
        }
        inputStream.close();  

		return arrayList; // REMOVE; USED SO THIS FILE COMPILES
	}

	/**
	 * Creates a file of employee data from an <code>ArrayList</code> of
	 * <code>Employee</code> objects.
	 * <p>
	 * Every line in the file should contain the ID, name, and salary of an
	 * employee separated by an underscore: ID_name_salary
	 * </p>
	 *
	 * @param filename  the name of the file that will store the employee data.
	 * @param arrayList  an <code>ArrayList</code> of <code>Employee</code>
	 *                   objects.
	 * @throws IOException  if an I/O error occurs.
	 */
	public static void write(String filename, ArrayList<Employee> arrayList)
		throws IOException  {
		PrintWriter printWriter = new PrintWriter(filename);
		for(Employee employee:arrayList){
			printWriter.println(employee.getId() + "_" + employee.getName() + "_" + employee.getSalary());
		}
		printWriter.close();

		/* PLACE YOUR CODE HERE */

	}
}
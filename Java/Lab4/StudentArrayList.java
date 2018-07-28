import java.util.*;

/**
 * This class contains methods to process array lists of {@link Student}
 * objects.
 *
 * @author  autor name
 * @version  1.0.0
 * @see  Student
 * @see  ArrayList
 */
public class  StudentArrayList  {

	/**
	 * Returns an array list with three elements.
	 *
	 * @param first  a <code>Student</code> object.
	 * @param second  a <code>Student</code> object.
	 * @param third  a <code>Student</code> object.
	 * @return an array list with the objects <code>first</code>,
	 *           <code>second</code>, and <code>third</code>
	 */
	public static ArrayList<Student> makeArrayList(
		Student  first,
		Student  second,
		Student  third)  {

		/* PLACE YOUR CODE HERE */
		ArrayList<Student> students = new ArrayList<>();
		students.add(first);
		students.add(second);
		students.add(third);
		return students;

//		return null; // REMOVE; USED SO THIS FILE COMPILES
	}

	/**
	 * Returns an array list with the same elements of the specified array
	 * arranged in the same order.
	 *
	 * @param array  an array with <code>Student</code> objects .
	 * @return an array list with the same elements of the specified array
	 *         arranged in the same order
	 */
	public static ArrayList<Student> makeArrayListFromArray(Student[] array) {

		/* PLACE YOUR CODE HERE */
		ArrayList<Student> students = new ArrayList<>();
		for(Student student:array) {
			students.add(student);
		}

		return students; // REMOVE; USED SO THIS FILE COMPILES
	}

	/**
	 * Returns <code>true</code> if the specified array list contains a
	 * student whose id matches the specified ID.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @param id  a student ID.
	 * @return  <code>true</code> if the specified array list contains a
	 *          student whose ID matches the specified ID;
	 *          <code>false</code> otherwise.
	 */
	public static boolean hasStudent(
		ArrayList<Student>  arrayList,
		int  id)  {
		boolean has = false;
		/* PLACE YOUR CODE HERE */
		for(Student student:arrayList) {
			if(student.getId() == id)
				has = true;
		}

		return has; // REMOVE; USED SO THIS FILE COMPILES
	}

	/**
	 * Returns the number of students in the specified array list whose
	 * grade is greater than or equal to the specified grade.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @param grade  a grade.
	 * @return  the number of students in the specified array list whose
	 *          grade is greater than or equal to the specified grade.
	 */
	public static int countGradeGreaterOrEqual(
		ArrayList<Student> arrayList,
		int grade)  {

		/* PLACE YOUR CODE HERE */
		int num = 0;
		for(Student student:arrayList) {
			if(student.getGrade() >= grade)
				num++;
		}

		return num; // REMOVE; USED SO THIS FILE COMPILES
	}

	/**
	 * Returns the smallest grade of the students in the specified array list.
	 * <p>
	 * This method assumes that the array list is not empty.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @return  the smallest grade of the students in the specified array list.
	 */
	public static int getMinGrade(ArrayList<Student> arrayList)  {

		/* PLACE YOUR CODE HERE */
		int minGrade = 100;
		for(Iterator<Student> itr = arrayList.iterator();itr.hasNext();)
		{
			Student student = itr.next();
			if(student.getGrade() < minGrade)
				minGrade = student.getGrade(); 
		}

		return minGrade; // REMOVE; USED SO THIS FILE COMPILES
	}

	/**
	 * Returns the average grade of the students in the specified array list.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @return  the average grade of the students in the specified array list.
	 */
	public static double getGradeAverage(ArrayList<Student>  arrayList)  {

		/* PLACE YOUR CODE HERE */
		double average = 0;
		int sum = 0;
		for(Student student:arrayList) {
			sum += student.getGrade();
		}
		average = sum/arrayList.size();
		return average; // REMOVE; USED SO THIS FILE COMPILES
	}

	/**
	 * Removes all students in the specified array list whose grade
	 * is less than the specified grade.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @param grade  a grade.
	 */
	public static void removeGradeLess(
		ArrayList<Student>  arrayList,
		int  grade)  {
		
		for(Iterator<Student> itr = arrayList.iterator();itr.hasNext();)
		{
			Student student = itr.next();
			if(student.getGrade() < grade)
				itr.remove();
		}

		
		/* PLACE YOUR CODE HERE */
	}

	/**
	 * Returns the string representation of the objects in the specified
	 * array list.
	 * <p>
	 * A new line character ( \n ) should separate the string
	 * representations of the objects. For example:
	 * </p>
	 * <pre>
	 * Student[328,Galileo Galilei,80]\nStudent[123,Albert Einstein,100]
	 * </pre>
	 * <p>
	 * Note that the string does <i>not</i> end with a new line character ( \n )
	 * </p>
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @return  the string representation of the objects in the specified
	 *          array list.
	 */
	public static String displayAll(ArrayList<Student>  arrayList)  {

		/* PLACE YOUR CODE HERE */
				
		String displayAll = "";
		Iterator<Student> itr = arrayList.iterator();
		while(itr.hasNext())
		{
			Student student = itr.next();
			displayAll += student.toString();
			if(itr.hasNext())
				displayAll += "\n";
		}
		
		return displayAll; // REMOVE; USED SO THIS FILE COMPILES
	}
}
//Array's size is fixed, so we use ArrayList
//array   collection->list->arrayList  & set

//set
import java.util.*;
import java.lang.*;
public class Test{
    public static void main(String[], args){
        //set is not sequencial,doesn't have positiion
        List list = new ArrayList();
        list.add(123);
        list.add(123);
    //about hashSet
        Set set1 = new HashSet();
        set1.add(123);
        set1.add(123);//have no use

        //but when we add objects:
        set1.add(new Person(1,"abc"));
        set1.add(new Person(1,'abc'));
        //add the second object, it depends on whether they are the same
        //but when we override the equal method of the class Person, the JVM will know how to campare the two objects,
        //if the two objects are recognized as the same, it will not add the second one.
        //and we can override the hashCode method to select some diffrent objects instead of invoking equals method many times


    //about treeSet, it invoke method campareto.

        Set set2 = new TreeSet();
        set2.add(132);
        set2.add("abc");//will be error because they are not camparable.

        set2.add(new Person(1,"abc"));
        set2.add(new Person(2,"cde"));


    }
}

class Person implements Camparable{
    int pid;
    String name;
    public Person(int pid, String name){
        super();
        this.pid = pid;
        this.name = name;
    }
    @override
    public boolean equals(object object){
        //to determine the important attribute
        Person p = (Person)object;
        return (this.pid == p.pid);
    }
    @override
    public int hashCode(){
        final int prime = 31;  
        int result = 1;  
        result = prime * result + pid;  
        result = prime * result + ((name == null) ? 0 : name.hashCode());  
        return result;
    }

    @override
    public int campareTo(object o){
        //that means when their pid is the same, they are regarded as the same
        Person p = (Person)o;
        return pid-p.pid;
    }
}
//Polymophism:
// 1. Inheritance
// 2. Override
// 3. PIG(program in general) 父类引用指向子类对象

public class Demo{
    public static void main(String[] args){
        Person p1 = new Student();//program in general, dataType is going to be losed(loss)    //UpCast
        Person p2 = new Teacher();//general
        Student s = new Student();//specific

        p1.learn();//error! compiler will forget the actual type but declare type(loss)
        System.out.pintln(p1.getClass().getName());//output Demo.Student

        ((Student)p1).learn();//convert back   //DownCast
        ((Student)p2).learn();//ClassCastException


        Shape s1 = new Circle();
        Shape s2 = new Rect();
        draw(s1);
        draw(s2);


        I1 i = new MyClass();//PIG
        i.f();//correct
        i.g();//error: there is not function g in I1!

    }

    static void draw(Shape s) throws IOException{
        if(s instanceof Circle){//the keyword 'instanceof' is an oprator
            //draw circle
            System.out.println("Draw a Circle");
        }
        else if(s instanceof Rect){
            //draw rect
            System.out.println("Draw a Rect");
        }
        else{
            //draw shape
            System.out.println("Draw a Shape");
        }
        //we can also use the code:
        try{
            s.draw();//do not ave to predefine,it is polymophism!
            System.out.println("s.i");//output:10 it's not polymophsim
        }
    }
}
class Person{
    int pid;
    
    public Person(int pid){
        super();
        this.pid = pid;

    }

    void f(){//if we declare it 'final', it cannot be inherited, but private one cannot be access

    }
}
class Student extends Person{

    Student(){//invoke the constructor of superclass, but now we don't have implict constructor in Person().
        super();
    }
    void g(){
        this.f();
    }
    //@Override -- the function must be in superclass and can be access
    void f(){

    }
    void learn(){

    }

}

class Teacher extends Person{
    void teach(){

    }
}


//if we declare it 'final', then disabled it's inheritance
class Shape{
    int i=10;
    void draw() throws IOException{
        System.out.println("Draw Method in Shape");
    }
}

class Circle extends Shape throws AException,BException{
    int i=100;
    @Override
    void draw(){
        System.out.println("Draw Method in Circle");
    }
}

class Rect extends Shape{
    @Override
    void draw(){
        System.out.println("Draw Method in Rect");
    }
}

//abstract class and interface

abstract class Shape{//abstract one cannot be instanced
    void draw(){//can be concret
        System.out.println("Draw Method in Shape");
        f();//we can invoke abstract function in concret one  //it's template mothed(模板模式) 
    }
    abstract void f();//can be abstract
}

class Circle extends Shape{
    @Override
    void f(){}
}



interface I1{//everything in interface is abstract
    int i=10;
    void f();//declared public
    void g(){}//error: cannot provide body
}

interface I2 extends I1{
    int g();
}

class MyClass implements I1{//interface is used more: class MyClass extends MySuperClass implements I1,I2
    public void f(){
        System.out.pintln("invoke f");
    }
    void g(){
        System.out.println("Never invoke g");
    }
}


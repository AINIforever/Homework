//Generic collection(泛型)
import java.util.*;

public class Test{
    public static void main(String[] args){


        List<String> strList = new ArrayList<String>();//or keep the <> empty
        strList.add(123); //error: not string type, the get method will return the type
        //but if we remove the type from <>, we can add any type object. But its not recommended
        strList.add("abc");
        String s = strList.get(0);
        strList.size();

        Glass<Milk> gm = new Glass<Milk>();
        Glass<Juice> gj = new Glass<Juice>();

        Liquid l = new Milk(); //this is true.
        Glass<Liquid> gl = gm;//error
        Glass<Milk> gmm = new Glass<Liquid>();//error!
        op(gl);//true
        op(gm);//error!
        //the three lines code above says: In java, for collections  they are invariant  (不变), have no relation

        Milk[] milks = null;
        Liquid[] liquids = null;
        milks = liquids; //error
        liquids = milks; //true
        op(new Milk[4])//true
        //the four lines code show: In java, for arrays, they are covariant (协变)
        
    }
    static void op(Glass<Liquid> gl){

    }
    //but when we declare it as so:
    // static void op(Glass<? extends Liquid> gl){

    // }
    //the code : op(gm); is true
    static void op(Liquid[] gl){

    }
}

class Glass<T>{//declare it generic
    T content;

    public T getContent(T content){
        return content;
    }
    public void setContent(T content){
        this.content = content;
    }

    public Glass(T content){
        super();
        this.content = content;
    }
}
//if we want to do more thing:
class PaperGlass<T> extends Glass<T>{//one more generic class

}

class MilkGlass extends Glass<Milk>{//one ordinary class, not generic class

}


class Liquid{}

class Milk extends Liquid{}
class Juice extends Liquid{}
class Coffee extends Liquid{}
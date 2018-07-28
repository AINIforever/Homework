//装饰者模式(decorator pattern)：

//定义被装饰者：
public interface Human{
    public void wearClothes();
    public void walkToWhere();
}

//被装饰者具体类：可以有自己的初始装饰状态
public class Person implements Human{
    @Override
    public void wearClothes(){
        System.out.println("Wear what?");
    }

    @Override
    public void walkToWhere(){
        System.out.println("Go where?");
    }
}


//定义装饰者（抽象）
public abstract class Decorator implements Human{
    private Human human;

    public Decorator(Human human){
        this.human = human;
    }

    public void wearClothes(){
        human.wearClothes();
    }

    public void walkToWhere(){
        human.walkToWhere();
    }
}

//三种装饰，依次细化
public class Decorator_first extends Decorator{
    public Decorator_first(Human human){
        super(human);
    }

    public void goHome(){
        System.out.println("Go home.");
    }

    public void findMap(){
        System.out.println("Go to room to find map.");
    }

    @Override
    public void wearClothes(){
        super.wearClothes();
        goHome();
    }

    @Override
    public void walkToWhere(){
        super.walkToWhere();
        findMap();
    }
}

public class Decorator_second extends Decorator{
    public Decorator_second(Human human){
        super(human);
    }

    public void goClothespress(){
        System.out.println("Go to clothes press.");
    }

    public void findPlaceOnMap(){
        System.out.println("Find on map.");
    }

    @Override
    public void wearClothes(){
        super.wearClothes();
        goClothespress();
    }

    @Override
    public void walkToWhere(){
        super.walkToWhere();
        findPlaceOnMap();
    }
}

public class Decorator_third extends Decorator{
    public Decorator_third(Human human){
        super(human);
    }

    public void findClothes(){
        System.out.println("Find out a clothes.");
    }

    public void findTarget(){
        System.out.println("Find out the target.");
    }

    @Override
    public void wearClothes(){
        super.wearClothes();
        findClothes();
    }

    @Override
    public void walkToWhere(){
        super.walkToWhere();
        findTarget();
    }
}


//测试类：
public class Test{
    public static void main(string[] args){
        Human person = new Person();
        Decorator decorator = new Decorator_third(new Decorator_second(new Decorator_first(person)));
        decorator.wearClothes();
        decorator.walkToWhere();
    }
}

//输出:
// Wear what?
// Go home.
// Go to clothes press.
// Find out a clothes.
// Go where?
// Go to room to find map.
// Find on map.
// Find out the target.
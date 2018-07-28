import java.util.*;

public class Sales implements Iterable<Order>{
    private ArrayList<Order> orders;

    public Sales(){
        this.orders = new ArrayList<Order>();
    }

    public void addOrder(Order order){
        this.orders.add(order);
    }

    public Iterator<Order> iterator(){
        return this.orders.iterator();
    }

    public int getNumberOfOrders(){
        return this.orders.size();
    }
}
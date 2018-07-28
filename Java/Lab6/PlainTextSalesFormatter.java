public class PlainTextSalesFormatter implements SalesFormatter{
    private static PlainTextSalesFormatter singletonInstance = null;

    public static PlainTextSalesFormatter getSingletonInstance(){
        if(singletonInstance==null){
               singletonInstance = new PlainTextSalesFormatter();
        }
        return singletonInstance;
    }

    private PlainTextSalesFormatter(){

    }

    public String formatSales(Sales sales){
        String plainText = "";
        int i = 1;
        for(Order order : sales){
            plainText += "-----------------\n";
            plainText += "order" + i + "\n\n";
            for(OrderItem orderItem : order)
                plainText += orderItem.getQuantity() + " " + orderItem.getProduct().getCode() + " " + orderItem.getProduct().getPrice() + "\n"; 
            plainText += "\n" + "Total = " + order.getTotalCost()+ "\n";
            i++;
        }
        
        return plainText;
    }
}
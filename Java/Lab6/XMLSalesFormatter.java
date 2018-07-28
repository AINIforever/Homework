public class XMLSalesFormatter implements SalesFormatter{
    private static XMLSalesFormatter singletonInstance = null;

    public static XMLSalesFormatter getSingletonInstance(){
        if(singletonInstance==null){
               singletonInstance = new XMLSalesFormatter();
        }
        return singletonInstance;
    }

    private XMLSalesFormatter(){

    }

    public String formatSales(Sales sales){
        String HtmlText = "";
        HtmlText += "<Sales>\n";
        for(Order order : sales){
            HtmlText += "  <Order total=\"" + order.getTotalCost()+ "\">\n";
            for(OrderItem orderItem : order){
                HtmlText += "    <OrderItem quantity=\"" 
                         + orderItem.getQuantity()
                         + "\" price=\"" 
                         + orderItem.getProduct().getPrice() 
                         + "\">" 
                         + orderItem.getProduct().getCode() 
                         + "</OrderItem>\n";
            }
            HtmlText += "  </Order>\n";
        }
        HtmlText += "</Sales>";
        return HtmlText;
    }
}
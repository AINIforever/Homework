public class HTMLSalesFormatter implements SalesFormatter{
    private static HTMLSalesFormatter singletonInstance = null;

    public static HTMLSalesFormatter getSingletonInstance(){
        if(singletonInstance==null){
               singletonInstance = new HTMLSalesFormatter();
        }
        return singletonInstance;
    }

    private HTMLSalesFormatter(){

    }

    public String formatSales(Sales sales){
        String HtmlText = "";
        HtmlText += "<html>\n  <body>\n    <center><h2>Orders</h2></center>\n";
        for(Order order : sales){
            HtmlText += "    <hr>\n";
            HtmlText += "    <h4>Total = " + order.getTotalCost()+ "</h4>\n";
            for(OrderItem orderItem : order){
                HtmlText += "      <p>\n";
                HtmlText += "        <b>code:</b> " + orderItem.getProduct().getCode() + "<br>\n";
                HtmlText += "        <b>quantity:</b> " + orderItem.getQuantity() + "<br>\n";
                HtmlText += "        <b>price:</b> " + orderItem.getProduct().getPrice() + "\n";
                HtmlText += "      </p>\n";
            }
        }
        HtmlText += "   </body>\n</html>";
        return HtmlText;
    }
}
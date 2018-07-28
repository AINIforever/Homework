public class Product {
	
	private String code;
	private String description;
	private double price;
	
	
	public Product(String initialCode, String initialDescription, double initialPrice) {
		super();
		this.code = initialCode;
		this.description = initialDescription;
		this.price = initialPrice;
	}
	
	
	public String getCode() {
		return code;
	}
	public String getDescription() {
		return description;
	}
	public double getPrice() {
		return price;
	}

	@Override
	public String toString() {
		return code + "_" + description + "_" + price;
	}

	@Override
	public boolean equals(Object object) {
		// TODO Auto-generated method stub
		return object instanceof Product && this.code == (((Product) object).code);
	}
	
	
}
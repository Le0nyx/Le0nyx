package c1_kassazettel;

public class ReceiptItem {
    private String itemName;
    private int amount;
    private double price;

    public ReceiptItem(String itemName, int amount, double price) {
        if(!itemName.isEmpty()){
            this.itemName = itemName;
            this.amount = amount;
            this.price = price;
        }else{
            this.itemName = "";
            this.amount = 0;
            this.price = 0;
        }
    }

    public String getItemName() {
        return itemName;
    }

    public int getAmount() {
        return amount;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        if(price >= 0) {
            this.price = price;
        }
    }
}

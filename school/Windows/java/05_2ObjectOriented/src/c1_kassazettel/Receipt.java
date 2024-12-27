package c1_kassazettel;

import java.util.ArrayList;

public class Receipt {
    private final ArrayList<ReceiptItem> receiptItems = new ArrayList<>();
    private static int receiptAmount = 0;

    public void add(ReceiptItem receiptItem) {
        if(!receiptItem.getItemName().isEmpty() && receiptItem.getAmount() > 0) {
            receiptItems.add(receiptItem);
            receiptAmount++;
        }
    }

    public int getReceiptAmount() {
        return receiptAmount;
    }

    public void print(){
        double total = 0;
        System.out.println(" \n" +
                "╔════════════════════════╗\n" +
                "║ Shop                   ║\n" +
                "║ Marchstr. 23           ║\n" +
                "║ 10587 Berlin           ║\n" +
                "║ ☏ 030 314 213 86      ║\n" +
                "╚════════════════════════╝ \n\n");
        for (ReceiptItem receiptItem : receiptItems) {
            total += receiptItem.getPrice() * receiptItem.getAmount();
            System.out.println(receiptItem.getItemName()+ "\n" + receiptItem.getAmount()+ "x \t" + receiptItem.getPrice()+ "€\n");
        }

        System.out.println(
                "          =====\n" +
                "Summe EUR "+ String.format("%.2f", total) + "€\n" +
                "          =====");
    }
}

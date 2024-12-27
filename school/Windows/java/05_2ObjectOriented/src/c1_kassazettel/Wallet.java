package c1_kassazettel;

import java.util.ArrayList;

public class Wallet {
    private final ArrayList<Receipt> content = new ArrayList<>();

    public void add_to_wallet(Receipt receipt) {
        content.add(receipt);
    }

    public int getReceiptAmounts(){
        return content.size();
    }
}

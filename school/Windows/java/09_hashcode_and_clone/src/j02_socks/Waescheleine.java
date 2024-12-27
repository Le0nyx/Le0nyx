package j02_socks;

import java.util.ArrayList;

public class Waescheleine {
    private final int max_clothes = 10;
    ArrayList<Clothes> list = new ArrayList<>();

    public void addClothes(Clothes c1){
        if(list.size()<max_clothes){
            list.add(c1);
        }else{
            System.out.println("Line is full. Remove an Item or dry it somehwere else");
        }
    }

    public Clothes getClothePiece(int index){
        return list.get(index);
    }

    public int getClothesAmount(){
        return list.size();
    }

    public void dryClothes(){
        for (Clothes c1 : list) {
            c1.dry();
        }
    }

    public void removeClothes(int index){
        if(list.get(index).check_if_dry()) {
            list.remove(index);
        }else{
            System.out.println("Not dry yet");
        }
    }

}

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Room mainArea = new Room("On the streets", Descriptions.getDescriptionStreet());
        Room graveyard = new Room("Graveyard", Descriptions.getDescriptionGraveyard());
        RHouse1 house1 = new RHouse1("House 1", Descriptions.getDescriptionHouse1());
        RHouse2 house2 = new RHouse2("House 2", Descriptions.getDescriptionHouse2());
        RHouse3 house3 = new RHouse3("House 3", Descriptions.getDescriptionHouse3());
        RBushes bushes = new RBushes("Bushes", Descriptions.getDescriptionBushes());
        RGate gate = new RGate("Gate", Descriptions.getDescriptionGate());
        RTavern tavern = new RTavern("Tavern", Descriptions.getDescriptionTavern());
        RBlacksmith blacksmith = new RBlacksmith("Blacksmith", Descriptions.getDescriptionBlacksmith());
        RWell well = new RWell("Well", Descriptions.getDescriptionWell());
        RCurch curch = new RCurch("Curch", Descriptions.getDescriptionChurch());
        RCatacombs catacombs = new RCatacombs("Catacombs", Descriptions.getDescriptionCatacombs());

        // story start
        System.out.println(graveyard.getDescription());
        System.out.println("You are a lone knight, lost in a mysterious land. Your journey begins...");
        System.out.println("What is thy name?");
        String name = scanner.nextLine();
        Player player = new Player(name, graveyard);

        // start main game loop here
        int choice;

        while(player.getStillAlive()){
            // all the prints here
            System.out.println("\nChoose next action: \n");
            System.out.println("[0] View stats");
            System.out.println("[1] Move");
            System.out.println("[2] Give up");
            System.out.println("[Else] Go to street");


            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice){
                case 0: //print stats
                    System.out.println("\nPlayername: "+player.getPlayerName());
                    System.out.println("Player health: "+ player.getHealth() + "/" + player.getMaxhealth());
                    System.out.println("Current location: " + player.getCurrentRoom());
                    player.printInventory();

                    break;

                case 1: // show all rooms and let player move
                    System.out.println("Where do you want to go to?");
                    System.out.println("[0] Graveyard");
                    System.out.println("[1] House 1");
                    System.out.println("[2] House 2");
                    System.out.println("[3] House 3");
                    System.out.println("[4] Well");
                    System.out.println("[5] Bushes");
                    System.out.println("[6] Gate");
                    System.out.println("[7] Tavern");
                    System.out.println("[8] Blacksmith");
                    System.out.println("[9] Catacombs");
                    System.out.println("[10] Curch ");
                    System.out.println("[Else] Streets");

                    choice = scanner.nextInt();
                    scanner.nextLine();
                        switch (choice){
                            case 0:
                                player.setCurrentRoom(graveyard);

                                System.out.println(Descriptions.getDescriptionGraveyard());

                                player.setCurrentRoom(mainArea);
                                break;
                            case 1: //house1
                                player.setCurrentRoom(house1);

                                System.out.println("Location: " + house1.getRoomName());
                                System.out.println(house1.getDescription());

                                house1.playScenario(player);

                                player.setCurrentRoom(mainArea);
                                break;
                            case 2: //house2
                                if(player.isKeyHouse2()){
                                    player.setCurrentRoom(house2);

                                    System.out.println("Location: " + house2.getRoomName());
                                    System.out.println(house2.getDescription());

                                    house2.playScenario(player);

                                    player.setCurrentRoom(mainArea);
                                }else{
                                    System.out.println(house2.getDescription());
                                    System.out.println("The house is open. You see a door to the cellar. It's locked, but you seemed to have seen something shiny in the bushes before.");
                                    System.out.println("You leave again back into the streets. May you find the key.");

                                    player.setCurrentRoom(mainArea);
                                }

                                break;
                            case 3: //house3
                                player.setCurrentRoom(house3);

                                System.out.println("Location: " + house3.getRoomName());
                                System.out.println(house3.getDescription());

                                if(!player.isSolvedPuzzle()){
                                    house3.playScenario(player);
                                }else{
                                    System.out.println("You have already solved the puzzle in this house.");
                                }

                                player.setCurrentRoom(mainArea);

                                break;
                            case 4: //well
                                player.setCurrentRoom(well);

                                System.out.println("Location: " + well.getRoomName());
                                System.out.println(well.getDescription());

                                if(!player.isHasTalisman()){
                                    well.playScenario(player);
                                }else{
                                    System.out.println("There seems nothing more to be found around here. You should head back.");
                                }

                                player.setCurrentRoom(mainArea);

                                break;
                            case 5: //bushes
                                player.setCurrentRoom(bushes);

                                System.out.println("Location: " + bushes.getRoomName());
                                System.out.println(bushes.getDescription());

                                bushes.playScenario(player);

                                player.setCurrentRoom(mainArea);

                                break;
                            case 6: //gate
                                player.setCurrentRoom(gate);

                                System.out.println("Location: " + gate.getRoomName());
                                System.out.println(gate.getDescription());

                                gate.playScenario(player);

                                player.setCurrentRoom(mainArea);

                                break;
                            case 7: //tavern

                                if(player.isKeyGate() | player.isHasTNT()){ // can pass through
                                    player.setCurrentRoom(tavern);
                                    System.out.println("Location: " + tavern.getRoomName());
                                    System.out.println(tavern.getDescription());

                                    tavern.playScenario(player);

                                }else{
                                    System.out.println("You need something to get through the gate first.");
                                }

                                player.setCurrentRoom(mainArea);

                                break;
                            case 8: //blacksmith

                                if(player.isKeyGate() | player.isHasTNT()) {
                                    player.setCurrentRoom(blacksmith);

                                    System.out.println("Location: " + blacksmith.getRoomName());
                                    System.out.println(blacksmith.getDescription());

                                    blacksmith.playScenario(player);


                                }else{

                                    System.out.println("You need something to get through the gate first.");
                                }

                                player.setCurrentRoom(mainArea);

                                break;
                            case 9: //catacombs

                                if(player.isKeyGate() | player.isHasTNT()) {
                                    player.setCurrentRoom(catacombs);

                                    System.out.println("Location: " + catacombs.getRoomName());
                                    System.out.println(catacombs.getDescription());

                                    catacombs.playScenario(player);

                                }else{
                                    System.out.println("You need something to get through the gate first.");
                                }

                                player.setCurrentRoom(mainArea);

                                break;
                            case 10: //curch
                                if(player.isTrollDefeated()){
                                    player.setCurrentRoom(curch);

                                    System.out.println("Location: " + curch.getRoomName());
                                    System.out.println(curch.getDescription());

                                    curch.playScenario(player);

                                }else{
                                    System.out.println("The key to the curch is missing. A powerful foe seems to have it. Slay him and get the key! ");
                                }

                                player.setCurrentRoom(mainArea);

                                break;
                            default:
                                System.out.println("You seem to have forgotten where you wanted to go while walking.");
                                System.out.println(mainArea.getDescription());
                                break;
                        } //end of movement switchcase

                    break;
                case 2: // if player gives up
                    System.out.println("You decide to return to your grave in the Graveyard and stare into the sky \nas the light in your eyes fade and you fall asleep. ");
                    System.out.println("\nGame Over\n");
                    System.exit(0);
                    break;

                default: // if choice wrong
                    System.out.println("You seem to have forgotten what you wanted to do while walking.");
                    System.out.println(mainArea.getDescription());
                    break;
            }
        }

        scanner.close();
    } //end of main
}
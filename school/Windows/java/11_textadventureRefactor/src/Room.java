import java.util.ArrayList;

public class Room {
    private String roomName;
    private String description;

    private Npc npc;

    public Room(String roomName, String description) {
        this.roomName = roomName;
        this.description = description;
    }


    @Override
    public String toString() {
        return roomName;
    }

    public String getRoomName() {
        return roomName;
    }

    public String getDescription() {
        return description + "\n";
    }
}

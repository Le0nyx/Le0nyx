package j02_abstract_robot;

import java.util.ArrayList;

public class RemoteControl extends Robot{
    // p(getPos), a(advance), l(turnLeft), r(turnRight)

    public void run_command(String command) {
        for (int i = 0; i < command.length(); i++) {
            if (command.charAt(i) == 'p' || command.charAt(i) == 'P') {
                super.getPos();
            } else if (command.charAt(i) == 'a' || command.charAt(i) == 'A') {
                super.advance();
            } else if (command.charAt(i) == 'l' || command.charAt(i) == 'L') {
                super.turnLeft();
            } else if (command.charAt(i) == 'r' || command.charAt(i) == 'R') {
                super.turnRight();
            }
        }
    }
}

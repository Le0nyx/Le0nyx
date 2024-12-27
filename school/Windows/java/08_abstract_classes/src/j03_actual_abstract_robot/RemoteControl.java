package j03_actual_abstract_robot;

public abstract class RemoteControl implements Robot{
    // p(getPos), a(advance), l(turnLeft), r(turnRight)

    public void run_command(String command) {
        for (int i = 0; i < command.length(); i++) {
            if (command.charAt(i) == 'p' || command.charAt(i) == 'P') {
                this.getPos();
            } else if (command.charAt(i) == 'a' || command.charAt(i) == 'A') {
                this.advance();
            } else if (command.charAt(i) == 'l' || command.charAt(i) == 'L') {
                this.turnLeft();
            } else if (command.charAt(i) == 'r' || command.charAt(i) == 'R') {
                this.turnRight();
            }
        }
    }


}

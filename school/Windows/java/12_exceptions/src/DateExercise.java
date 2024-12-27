import java.text.DateFormat;
import java.text.ParseException;
import java.util.Date;

public class DateExercise {
    public static void main(String[] args) {
        String dateString = "18.12.2015";

        DateFormat dateFormat = DateFormat.getDateInstance();

        try {
            Date parsedDate = dateFormat.parse(dateString);

            System.out.println("Parsed Date: " + parsedDate.toString());
        } catch (ParseException e) {
            System.out.println("Error: Unable to parse the date string - " + e.getMessage());
        }
    }
}

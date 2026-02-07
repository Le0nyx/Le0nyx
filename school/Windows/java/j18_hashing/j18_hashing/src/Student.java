public class Student {
    private String firstName;
    private String lastName;
    private String birthDate;
    public String address;

    public Student(String firstName, String lastName, String birthDate, String address) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.birthDate = birthDate;
        this.address = address;
    }

    public String getLastName() { return lastName; }
    public String getFirstName() { return firstName; }
    public String getBirthDate() { return birthDate; }
    public String getAddress() { return address; }

    @Override
    public String toString() {
        return firstName + " " + lastName + " (" + birthDate + ") - " + address;
    }
}


package j01_personTest2;

public final class PersonTest2 {
	private PersonTest2() {
	}

	public static void main(final String[] args) {
		final Person p1 = new Person("Willi", "Weg 3");
		final Person p2 = p1.clone();

		System.out.println(p1 + ", " + p2);

		final Student s1 = new Student("Max", "Straße 4", 011);
		final Student s2 = s1.clone();

		System.out.println(s1 + ", " + s2);

		/*
		final Person p1 = new Person("Willi", "Weg 3");
		final Person p2 = new Person("Willi", "Weg 3");
		final Person p3 = new Person("Willie", "Weg 3");
		final Student s1 = new Student("Maja", "Allee 2", 000);

		s1.changeCode(521);

		final Student s2 = new Student("Maja", "Allee 2", 000);
		final Student s3 = new Student("Maja", "Allee 2", 521);
		System.out.println(p1.equals(p2));
		System.out.println(p1.equals(p3));
		System.out.println(s1.equals(s1));
		System.out.println(s1.equals(s2));
		System.out.println(s1.equals(s3));
		System.out.println(s1.equals(null));
		System.out.println(p1);
		System.out.println(s1);
		*/
	}
}
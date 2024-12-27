package j01_personTest2;

public class Student extends Person implements Cloneable {
	private int code;

	public Student(final String name, final String address, final int code) {
		super(name, address);
		this.code = code;
	}

	void changeCode(final int code) {
		this.code = code;
	}

	@Override
	public String toString() {
		return super.toString() + " " + this.code;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = super.hashCode();
		result = prime * result + this.code;
		return result;
	}

	@Override
	public boolean equals(final Object obj) {
		if (this == obj) {
			return true;
		}
		if (!super.equals(obj)) {
			return false;
		}
		if (this.getClass() != obj.getClass()) {
			return false;
		}
		final Student other = (Student) obj;
		if (this.code != other.code) {
			return false;
		}
		return true;
	}


	public Student clone() {
		return new Student(super.getName(), super.getAddress(), this.code);
	}

}
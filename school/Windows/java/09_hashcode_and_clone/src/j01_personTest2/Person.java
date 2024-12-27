package j01_personTest2;

public class Person implements Cloneable {
	private final String name;
	private final String address;

	public Person(final String name, final String address) {
		this.name = name;
		this.address = address;
	}

	@Override
	public String toString() {
		return this.name + " " + this.address;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 17;
		result = prime * result
				+ ((this.address == null) ? 0 : this.address.hashCode());
		result = prime * result
				+ ((this.name == null) ? 0 : this.name.hashCode());
		return result;
	}

	@Override
	public boolean equals(final Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (this.getClass() != obj.getClass()) {
			return false;
		}
		final Person other = (Person) obj;
		if (this.address == null) {
			if (other.address != null) {
				return false;
			}
		} else if (!this.address.equals(other.address)) {
			return false;
		}
		if (this.name == null) {
			if (other.name != null) {
				return false;
			}
		} else if (!this.name.equals(other.name)) {
			return false;
		}
		return true;
	}

	protected String getName() { return name; }
	protected String getAddress() { return address; }

	@Override
	public Person clone() {
		return new Person(this.name, this.address);
	}
}
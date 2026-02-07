package musicSerialization;

import java.io.Serializable;

/**
 * Represents a music album with metadata and pricing information.
 * <p>
 * This class is serializable and can be converted to and from a string
 * representation using a semicolon-delimited format.
 * </p>
 */
public class Album implements Serializable {
    private static final long serialVersionUID = 1L;

    private int albumID;
    private int artistID;
    private String name;
    private int numberOfTracks;
    private String label;
    private String releaseDate;
    private double price;

    /**
     * Constructs a new Album instance with the given properties.
     *
     * @param price           the price of the album in the local currency
     * @param releaseDate     the release date of the album (e.g., "YYYY-MM-DD")
     * @param label           the record label that published the album
     * @param numberOfTracks  the total number of tracks on the album
     * @param name            the title of the album
     * @param artistID        the unique identifier of the artist
     * @param albumID         the unique identifier of the album
     */
    public Album(double price, String releaseDate, String label,
                 int numberOfTracks, String name, int artistID, int albumID) {
        this.price = price;
        this.releaseDate = releaseDate;
        this.label = label;
        this.numberOfTracks = numberOfTracks;
        this.name = name;
        this.artistID = artistID;
        this.albumID = albumID;
    }

    /**
     * Returns the unique identifier of this album.
     *
     * @return the album ID
     */
    public int getAlbumID() {
        return albumID;
    }

    /**
     * Returns the unique identifier of the artist for this album.
     *
     * @return the artist ID
     */
    public int getArtistID() {
        return artistID;
    }

    /**
     * Returns the title of this album.
     *
     * @return the album name
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the total number of tracks on this album.
     *
     * @return the number of tracks
     */
    public int getNumberOfTracks() {
        return numberOfTracks;
    }

    /**
     * Returns the record label for this album.
     *
     * @return the label name
     */
    public String getLabel() {
        return label;
    }

    /**
     * Returns the release date of this album.
     *
     * @return the release date in string format
     */
    public String getReleaseDate() {
        return releaseDate;
    }

    /**
     * Returns the price of this album.
     *
     * @return the album price
     */
    public double getPrice() {
        return price;
    }

    /**
     * Returns a semicolon-delimited string representation of this album.
     * <p>
     * Format: albumID;artistID;name;numberOfTracks;label;releaseDate;price
     * </p>
     *
     * @return the serialized album string
     */
    @Override
    public String toString() {
        return albumID + ";" + artistID + ";" + name + ";" + numberOfTracks + ";"
                + label + ";" + releaseDate + ";" + price;
    }

    /**
     * Creates an Album instance by parsing a semicolon-delimited string.
     * <p>
     * Expected format: albumID;artistID;name;numberOfTracks;label;releaseDate;price
     * </p>
     *
     * @param data the semicolon-delimited album data string
     * @return a new Album object with fields populated from the data string
     * @throws IllegalArgumentException if the data string is invalid or parts cannot be parsed
     */
    public static Album fromString(String data) {
        if (data == null) {
            throw new IllegalArgumentException("Input data cannot be null");
        }
        String[] parts = data.split(";");
        if (parts.length != 7) {
            throw new IllegalArgumentException("Expected 7 fields but got " + parts.length);
        }
        try {
            int albumID = Integer.parseInt(parts[0]);
            int artistID = Integer.parseInt(parts[1]);
            String name = parts[2];
            int numberOfTracks = Integer.parseInt(parts[3]);
            String label = parts[4];
            String releaseDate = parts[5];
            double price = Double.parseDouble(parts[6]);
            return new Album(price, releaseDate, label, numberOfTracks, name, artistID, albumID);
        } catch (NumberFormatException ex) {
            throw new IllegalArgumentException("Failed to parse numeric fields", ex);
        }
    }
}

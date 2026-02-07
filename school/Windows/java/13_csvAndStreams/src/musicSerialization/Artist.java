package musicSerialization;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * Represents a musical artist with associated metadata such as genres and web links.
 * <p>
 * This class is serializable and supports conversion to and from a semicolon-delimited string format.
 * </p>
 */
public class Artist implements Serializable {
    private static final long serialVersionUID = 1L;

    private int artistID;
    private String name;
    private ArrayList<String> genres;
    private String website;
    private String lastFmUrl;

    /**
     * Constructs a new Artist instance with the specified properties.
     *
     * @param name      the name of the artist
     * @param artistID  the unique identifier for the artist
     * @param genres    a list of genres associated with the artist
     * @param website   the artist's official website URL, or null if none
     * @param lastFmUrl the Last.fm profile URL for the artist
     */
    public Artist(String name, int artistID, ArrayList<String> genres, String website, String lastFmUrl) {
        this.name = name;
        this.artistID = artistID;
        this.genres = genres;
        this.website = website;
        this.lastFmUrl = lastFmUrl;
    }

    /**
     * Returns the unique identifier of this artist.
     *
     * @return the artist ID
     */
    public int getArtistID() {
        return artistID;
    }

    /**
     * Returns the name of the artist.
     *
     * @return the artist's name
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the list of genres associated with this artist.
     *
     * @return a list of genre names
     */
    public ArrayList<String> getGenres() {
        return genres;
    }

    /**
     * Sets the genres associated with this artist.
     *
     * @param genres a new list of genre names
     */
    public void setGenres(ArrayList<String> genres) {
        this.genres = genres;
    }

    /**
     * Returns the artist's official website URL.
     *
     * @return the website URL, or null if not available
     */
    public String getWebsite() {
        return website;
    }

    /**
     * Returns the Last.fm profile URL for this artist.
     *
     * @return the Last.fm URL
     */
    public String getLastFmUrl() {
        return lastFmUrl;
    }

    /**
     * Returns a semicolon-delimited string representation of this artist.
     * <p>
     * Format: artistID;name;genre1,genre2;website;lastFmUrl
     * </p>
     *
     * @return the serialized artist string
     */
    @Override
    public String toString() {
        String genreList = genres == null ? "" : String.join(",", genres);
        String site = website == null ? "-" : website;
        return artistID + ";" + name + ";" + genreList + ";" + site + ";" + lastFmUrl;
    }

    /**
     * Creates an Artist instance by parsing a semicolon-delimited string.
     * <p>
     * Expected format: artistID;name;genre1,genre2;website;lastFmUrl
     * </p>
     *
     * @param data the semicolon-delimited artist data string
     * @return a new Artist object populated from the data string
     * @throws IllegalArgumentException if the data string is null, has an incorrect number of fields,
     *                                  or if the artistID cannot be parsed as an integer
     */
    public static Artist fromString(String data) {
        if (data == null) {
            throw new IllegalArgumentException("Input data cannot be null");
        }
        String[] parts = data.split(";");
        if (parts.length != 5) {
            throw new IllegalArgumentException("Expected 5 fields but got " + parts.length);
        }
        try {
            int artistID = Integer.parseInt(parts[0]);
            String name = parts[1];
            ArrayList<String> genres = new ArrayList<>();
            if (!parts[2].trim().isEmpty()) {
                genres.addAll(Arrays.asList(parts[2].split(",")));
            }
            String website = "-".equals(parts[3]) ? null : parts[3];
            String lastFmUrl = parts[4];
            return new Artist(name, artistID, genres, website, lastFmUrl);
        } catch (NumberFormatException ex) {
            throw new IllegalArgumentException("Failed to parse artistID", ex);
        }
    }
}
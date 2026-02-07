package musicSerialization;

import java.io.Serializable;

/**
 * Represents a single song with metadata including artist and album associations,
 * track details, and file information.
 * <p>
 * This class implements Serializable and supports conversion to and from
 * a semicolon-delimited string representation.
 * </p>
 */
public class Song implements Serializable {
    private static final long serialVersionUID = 1L;

    private int artistID;
    private int albumID;
    private String title;
    private int trackNumber;
    private String format;
    private double length;
    private String bitrate;
    private String filename;

    /**
     * Constructs a new Song instance with the specified properties.
     *
     * @param artistID    the unique identifier of the artist
     * @param albumID     the unique identifier of the album
     * @param title       the title of the song
     * @param trackNumber the track number within the album
     * @param format      the audio format (e.g., "MP3", "FLAC")
     * @param length      the duration of the song in seconds
     * @param bitrate     the audio bitrate (e.g., "320kbps")
     * @param filename    the filename or path where the song file is stored
     */
    public Song(int artistID,
                int albumID,
                String title,
                int trackNumber,
                String format,
                double length,
                String bitrate,
                String filename) {
        this.artistID = artistID;
        this.albumID = albumID;
        this.title = title;
        this.trackNumber = trackNumber;
        this.format = format;
        this.length = length;
        this.bitrate = bitrate;
        this.filename = filename;
    }

    /**
     * Returns the artist ID associated with this song.
     *
     * @return the artist ID
     */
    public int getArtistID() {
        return artistID;
    }

    /**
     * Returns the album ID associated with this song.
     *
     * @return the album ID
     */
    public int getAlbumID() {
        return albumID;
    }

    /**
     * Returns the title of this song.
     *
     * @return the song title
     */
    public String getTitle() {
        return title;
    }

    /**
     * Returns the track number of this song within its album.
     *
     * @return the track number
     */
    public int getTrackNumber() {
        return trackNumber;
    }

    /**
     * Returns the audio format of this song.
     *
     * @return the audio format
     */
    public String getFormat() {
        return format;
    }

    /**
     * Returns the duration of this song in seconds.
     *
     * @return the song length in seconds
     */
    public double getLength() {
        return length;
    }

    /**
     * Returns the bitrate of this song's audio.
     *
     * @return the audio bitrate
     */
    public String getBitrate() {
        return bitrate;
    }

    /**
     * Returns the filename or path of the song file.
     *
     * @return the filename or file path
     */
    public String getFilename() {
        return filename;
    }

    /**
     * Returns a semicolon-delimited string representation of this song.
     * <p>
     * Format: artistID;albumID;title;trackNumber;format;length;bitrate;filename
     * </p>
     *
     * @return the serialized song string
     */
    @Override
    public String toString() {
        return artistID + ";" + albumID + ";" + title + ";" + trackNumber + ";"
                + format + ";" + length + ";" + bitrate + ";" + filename;
    }

    /**
     * Creates a Song instance by parsing a semicolon-delimited string.
     * <p>
     * Expected format: artistID;albumID;title;trackNumber;format;length;bitrate;filename
     * </p>
     *
     * @param data the semicolon-delimited song data string
     * @return a new Song object populated with parsed values
     * @throws IllegalArgumentException if the input string is null, has an incorrect
     *                                  number of fields, or if numeric parsing fails
     */
    public static Song fromString(String data) {
        if (data == null) {
            throw new IllegalArgumentException("Input data cannot be null");
        }
        String[] parts = data.split(";");
        if (parts.length != 8) {
            throw new IllegalArgumentException("Expected 8 fields but got " + parts.length);
        }
        try {
            int artistID = Integer.parseInt(parts[0]);
            int albumID = Integer.parseInt(parts[1]);
            String title = parts[2];
            int trackNumber = Integer.parseInt(parts[3]);
            String format = parts[4];
            double length = Double.parseDouble(parts[5]);
            String bitrate = parts[6];
            String filename = parts[7];
            return new Song(artistID, albumID, title, trackNumber, format, length, bitrate, filename);
        } catch (NumberFormatException ex) {
            throw new IllegalArgumentException("Failed to parse numeric fields", ex);
        }
    }
}

package musicSerialization;

import java.io.*;
import java.util.ArrayList;

/**
 * Provides utility methods for reading and writing a MusicCollection
 * to and from text files (semicolon-delimited) or binary serialized files.
 */
public class MusicCollectionManager {

    /**
     * Reads artists, albums, and songs from separate text files and populates
     * a MusicCollection instance.
     * <p>
     * Each file should contain one record per line in the format produced by
     * the corresponding `toString` methods, delimited by semicolons.
     * </p>
     *
     * @param artistsFile the file containing serialized artists
     * @param albumsFile  the file containing serialized albums
     * @param songsFile   the file containing serialized songs
     * @return a MusicCollection populated with the parsed data
     * @throws IOException if an I/O error occurs while reading any file
     */
    public static MusicCollection read(File artistsFile,
                                       File albumsFile,
                                       File songsFile) throws IOException {
        MusicCollection collection = new MusicCollection();
        // Read artists
        try (BufferedReader reader = new BufferedReader(new FileReader(artistsFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                collection.addArtist(Artist.fromString(line));
            }
        }
        // Read albums
        try (BufferedReader reader = new BufferedReader(new FileReader(albumsFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                collection.addAlbum(Album.fromString(line));
            }
        }
        // Read songs
        try (BufferedReader reader = new BufferedReader(new FileReader(songsFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                collection.addSong(Song.fromString(line));
            }
        }
        return collection;
    }

    /**
     * Writes the artists, albums, and songs from a MusicCollection
     * to separate text files, one record per line using semicolon-delimited format.
     *
     * @param collection   the MusicCollection to serialize
     * @param artistsFile  the destination file for artists
     * @param albumsFile   the destination file for albums
     * @param songsFile    the destination file for songs
     * @throws IOException if an I/O error occurs while writing any file
     */
    public static void write(MusicCollection collection,
                             File artistsFile,
                             File albumsFile,
                             File songsFile) throws IOException {
        // Write artists
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(artistsFile))) {
            for (Artist artist : collection.getArtists()) {
                writer.write(artist.toString());
                writer.newLine();
            }
        }
        // Write albums
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(albumsFile))) {
            for (Album album : collection.getAlbums()) {
                writer.write(album.toString());
                writer.newLine();
            }
        }
        // Write songs
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(songsFile))) {
            for (Song song : collection.getSongs()) {
                writer.write(song.toString());
                writer.newLine();
            }
        }
    }

    /**
     * Reads lists of artists, albums, and songs from separate binary files
     * and populates a MusicCollection.
     *
     * @param artistsFile the file containing a serialized ArrayList&lt;Artist&gt;
     * @param albumsFile  the file containing a serialized ArrayList&lt;Album&gt;
     * @param songsFile   the file containing a serialized ArrayList&lt;Song&gt;
     * @return a MusicCollection populated from the binary data
     * @throws IOException            if an I/O error occurs while reading any file
     * @throws ClassNotFoundException if the class of a serialized object cannot be found
     */
    @SuppressWarnings("unchecked")
    public static MusicCollection binaryRead(File artistsFile,
                                             File albumsFile,
                                             File songsFile)
            throws IOException, ClassNotFoundException {
        MusicCollection collection = new MusicCollection();
        // Read artist list
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(artistsFile))) {
            collection.getArtists().addAll((ArrayList<Artist>) ois.readObject());
        }
        // Read album list
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(albumsFile))) {
            collection.getAlbums().addAll((ArrayList<Album>) ois.readObject());
        }
        // Read song list
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(songsFile))) {
            collection.getSongs().addAll((ArrayList<Song>) ois.readObject());
        }
        return collection;
    }

    /**
     * Writes the lists of artists, albums, and songs from a MusicCollection
     * to separate binary files.
     *
     * @param collection   the MusicCollection to serialize
     * @param artistsFile  the destination file for artists list
     * @param albumsFile   the destination file for albums list
     * @param songsFile    the destination file for songs list
     * @throws IOException if an I/O error occurs while writing any file
     */
    public static void binaryWrite(MusicCollection collection,
                                   File artistsFile,
                                   File albumsFile,
                                   File songsFile) throws IOException {
        // Write artist list
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(artistsFile))) {
            oos.writeObject(collection.getArtists());
        }
        // Write album list
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(albumsFile))) {
            oos.writeObject(collection.getAlbums());
        }
        // Write song list
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(songsFile))) {
            oos.writeObject(collection.getSongs());
        }
    }

    /**
     * Reads an entire MusicCollection from a single binary file.
     *
     * @param musicCollectionFile the file containing a serialized MusicCollection
     * @return the deserialized MusicCollection
     * @throws IOException            if an I/O error occurs while reading the file
     * @throws ClassNotFoundException if the MusicCollection class cannot be found
     */
    public static MusicCollection binaryReadSingleFile(File musicCollectionFile)
            throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(musicCollectionFile))) {
            return (MusicCollection) ois.readObject();
        }
    }

    /**
     * Writes the entire MusicCollection to a single binary file.
     *
     * @param collection          the MusicCollection to serialize
     * @param musicCollectionFile the destination file for the serialized MusicCollection
     * @throws IOException if an I/O error occurs while writing the file
     */
    public static void binaryWriteSingleFile(MusicCollection collection,
                                             File musicCollectionFile) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(musicCollectionFile))) {
            oos.writeObject(collection);
        }
    }

}

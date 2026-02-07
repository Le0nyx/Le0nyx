package musicSerialization;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 * Represents a collection of music entities including artists, albums, and songs.
 * <p>
 * This class is serializable and manages three lists:
 * <ul>
 *   <li>Artists</li>
 *   <li>Albums</li>
 *   <li>Songs</li>
 * </ul>
 * </p>
 */
public class MusicCollection implements Serializable {
    private static final long serialVersionUID = 1L;

    private List<Artist> artists;
    private List<Album> albums;
    private List<Song> songs;

    /**
     * Constructs an empty MusicCollection with initialized lists for artists, albums, and songs.
     */
    public MusicCollection() {
        this.artists = new ArrayList<>();
        this.albums = new ArrayList<>();
        this.songs = new ArrayList<>();
    }

    /**
     * Returns the list of artists in this collection.
     *
     * @return a list of Artist objects
     */
    public List<Artist> getArtists() {
        return artists;
    }

    /**
     * Returns the list of albums in this collection.
     *
     * @return a list of Album objects
     */
    public List<Album> getAlbums() {
        return albums;
    }

    /**
     * Returns the list of songs in this collection.
     *
     * @return a list of Song objects
     */
    public List<Song> getSongs() {
        return songs;
    }

    /**
     * Adds an artist to this collection.
     *
     * @param artist the Artist to add; must not be null
     * @throws IllegalArgumentException if artist is null
     */
    public void addArtist(Artist artist) {
        if (artist == null) {
            throw new IllegalArgumentException("Artist cannot be null");
        }
        this.artists.add(artist);
    }

    /**
     * Adds an album to this collection.
     *
     * @param album the Album to add; must not be null
     * @throws IllegalArgumentException if album is null
     */
    public void addAlbum(Album album) {
        if (album == null) {
            throw new IllegalArgumentException("Album cannot be null");
        }
        this.albums.add(album);
    }

    /**
     * Adds a song to this collection.
     *
     * @param song the Song to add; must not be null
     * @throws IllegalArgumentException if song is null
     */
    public void addSong(Song song) {
        if (song == null) {
            throw new IllegalArgumentException("Song cannot be null");
        }
        this.songs.add(song);
    }
}

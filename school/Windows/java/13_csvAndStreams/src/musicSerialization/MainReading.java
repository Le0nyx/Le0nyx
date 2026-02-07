package musicSerialization;

import java.io.File;
import java.util.ArrayList;

public class MainReading {
    public static void main(String[] args) {
        try {
            File artistsFile = new File("artist.dat");
            File albumsFile = new File("albums.dat");
            File songsFile = new File("songs.dat");
            //File singleBinaryFile = new File("musiccollection.bin");

            System.out.println("Datei lesen");
            MusicCollection collectionFromText = MusicCollectionManager.read(artistsFile, albumsFile, songsFile);
            printCollection(collectionFromText);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void printCollection(MusicCollection collection) {
        System.out.println("Künstler:");
        for (Artist artist : collection.getArtists()) {
            System.out.println(artist);
        }

        System.out.println("\nAlben:");
        for (Album album : collection.getAlbums()) {
            System.out.println(album);
        }

        System.out.println("\nSongs:");
        for (Song song : collection.getSongs()) {
            System.out.println(song);
        }
    }
}

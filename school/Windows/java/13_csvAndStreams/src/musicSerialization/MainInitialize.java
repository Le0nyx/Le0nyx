package musicSerialization;

import java.io.File;
import java.util.ArrayList;

public class MainInitialize {
    public static void main(String[] args) {
        try {
            // can also be .dat or .csv or .txt since saving is always just a string
            File artistsFile = new File("artist1.csv");
            File albumsFile = new File("albums1.csv");
            File songsFile = new File("songs1.csv");
            //File singleBinaryFile = new File("musiccollection.bin");

            MusicCollection collection = new MusicCollection();

            ArrayList<String> genres1 = new ArrayList<>();
            genres1.add("new age");
            genres1.add("electronic");
            Artist artist1 = new Artist("Vangelis", 1, genres1, "-", "http://www.lastfm.de/music/Vangelis");


            ArrayList<String> genres2 = new ArrayList<>();
            genres2.add("electronic");
            Artist artist2 = new Artist("Jean-Michel Jarre", 2, genres2, "http://www.jeanmicheljarre.com/", "http://www.lastfm.de/music/Jean-Michel+Jarre");
            collection.addArtist(artist1);
            collection.addArtist(artist2);


            Album album1 = new Album(9.90, "30. Nov. 1980", "Polydor", 7, "Chariots Of Fire", 1, 1);
            Album album2 = new Album(9.90, "30. Nov. 1988", "Polydor", 14, "Themes", 1, 2);
            Album album3 = new Album(9.90, "20. Sep. 2004", "Nonesuch", 14, "Aero", 2, 3);
            Album album4 = new Album(9.90, "30. Nov. 1977", "Epic", 16, "Equinoxe", 2, 4);
            collection.addAlbum(album1);
            collection.addAlbum(album2);
            collection.addAlbum(album3);
            collection.addAlbum(album4);


            Song song1 = new Song(1, 1, "Chariots of Fire", 7, "mp3", 211, "192kbps", "/home/max/music/vangelis-chariots.mp3");
            Song song2 = new Song(2, 4, "Equinoxe Part 1", 1, "mp3", 220, "192kbps", "/home/max/music/jarre-equinoxe_part_1.mp3");
            collection.addSong(song1);
            collection.addSong(song2);

            // write to fle
            System.out.println("write to file");
            MusicCollectionManager.write(collection, artistsFile, albumsFile, songsFile);

            // read from file
            System.out.println("read file");
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

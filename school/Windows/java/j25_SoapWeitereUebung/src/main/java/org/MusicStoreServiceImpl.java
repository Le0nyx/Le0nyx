package org;

import jakarta.jws.WebService;
import java.util.HashMap;
import java.util.Map;

@WebService(
        targetNamespace = "http://localhost:12345/MusicStore",
        endpointInterface = "org.MusicStoreInterface",
        serviceName = "MusicStoreService",
        portName = "MusicStorePort"
)
public class MusicStoreServiceImpl implements MusicStoreInterface {

    private Map<String, Map<String, Double>> musicDatabase = new HashMap<>();

    public MusicStoreServiceImpl() {
        // Beispiel-Daten
        Map<String, Double> beatlesAlbums = new HashMap<>();
        beatlesAlbums.put("Abbey Road", 25.99);
        beatlesAlbums.put("Let It Be", 22.99);

        Map<String, Double> pinkFloydAlbums = new HashMap<>();
        pinkFloydAlbums.put("The Dark Side of the Moon", 29.99);
        pinkFloydAlbums.put("The Wall", 31.50);

        musicDatabase.put("The Beatles", beatlesAlbums);
        musicDatabase.put("Pink Floyd", pinkFloydAlbums);
    }

    @Override
    public double getPrice(String artist, String albumTitle) {
        if (musicDatabase.containsKey(artist)) {
            Map<String, Double> artistAlbums = musicDatabase.get(artist);
            if (artistAlbums.containsKey(albumTitle)) {
                return artistAlbums.get(albumTitle);
            }
        }
        return -1.0;
    }

    @Override
    public String[] getAlbums(String artist) {
        if (musicDatabase.containsKey(artist)) {
            return musicDatabase.get(artist).keySet().toArray(new String[0]);
        }
        return new String[0];
    }

    @Override
    public String purchaseAlbum(String artist, String albumTitle) {
        double price = getPrice(artist, albumTitle);
        if (price > 0) {
            return "Kauf bestätigt! " + albumTitle + " von " + artist +
                    " für " + price + " EUR. Transaktions-ID: TXN" + System.currentTimeMillis();
        } else {
            return "Album nicht gefunden!";
        }
    }
}

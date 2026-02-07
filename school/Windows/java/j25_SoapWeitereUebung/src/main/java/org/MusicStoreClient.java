package org;

import jakarta.xml.ws.Service;
import javax.xml.namespace.QName;
import java.net.URL;

public class MusicStoreClient {
    public static void main(String[] args) throws Exception {
        URL wsdlUrl = new URL("http://localhost:12345/MusicStore?wsdl");
        QName qname = new QName("http://localhost:12345/MusicStore", "MusicStoreService");
        Service service = Service.create(wsdlUrl, qname);

        MusicStoreInterface musicStore = service.getPort(MusicStoreInterface.class);

        System.out.println("=== MusicStore SOAP Client ===");

        // Test 1: Preisabfrage
        System.out.println("\n1. Preisabfrage:");
        double price = musicStore.getPrice("The Beatles", "Abbey Road");
        System.out.println("Preis: " + price + " EUR");

        // Test 2: Alben anzeigen
        System.out.println("\n2. Alben eines Künstlers:");
        String[] albums = musicStore.getAlbums("Pink Floyd");
        for (String album : albums) {
            System.out.println(" - " + album);
        }

        // Test 3: Kaufen
        System.out.println("\n3. Album kaufen:");
        String result = musicStore.purchaseAlbum("The Beatles", "Abbey Road");
        System.out.println(result);
    }
}

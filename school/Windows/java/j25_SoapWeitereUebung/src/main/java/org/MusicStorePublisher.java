package org;

import jakarta.xml.ws.Endpoint;

public class MusicStorePublisher {
    public static void main(String[] args) {
        String url = "http://localhost:12345/MusicStore";
        Endpoint.publish(url, new MusicStoreServiceImpl());
        System.out.println("MusicStore SOAP Service läuft auf: " + url);
        System.out.println("WSDL verfügbar unter: " + url + "?wsdl");
    }
}

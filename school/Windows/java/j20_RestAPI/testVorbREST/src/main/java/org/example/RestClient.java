package org.example;

import jakarta.ws.rs.client.Client;
import jakarta.ws.rs.client.ClientBuilder;
import jakarta.ws.rs.client.Entity;
import jakarta.ws.rs.core.MediaType;

public class RestClient {
    public static void main(String[] args) {
        Client client = ClientBuilder.newClient();

        String result = client
                .target("http://localhost:9998/user")
                .request(MediaType.APPLICATION_JSON)
                .get(String.class);

        System.out.println(result);

        User newUser = new User(5, "user5");

        client.target("http://localhost:9998/user").request().post(Entity.entity(newUser, MediaType.APPLICATION_JSON));

        String result2 = client
                .target("http://localhost:9998/user")
                .request(MediaType.APPLICATION_JSON)
                .get(String.class);

        System.out.println(result2);

    }


}

package org.example;

import jakarta.ws.rs.core.UriBuilder;
import org.glassfish.jersey.jdkhttp.JdkHttpServerFactory;
import org.glassfish.jersey.server.ResourceConfig;

import java.net.URI;

public class RestServer {
    public static void main(String[] args) {
        UserVerwaltung.initialize();

        // Uniform Ressource Identifier
        URI uri = UriBuilder.fromUri("http://localhost/").port(9998).build();

        ResourceConfig config = new ResourceConfig();
        config.packages("org.example"); // sees automatically UserResource

        JdkHttpServerFactory.createHttpServer(uri, config);
    }

}

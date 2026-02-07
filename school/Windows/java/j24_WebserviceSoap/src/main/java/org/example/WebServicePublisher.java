package org.example;

import jakarta.xml.ws.Endpoint;

public class WebServicePublisher {
    public static void main(String[] args) {
        Endpoint.publish("http://localhost:12345/HelloWorld", new WebServiceImpl());
    }
}


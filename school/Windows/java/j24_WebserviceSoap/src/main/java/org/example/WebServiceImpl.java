package org.example;

import jakarta.jws.WebService;

@WebService(targetNamespace = "http://localhost:12345/HelloWorld", endpointInterface = "org.example.WebServiceInterface", name="HelloWord", serviceName="HelloWorldService")
public class WebServiceImpl implements WebServiceInterface {
    @Override
    public String getHelloWorldAsString(String str) {
        return "Hello World of JAX-WS " + str;
    }
}


package org.example;

import jakarta.xml.ws.Service;

import javax.xml.namespace.QName;
import java.net.URL;

public class WebServiceClient {
    public static void main(String[] args) throws Exception {
        URL wsdlUrl = new URL("http://localhost:12345/HelloWorld?wsdl");
        QName qname = new QName("http://localhost:12345/HelloWorld", "HelloWorldService");
        Service service = Service.create(wsdlUrl, qname);
        WebServiceInterface helloWorldInterface = service.getPort(WebServiceInterface.class);
        System.out.println(helloWorldInterface.getHelloWorldAsString("- This is Java Code Geeks"));
    }
}


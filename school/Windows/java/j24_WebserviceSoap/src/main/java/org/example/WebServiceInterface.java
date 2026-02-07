package org.example;

import jakarta.jws.WebMethod;
import jakarta.jws.WebParam;
import jakarta.jws.WebResult;
import jakarta.jws.WebService;
import jakarta.jws.soap.SOAPBinding;

@WebService(name = "HelloWorld", targetNamespace = "http://localhost:12345/HelloWorld")
@SOAPBinding(style = SOAPBinding.Style.RPC)
public interface WebServiceInterface {

    @WebMethod(operationName = "getHelloWorldAsString")
    @WebResult(name = "result")
    public String getHelloWorldAsString(@WebParam(name = "str") String str);
}
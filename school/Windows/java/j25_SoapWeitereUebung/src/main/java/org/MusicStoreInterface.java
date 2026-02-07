package org;

import jakarta.jws.WebMethod;
import jakarta.jws.WebParam;
import jakarta.jws.WebResult;
import jakarta.jws.WebService;
import jakarta.jws.soap.SOAPBinding;

@WebService(name = "MusicStore", targetNamespace = "http://localhost:12345/MusicStore")
@SOAPBinding(style = SOAPBinding.Style.RPC)
public interface MusicStoreInterface {

    @WebMethod(operationName = "getPrice")
    @WebResult(name = "price")
    double getPrice(@WebParam(name = "artist") String artist,
                    @WebParam(name = "albumTitle") String albumTitle);

    @WebMethod(operationName = "getAlbums")
    @WebResult(name = "albums")
    String[] getAlbums(@WebParam(name = "artist") String artist);

    @WebMethod(operationName = "purchaseAlbum")
    @WebResult(name = "confirmation")
    String purchaseAlbum(@WebParam(name = "artist") String artist,
                         @WebParam(name = "albumTitle") String albumTitle);
}

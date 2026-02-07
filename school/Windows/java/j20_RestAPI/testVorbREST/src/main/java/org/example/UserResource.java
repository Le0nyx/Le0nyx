package org.example;

import jakarta.ws.rs.*;
import jakarta.ws.rs.core.MediaType;

import java.util.List;

@Path("/user")
public class UserResource {
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public List<User> getUsers() {
        return UserVerwaltung.getUsers();
    }

    @GET
    @Path("/{id}")
    @Produces(MediaType.APPLICATION_JSON)
    public User getUser(@PathParam("id") int id) {
        return UserVerwaltung.getUser(id);
    }

    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public void createUser(User user) {
        UserVerwaltung.addUser(user);
    }


    @DELETE
    @Path("/{delete_id}")
    public void deleteUser(@PathParam("delete_id") int deleteid) {
        UserVerwaltung.removeUser(deleteid);
    }


}

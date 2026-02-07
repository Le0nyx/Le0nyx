package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class UserVerwaltung {
    private static List<User> users;

    public static void initialize() {
        users = Collections.synchronizedList(new ArrayList<>());

        users.add(new User(1, "user1"));
        users.add(new User(2, "user2"));
        users.add(new User(3, "user3"));
    }

    public static User getUser(int id) {
        for (User user : users) {
            if (user.getId() == id) {
                return user;
            }
        }
        return null;
    }

    public static List<User> getUsers() {
        return users;
    }

    public static void addUser(User user) {
        users.add(user);
    }

    public static void removeUser(int id) {
        users.remove(getUser(id));
    }
}
